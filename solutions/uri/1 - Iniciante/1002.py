pi = 3.14159

def area(radius):
    return format(pi*radius**2, '.4f')

radius = float(input())

print("A=", end="", flush=True)
print(area(radius))
