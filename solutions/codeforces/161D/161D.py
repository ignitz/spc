# Yuri Diego Santos Niitsuma
# 2011039023
# http://codeforces.com/problemset/problem/161/D
# Distance in Tree

from pprint import *

class Graph:

    def __init__(self, n, k):
        self.n = n
        self.k = k
        self.edges = dict()
        self.cost = []
        self.many_with_k = 0

        for i in range(n):
            self.edges[i+1] = list()
            self.cost.append( [0] * n)

    def set_connection(self, a, b):
        self.edges[a].append(b)
        self.edges[b].append(a)

    # using dfs to walk on tree and update cost matrix
    def walk_vertice(self, vertice, came_from=0):
        self.cost[vertice-1][0] = 1
        for i in range( len(self.edges[vertice]) ):
            v = self.edges[vertice][i]
            if v != came_from:
                self.walk_vertice(v, vertice)
                # print("walk_vertice(", vertice, came_from, ")")
                # pprint(graph.cost)
                # print("back to walk_vertice(", v, vertice, ")")
                for ii in range( self.k ):
                    self.many_with_k += self.cost[vertice-1][ii] * self.cost[v - 1][self.k - ii -1]
                for ii in range( self.k ):
                    self.cost[vertice-1][ii+1] += self.cost[v-1][ii]



n, k = list(map(int, input().split(" ")[0:2]))

graph = Graph(n, k)

for i in range(n-1):
    a, b = list(map(int, input().split(" ")[0:2]))
    graph.set_connection(a,b)

# pprint(graph.edges)
graph.walk_vertice(1) # dfs(1, -1);
# pprint(graph.cost)
print(graph.many_with_k)
