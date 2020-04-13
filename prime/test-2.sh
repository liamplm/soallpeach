#!/bin/sh

printf "\nTest 2:\n"

time (python3 main-cache.py ./test-2.txt > /dev/null)
time (python3 main.py ./test-2.txt > /dev/null)

