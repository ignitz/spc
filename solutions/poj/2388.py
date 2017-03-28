# Yuri Diego Santos Niitsuma
# 2011039023
# Link: http://poj.org/problem?id=2388

#!/usr/bin/python3

def get_mediana(list):
    length = len(list)
    mid = divmod(length, 2)[0]
    if length % 2:
        return list[mid]
    else:
        return divmod(list[mid] + list[mid-1], 2)[0]

def main():
    n = int(input())
    list = []

    for i in range(0, n):
        list.append(int(input()))

    list.sort()
    print(get_mediana(list))


if __name__ == '__main__':
    main()
