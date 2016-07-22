def maiorAB(a, b):
    return int((a + b + abs(a - b))/2)

entrada = input().split()
a, b, c = entrada
a = maiorAB(int(a), int(b))
a = maiorAB(a, int(c))
print(a, "eh o maior")