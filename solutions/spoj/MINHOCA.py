def __main__():
    pass

def __test__(entrada):
    # Passo 1 construir matriz
    matrix = [] # (linha, coluna) começa em zero

    M, N = list(map(int, entrada[0]))

    for line_num in range(1, M + 1):
        line = list(map(int, entrada[line_num]))

    # Passo 2, fazer o que quer que faça... i have no idea what i'm doing
    # TODO

# __main__()
__test__(
    [
        ['3', '4'],
        ['81', '28', '240', '10'],
        ['40', '10', '100', '240'],
        ['20', '180', '110', '35'],
    ])
__test__(
    [
        ['4', '1'],
        ['100'],
        ['110'],
        ['0'],
        ['100'],
    ])
