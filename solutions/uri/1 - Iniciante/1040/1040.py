def convertFloat(param):
    return float(param)

def mediaPond(*args):
    total = 0.0
    total = 2 * args[0] + 3 * args[1] + 4 * args[2] + 1 * args[3]
    return total/(10)

# entrada = '9.0 4.0 8.5 9.0'.split()
entrada = input().split()

notas = list((map(convertFloat, entrada)))

mediaAluno = round(mediaPond(*notas),1)

print("Media:", format(mediaAluno, '.1f'))

if mediaAluno >= 7.0:
    print("Aluno aprovado.")
elif 5.0 <= mediaAluno < 7.0:
    print("Aluno em exame.")
    entrada = input()
    print("Nota do exame:", entrada)
    entrada = float(entrada)
    mediaAluno = (mediaAluno + entrada)/2
    if mediaAluno >= 5.0:
        print("Aluno aprovado.")
    else:
        print("Aluno reprovado.")
    print("Media final:", format(mediaAluno, '.1f'))
else:
    print("Aluno reprovado.")