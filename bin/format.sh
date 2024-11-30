#!/bin/bash

RESET="\033[0m"
BOLD="\033[1m"
GREEN="\033[32m"
YELLOW="\033[33m"

files=$(find . -type f \( -name "*.cpp" -o -name "*.hpp" \) ! -path '*/.*' ! -path './build/*')

if [ -n "$files" ]; then
    echo -e $BOLD$GREEN " >> Running clang-format..." $RESET
    for file in $files; do
        clang-format -i "$file"
        echo -e $GREEN "\t> $file" $RESET
    done
else
    echo -e $YELLOW "No .cpp or .hpp files found." $RESET
fi
