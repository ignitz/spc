#!python3

n = int(input())

for _ in range(n):
    string = input().split(" ")
    string.sort(key=len, reverse=True)
    output = ''
    for i in range(len(string)-1):
        output += string[i] + ' '
    output += string[-1]
    print(output)
