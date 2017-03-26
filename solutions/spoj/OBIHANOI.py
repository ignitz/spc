# Fonte: http://www.iceb.ufop.br/demat/perfil/arquivos/0.091292001363381611.pdf
import sys

def main(args):
    count = 1
    while True:
        n = int(input())
        if n == 0:
            break
        print('Teste ' + count.__str__())
        print(2 ** n - 1)
        count += 1

if __name__ == '__main__':
    main(sys.argv[1:])