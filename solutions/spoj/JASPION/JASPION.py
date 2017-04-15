#!/usr/bin/python3
# Yuri Diego Santos Niitsuma
# 2011039023
# http://br.spoj.com/problems/JASPION/
# JASPION

# Usei um dicionario com palavras aninhadas
# observe o "o galaxy" e "o pokemon"

# example da estrutura do dicionario
# {
#     'atsuki': 'alto que',
#     'kagayaku': 'canalha do',
#     'o': {
#         'galaxy': 'o cara tossiu',
#         'pokemon': 'temos que pegar',
#     },
#     'yuushi': 'util'
# }

import pprint

class Dicionary:

    def __init__(self, M, N):
        self.words = dict()
        self.M = M
        self.N = N
        pass

    def add_word(self, key, value):
        key = str(key).split(" ")
        if len(key) == 1:
            self.words[key.pop()] = value
        else:
            if key[0] not in self.words:
                aux = self.words[key[0]] = dict()
            else:
                aux = self.words[key[0]]

            del key[0]
            while len(key) > 1:
                if key[0] not in aux[key[0]]:
                    aux = aux[key[0]] = dict()
                else:
                    aux = aux[key[0]]
                del key[0]
            aux[key[0]] = value

    # Ler M linhas criando um dict associando cada palavra na traducao
    def generate_dict(self):
        for i in range(0, self.M):
            palavra_estrangeira = input()
            palavra_nativa = input()
            self.add_word(palavra_estrangeira, palavra_nativa)

    def generate_translation(self):
        for i in range(0, self.N):
            print(self.translate_line(input()))

    def translate_line(self, line):
        words = line.split(' ')
        response = ''
        aux = self.words
        original_text = ''

        while True:
            if words == []:
                if type(aux) == dict:
                    response += original_text
                elif type(aux) == str:
                    response += aux
                break
            else:
                if words[0] in aux:
                    aux = aux[words[0]]
                    original_text += words[0]
                else:
                    if type(aux) == dict:
                        response += original_text + ' '
                        aux = self.words
                        original_text = ''
                    elif type(aux) == str:
                        response += aux + ' '
                    aux = self.words
                    original_text = ''
                    continue
            del words[0]
        return response

    def print_all(self):
        pprint.pprint(self.words)

def test():
    M, N = list(map(int, input().split(" "))) # M e N
    dicionario = Dicionary(M, N)
    dicionario.generate_dict()
    dicionario.generate_translation()

def main():
    number_of_instances = int(input())
    for instance_number in range(0, number_of_instances):
        test()

if __name__ == '__main__':
    main()
