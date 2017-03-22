class Esfera:
    def __init__(self, radius):
        self.radius = float(radius)

    def volume(self):
        return (4.0/3.0)*3.14159*(self.radius)**3

esfera = Esfera(input())
print("VOLUME =", format(esfera.volume(), '.3f'))
