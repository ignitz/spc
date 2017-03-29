#!/usr/bin/python3
# Yuri Diego Santos Niitsuma
# 2011039023
# http://br.spoj.com/problems/IMPEDIDO/
# IMPEDIDO

class Impedido():
    def __init__(self, arg):
        self.num_atacantes   = int(str(arg).split(" ")[0])
        self.num_defensores  = int(str(arg).split(" ")[1])
        self.posicoes_atacantes = []
        self.posicoes_defensores = []


    def set_atacantes(self, arg):
        if len(arg.split(" ")) != self.num_atacantes:
            return False
        for value in arg.split(" "):
            self.posicoes_atacantes.append(int(value))
        self.posicoes_atacantes.sort(reverse=True)
        return True

    def set_defensores(self, arg):
        if len(arg.split(" ")) != self.num_defensores:
            return False
        for value in arg.split(" "):
            self.posicoes_defensores.append(int(value))
        self.posicoes_defensores.sort(reverse=True)
        return True

    def get_num_atacantes(self):
        return self.num_atacantes

    def get_num_defensores(self):
        return self.num_defensores

    def get_atacante_avancado(self):
        return self.posicoes_atacantes[-1]

    def get_ultimo_defensor(self):
        return self.posicoes_defensores[-1]

    def get_penultimo_defensor(self):
        return self.posicoes_defensores[-2]

    def testa_impedimento(self):
        atacante = self.get_atacante_avancado()
        if atacante < self.get_penultimo_defensor():
            return True
        else:
            return False

def main():
    while True:
        problema = Impedido(str(input()))
        if problema.get_num_atacantes() == 0 or problema.get_num_defensores() == 0:
            return True
        problema.set_atacantes(str(input()))
        problema.set_defensores(str(input()))
        if problema.testa_impedimento():
            print('Y')
        else:
            print('N')

if __name__ == '__main__':
    main()
