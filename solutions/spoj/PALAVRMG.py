#!/usr/bin/python3
# Yuri Diego Santos Niitsuma
# 2011039023
# http://br.spoj.com/problems/PALAVRMG/
# PALAVRMG

def is_ordered(word):
    aux = word[0]
    for i in range(1, len(word)):
        if word[i] <= aux:
            return False
        else:
            aux = word[i]
    return True

def main():
    n = int(input())
    for i in range(0, n):
        word = input()
        if is_ordered(word.lower()):
            print(word + ': O')
        else:
            print(word + ': N')

if __name__ == '__main__':
    main()
