# Yuri Diego Santos Niitsuma
# 2011039023
# http://codeforces.com/problemset/problem/18/A
# TRIANGLE

'''
Tentei resolver com dotproduct igual a zero para encontrar
vetores perpendiculares. Mas mudei a estratégia para o
teorema de pitágoras pois caia no problema de pontos
sobrepostos (provalmente).
'''

import operator

def get_size(a, b):
    return (a[0] - b[0])**2 + (a[1] - b[1])**2

def get_pitagoras(a, b, c):

    size = []
    size.append(get_size(a, b))
    size.append(get_size(a, c))
    size.append(get_size(b, c))
    size.sort()
    return True if size[0] > 0 and size[2] == size[0] + size[1] else False

def are_right(point1, point2, point3):
    if get_pitagoras(point1, point2, point3):
        return True
    elif get_pitagoras(point2, point1, point3):
        return True
    elif get_pitagoras(point3, point1, point2):
        return True
    return False

def are_almost(point1, point2, point3):
    if point1[0] < 100 and get_pitagoras(tuple(map(operator.add, point1, (1, 0))), point2, point3):
        return True
    elif point1[1] < 100 and get_pitagoras(tuple(map(operator.add, point1, (0, 1))), point2, point3):
        return True
    elif point1[0] > -100 and get_pitagoras(tuple(map(operator.add, point1, (-1, 0))), point2, point3):
        return True
    elif point1[1] > -100 and get_pitagoras(tuple(map(operator.add, point1, (0, -1))), point2, point3):
        return True
    elif point2[0] < 100 and get_pitagoras(tuple(map(operator.add, point2, (1, 0))), point1, point3):
        return True
    elif point2[1] < 100 and get_pitagoras(tuple(map(operator.add, point2, (0, 1))), point1, point3):
        return True
    elif point2[0] > -100 and get_pitagoras(tuple(map(operator.add, point2, (-1, 0))), point1, point3):
        return True
    elif point2[1] > -100 and get_pitagoras(tuple(map(operator.add, point2, (0, -1))), point1, point3):
        return True
    elif point3[0] < 100 and get_pitagoras(tuple(map(operator.add, point3, (1, 0))), point1, point2):
        return True
    elif point3[1] < 100 and get_pitagoras(tuple(map(operator.add, point3, (0, 1))), point1, point2):
        return True
    elif point3[0] > -100 and get_pitagoras(tuple(map(operator.add, point3, (-1, 0))), point1, point2):
        return True
    elif point3[1] > -100 and get_pitagoras(tuple(map(operator.add, point3, (0, -1))), point1, point2):
        return True
    return False

x1, y1, x2, y2, x3, y3 = list(map(int, input().split(" ")))
point1 = (x1, y1)
point2 = (x2, y2)
point3 = (x3, y3)

if are_right(point1, point2, point3):
    print('RIGHT')
elif are_almost(point1, point2, point3):
    print('ALMOST')
else:
    print('NEITHER')
