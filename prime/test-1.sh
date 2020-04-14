#!/bin/sh

printf "\nTest 1:\n"

time (python3 main-cache.py ./test-1.txt > /dev/null)
time (./main ./test-1.txt > /dev/null)
time (./main-2 ./test-1.txt > /dev/null)
time (./main-3 ./test-1.txt > /dev/null)
time (python3 main.py ./test-1.txt > /dev/null)


