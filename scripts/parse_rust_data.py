#!/usr/bin/env python3
"""
Validate manually-curated mapping.json against a fresh rust.h dump.

Does NOT discover fields. The mapping is authoritative. This script only
checks that the offsets in the mapping still exist and still have the same
types. Drift is logged but does not fail the pipeline.

Usage: parse_rust_data.py <rust.h> <mapping.json> <offsets.h>
"""

import json
import re
import sys
from datetime import datetime, timezone
from pathlib import Path


def parse_rust_h(path: str) -> dict:
    src = Path(path).read_text(encoding="utf-8", errors="ignore")
    ns_re = re.compile(r"^\s*namespace\s+(\w+)")
    field_re = re.compile(
        r"^\s*inline\s+constexpr\s+::std::ptrdiff_t\s+(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;"
        r"(?:\s*//\s*(.*))?$"
    )
    result = {}
    current = None
    for line in src.splitlines():
        nm = ns_re.match(line)
        if nm:
            current = nm.group(1)
            result.setdefault(current, {})
            continue
        fm = field_re.match(line)
        if fm and current:
            result[current][fm.group(2).lower()] = {
                "name": fm.group(1),
                "type": (fm.group(3) or "").strip(),
            }
    return result


def write_header(mapping: dict, dump: dict, out_path: str):
    lines = [
        "#pragma once",
        "#include <cstdint>",
        "",
        "// Auto-generated from mapping.json, validated against rust.h.",
        f"// Generated: {datetime.now(timezone.utc).isoformat()}",
        "",
        "namespace Offsets {",
    ]

    ok, drift, missing = 0, [], []

    for cls, fields in sorted(mapping["offsets"].items()):
        lines.append(f"    // ── {cls} ──")
        ns = dump.get(cls, {})
        if not ns:
            lines.append(f"    // MISSING CLASS: {cls}")
            for f in fields:
                missing.append(f"{cls}::{f}")
            lines.append("")
            continue

        for name, spec in fields.items():
            off = spec["offset"].lower()
            expected_type = spec.get("type", "")

            found = ns.get(off)
            if not found:
                name_match = next((v for k, v in ns.items()
                                   if v["name"] == name), None)
                if name_match:
                    lines.append(
                        f"    // DRIFT: {cls}::{name} expected at {off}, "
                        f"dump has it elsewhere"
                    )
                    drift.append(f"{cls}::{name} {off}")
                    continue
                lines.append(f"    // MISSING: {cls}::{name} @ {off}")
                missing.append(f"{cls}::{name}")
                continue

            if expected_type and expected_type.lower() not in found["type"].lower():
                lines.append(
                    f"    // TYPE DRIFT: {cls}::{name} @ {off} "
                    f"dump={found['type']} expected={expected_type}"
                )
                drift.append(f"{cls}::{name} type changed")
                continue

            const_name = f"{cls}_{name.lstrip('_')}"
            lines.append(
                f"    constexpr uintptr_t {const_name} = {off};  "
                f"// {found['type']}"
            )
            ok += 1

        lines.append("")

    if "type_info" in mapping:
        lines.append("    // ── TypeInfo ──")
        for name, addr in mapping["type_info"].items():
            const_name = f"{name}_TypeInfo"
            lines.append(f"    constexpr uintptr_t {const_name} = {addr};")
        lines.append("")

    lines.append("}")
    Path(out_path).write_text("\n".join(lines), encoding="utf-8")
    return ok, drift, missing


def main():
    if len(sys.argv) != 4:
        print(f"usage: {sys.argv[0]} <rust.h> <mapping.json> <offsets.h>")
        sys.exit(1)

    rust_h, mapping_path, out_path = sys.argv[1:4]
    mapping = json.loads(Path(mapping_path).read_text())
    dump = parse_rust_h(rust_h)

    print(f"[parse] dump has {len(dump)} namespaces")
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
