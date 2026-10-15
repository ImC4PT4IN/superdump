#!/usr/bin/env python3
"""Report whether every target field is present in the generated header.

Usage: validate_offsets.py <rust.h> <targets.json> <offsets.h>
"""
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from parse_rust_data import parse_rust_h


def main():
    if len(sys.argv) != 4:
        print(f"usage: {sys.argv[0]} <rust.h> <targets.json> <offsets.h>")
        sys.exit(1)

    rust_h, targets_path, header_path = sys.argv[1:4]
    targets = json.loads(Path(targets_path).read_text())
    parsed = parse_rust_h(rust_h)

    ok, miss = [], []
    for cls, fields in targets["fields"].items():
        ns = parsed.get(cls, {})
        for f in fields:
            if f in ns:
                ok.append(f"{cls}::{f} = {ns[f]}")
            else:
                miss.append(f"{cls}::{f}")

    print("=== Validation Report ===")
    print(f"OK:      {len(ok)}")
    print(f"Missing: {len(miss)}")
    print()
    for o in ok:
        print(f"  OK  {o}")
    for m in miss:
        print(f"  MISSING  {m}")


if __name__ == "__main__":
    main()
