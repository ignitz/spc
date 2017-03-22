# Leia um valor inteiro N que é o tamanho da matriz que deve ser impressa conforme o modelo fornecido.
# Entrada
# A entrada contém vários casos de teste e termina com EOF. Cada caso de teste é composto por um único inteiro N (3 ≤ N < 70), que determina o tamanho (linhas e colunas) de uma matriz que deve ser impressa.
# Saída
# Para cada N lido, apresente a saída conforme o exemplo fornecido.

def make_matrix(n):
    matrix = []
    # All 3
    for i in range(0, n):
        line = []
        for j in range(0, n):
            line.append(3)
        matrix.append(line)
    # put 1's and 2's
    for i in range(0, n):
        matrix[i][i] = 1
        matrix[i][n - i - 1] = 2

    return matrix

def __main__():
    try:
        while True:
            n = int(input())
            matrix = make_matrix(n)
            for line_num in range(0, n):
                print(''.join(str(index) for index in matrix[line_num]))
    except:
        pass

__main__()
