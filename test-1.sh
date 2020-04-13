#!/bin/sh

printf "\nTest 1:\n"

time (python3 main-cache.py ./test-1.txt > /dev/null)
time (python3 1.py ./test-1.txt > /dev/null)
time (python3 2.py ./test-1.txt > /dev/null)
time (python3 main.py ./test-1.txt > /dev/null)


