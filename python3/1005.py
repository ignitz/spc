def media(a, b):
    x = (a*3.5 + b*7.5)/11
    return format(x, '.5f')

a = float(input())
b = float(input())
x = media(a, b)
print("MEDIA =", x)