class Produto:
    def __init__(self, *args):
        self.codigo, self.nome, self.preco = args
        self.codigo = int(self.codigo)
        self.preco = float(self.preco)

    def print(self):
        print(self.codigo, self.nome, self.preco)

    def calcTotal(self, quantidade):
        total = int(quantidade) * self.preco
        return 'Total: R$ ' + str(format(total, '.2f'))


produtos = []
produtos.append(Produto(1, "Cachorro Quente", 4.00))
produtos.append(Produto(2, "X-Salada", 4.50))
produtos.append(Produto(3, "X-Bacon", 5.00))
produtos.append(Produto(4, "Torrada Simples", 2.00))
produtos.append(Produto(5, "Refrigerante", 1.50))

entrada = input().split()
for x in entrada:
    x = int(x)
codigo, quantidade= entrada
codigo = int(codigo)

for x in produtos:

    if codigo == x.codigo:
        print(x.calcTotal(quantidade))