#!/usr/bin/env python3

# for stderr
from __future__ import print_function
import sys

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

class SetOfNumbers:

    def __init__(self, id, numbers):
        self.id = id
        if len(numbers) != numbers[0] + 1:
            eprint('Error in size of set:', len(numbers), numbers[0])
        del numbers[0]
        self.numbers = set(numbers)

def choose_operation(sets, args):
    if int(args[0]) == 1:
        operation1(sets, int(args[1])-1, int(args[2])-1)
    else:
        operation2(sets, int(args[1])-1, int(args[2])-1)

# 1 X Y: Retorna a quantidade de elementos distintos da intersecção entre o conjunto X com o Y.
def operation1(sets, x, y):
    print(len(sets[x].numbers & sets[y].numbers))

# 2 X Y: Retorna a quantidade de elementos distintos da união entre o conjunto X com o Y.
def operation2(sets, x, y):
    print(len(sets[x].numbers | sets[y].numbers))


test_numbers = int(input())

for test in range(test_numbers):
    set_numbers = int(input())

    sets = []
    for i in range(1, set_numbers + 1):
        sets.append(SetOfNumbers(i, [int(d) for d in input().split(" ") if d.isdigit()]))
    for i in range(int(input())):
        choose_operation(sets, tuple(input().split(" ")))
