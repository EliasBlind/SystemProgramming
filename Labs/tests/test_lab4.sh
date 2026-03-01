#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

BUILD_DIR="$PROJECT_ROOT/builds/lab_4"
LOG_DIR="$PROJECT_ROOT/tests/logs"

if ! command -v valgrind &> /dev/null; then
    echo "Ошибка: valgrind не установлен. Установите его: sudo apt install valgrind"
    exit 1
fi

cd "$PROJECT_ROOT"
mkdir -p "$LOG_DIR"
make lab_4

echo "=== Запуск динамического анализа (Лабораторная №4) ==="

analyze() {
    local target=$1
    local bin="$BUILD_DIR/$target"
    local log="$LOG_DIR/${target}_valgrind.log"

    if [ ! -f "$bin" ]; then
        echo "[!] Файл $target не найден. Пропуск."
        return
    fi

    echo "--- Анализ: $target ---"
    
    valgrind --leak-check=full \
             --show-leak-kinds=all \
             --track-origins=yes \
             --log-file="$log" \
             "$bin" > /dev/null 2>&1

    if [ -s "$log" ]; then
        if grep -q "ERROR SUMMARY: 0 errors" "$log"; then
            echo "Ошибок не обнаружено."
        else
            echo "Обнаружены ошибки! См. лог: $log"
            grep -E "lost:|at 0x" "$log" | head -n 3
        fi
    else
        echo "[!] Ошибка: Valgrind не создал отчет. Попробуйте запустить: valgrind $bin"
    fi
    echo ""
}

targets=("leak" "overflow" "hello" "abs_example")

for t in "${targets[@]}"; do
    analyze "$t"
done

echo "=== Анализ завершен. Детальные отчеты в $LOG_DIR ==="
