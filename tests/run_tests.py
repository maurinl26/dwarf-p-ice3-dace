#!/usr/bin/env python3
"""
Test runner script for ice3 test suite
"""
import sys
import subprocess
import argparse
from pathlib import Path


def run_tests(test_pattern=None, verbose=False, coverage=False):
    """Run the test suite with optional filtering and coverage"""
    
    # Base pytest command
    cmd = ["uv", "run", "pytest"]
    
    # Add verbosity
    if verbose:
        cmd.append("-v")
    else:
        cmd.append("-q")
    
    # Add coverage if requested
    if coverage:
        cmd.extend(["--cov=src", "--cov-report=term-missing"])
    
    # Add test pattern if specified
    if test_pattern:
        cmd.append(f"-k {test_pattern}")
    
    # Add test directory
    cmd.append("tests/")
    
    # Add options for better output
    cmd.extend([
        "--tb=short",
        "--disable-warnings",
        "-x"  # Stop on first failure
    ])
    
    print(f"Running: {' '.join(cmd)}")
    
    try:
        result = subprocess.run(cmd, cwd=Path(__file__).parent.parent)
        return result.returncode
    except KeyboardInterrupt:
        print("\nTest run interrupted by user")
        return 1
    except Exception as e:
        print(f"Error running tests: {e}")
        return 1


def main():
    parser = argparse.ArgumentParser(description="Run ice3 test suite")
    parser.add_argument(
        "-k", "--pattern", 
        help="Run tests matching this pattern"
    )
    parser.add_argument(
        "-v", "--verbose", 
        action="store_true",
        help="Verbose output"
    )
    parser.add_argument(
        "--coverage", 
        action="store_true",
        help="Run with coverage reporting"
    )
    parser.add_argument(
        "--components", 
        action="store_true",
        help="Run only component tests"
    )
    parser.add_argument(
        "--dace", 
        action="store_true",
        help="Run only DaCe tests"
    )
    parser.add_argument(
        "--stencils", 
        action="store_true",
        help="Run only stencil tests"
    )
    parser.add_argument(
        "--integration", 
        action="store_true",
        help="Run only integration tests"
    )
    parser.add_argument(
        "--utils", 
        action="store_true",
        help="Run only utility tests"
    )
    
    args = parser.parse_args()
    
    # Determine test pattern based on flags
    pattern = args.pattern
    
    if args.components:
        pattern = "test_components"
    elif args.dace:
        pattern = "dace"
    elif args.stencils:
        pattern = "test_stencils"
    elif args.integration:
        pattern = "test_integration"
    elif args.utils:
        pattern = "test_utils"
    
    # Run tests
    return_code = run_tests(
        test_pattern=pattern,
        verbose=args.verbose,
        coverage=args.coverage
    )
    
    sys.exit(return_code)


if __name__ == "__main__":
    main()