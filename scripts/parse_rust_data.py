#!/usr/bin/env python3
"""
Parse Rust-Data's rust.h and emit our offsets.h.

rust.h format:
    namespace BasePlayer {
        inline constexpr ::std::ptrdiff_t playerModel = 0x838; // PlayerModel
    }

Usage: parse_rust_data.py <rust.h> <targets.json> <offsets.h>
"""

import json
import re
import sys
from datetime import datetime, timezone
from pathlib import Path


def parse_rust_h(path: str) -> dict:
    """
    Returns { "NamespaceName": { "fieldname": "0xOFFSET" } }
    """
    src = Path(path).read_text(encoding="utf-8", errors="ignore")
    result = {}

    # track current namespace by scanning lines
    ns_re = re.compile(r"^\s*namespace\s+(\w+)")
    # field line
    field_re = re.compile(
        r"^\s*inline\s+constexpr\s+::std::ptrdiff_t\s+(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;"
    )

    current_ns = None
    for line in src.splitlines():
        nm = ns_re.match(line)
        if nm:
            current_ns = nm.group(1)
            result.setdefault(current_ns, {})
            continue
        fm = field_re.match(line)
        if fm and current_ns:
            result[current_ns][fm.group(1)] = fm.group(2).lower()

    return result


def write_header(parsed: dict, targets: dict, out_path: str):
    lines = [
        "#pragma once",
        "#include <cstdint>",
        "",
        "// Auto-generated from Rust-Data rust.h.",
        "// Do not edit manually.",
        "",
        f"// Generated: {datetime.now(timezone.utc).isoformat()}",
        "",
        "namespace Offsets {",
    ]

    written = 0
    missing = []

    for class_name, fields in targets["fields"].items():
        lines.append(f"    // ── {class_name} ──")
        ns = parsed.get(class_name, {})
        if not ns:
            lines.append(f"    // MISSING CLASS: {class_name}")
            for f in fields:
                missing.append(f"{class_name}::{f}")
            lines.append("")
            continue

        for field in fields:
            if field in ns:
                const = f"{class_name}_{field.lstrip('_')}"
                lines.append(f"    constexpr uintptr_t {const} = {ns[field]};")
                written += 1
            else:
                lines.append(f"    // MISSING: {class_name}::{field}")
                missing.append(f"{class_name}::{field}")

        lines.append("")

    lines.append("}")
    Path(out_path).write_text("\n".join(lines), encoding="utf-8")
    return written, missing


def main():
    if len(sys.argv) != 4:
        print(f"usage: {sys.argv[0]} <rust.h> <targets.json> <offsets.h>")
        sys.exit(1)

    rust_h, targets_path, out_path = sys.argv[1:4]
    targets = json.loads(Path(targets_path).read_text())
    parsed = parse_rust_h(rust_h)

    print(f"[parse] rust.h has {len(parsed)} namespaces")
    for ns in parsed:
        print(f"[parse]   {ns}: {len(parsed[ns])} fields")

    written, missing = write_header(parsed, targets, out_path)
    print(f"[parse] wrote {written} offsets, {len(missing)} missing")
    if missing:
        print("[parse] missing fields:")
        for m in missing:
            print(f"[parse]   {m}")


if __name__ == "__main__":
    main()
