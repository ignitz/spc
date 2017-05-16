#!/usr/bin/env python3

# for stderr
from __future__ import print_function
import sys

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

while True:
    n = int(input())
    if n == 0:
        break

    line = input().split(" ")
    numbers = [int(d) for d in line if d.isdigit()]

    setNumbers = set()
    setNumbersRepeat = set()

    for number in numbers:
        if number not in setNumbers:
            setNumbers.add(number)
        elif number in setNumbers and number not in setNumbersRepeat:
            setNumbersRepeat.add(number)
        else: # number in setNumbers and number in setNumbersRepeat
            setNumbersRepeat.remove(number)

    print(list(setNumbers - setNumbersRepeat)[0])
