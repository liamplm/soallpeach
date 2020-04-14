#!/bin/sh

printf "\nTest 2:\n"

time (python3 main-cache.py ./test-2.txt > /dev/null)
time (./main ./test-2.txt > /dev/null)
time (./main-2 ./test-2.txt > /dev/null)
time (./main-3 ./test-2.txt > /dev/null)
time (python3 main.py ./test-2.txt > /dev/null)
