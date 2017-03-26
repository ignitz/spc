# Yuri Diego Santos Niitsuma
# 2011039023
# Maior e Posição
# https://www.urionlinejudge.com.br/judge/pt/problems/view/1080

max_number = (0, None)

for i in range(0, 100):
    x = int(input())
    if x > max_number[0]:
        max_number = (x, i + 1)

print(max_number[0])
print(max_number[1])
