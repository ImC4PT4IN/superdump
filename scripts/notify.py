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
import time
import urllib.error
import urllib.request

# Cloudflare in front of Discord rejects Python's default urllib UA with HTTP 403.
USER_AGENT = "RustOffsetsBot/1.0 (+https://github.com/)"

MAX_REPORT_CHARS = 1400
MAX_RETRIES = 3
RETRY_BACKOFF = 2.0


def read_report(path: str) -> str:
    if not path or not os.path.exists(path):
        return ""
    with open(path, "r", encoding="utf-8", errors="ignore") as f:
        content = f.read()
    if len(content) > MAX_REPORT_CHARS:
        content = content[:MAX_REPORT_CHARS] + "\n... (truncated)"
    return content


def _post_json(url: str, payload: dict, timeout: int = 10) -> bool:
    body = json.dumps(payload).encode("utf-8")

    for attempt in range(1, MAX_RETRIES + 1):
        req = urllib.request.Request(
            url,
            data=body,
            headers={
                "Content-Type": "application/json",
                "User-Agent": USER_AGENT,
                "Accept": "application/json",
            },
            method="POST",
        )
        try:
            with urllib.request.urlopen(req, timeout=timeout) as resp:
                if resp.status in (200, 201, 202, 204):
                    return True
                print(f"[notify] unexpected status {resp.status}", file=sys.stderr)
                return False

        except urllib.error.HTTPError as e:
            if e.code == 429:
                retry_after = e.headers.get("Retry-After")
                try:
                    wait = float(retry_after) if retry_after else RETRY_BACKOFF * attempt
                except ValueError:
                    wait = RETRY_BACKOFF * attempt
                print(f"[notify] 429 rate limited, retrying in {wait}s", file=sys.stderr)
                if attempt < MAX_RETRIES:
                    time.sleep(wait)
                    continue
                return False

            if 500 <= e.code < 600 and attempt < MAX_RETRIES:
                wait = RETRY_BACKOFF * attempt
                print(f"[notify] {e.code} server error, retrying in {wait}s", file=sys.stderr)
                time.sleep(wait)
                continue

            print(f"[notify] HTTP {e.code}: {e.reason}", file=sys.stderr)
            try:
                print(f"[notify] body: {e.read().decode('utf-8', 'ignore')[:300]}", file=sys.stderr)
            except Exception:
                pass
            return False

        except urllib.error.URLError as e:
            if attempt < MAX_RETRIES:
                wait = RETRY_BACKOFF * attempt
                print(f"[notify] network error ({e.reason}), retrying in {wait}s", file=sys.stderr)
                time.sleep(wait)
                continue
            print(f"[notify] network error: {e.reason}", file=sys.stderr)
            return False

        except Exception as e:
            print(f"[notify] unexpected error: {e}", file=sys.stderr)
            return False

    return False


def send_discord(webhook_url: str, title: str, message: str, report: str) -> bool:
    content = f"**{title}**\n{message}"
    if report:
        content += f"\n```\n{report}\n```"
    return _post_json(webhook_url, {"content": content})


def send_generic(url: str, title: str, message: str, report: str) -> bool:
    return _post_json(url, {"title": title, "message": message, "report": report})


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--title", required=True)
    parser.add_argument("--message", required=True)
    parser.add_argument("--report", default="")
    parser.add_argument("--strict", action="store_true")
    args = parser.parse_args()

    report = read_report(args.report)

    discord = os.environ.get("DISCORD_WEBHOOK", "").strip()
    generic = os.environ.get("GENERIC_WEBHOOK", "").strip()

    if not discord and not generic:
        print(f"[notify] {args.title}")
        print(f"[notify] {args.message}")
        if report:
            print(report)
        return 0

    results = {}
    if discord:
        results["discord"] = send_discord(discord, args.title, args.message, report)
    if generic:
        results["generic"] = send_generic(generic, args.title, args.message, report)

    for name, ok in results.items():
        print(f"[notify] {name}: {'ok' if ok else 'failed'}", file=sys.stderr)

    if args.strict and not all(results.values()):
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
