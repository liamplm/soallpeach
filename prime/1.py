import sys
from math import sqrt

file_name = sys.argv[1]

def is_prime(n: int) -> int:
    if n <= 3:
        return 1

    if n % 2 == 0:
        return 0

    if n % 3 == 0:
        return 0
    
    for m in range(5, int(sqrt(n))+1, 6):
        if n % m == 0 or n % (m + 2) ==0:
            return 0

    return 1


with open(file_name) as input_numbers:
    for line in input_numbers:
        number = int(line)
        print(number, is_prime(number))
    