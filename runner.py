#!/usr/bin/env python3
"""
C++ String Exercises Runner (Rustlings-style)
Usage: python3 runner.py [exercise_path]
"""

import os
import sys
import subprocess
import glob
from pathlib import Path

EXERCISES_DIR = "exercises"
NOT_DONE_MARKER = "// I AM NOT DONE"


def find_exercises():
    """Find all .cpp files in exercises directory, sorted."""
    exercises = []
    for root, dirs, files in os.walk(EXERCISES_DIR):
        for f in sorted(files):
            if f.endswith(".cpp"):
                rel_path = os.path.relpath(os.path.join(root, f), EXERCISES_DIR)
                exercises.append(rel_path)
    return exercises


def is_not_done(filepath):
    """Check if exercise is marked as not done."""
    try:
        with open(filepath, "r", encoding="utf-8") as f:
            content = f.read()
            return NOT_DONE_MARKER in content
    except:
        return False


def compile_and_run(filepath):
    """Compile and run an exercise. Returns (success, message)."""
    import random
    import string

    # Create unique temp binary name
    temp_bin = f"temp_bin_{random.randint(10000, 99999)}.exe"

    try:
        # Compile
        compile_cmd = [
            "g++",
            "-std=c++17",
            "-Wall",
            "-Wextra",
            "-o",
            temp_bin,
            filepath,
        ]
        comp_result = subprocess.run(
            compile_cmd, capture_output=True, text=True, timeout=30
        )

        if comp_result.returncode != 0:
            return False, f"Compilation failed:\n{comp_result.stderr}"

        # Run
        run_result = subprocess.run(
            [temp_bin], capture_output=True, text=True, timeout=10
        )

        if run_result.returncode != 0:
            return (
                False,
                f"Runtime failed (exit code {run_result.returncode}):\n{run_result.stderr}\n{run_result.stdout}",
            )

        return True, run_result.stdout if run_result.stdout else "OK"

    except subprocess.TimeoutExpired:
        return False, "Timeout during compilation or execution"
    except FileNotFoundError:
        return False, "g++ not found. Make sure MinGW/compiler is installed."
    finally:
        # Clean up temp binary
        if os.path.exists(temp_bin):
            try:
                os.remove(temp_bin)
            except:
                pass


def run_specific(exercise_path):
    """Run a specific exercise."""
    full_path = (
        os.path.join(EXERCISES_DIR, exercise_path)
        if not os.path.exists(exercise_path)
        else exercise_path
    )

    if not os.path.exists(full_path):
        print(f"Error: Exercise not found: {full_path}")
        return False

    if is_not_done(full_path):
        print(f"⏳ {exercise_path}: NOT DONE (marker found)")
        return False

    print(f"Testing {exercise_path}...", end=" ")
    success, msg = compile_and_run(full_path)

    if success:
        print(f"✓ PASS")
        if msg and msg != "OK":
            print(f"  Output: {msg.strip()}")
        return True
    else:
        print(f"✗ FAIL")
        for line in msg.strip().split("\n")[:10]:
            print(f"  {line}")
        return False


def run_all():
    """Run all exercises in order."""
    exercises = find_exercises()

    if not exercises:
        print("No exercises found!")
        return

    print(f"Found {len(exercises)} exercises\n")

    pending = []
    completed = []
    failed = []

    for i, ex in enumerate(exercises, 1):
        full_path = os.path.join(EXERCISES_DIR, ex)

        if is_not_done(full_path):
            print(f"⏳ [{i}/{len(exercises)}] {ex} - NOT DONE")
            pending.append(ex)
            continue

        print(f"Testing [{i}/{len(exercises)}] {ex}...", end=" ")
        success, msg = compile_and_run(full_path)

        if success:
            print(f"✓ PASS")
            completed.append(ex)
        else:
            print(f"✗ FAIL")
            failed.append((ex, msg))
            # Show first few lines of error
            for line in msg.strip().split("\n")[:5]:
                print(f"    {line}")

    print("=" * 50)
    print(
        f"Results: {len(completed)} passed, {len(failed)} failed, {len(pending)} pending"
    )

    if failed:
        print("\nFailed exercises:")
        for ex, msg in failed:
            print(f"  - {ex}")
        return False

    if pending:
        print("\nPending exercises:")
        for ex in pending:
            print(f"  - {ex}")

    if not pending and not failed:
        print("\n🎉 All exercises completed!")

    return len(failed) == 0


def main():
    if len(sys.argv) > 1:
        # Run specific exercise
        success = run_specific(sys.argv[1])
        sys.exit(0 if success else 1)
    else:
        # Run all
        success = run_all()
        sys.exit(0 if success else 1)


if __name__ == "__main__":
    main()
