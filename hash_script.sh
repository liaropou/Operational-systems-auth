#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: $0 <4-digit-integer>"
    exit 1
fi

if ! [[ $1 =~ ^[0-9]{4}$ ]]; then
    echo "Error: Not valid integer."
    exit 1
fi

input=$1
hash=$(echo -n "$input" | sha256sum)

echo "$hash" > hash_output.txt

echo "Hash of $input is on hash_output.txt"


# to run: 1. chmod +x hash_script.sh
#2. ./hash_script.sh 0066
