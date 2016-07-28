def convertFloat(param):
    return float(param)

paramA, paramB, paramC = input().split()
paramA = convertFloat(paramA)
paramB = convertFloat(paramB)
paramC = convertFloat(paramC)

paramA, paramB, paramC = sorted((paramA, paramB, paramC), reverse=True)

parte1 = paramA**2
parte2 = paramB**2 + paramC**2

if paramA >= paramB + paramC:
    print('NAO FORMA TRIANGULO')
else:
    if parte1 == parte2:
        print('TRIANGULO RETANGULO')
    if parte1 > parte2:
        print('TRIANGULO OBTUSANGULO')
    if parte1 < parte2:
        print('TRIANGULO ACUTANGULO')
    if paramA == paramB == paramC:
        print('TRIANGULO EQUILATERO')
    elif paramA == paramB or paramA == paramC or paramB == paramC:
        print('TRIANGULO ISOSCELES')
