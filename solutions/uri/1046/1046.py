#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# https://www.urionlinejudge.com.br/judge/pt/problems/view/1046


def main():
    start_hour, end_hour = map(int, input().split(' ')[:2])

    if start_hour < end_hour:
        print('O JOGO DUROU', str(end_hour - start_hour), 'HORA(S)')
    elif start_hour == end_hour:
        print('O JOGO DUROU 24 HORA(S)')
    else:
        print('O JOGO DUROU', str(end_hour + 24 - start_hour), 'HORA(S)')


if __name__ == '__main__':
    main()
