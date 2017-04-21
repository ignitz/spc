# Yuri Niitsuma
# 2011039023
# http://br.spoj.com/problems/CONTAGEM/
# CONTAGEM

'''
Se um 'b' é escolhido para fazer a transição entre
a parte de cima e a de baixo do autômato, o valor
do caminho é 2^r, onde r é o número de caracteres
(a's ou b's) depois do b escolhido. Não é difícil
ver isso: até a transição dita, o valor do caminho
é 1. Quando a transição é feita, cada aresta (ou seja,
cada caractere restante) dobra o valor do caminho.
Sendo assim, basta somar, para cada 'b' da palavra, 2^r.
'''

count = 1

while True:
    try:
        entrada = input()
    except:
        break

    soma = 0
    for i in range(len(entrada)):
        if entrada[i] == 'b':
            soma += 2**(len(entrada)-i-1)

    print('Palavra', count)
    count+=1
    print(soma, end="\n\n")
