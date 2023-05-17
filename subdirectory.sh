#!/bin/bash

echo "Subdirectories in the present working directory:"
echo "----------------------------------------------"

for dir in */; do
    if [ -d "$dir" ]; then
        echo "${dir%/}"
    fi
done