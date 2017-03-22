def checkIntervalo(x):
    x = float(x)
    # ([0, 25], (25, 50], (50, 75], (75, 100])
    if 0.0 <= x <= 25.0:
        print('Intervalo [0,25]')
    elif 25.0 < x <= 50.0:
        print('Intervalo (25,50]')
    elif 50.0 < x <= 75.0:
        print('Intervalo (50,75]')
    elif 75.0 < x <= 100.0:
        print('Intervalo (75,100]')
    else:
        print('Fora de intervalo')

n = input()
checkIntervalo(n)

# a = 2.2 * 3.0
# b = 3.3 * 2.0

# checkIntervalo(25.01)
# checkIntervalo(25.00)
# checkIntervalo(100.00)
# checkIntervalo(-25.02)