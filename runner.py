#!/usr/bin/env python3
"""
C++ String Exercises Runner (Rustlings-style)
Usage:
    python3 runner.py              # Run all exercises
    python3 runner.py <exercise>   # Run specific exercise
    python3 runner.py --watch      # Watch mode - auto-run on file changes

Features:
    - Cross-platform (Windows/Linux/macOS)
    - Auto-detects compiler (clang > gcc > msvc)
    - File watching for auto-validation
"""

import os
import sys
import subprocess
import glob
import platform
import random
import string
import time
import shutil
from pathlib import Path
from typing import Optional, Tuple, List

# Try to import watchdog for file watching
# Using dynamic import to handle optional dependency gracefully
try:
    from watchdog.observers import Observer  # type: ignore
    from watchdog.events import FileSystemEventHandler  # type: ignore

    WATCHDOG_AVAILABLE = True
except ImportError:
    WATCHDOG_AVAILABLE = False
    Observer = None  # type: ignore
    FileSystemEventHandler = None  # type: ignore

EXERCISES_DIR = "exercises"
NOT_DONE_MARKER = "// I AM NOT DONE"


def get_platform() -> str:
    """Get current platform."""
    return platform.system().lower()


def is_windows() -> bool:
    return get_platform() == "windows"


def is_linux() -> bool:
    return get_platform() == "linux"


def is_macos() -> bool:
    return get_platform() == "darwin"


def detect_compiler() -> Tuple[Optional[str], str]:
    """
    Auto-detect available C++ compiler.
    Priority: clang > gcc > msvc

    Returns: (compiler_path, compiler_name)
    """
    compilers = [
        # Priority 1: Clang (best for cross-platform)
        ("clang++", "clang++"),
        ("clang++-18", "clang++-18"),
        ("clang++-17", "clang++-17"),
        ("clang++-16", "clang++-16"),
        ("clang++-15", "clang++-15"),
        ("clang++-14", "clang++-14"),
        ("clang++-13", "clang++-13"),
        ("clang++-12", "clang++-12"),
        # Priority 2: GCC
        ("g++", "g++"),
        ("g++-13", "g++-13"),
        ("g++-12", "g++-12"),
        ("g++-11", "g++-11"),
        ("g++-10", "g++-10"),
        ("g++-9", "g++-9"),
        ("g++-8", "g++-8"),
    ]

    # On Windows, prefer g++ over clang if clang targets MSVC (common issue)
    if is_windows():
        # Reorder to prefer g++ on Windows
        compilers = [
            ("g++", "g++"),
            ("g++-13", "g++-13"),
            ("g++-12", "g++-12"),
            ("g++-11", "g++-11"),
            ("clang++", "clang++"),
            ("clang++-18", "clang++-18"),
            ("clang++-17", "clang++-17"),
            ("clang++-16", "clang++-16"),
        ]

    for compiler, name in compilers:
        # Check if compiler exists and is executable
        if shutil.which(compiler):
            return compiler, name

    return None, "none"


def get_temp_binary_name() -> str:
    """Get platform-appropriate temp binary name."""
    rand_suffix = random.randint(10000, 99999)
    if is_windows():
        return f"temp_bin_{rand_suffix}.exe"
    else:
        return f"temp_bin_{rand_suffix}"


def get_compile_flags(compiler_name: str) -> List[str]:
    """Get compiler-specific flags."""
    base_flags = ["-std=c++17", "-Wall", "-Wextra", "-Werror"]

    if compiler_name == "msvc":
        return ["/EHsc", "/W4", "/std:c++17"]
    else:
        return base_flags + ["-pedantic"]


def find_exercises() -> List[str]:
    """Find all .cpp files in exercises directory, sorted."""
    exercises = []
    for root, dirs, files in os.walk(EXERCISES_DIR):
        # Skip hidden directories and non-exercise dirs
        dirs[:] = [d for d in dirs if not d.startswith(".")]
        for f in sorted(files):
            if f.endswith(".cpp"):
                rel_path = os.path.relpath(os.path.join(root, f), EXERCISES_DIR)
                exercises.append(rel_path)
    return exercises


def is_not_done(filepath: str) -> bool:
    """Check if exercise is marked as not done."""
    try:
        with open(filepath, "r", encoding="utf-8") as f:
            content = f.read()
            return NOT_DONE_MARKER in content
    except:
        return False


def compile_and_run(
    filepath: str, compiler: Optional[str] = None, compiler_name: str = "g++"
) -> Tuple[bool, str]:
    """Compile and run an exercise. Returns (success, message)."""
    if compiler is None:
        compiler, compiler_name = detect_compiler()
        if compiler is None:
            return (
                False,
                "No C++ compiler found. Please install clang++, g++, or ensure MSVC is in PATH.",
            )

    temp_bin = get_temp_binary_name()
    compile_flags = get_compile_flags(compiler_name)

    try:
        # Build compile command based on compiler
        if compiler_name == "msvc":
            compile_cmd = [compiler] + compile_flags + ["/Fe:" + temp_bin, filepath]  # type: ignore
        else:
            compile_cmd = [compiler] + compile_flags + ["-o", temp_bin, filepath]  # type: ignore

        comp_result = subprocess.run(
            compile_cmd,
            capture_output=True,
            text=True,
            timeout=60,
            shell=is_windows(),  # Use shell on Windows for PATH resolution
        )

        if comp_result.returncode != 0:
            # Try to provide helpful error message
            stderr = comp_result.stderr
            stdout = comp_result.stdout
            error_output = stderr if stderr else stdout

            # Clean up MSVC noise
            if compiler_name == "msvc":
                lines = error_output.split("\n")
                error_output = "\n".join([l for l in lines if l.strip()])

            return False, f"Compilation failed ({compiler_name}):\n{error_output}"

        # Run the compiled binary
        run_cmd = [temp_bin] if not is_windows() else temp_bin
        run_result = subprocess.run(
            run_cmd, capture_output=True, text=True, timeout=10, shell=is_windows()
        )

        if run_result.returncode != 0:
            return (
                False,
                f"Runtime failed (exit code {run_result.returncode}):\n"
                f"STDERR: {run_result.stderr}\n"
                f"STDOUT: {run_result.stdout}",
            )

        output = run_result.stdout.strip() if run_result.stdout else "OK"
        return True, output

    except subprocess.TimeoutExpired:
        return False, "Timeout during compilation or execution"
    except FileNotFoundError:
        return (
            False,
            f"{compiler} not found. Make sure the compiler is installed and in PATH.",
        )
    except Exception as e:
        return False, f"Error: {str(e)}"
    finally:
        # Clean up temp binary
        if os.path.exists(temp_bin):
            try:
                os.remove(temp_bin)
            except:
                pass


def run_specific(exercise_path: str, verbose: bool = False) -> bool:
    """Run a specific exercise."""
    full_path = (
        os.path.join(EXERCISES_DIR, exercise_path)
        if not os.path.exists(exercise_path)
        else exercise_path
    )

    if not os.path.exists(full_path):
        print(f"Error: Exercise not found: {full_path}")
        return False

    # Detect compiler
    compiler, compiler_name = detect_compiler()
    if verbose:
        print(f"Using compiler: {compiler} ({compiler_name})")

    if is_not_done(full_path):
        print(f"  ⏳ {exercise_path}: NOT DONE (marker found)")
        return False

    print(f"Testing {exercise_path}...", end=" ", flush=True)
    success, msg = compile_and_run(
        filepath=full_path, compiler=compiler, compiler_name=compiler_name
    )

    if success:
        print(f"✓ PASS")
        if msg and msg != "OK":
            print(f"  Output: {msg}")
        return True
    else:
        print(f"✗ FAIL")
        # Show error message (limit lines)
        for line in msg.strip().split("\n")[:15]:
            print(f"  {line}")
        return False


def run_all(verbose: bool = False) -> bool:
    """Run all exercises in order."""
    # Detect compiler first
    compiler, compiler_name = detect_compiler()
    if compiler is None:
        print("ERROR: No C++ compiler found!")
        print("Please install one of: clang++, g++ (Linux/macOS), or MSVC (Windows)")
        return False

    print(f"Using compiler: {compiler} ({compiler_name})")
    print(f"Platform: {get_platform()}")
    print("-" * 50)

    exercises = find_exercises()

    if not exercises:
        print("No exercises found!")
        return False

    print(f"Found {len(exercises)} exercises\n")

    pending = []
    completed = []
    failed = []

    for i, ex in enumerate(exercises, 1):
        full_path = os.path.join(EXERCISES_DIR, ex)

        if is_not_done(full_path):
            print(f"  ⏳ [{i}/{len(exercises)}] {ex} - NOT DONE")
            pending.append(ex)
            continue

        print(f"Testing [{i}/{len(exercises)}] {ex}...", end=" ", flush=True)
        success, msg = compile_and_run(
            filepath=full_path, compiler=compiler, compiler_name=compiler_name
        )

        if success:
            print(f"✓ PASS")
            completed.append(ex)
        else:
            print(f"✗ FAIL")
            failed.append((ex, msg))
            # Show first few lines of error
            for line in msg.strip().split("\n")[:3]:
                print(f"    {line}")

    print("=" * 50)
    print(
        f"Results: {len(completed)} passed, {len(failed)} failed, {len(pending)} pending"
    )

    if failed:
        print("\nFailed exercises:")
        for ex, msg in failed:
            print(f"  - {ex}")

    if pending:
        print("\nPending exercises:")
        for ex in pending:
            print(f"  - {ex}")

    if not pending and not failed:
        print("\n  All exercises completed!")

    return len(failed) == 0


# Base handler - using object as base for both cases
class ExerciseFileHandler:
    """Handler for file system events in watch mode."""

    def __init__(self, runner_script: str, debounce_seconds: float = 0.5):
        super().__init__()
        self.runner_script = runner_script
        self.debounce_seconds = debounce_seconds
        self.last_run_time = {}
        self.exercise_path = None

        # Determine which exercise to watch
        if len(sys.argv) > 2:
            self.exercise_path = sys.argv[2]
        elif len(sys.argv) > 1 and sys.argv[1] != "--watch":
            self.exercise_path = sys.argv[1]

    def on_modified(self, event):
        """Handle file modification events."""
        if event.is_directory:
            return

        # Only process .cpp files in exercises directory
        if not event.src_path.endswith(".cpp"):
            return

        if EXERCISES_DIR not in event.src_path:
            return

        # Get relative path
        rel_path = os.path.relpath(event.src_path, EXERCISES_DIR)

        # If watching specific exercise, only process that one
        if self.exercise_path:
            expected = self.exercise_path.replace("\\", "/")
            actual = rel_path.replace("\\", "/")
            if expected != actual:
                return

        # Debounce: don't run too frequently
        current_time = time.time()
        last_time = self.last_run_time.get(rel_path, 0)

        if current_time - last_time < self.debounce_seconds:
            return

        self.last_run_time[rel_path] = current_time

        # Clear screen and run the exercise
        self.run_exercise(rel_path)

    def on_created(self, event):
        """Handle file creation events."""
        self.on_modified(event)

    def run_exercise(self, rel_path: str):
        """Run a specific exercise with nice output."""
        # Clear screen (cross-platform)
        os.system("cls" if is_windows() else "clear")

        print("\n" + "=" * 50)
        print(f"FILE CHANGED: {rel_path}")
        print("=" * 50 + "\n")

        # Run the exercise
        success = run_specific(rel_path, verbose=True)


def run_watch_mode():
    """Run in watch mode - auto-compile on file changes."""
    if not WATCHDOG_AVAILABLE:
        print("ERROR: 'watchdog' library required for watch mode.")
        print("Install it with: pip install watchdog")
        print("\nAlternatively, you can:")
        print("  - Run all: python3 runner.py")
        print("  - Run specific: python3 runner.py <exercise>")
        sys.exit(1)

    # Detect which exercise to watch
    exercise_to_watch = None
    if len(sys.argv) > 2:
        exercise_to_watch = sys.argv[2]
    elif len(sys.argv) > 1 and sys.argv[1] != "--watch":
        exercise_to_watch = sys.argv[1]

    # Show info
    compiler, compiler_name = detect_compiler()
    if compiler is None:
        print("ERROR: No C++ compiler found!")
        sys.exit(1)

    print(f"Compiler: {compiler} ({compiler_name})")
    print(f"Platform: {get_platform()}")
    if exercise_to_watch:
        print(f"Watching: {exercise_to_watch}")
    else:
        print("Watching: all exercises")
    print("\nPress Ctrl+C to stop\n")

    # Set up file watcher
    event_handler = ExerciseFileHandler(sys.argv[0])
    observer = Observer()  # type: ignore

    watch_path = os.path.abspath(EXERCISES_DIR)
    observer.schedule(event_handler, watch_path, recursive=True)  # type: ignore
    observer.start()  # type: ignore

    # Run initial check
    print("\n--- Initial Check ---")
    if exercise_to_watch:
        run_specific(exercise_to_watch, verbose=True)
    else:
        run_all(verbose=True)

    print("\n--- Watching for changes ---")
    print("Modify a .cpp file to trigger recompilation...")

    try:
        while True:
            time.sleep(0.5)
    except KeyboardInterrupt:
        print("\n\nStopping watch mode...")
        observer.stop()  # type: ignore

    observer.join()  # type: ignore


def main():
    # Parse arguments
    if len(sys.argv) > 1:
        if sys.argv[1] == "--help" or sys.argv[1] == "-h":
            print(__doc__)
            print("\nExamples:")
            print("  python3 runner.py                  # Run all exercises")
            print("  python3 runner.py 01_init.cpp      # Run specific exercise")
            print(
                "  python3 runner.py --watch           # Watch mode (auto-run on changes)"
            )
            print("  python3 runner.py --watch 01_init  # Watch specific exercise")
            print("  python3 runner.py --compiler       # Show detected compiler")
            return

        elif sys.argv[1] == "--watch" or sys.argv[1] == "-w":
            run_watch_mode()
            return

        elif sys.argv[1] == "--compiler" or sys.argv[1] == "-c":
            compiler, name = detect_compiler()
            print(f"Detected compiler: {compiler} ({name})")
            return

        elif sys.argv[1] == "--list":
            exercises = find_exercises()
            print(f"Found {len(exercises)} exercises:")
            for ex in exercises:
                status = (
                    "pending"
                    if is_not_done(os.path.join(EXERCISES_DIR, ex))
                    else "ready"
                )
                print(f"  [{status}] {ex}")
            return

        else:
            # Run specific exercise
            success = run_specific(sys.argv[1], verbose=True)
            sys.exit(0 if success else 1)
    else:
        # Run all
        success = run_all(verbose=True)
        sys.exit(0 if success else 1)


if __name__ == "__main__":
    main()
