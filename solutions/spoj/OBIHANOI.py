def solve_hanoi(n):
    # TODO
    # procedimento Hanoi(N, Orig, Dest, Temp)
    #    se N = 1 então
    #       mover o menor disco do pino Orig para o pino Dest;
    #    senão
    #       Hanoi(N-1, Orig, Temp, Dest);
    #       mover o N-ésimo menor disco do pino Orig para o pino Dest;
    #       Hanoi(N-1, Temp, Dest, Orig);
    #    fim-se
    # fim
    return 'Olha o n ' + str(n)

def __main__():
    while True:
        n = int(input())
        if n == 0:
            break
        print(solve_hanoi(n))

def __test__():
    entrada = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '0']
    entrada.reverse()
    while True:
        n = int(entrada.pop())
        if n == 0:
            break
        print(solve_hanoi(n))

# __main__()
__test__()
