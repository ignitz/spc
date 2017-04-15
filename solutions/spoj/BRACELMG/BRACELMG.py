#!/usr/bin/python3
# Yuri Diego Santos Niitsuma
# 2011039023
# http://br.spoj.com/problems/BRACELMG/
# BRACELMG

import sys

def search_pattern(line):
    if len(line) > 2:
        i = 0
        while i < len(line):
            if line[i] == '':
                del line[i]
                continue
            i += 1
        if len(line) > 2: # Caso tenha algo que nao tenho em mente
            print('Check another error')
            sys.exit(1)

    pattern, word = line
    word += word
    check = word.find(pattern)
    if check >= 0:
        return True
    check = word[::-1].find(pattern)
    if check >= 0:
        return True
    return False

def main():
    test_size = int(input())
    for _ in range(test_size):
        if search_pattern(input().split(' ')):
            print('S')
        else:
            print('N')

if __name__ == '__main__':
    main()