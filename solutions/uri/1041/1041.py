# Yuri Diego Santos Niitsuma
# 2011039023
# Coordenadas de um Ponto
# https://www.urionlinejudge.com.br/judge/pt/problems/view/1041

x , y = input().split()
x = float(x)
y = float(y)

if x == 0.0 and y == 0.0:
    print("Origem")
else:
    if x == 0.0:
        print("Eixo Y")
    elif y == 0.0:
        print("Eixo X")
    elif x > 0.0:
        if y > 0.0:
            print('Q1')
        else:
            print('Q4')
    else:
        if y > 0.0:
            print('Q2')
        else:
            print('Q3')