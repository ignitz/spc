def media(a, b, c):
    x = (a*2.0 + b*3.0 + c*5.0)/10
    return format(x, '.1f')

a = float(input())
b = float(input())
c = float(input())
x = media(a, b, c)
print("MEDIA =", x)