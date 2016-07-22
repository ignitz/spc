class Peca:
    def __init__(self, codigo, quantidade, valorUnit):
        self.codigo = codigo
        self.quantidade = float(quantidade)
        self.valorUnit = float(valorUnit)

    def soma(self):
        return self.quantidade * self.valorUnit

entrada = input().split()
peca1 = Peca(*entrada)
entrada = input().split()
peca2 = Peca(*entrada)
print("VALOR A PAGAR: R$", format(peca1.soma() + peca2.soma(), '.2f'))
