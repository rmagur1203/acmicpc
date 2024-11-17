g++ validator.cpp -o validator
g++ problem.cpp -o problem
COUNT=0
while true; do
    ./datagenerator > output
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
    echo $COUNT
    ((COUNT++))
done