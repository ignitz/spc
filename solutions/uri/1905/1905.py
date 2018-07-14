#!/usr/bin/env python3

# for stderr
from __future__ import print_function
import sys

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

from pprint import *

class Game:
    def __init__(self):
        self.matrix = []
        self.colors = []
        for i in range(5):
            line = input().split(" ")
            if len(line) < 5:
                line = input().split(" ")
            line = [int(d) for d in line if d.isdigit()]
            # eprint(line)
            self.matrix.append(line)
            self.colors.append([0] * 5)
        # pprint(self.matrix)

    def go_after_them(self, x, y):
        if self.matrix[x][y] == 1 or self.colors[x][y] == 1:
            return False
        if x == 4 and y == 4:
            return True

        self.colors[x][y] = 1
        response = False

        if x > 0:
            response = response or self.go_after_them(x - 1, y)
        if y > 0:
            response = response or self.go_after_them(x, y - 1)
        if x < 4:
            response = response or self.go_after_them(x + 1, y)
        if y < 4:
            response = response or self.go_after_them(x, y + 1)
        return response

    def get_winner(self):
        return "COPS" if self.go_after_them(0, 0) else "ROBBERS"

t = int(input()) # (1 ≤ T ≤ 400)

for test_number in range(t):
    # read 5 x 5 matrix
    game = Game()
    print(game.get_winner())
