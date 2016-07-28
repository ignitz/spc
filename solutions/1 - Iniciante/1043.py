def convertFloat(param):
    return float(param)

def desTriangular(paramA, paramB, paramC):
    if abs(paramB - paramC) < paramA < paramB + paramC:
        return True
    else:
        return False

entrada = input().split()
entrada = list(map(convertFloat, entrada))

if desTriangular(*entrada):
    perimetro = 0
    for i in entrada:
        perimetro += i
    print('Perimetro =', format(perimetro, '.1f'))
else:
    area = (entrada[0] + entrada[1])*entrada[2]/2
    print('Area =', format(area, '.1f'))