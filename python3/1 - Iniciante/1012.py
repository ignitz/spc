class Figura:
    name = ""
    def __init__(self, a, b, c):
        self.a = float(a)
        self.b = float(b)
        self.c = float(c)
    def area(self):
        return 0.0
    def print(self):
        return self.name + str(format(self.area(), '.3f'))

class Triangulo(Figura):
    name = "TRIANGULO: "
    def area(self):
        return self.a*self.c/2

class Circulo(Figura):
    name = "CIRCULO: "
    def area(self):
        a = self.a
        b = self.b
        c = self.c
        return 3.14159*c**2

class Trapezio(Figura):
    name = "TRAPEZIO: "
    def area(self):
        a = self.a
        b = self.b
        c = self.c
        return (a+b)*c/2

class Quadrado(Figura):
    name = "QUADRADO: "
    def area(self):
        a = self.a
        b = self.b
        c = self.c
        return b**2

class Retangulo(Figura):
    name = "RETANGULO: "
    def area(self):
        a = self.a
        b = self.b
        c = self.c
        return a*b

entrada = input().split()
figura1 = Triangulo(*entrada)
figura2 = Circulo(*entrada)
figura3 = Trapezio(*entrada)
figura4 = Quadrado(*entrada)
figura5 = Retangulo(*entrada)

print(figura1.print())
print(figura2.print())
print(figura3.print())
print(figura4.print())
print(figura5.print())
