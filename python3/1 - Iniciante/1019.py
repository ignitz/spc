class Tempo:
    def __init__(self, n):
        self.hours = self.calcHours(n)
        self.min = self.calcMin(n)
        self.sec = self.calcSec(n)

    def calcHours(self, n):
        return divmod(divmod(n, 60)[0], 60)[0]
    def calcMin(self, n):
        return divmod(divmod(n, 60)[0], 60)[1]
    def calcSec(self, n):
        return divmod(n, 60)[1]

    def getHour(self):
        return self.hours
    def getMin(self):
        return self.min
    def getSec(self):
        return self.sec

tempo = Tempo(int(input()))
print(tempo.getHour(), end=":")
print(tempo.getMin(), end=":")
print(tempo.getSec())
