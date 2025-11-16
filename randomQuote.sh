#!/bin/bash

file="randomQuote.c"
execName="${file%.*}"

gcc "$file" -o "$execName"

if [ "$?" -eq 0 ]; then
	./"$execName"
else
	echo "Compilation failed"
fi
