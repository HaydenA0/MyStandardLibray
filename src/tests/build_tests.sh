#!/bin/bash
set -e


SRC_DIR=".."
BIN_DIR="../bin"
TEST_DIR="."


mkdir -p "$BIN_DIR"


LIB_SOURCES=$(find "$SRC_DIR" -maxdepth 1 -name "*.c" ! -name "main.c")


for test_file in "$TEST_DIR"/*_test.c; do

    test_name=$(basename "$test_file" .c)
    output="$BIN_DIR/$test_name"
    
    echo "Building $test_name ..."
    gcc $LIB_SOURCES "$test_file" -I"$SRC_DIR" -o "$output"

    echo "Built $output"
done

echo "All tests compiled successfully."

