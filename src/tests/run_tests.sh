#!/bin/bash
set -e
BIN_DIR="../bin"
echo "Running all tests in $BIN_DIR ..."
shopt -s nullglob
test_bins=("$BIN_DIR"/*_test)
echo "Found ${#test_bins[@]} test(s): ${test_bins[*]}"
for test_bin in "${test_bins[@]}"; do
    echo "Running $test_bin..."
    "$test_bin"
done

