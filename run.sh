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
./$input.linux < $input.in > $input.out
cat $input.out