#!/usr/bin/env python3
"""
Parse dump.cs and emit offsets.h using a manually-curated mapping.json.

The mapping maps semantic names to the actual field names in the dump.
Field names may be readable (playerModel) or hashed (_f58252d68b0c36a8bbec7510d27a20efc311304d).

Usage: parse_offsets.py <dump.cs> <mapping.json> <offsets.h>
"""

import json
import re
import sys
from datetime import datetime, timezone
from pathlib import Path


def parse_dump(path: str) -> dict:
    """
    Returns { "ClassName": { "fieldName": {offset, type}, ... } }
    Handles the rodroid dumper's dump.cs format:
        public class ClassName : BaseClass
        {
            public Vector3 fieldName; // 0x1A0
            private static object %hash; // 0x0
        }
    """
    src = Path(path).read_text(encoding="utf-8", errors="ignore")

    class_re = re.compile(
        r"^((?:public |private |internal |protected )?"
        r"(?:sealed |abstract |static )*"
        r"(?:class|struct)\s+([\w.]+)[^\n]*\n\{)",
        re.M
    )
    field_re = re.compile(
        r"^\s*(public|private|protected|internal)?\s*"
        r"(static\s+)?"
        r"(?:readonly\s+)?"
        r"([\w<>\[\]\.\,\?%]+)\s+"
        r"([\w%<>\.]+)\s*"
        r";\s*//\s*(0x[0-9A-Fa-f]+)"
    )

    classes = {}
    for m in class_re.finditer(src):
        cls = m.group(2)
        if "." in cls:
            continue
        end = src.find("\n}", m.end())
        body = src[m.end():end] if end != -1 else src[m.end():m.end()+20000]

        fields = {}
        for line in body.split("\n"):
            fm = field_re.match(line)
            if fm:
                fname = fm.group(4)
                ftype = fm.group(3)
                offset = fm.group(5).lower()
                fields[fname] = {"offset": offset, "type": ftype}

        if cls not in classes:
            classes[cls] = {}
        classes[cls].update(fields)

    return classes


def write_header(mapping: dict, dump: dict, out_path: str):
    lines = [
        "#pragma once",
        "#include <cstdint>",
        "",
        "// Auto-generated from dump.cs via mapping.json.",
        f"// Generated: {datetime.now(timezone.utc).isoformat()}",
        "",
        "namespace Offsets {",
    ]

    ok, drift, missing = 0, [], []

    for cls, fields in sorted(mapping["offsets"].items()):
        lines.append(f"    // ── {cls} ──")
        dump_cls = dump.get(cls, {})
        if not dump_cls:
            lines.append(f"    // MISSING CLASS: {cls}")
            for f in fields:
                missing.append(f"{cls}::{f}")
            lines.append("")
            continue

        for semantic, spec in fields.items():
            field_name = spec["field"]
            expected = spec.get("expected_offset", "").lower()

            found = dump_cls.get(field_name)
            if not found:
                # try to find by offset
                if expected:
                    for k, v in dump_cls.items():
                        if v["offset"] == expected:
                            found = v
                            field_name = k
                            break
                if not found:
                    lines.append(f"    // MISSING: {cls}::{semantic} (field '{field_name}')")
                    missing.append(f"{cls}::{semantic}")
                    continue

            actual = found["offset"]
            const_name = f"{cls}_{semantic.lstrip('_')}"

            if expected and actual != expected:
                lines.append(
                    f"    // DRIFT: {cls}::{semantic} was {expected}, now {actual}  "
                    f"(type: {found['type']})"
                )
                drift.append(f"{cls}::{semantic} {expected} -> {actual}")
                # still write the new offset so the cheat keeps working
                lines.append(f"    constexpr uintptr_t {const_name} = {actual};  // DRIFTED")
            else:
                lines.append(
                    f"    constexpr uintptr_t {const_name} = {actual};  // {found['type']}"
                )
            ok += 1

        lines.append("")

    if "type_info" in mapping:
        lines.append("    // ── TypeInfo ──")
        for name, addr in mapping["type_info"].items():
            const_name = f"{name}_TypeInfo"
            lines.append(f"    constexpr uintptr_t {const_name} = {addr};")
        lines.append("")

    if "manual" in mapping:
        lines.append("    // ── Manual (fill in yourself) ──")
        for name, spec in mapping["manual"].items():
            lines.append(f"    // {name} = {spec['offset']}  — {spec['note']}")
        lines.append("")

    lines.append("}")
    Path(out_path).write_text("\n".join(lines), encoding="utf-8")
    return ok, drift, missing


def main():
    if len(sys.argv) != 4:
        print(f"usage: {sys.argv[0]} <dump.cs> <mapping.json> <offsets.h>")
        sys.exit(1)

    dump_path, mapping_path, out_path = sys.argv[1:4]
    mapping = json.loads(Path(mapping_path).read_text())
    dump = parse_dump(dump_path)

    print(f"[parse] dump has {len(dump)} classes")
    print(f"[parse] mapping has {sum(len(v) for v in mapping['offsets'].values())} offsets")

    ok, drift, missing = write_header(mapping, dump, out_path)
    print(f"[parse] OK={ok} drift={len(drift)} missing={len(missing)}")
    for d in drift:
        print(f"[parse] DRIFT   {d}")
    for m in missing:
        print(f"[parse] MISSING {m}")

    if ok == 0:
        print("[parse] ERROR: nothing resolved")
        sys.exit(1)


if __name__ == "__main__":
    main()
