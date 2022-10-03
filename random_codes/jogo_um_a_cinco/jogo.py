# depois do pull request de jõao arthur esse é meu segundo, então me perdoa ai maria please se ficar errado
# esse jogo vai tentar adivinhar o numero que você está pensando

SLASH_QTD = 15

print('Bem vindo meu nome é dado e eu vou tentar adivinhar um numero de 0 a 5 baseado em algumas perguntas', end='\n\n')
print('Todas as perguntas devem ser respondidas somente com s/n', end='\n\n')
print('-' * SLASH_QTD, end='\n\n')


def pergunta(texto):
    try:
        resposta = input(texto)
    except KeyboardInterrupt:
        print('Você interrompeu o jogo')
        exit()

    if resposta == 's':
        return True
    elif resposta == 'n':
        return False
    else:
        print('Resposta invalida! Tente novamente')
        return pergunta(texto)


resposta1 = pergunta('Para começar me diga, seu numero é divisível por 2? ')
if resposta1:
    resposta2 = pergunta(
        'Seu número é especial pois apesar de ser par ele só tem dois divisores? ')
    print('Seu número é o 2' if resposta2 else 'Seu número é o 4', end='\n\n')
else:
    resposta3 = pergunta('O seu número é primo? ')
    if resposta3:
        resposta4 = pergunta(
            'Os multiplos do seu número sempre acabam em 0 e ele mesmo? ')
        print('Seu número é o 5' if resposta4 else 'Seu número é o 3', end='\n\n')
    else:
        resposta5 = pergunta(
            'Seu número multiplicado por qualquer outro dá ele mesmo? ')
        print('Seu número é o 0' if resposta5 else 'Seu número é o 1', end='\n\n')


print('-' * SLASH_QTD, end='\n\n')
print('Muito obrigado por jogar!')
