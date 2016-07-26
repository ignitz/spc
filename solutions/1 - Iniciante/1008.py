def rounding(x):
    return format(x, '.2f')

nome = str(input())
sal_fix = float(input())
venda = float(input())

comissao = 0.15*venda

print("TOTAL = R$", rounding(sal_fix + comissao))