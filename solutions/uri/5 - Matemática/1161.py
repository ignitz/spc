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
