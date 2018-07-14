#!/usr/bin/env python3

# https://www.urionlinejudge.com.br/judge/pt/problems/view/2220
# Ajudando Gust-Avô

from pprint import *

num_of_tests = int(input())

for test_no in range(num_of_tests):
    word_a = str(input())
    word_b = list(str(input()))
    state = []
    for i in range(len(word_a)):
        state.append([False] * len(word_b))

    for c in word_a:
        for i in range(1, len(word_b)):
            if c == word_b[i]:
                for j in range(len(word_a)):
                    if state[j][i-1] and not state[j][i]:
                        state[j][i] = True
                        break
            # put in state
        if c == word_b[0]:
            for i in range(len(word_a)):
                if not state[i][0]:
                    state[i][0] = True
                    break
    count = 0
    n = len(word_b)
    for i in range(len(state)):
        if state[i][n-1]:
            count += 1
    # pprint(state)
    print(count)
