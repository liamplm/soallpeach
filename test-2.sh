#!/bin/sh

printf "\nTest 3:\n"

time (python3 main-cache.py ./test-2.txt > /dev/null)
time (python3 1.py ./test-2.txt > /dev/null)
time (python3 2.py ./test-2.txt > /dev/null)
time (python3 main.py ./test-2.txt > /dev/null)

