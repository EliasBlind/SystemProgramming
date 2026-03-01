#!/bin/bash

# Пути к исполняемым файлам
BUILD_DIR="./builds/lab_7"
PR1="$BUILD_DIR/pr7-1"
PR2="$BUILD_DIR/pr7-2"
PR3="$BUILD_DIR/pr7-3"

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

echo "--- Running Tests for Lab 7 ---"

for FILE in $PR1 $PR2 $PR3; do
    if [ -f "$FILE" ]; then
        echo -e "${GREEN}[OK]${NC} Executable $FILE found."
    else
        echo -e "${RED}[FAIL]${NC} Executable $FILE not found. Run 'make' first."
        exit 1
    fi
done

echo -n "Testing pr7-1... "
if $PR1 | grep -q "Ivanov"; then
    echo -e "${GREEN}PASSED${NC}"
else
    echo -e "${RED}FAILED${NC}"
fi

echo -n "Testing pr7-2... "
if $PR2 | grep -qE "[0-9]+\.[0-9]+"; then
    echo -e "${GREEN}PASSED${NC}"
else
    echo -e "${RED}FAILED${NC}"
fi

echo -n "Testing pr7-3 (Dynamic Memory)... "
echo -e "1\nTestUser\n101\n5 5 5 5 5" | $PR3 > /dev/null
if [ $? -eq 0 ]; then
    if command -v valgrind &> /dev/null; then
        echo -e "1\nTestUser\n101\n5 5 5 5 5" | valgrind --leak-check=full $PR3 2>&1 | grep -q "no leaks are possible"
        if [ $? -eq 0 ]; then
            echo -e "${GREEN}PASSED (Memory Clean)${NC}"
        else
            echo -e "${RED}PASSED (with Memory Leaks)${NC}"
        fi
    else
        echo -e "${GREEN}PASSED${NC}"
    fi
else
    echo -e "${RED}FAILED (Crash)${NC}"
fi

echo "--- Tests Completed ---"
