#!/usr/bin/env python3
"""
Validate that every field defined in targets.json was found in the dump
and written to offsets.h. Fails with a detailed report if anything is missing.

Usage:
    python3 validate_offsets.py <dump.cs> <targets.json> <offsets.h>
"""

import json
import re
import sys
from pathlib import Path


def load_targets(path: str) -> dict:
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)


def parse_dump_classes(dump_path: str) -> dict:
    """
    Return { "ClassName": set_of_field_names } for every class in the dump.
    We don't need offsets here — just presence.
    """
    if not Path(dump_path).exists():
        raise FileNotFoundError(f"dump.cs not found: {dump_path}")

    with open(dump_path, "r", encoding="utf-8", errors="ignore") as f:
        content = f.read()

    classes = {}

    class_re = re.compile(
        r"^\s*(?:public\s+)?(?:sealed\s+)?(?:abstract\s+)?"
        r"(?:class|struct)\s+(\w+)",
        re.MULTILINE,
    )
    field_re = re.compile(
        r"^\s*(?:public|private|protected|internal)\s+"
        r"(?:static\s+)?(?:readonly\s+)?"
        r"[\w<>\[\]\.\,]+\s+([\w<>]+)\s*;",
        re.MULTILINE,
    )

    lines = content.splitlines()
    current = None

    for line in lines:
        cm = class_re.search(line)
        if cm:
            current = cm.group(1)
            classes.setdefault(current, set())
            continue

        if current:
            fm = field_re.search(line)
            if fm:
                classes[current].add(fm.group(1))

    return classes


def parse_header_offsets(header_path: str) -> dict:
    """
    Parse offsets.h and return { "ClassName_fieldname": offset } for every
    defined offset. Missing entries are commented out and won't appear.
    """
    if not Path(header_path).exists():
        return {}

    with open(header_path, "r", encoding="utf-8") as f:
        content = f.read()

    pattern = re.compile(
        r"constexpr\s+uintptr_t\s+"
        r"(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;"
    )

    result = {}
    for m in pattern.finditer(content):
        result[m.group(1)] = m.group(2)
    return result


def main():
    if len(sys.argv) != 4:
        print(f"usage: {sys.argv[0]} <dump.cs> <targets.json> <offsets.h>")
        sys.exit(1)

    dump_path = sys.argv[1]
    targets_path = sys.argv[2]
    header_path = sys.argv[3]

    targets = load_targets(targets_path)
    dump_classes = parse_dump_classes(dump_path)
    header_offsets = parse_header_offsets(header_path)

    missing = []
    found = []
    warnings = []

    for class_name, class_def in targets["classes"].items():
        if class_name not in dump_classes:
            missing.append({
                "class": class_name,
                "field": "(entire class)",
                "reason": "class not found in dump",
            })
            continue

        for field in class_def["fields"]:
            const_name = f"{class_name}_{field.lstrip('_')}"

            if field not in dump_classes[class_name]:
                missing.append({
                    "class": class_name,
                    "field": field,
                    "reason": "field not found in dump",
                })
                continue

            if const_name not in header_offsets:
                missing.append({
                    "class": class_name,
                    "field": field,
                    "reason": "field found in dump but not written to header",
                })
                continue

            found.append({
                "class": class_name,
                "field": field,
                "offset": header_offsets[const_name],
            })

    # Sanity checks on written offsets
    for const_name, offset in header_offsets.items():
        val = int(offset, 16)
        if val == 0:
            warnings.append(f"{const_name} = 0x0 — suspicious, may be placeholder")
        if val > 0x100000:
            warnings.append(f"{const_name} = {offset} — unusually large for a struct offset")

    # Report
    print(f"=== Validation Report ===")
    print(f"Targets defined:   {sum(len(v['fields']) for v in targets['classes'].values())}")
    print(f"Offsets found:     {len(found)}")
    print(f"Missing:           {len(missing)}")
    print(f"Warnings:          {len(warnings)}")
    print()

    if found:
        print("--- Found ---")
        for f in found:
            print(f"  ✅ {f['class']}.{f['field']} = {f['offset']}")
        print()

    if warnings:
        print("--- Warnings ---")
        for w in warnings:
            print(f"  ⚠️  {w}")
        print()

    if missing:
        print("--- MISSING ---")
        for m in missing:
            print(f"  ❌ {m['class']}.{m['field']} — {m['reason']}")
        print()

        # Write a machine-readable report for the notifier
        report = {
            "missing": missing,
            "found_count": len(found),
            "missing_count": len(missing),
            "warnings": warnings,
        }
        Path("/tmp/validation_report.json").write_text(json.dumps(report, indent=2))

        sys.exit(1)

    print("✅ All targets validated.")
    sys.exit(0)


if __name__ == "__main__":
    main()