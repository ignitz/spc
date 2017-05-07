a, b = input().split()
a, b = (int(a), int(b))

if a < b:
    temp = a
    a = b
    b = temp

if divmod(a, b)[1] == 0:
    print('Sao Multiplos')
else:
    print('Nao sao Multiplos')
