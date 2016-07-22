import math

class Ponto:
    def __init__(self, x, y):
        self.x = float(x)
        self.y = float(y)

def dist(a, b):
    return math.sqrt((a.x - b.x)**2 + (a.y - b.y)**2)

ponto1 = Ponto(*input().split())
ponto2 = Ponto(*input().split())
print(format(dist(ponto1, ponto2), '.4f'))
