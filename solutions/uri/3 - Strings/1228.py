#!/usr/bin/python3
# Yuri Diego Santos Niitsuma
# 2011039023
# https://www.urionlinejudge.com.br/judge/pt/problems/view/1228
# Grid de Largada

class Race:
    def __init__(self):
        self.cars = []
        pass

    def append(self, car):
        self.cars.append(car);
        return car

    def get_car(self, i):
        return self.cars[i - 1]

    # A manteiga do meu pao
    # O que vai retornar o numero pedido do problema
    def get_valor_magico(self):
        size = len(self.cars)
        lista = [0] * size
        for car in self.cars:
            lista[car.get_pos_largada() - 1] = car.get_pos_chegada()

        # ordenar
        count = 0
        for i in range(0, size):
            for j in range(i + 1, size):
                if lista[j] < lista[i]:
                    aux = lista[j]
                    lista[j] = lista[i]
                    lista[i] = aux
                    count += 1
        return count

    def print_all(self):
        for car in self.cars:
            print(car.get_numero())
            print(car.get_pos_largada(), car.get_pos_chegada())

class Car:
    numero = None
    pos_largada = None
    pos_chegada = None

    def __init__(self, **kwargs):
        self.numero = kwargs.get('numero', None)

    def get_numero(self):
        return self.numero

    def set_pos_largada(self, pos):
        self.pos_largada = pos

    def set_pos_chegada(self, pos):
        self.pos_chegada = pos

    def get_pos_largada(self):
        return self.pos_largada

    def get_pos_chegada(self):
        return self.pos_chegada

def test(n):
    carros = Race()

    for i in range(1, n + 1):
        carros.append(Car(numero=i))

    pos_largada = list(map(int, input().split(" ")))
    i = 1
    for largada in pos_largada:
        car = carros.get_car(largada)
        car.set_pos_largada(i)
        i += 1

    pos_chegada = list(map(int, input().split(" ")))
    i = 1
    for chegada in pos_chegada:
        car = carros.get_car(chegada)
        car.set_pos_chegada(i)
        i += 1

    print(carros.get_valor_magico())

def main():
    try:
        while True:
            n = input()
            test(int(n))
    except:
        pass

if __name__ == '__main__':
    main()

