#!/bin/bash

LIB_PATH="builds/lab_6/libmylib.so"
EXE_PATH="builds/lab_6/main"
FILE_DEMO="builds/lab_6/file_demo"
LOG_DIR="tests/logs"
LOG_FILE="$LOG_DIR/test_lab6.log"

mkdir -p "$LOG_DIR"
make

echo "--- Running Lab 6 Tests ---" | tee "$LOG_FILE"

for file in "$LIB_PATH" "$EXE_PATH" "$FILE_DEMO"; do
    if [ ! -f "$file" ]; then
        echo "ERROR: $file not found." | tee -a "$LOG_FILE"
        exit 1
    fi
done

echo "Testing file_demo (pipes)..." | tee -a "$LOG_FILE"
PIPE_OUT=$($FILE_DEMO)
echo "$PIPE_OUT" >> "$LOG_FILE"
if echo "$PIPE_OUT" | grep -qE "received|sent"; then
    echo "SUCCESS: pipe_demo works." | tee -a "$LOG_FILE"
else
    echo "FAILED: pipe_demo unexpected output." | tee -a "$LOG_FILE"
fi

echo "Testing main with shared library..." | tee -a "$LOG_FILE"
export LD_LIBRARY_PATH="./builds/lab_6:$LD_LIBRARY_PATH"

MAIN_OUT=$($EXE_PATH)
echo "$MAIN_OUT" >> "$LOG_FILE"

if echo "$MAIN_OUT" | grep -q "from the shared library"; then
    echo "SUCCESS: shared library linked and called." | tee -a "$LOG_FILE"
else
    echo "FAILED: shared library test failed." | tee -a "$LOG_FILE"
    exit 1
fi

echo "--- Lab 6 Tests Finished ---" | tee -a "$LOG_FILE"
