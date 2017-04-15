# Yuri Diego Santos Niitsuma
# 2011039023
# http://br.spoj.com/problems/IREVIR/
# IREVIR

'''
Utilizei a ideia de grafos usando dicionário a partir daqui
https://www.python.org/doc/essays/graphs/
https://pt.wikipedia.org/wiki/Busca_em_largura
'''

from pprint import *

class Graph:

    def __init__(self, n, m):
        self.n = n
        self.m = m
        self.edges = dict()
        for i in range(n):
            self.edges[i + 1] = []

    def add(self, v, w):
        if w not in self.edges[v]:
            self.edges[v].append(w)

    def is_connected(self):

        for v in self.edges:
            if not v:
                return False

        response = True

        for i in range(1, n + 1): # check bfs on every vertice
            response = response and self.bfs(i)
            if not response:
                break
        return response

    def bfs(self, init_v):
        vs_marked = []

        # Poe vertice na fila
        queue = [init_v]
        vs_marked.append(init_v)

        while queue:
            vertice1 = queue[0] # vertice que esta no inicio da fila
            self.edges[vertice1] # vertices adjacentes

            for p in self.edges[vertice1]:
                if p not in vs_marked:
                    vs_marked.append(p) # marca p de cinza
                    queue.append(p) # poe p na fila
            queue.pop(0)

        if len(vs_marked) == self.n:
            return True
        else:
            return False

    def find_path(self, start, end, path=[]):
        path = path + [start]
        if start == end:
            return path
        if start not in self.edges:
            return None
        for node in self.edges[start]:
            if node not in path:
                newpath = self.find_path(node, end, path)
                if newpath: return newpath
        return None

while True:
    try:
        n, m = list(map(int, input().split(" ")[0:2]))
        graph = Graph(n, m)
    except:
        break

    for i in range(m):
        v, w, p = list(map(int, input().split(" ")[0:3]))
        if p == 1:
            graph.add(v, w)
        else:
            graph.add(v, w)
            graph.add(w, v)

    if graph.is_connected():
        print(1)
    else:
        print(0)
