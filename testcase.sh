#!/bin/bash
echo -n "input number: "
read input
cd $(dirname `ls -d */$input.{c,cpp} 2> /dev/null`) > /dev/null
if [ -f "$input.c" ]; then
    gcc -g $input.c -o $input.linux
fi
if [ -f "$input.cpp" ]; then
    g++ -g $input.cpp -o $input.linux
fi
chmod +x $input.linux

cd /workspaces/acmicpc
for file in testcase/$input/*.in; do
    # mv $file "${file%.*}"
    ./**/$input.linux < $file > "/tmp/$(basename "${file%.*}.out")"
    res=$(diff "${file%.*}.out" "/tmp/$(basename "${file%.*}.out")")
    if ! [ -z "$res" ]; then
        echo "FAIL $file"
        echo "$res"
    fi
done