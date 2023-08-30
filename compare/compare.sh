g++ validator.cpp -o validator
g++ problem.cpp -o problem
REAL=$(./validator < output)
GEN=$(./problem < output)
if [ "$REAL" != "$GEN" ]; then
    echo "WA"
    echo "Input:"
    cat output
    echo "Expected:"
    echo $REAL
    echo "Found:"
    echo $GEN
    exit 1
fi
echo "AC"
