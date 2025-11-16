#!/bin/bash

file="seePortrait.c"
execName="${file%.*}"

echo "Opening the portrait..."

gcc "$file" -o "$execName"

if [ "$?" -eq 0 ]; then
    ./"$execName"
else 
    echo "Compilation failed"
fi

echo "Ta da!"