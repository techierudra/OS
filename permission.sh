#!/bin/bash

echo "Enter the file path: "
read filepath

if [ -f "$filepath" ]; then
    if [ -x "$filepath" ]; then
        echo "The file already has execute permission."
    else
        chmod +x "$filepath"
        echo "Execute permission added to the file."
    fi
else
    echo "The specified file does not exist."
fi
