#!/usr/bin/env python3

import operator

class Alunos:

    def __init__(self, name):
        self.name = name
        self.respostas = []
        self.num_perolas = 0

    def add_respostas(self, x):
        self.respostas.append(x)

    def calc_perolas(self, perolas):
        self.num_perolas = 0
        for resposta in self.respostas:
            for perola in perolas:
                if resposta == perola:
                    self.num_perolas += 1
        # self.num_perolas = len(self.respostas & perolas)
        print(self.name, self.num_perolas)
        return self.num_perolas

while True:
    p, a, r = list(map(int, input().split(' ')[:3]))
    if p == 0 and a == 0 and r == 0:
        break

    perolas = set()
    alunos = []

    for i in range(p):
        perolas.add(str(input()))

    for i in range(a):
        alunos.append(Alunos(str(input())))
        for j in range(r):
            alunos[-1].add_respostas(str(input()))
        if alunos[-1].calc_perolas(perolas) == 0:
            alunos.pop()

    alunos.sort(key=operator.attrgetter('name'))
    alunos.sort(key=operator.attrgetter('num_perolas'), reverse=True)

    n = len(alunos)
    i = 1
    while i < n:
        if alunos[i].name == alunos[i-1].name or alunos[i].num_perolas < alunos[0].num_perolas:
            alunos.pop(i)
            i -= 1
            n -= 1
        i += 1

    for i in range(len(alunos)):
        print(alunos[i].name, end='')
        if i != n-1:
            print(end=', ')
    print()
