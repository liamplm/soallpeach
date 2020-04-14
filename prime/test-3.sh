#!/bin/sh

printf "\nTest 3:\n"

time (python3 main-cache.py ./test-3.txt > /dev/null)
time (./main ./test-3.txt > /dev/null)
time (./main-2 ./test-3.txt > /dev/null)
time (./main-3 ./test-3.txt > /dev/null)
# time (python3 main.py ./test-3.txt > /dev/null)
