#função que inverte a lista para apresentar o resultado em ordem correta
def inversor(lista):
    resposta = []
    tam = len(lista) - 1

    while tam >= 0:
        resposta.append(lista[tam])
        tam -= 1

    return resposta

# Transforma valores maiores que dez em algarismos doaalfabeto
def simbola(lista, tip):
    base = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

    if tip == 'cod':
        for i in range(len(lista)):
            if lista[i] > 9:
                lista[i] = base[ lista[i]-10 ]

    elif tip == 'decod':
        for i in range(len(lista)):
            if lista[i] in base:
                lista[i] = base.index(lista[i]) + 10

    return lista

# Transforma de qualquer base para decimal
def pDec(num, bEntrada):
    manipulacao = []
    stringNum = str(num)

    if bEntrada > 10:
        temp = simbola(list(stringNum), 'decod')
        for i in temp:
            manipulacao.append(int(i))
    else:
        for i in stringNum:
            manipulacao.append(int(i))

    ctrl = len(manipulacao) - 1
    pot = 0
    while ctrl >= 0:
        manipulacao[ctrl] = manipulacao[ctrl] * (bEntrada**pot)
        pot += 1
        ctrl -= 1

    saida = 0
    for i in manipulacao:
        saida = saida + i

    print(saida)
    return saida

def dDec(decimal, bSaida):
    resultado = []
    decimal = int(decimal)
    bSaida = int(bSaida)

    while decimal > bSaida-1:
        add = decimal % bSaida
        resultado.append(add)
        decimal = int(decimal/bSaida)
    
    if bSaida == 2:
        resultado.append(1)
    else:
        resultado.append(decimal)

    saida = simbola(inversor(resultado), 'cod')

    print(f'Em base {bSaida}: {saida}')
    print()

conversor = {
    'para': pDec,
    'de': dDec
}


print(
    """ Conversor yoyo, v2.0.0.
    INSTRUÇÕES:
    Digite no terminal a base do número que será convertido (2,3,4,5 ... 35)
    seguida da base do número para o qual se
    quer converter.
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    Exemplo:
    Para converter um numero de decimal para binário digite:
    > $ 10 2
    
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    
    Conversões de quaisquer bases entre 2 e 35
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
"""
)


while True:
    print()
    print('insira, respectivamente, as bases de partida e de chegada: ')
    partida, chegada = input().split()
    print()

    if partida != '10' and chegada == '10':
        conversor['para'](input('Insira o número a ser transformado: '), int(partida))

    elif partida != '10' and chegada != '10':
        a = conversor['para'](input('Insira o número a ser transformado: '), 10)
        conversor['de'](int(a), int(chegada))
    else:
        conversor['de'](input('Insira o número a ser transformado: '), int(chegada))