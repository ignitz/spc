# Condicao insuficiente

def main():
    while True:
        n = int(input())
        if n == 0:
            break
        sum_of_shit = 0
        for i in range(n):
            sum_of_shit += sum(list(map(int, input().split(" "))))

        if sum_of_shit % 3 == 0:
            print(1)
        else:
            print(0)

if __name__ == '__main__':
    main()
