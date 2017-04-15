# Yuri Diego Santos Niitsuma
# 2011039023
# http://br.spoj.com/problems/POPULAR/
# POPULAR

while True:
    try:
        n = int(input())
    except:
        break
    if n == 0:
        break
    sum_vec = [0] * n

    for i in range(n):
        linha = list(map(int, input().split(" ")))
        sum_vec = [x + y for x, y in zip(sum_vec, linha)]

    print(max(sum_vec))
