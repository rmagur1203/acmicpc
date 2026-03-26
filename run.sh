#!/bin/bash
input=$1
if [ -z "$input" ]; then
    echo "Usage: $0 <input>"
    exit 1
fi
cd $(dirname `ls -d */$input.{c,cpp} 2> /dev/null`) > /dev/null

OS=$(uname -s)
if [ "$OS" == "Darwin" ]; then
    POSTFIX="mac"   
elif [ "$OS" == "Linux" ]; then
    POSTFIX="linux"
fi

if [ -f "$input.c" ]; then
    gcc -g $input.c -o $input.$POSTFIX
fi
if [ -f "$input.cpp" ]; then
    g++ -g $input.cpp -o $input.$POSTFIX
fi
chmod +x $input.$POSTFIX
./$input.$POSTFIX < $input.in > $input.out
cat $input.out

if [ -d "$input.$POSTFIX.dSYM" ]; then
    rm -rf $input.$POSTFIX.dSYM
fi