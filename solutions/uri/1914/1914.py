#!/usr/bin/env python3

class Jogador:
    def __init__(self, *args):
        self.name = args[0]
        self.choice = args[1]

    def get_name(self):
        return self.name

    def is_even(self):
        if self.choice == 'PAR':
            return True
        else:
            return False

    def is_odd(self):
        if self.choice == 'IMPAR':
            return True
        else:
            return False

qt = int(input()) # (1 ≤ QT ≤ 100)

for i in range(qt):
    entrada = input().split(" ")
    jogador1 = Jogador(entrada[0], entrada[1])
    jogador2 = Jogador(entrada[2], entrada[3])
    entrada = list(map(int, input().split(" ")))
    if sum(entrada) % 2 == 0:
        print(jogador1.get_name()) if jogador1.is_even() else print(jogador2.get_name())
    else:
        print(jogador1.get_name()) if jogador1.is_odd() else print(jogador2.get_name())
