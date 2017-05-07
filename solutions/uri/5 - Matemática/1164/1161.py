# Yuri Diego Santos Niitsuma
# 2011039023
# Soma de Fatoriais
# https://www.urionlinejudge.com.br/judge/pt/problems/view/1161


def fact(n):
    if n > 1:
        return n*fact(n - 1)
    else:
        return 1

try:
    while True:
        M, N = input().split()
        M, N = list(map(int, [M, N]))
        M = fact(M)
        N = fact(N)
        result = M + N
        print(result)
except:
    pass
