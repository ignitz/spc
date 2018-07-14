#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# https://www.urionlinejudge.com.br/judge/pt/problems/view/1047

import sys

def is_python3():
    if sys.version_info >= (3, 0):
        return True
    else:
        return False


def timestamp(hour, minute):
    return hour * 60 + minute


def main():
    entrada = input() if is_python3() else raw_input()
    entrada = list(map(int, entrada.split(' ')[:4]))
    start_time = timestamp(*entrada[:2])
    end_time = timestamp(*entrada[2:])

    duration = None

    if start_time < end_time:
        duration = end_time - start_time
    elif start_time == end_time:
        duration = 24*60
    else:
        duration = end_time + 24*60 - start_time

    result = divmod(duration, 60)

    print('O JOGO DUROU', result[0], 'HORA(S) E', result[1], 'MINUTO(S)')


if __name__ == '__main__':
    main()
