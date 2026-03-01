#!/bin/bash

cd ../
make
cd builds/lab_2/

echo "--- Запуск расширенных тестов для Lab 2 ---"

if [ -f "./ex_1" ]; then
    echo -n "Тестирование Задача 1... "
    OUTPUT=$(./ex_1)
    if echo "$OUTPUT" | grep -q "file1.txt" && echo "$OUTPUT" | grep -q "file2.txt"; then
        echo "PASSED (Файлы прочитаны)"
    else
        echo "FAILED (Вывод не содержит имен файлов)"
    fi
else
    echo "Ошибка: ex_1 не найден."
fi

if [ -f "./ex_2_threads" ]; then
    echo -n "Тестирование Задача 2... "
    OUTPUT=$(./ex_2_threads)
    if echo "$OUTPUT" | grep -q "0" && echo "$OUTPUT" | grep -q "1"; then
        echo "PASSED (Запись выполнена обоими потоками)"
    else
        echo "FAILED (Ошибка вывода потоков)"
    fi
else
    echo "Ошибка: ex_2_threads не найден."
fi

if [ -f "./ex_2_data_race" ]; then
    echo -n "Тестирование Задача 2 (Data Race)... "
    RESULTS=($(./ex_2_data_race | grep -oE '[0-9]+'))
    ACTUAL=${RESULTS[0]}
    EXPECTED=${RESULTS[1]}

    if [ "$ACTUAL" -ne "$EXPECTED" ]; then
        echo "PASSED (Гонка данных обнаружена: $ACTUAL != $EXPECTED)"
    else
        echo "FAILED (Гонка данных не проявилась, попробуйте увеличить число итераций)"
    fi
else
    echo "Ошибка: ex_2_data_race не найден."
fi

echo "--- Тестирование завершено ---"
