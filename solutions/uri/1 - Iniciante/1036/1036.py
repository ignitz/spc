# Devo usar TryCatch?
import math

class Equacao:
    def __init__(self, *vector):
        self.a = float(vector[0])
        self.b = float(vector[1])
        self.c = float(vector[2])

    def calcRaizes(self):
        delta = self.calcDelta()
        if delta > 0:
            a, b, c = (self.a, self.b, self.c)
            R1, R2 = ((-b + math.sqrt(delta))/(2*a), (-b - math.sqrt(delta))/(2*a))
            print("R1 =", format(R1, '.5f'))
            print("R2 =", format(R2, '.5f'))
        else:
            self.printErro()

    def calcDelta(self):
        if self.a != 0:
            return float(self.b**2 - 4*self.a*self.c)
        else:
            return -1.0

    def printErro(self):
        print('Impossivel calcular')


segundoGrau = Equacao(*input().split())
segundoGrau.calcRaizes()
# segundoGrau1 = Equacao(*'10.0 20.0 5.1'.split())
# segundoGrau1.calcRaizes()
# segundoGrau2 = Equacao(*'0.0 20.0 5.0'.split())
# segundoGrau2.calcRaizes()
# segundoGrau3 = Equacao(*'10.3 203.0 5.0'.split())
# segundoGrau3.calcRaizes()
# segundoGrau4 = Equacao(*'10.0 3.0 5.0'.split())
# segundoGrau4.calcRaizes()
