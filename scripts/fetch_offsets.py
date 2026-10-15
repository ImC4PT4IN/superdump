#!/usr/bin/env python3
"""
Fetch the current Rust offsets from rustoffsets.com and emit offsets.h.

Usage: fetch_offsets.py [output_path]
"""

import json
import re
import sys
import urllib.request
from datetime import datetime, timezone
from pathlib import Path

URL = "https://www.rustoffsets.com/api/v1/offsets.json"
USER_AGENT = "RustOffsetsFetcher/1.0 (+https://github.com/)"


def fetch(url: str) -> dict:
    req = urllib.request.Request(url, headers={"User-Agent": USER_AGENT})
    with urllib.request.urlopen(req, timeout=30) as r:
        return json.loads(r.read().decode("utf-8"))


def sanitize(name: str) -> str:
    """Convert namespace / field names to valid C++ identifiers."""
    name = name.replace("::", "_")
    name = re.sub(r"[^A-Za-z0-9_]", "_", name)
    if name and name[0].isdigit():
        name = "_" + name
    return name or "_unnamed"


def emit(data: dict) -> tuple[str, int]:
    lines = [
        "#pragma once",
        "#include <cstdint>",
        "",
        "// Auto-generated from rustoffsets.com",
        f"// build_id:  {data.get('build_id', 'unknown')}",
        f"// timestamp: {data.get('timestamp', 'unknown')}",
        f"// generated: {datetime.now(timezone.utc).isoformat()}",
        "",
        "namespace Offsets {",
        "",
    ]

    count = 0

    # main namespace block
    for ns_name, ns_data in data.get("namespaces", {}).items():
        cpp_ns = sanitize(ns_name)
        lines.append(f"    // ── {ns_name} ──")
        for field_name, field_data in ns_data.get("fields", {}).items():
            if not field_data.get("resolved", True):
                continue
            off = field_data.get("offset", "0x0")
            comment = (field_data.get("comment") or "").strip()
            cpp_field = sanitize(field_name)
            const_name = f"{cpp_ns}_{cpp_field}"
            suffix = f"  // {comment}" if comment else ""
            lines.append(f"    constexpr uintptr_t {const_name} = {off};{suffix}")
            count += 1
        lines.append("")

    # decryption RVAs
    dec = data.get("decryptions", {})
    rva_fps = dec.get("rva_fingerprints", {})
    if rva_fps:
        lines.append("    // ── Decryption RVAs ──")
        for name, rva in rva_fps.items():
            lines.append(f"    constexpr uintptr_t Decryption_{sanitize(name)} = {rva};")
            count += 1
        lines.append("")

    lines.append("}")
    return "\n".join(lines), count


def main():
    out_path = sys.argv[1] if len(sys.argv) > 1 else "offsets.h"
    data = fetch(URL)
    content, count = emit(data)
    Path(out_path).write_text(content, encoding="utf-8")
    print(f"[fetch] build {data.get('build_id')}")
    print(f"[fetch] wrote {count} offsets to {out_path}")


if __name__ == "__main__":
    main()
