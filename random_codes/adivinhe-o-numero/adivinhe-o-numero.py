import random

print('Adivinhe o número aleatório. Digite exit para sair do jogo.\n')

while True:

    print('Escolha o intervalo do número.')

    min = int(input('Insira o número mínimo: '))
    max = int(input('Insira o número máximo: '))

    if (min > max):
        print('Entrada errada!')
        break

    print('')
    rand_num = random.randint(min, max)
    tentativas = 0

    while True:

        entrada = input('Insira um número: ')
    
        if entrada == 'exit':
            break
    
        tentativas += 1
        user_num = int(entrada)

        if rand_num < user_num:
            print('Você errou, o número é menor do que o seu')
        elif rand_num > user_num:
            print('Você errou, o número é maior do que o seu')
        else:
            print('Parabéns, você acertou!')
            break
    
    print('Partida acabada. Número de tentativas: ' + str(tentativas) + '\n')
    entrada = input('Quer jogar novamente (s/n)? ')

    if entrada == 's':
        print('\nNova partida:')
    else:
        break