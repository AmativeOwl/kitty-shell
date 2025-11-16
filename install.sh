#!/bin/bash

for file in *.sh; do
	name="${file%.sh}"
	sudo cp "$file" /usr/local/bin/"$name"
	sudo chmod +x /usr/local/bin/"$name"
done
