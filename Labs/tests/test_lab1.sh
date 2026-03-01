#!/bin/bash

BUILD_DIR="./builds/lab_1"

cd ..
make

echo "--- Running ex_2 ---"
if [ -f "$BUILD_DIR/ex_2" ]; then
    OUT2=$($BUILD_DIR/ex_2)
    echo "$OUT2"
    if echo "$OUT2" | grep -q "Я родитель" && echo "$OUT2" | grep -q "Я ребёнок"; then
        echo "Ex 2: PASS"
    else
        echo "Ex 2: FAIL"
    fi
else
    echo "Ex 2: Binary not found"
fi

echo "--- Running ex_3 ---"
if [ -f "$BUILD_DIR/ex_3" ]; then
    OUT3=$($BUILD_DIR/ex_3)
    echo "$OUT3"
    P=$(echo "$OUT3" | grep -c "родитель")
    C=$(echo "$OUT3" | grep -c "потомок")
    G=$(echo "$OUT3" | grep -c "внук")
    
    if [ "$P" -ge 1 ] && [ "$C" -ge 1 ] && [ "$G" -ge 1 ]; then
        echo "Ex 3: PASS"
    else
        echo "Ex 3: FAIL"
    fi
else
    echo "Ex 3: Binary not found"
fi

make clean