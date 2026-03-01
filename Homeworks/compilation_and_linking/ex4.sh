#!/bin/bash

cd src
echo "--- Сборка проекта ---"
make clean && make

if [ ! -f myprog ]; then
    echo "Ошибка: исполняемый файл myprog не найден."
    exit 1
fi

echo -e "\n--- Анализ через ldd ---"
ldd myprog | grep libc

echo -e "\n--- Анализ через readelf (.interp) ---"
readelf -p .interp myprog

echo -e "\n--- Очистка ---"
make clean
