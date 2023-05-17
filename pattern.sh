#!/bin/bash

echo "Enter the pattern to search: "
read pattern

echo "Files in the present working directory:"
echo "--------------------------------------"

for file in *; do
    if [ -f "$file" ]; then
        if grep -q "$pattern" "$file"; then
            echo "$file: Pattern found"
        else
            echo "$file: Pattern not found"
        fi
    fi
done
