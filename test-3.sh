#!/bin/sh

printf "\nTest 3:\n"

time (python3 main-cache.py ./test-3.txt > /dev/null)
time (python3 main.py ./test-3.txt > /dev/null)

