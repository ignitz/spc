class Tempo:
    def __init__(self, n):
        n = int(n)
        self.year = self.calcYear(n)
        self.month = self.calcMonth(n)
        self.days = self.calcDays(n)

    def calcYear(self, n):
        return divmod(n, 365)[0]

    def calcMonth(self, n):
        return divmod(divmod(n, 365)[1], 30)[0]

    def calcDays(self, n):
        return divmod(divmod(n, 365)[1], 30)[1]

    def printThis(self):
        print(self.year, "ano(s)")
        print(self.month, "mes(es)")
        print(self.days, "dia(s)")

tempo = Tempo(int(input()))
tempo.printThis()