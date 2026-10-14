#!/usr/bin/env python3
"""
Send a notification via Discord webhook or generic webhook.
Reads DISCORD_WEBHOOK env var (set in workflow).

Usage:
    python3 notify.py --title "..." --message "..." [--report file]
"""

import argparse
import json
import os
import sys
import urllib.request


def read_report(path: str) -> str:
    if not path or not os.path.exists(path):
        return ""
    with open(path, "r", encoding="utf-8", errors="ignore") as f:
        content = f.read()
    # Truncate to avoid Discord's 2000-char limit
    if len(content) > 1500:
        content = content[:1500] + "\n... (truncated)"
    return content


def send_discord(webhook_url: str, title: str, message: str, report: str):
    content = f"**{title}**\n{message}"
    if report:
        content += f"\n```\n{report}\n```"

    payload = json.dumps({"content": content}).encode("utf-8")

    req = urllib.request.Request(
        webhook_url,
        data=payload,
        headers={"Content-Type": "application/json"},
        method="POST",
    )

    try:
        with urllib.request.urlopen(req, timeout=10) as resp:
            if resp.status not in (200, 204):
                print(f"[notify] Discord returned {resp.status}", file=sys.stderr)
                return False
        return True
    except Exception as e:
        print(f"[notify] Failed to send Discord notification: {e}", file=sys.stderr)
        return False


def send_generic(url: str, title: str, message: str, report: str):
    payload = json.dumps({
        "title": title,
        "message": message,
        "report": report,
    }).encode("utf-8")

    req = urllib.request.Request(
        url,
        data=payload,
        headers={"Content-Type": "application/json"},
        method="POST",
    )

    try:
        with urllib.request.urlopen(req, timeout=10) as resp:
            return resp.status in (200, 201, 202, 204)
    except Exception as e:
        print(f"[notify] Generic webhook failed: {e}", file=sys.stderr)
        return False


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--title", required=True)
    parser.add_argument("--message", required=True)
    parser.add_argument("--report", default="")
    args = parser.parse_args()

    report = read_report(args.report)

    discord = os.environ.get("DISCORD_WEBHOOK", "")
    generic = os.environ.get("GENERIC_WEBHOOK", "")

    ok = False
    if discord:
        ok = send_discord(discord, args.title, args.message, report) or ok
    if generic:
        ok = send_generic(generic, args.title, args.message, report) or ok

    if not discord and not generic:
        # No webhook configured — just print. Workflow still succeeds.
        print(f"[notify] {args.title}")
        print(f"[notify] {args.message}")
        if report:
            print(report)
        return 0

    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())