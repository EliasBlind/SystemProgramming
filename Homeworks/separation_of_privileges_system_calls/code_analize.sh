#!/bin/bash

USE_CONSOLE=false
if [[ "$1" == "-c" ]]; then
    USE_CONSOLE=true
fi

first_prog_dir="../data_rase/src/"
second_prog_dir="../compilation_and_linking/src/"

start_dir="$PWD"
log1="$start_dir/trace_1.log"
log2="$start_dir/trace_2.log"

if [[ "$1" == "-r" ]]; then
    rm -f $log1 $log2
    exit
fi

run_trace() {
    local output_file=$1
    if [ "$USE_CONSOLE" = true ]; then
        strace ./myprog
    else
        strace -o "$output_file" ./myprog
        echo "Log saved to $output_file"
    fi
}

# First test
cd "$first_prog_dir" || exit
gcc -o myprog main.c
run_trace "$log1"
rm myprog

cd "$start_dir" || exit

# Second test
cd "$second_prog_dir" || exit
make
run_trace "$log2"
make clean
