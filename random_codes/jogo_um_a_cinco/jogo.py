#depois do pull request de jõao arthur esse é meu segundo, então me perdoa ai maria please se ficar errado
# esse jogo vai tentar adivinhar o numero que você está pensando
print('bem vindo meu nome é dado e eu vou tentar adivinhar um numero de 0 a 5 baseado em algumas perguntas')
print('   ')
print('todas as perguntas devem ser respondidas somente com s/n')
print('   ')
print('---------------')
print('   ')

resposta1 = input('para começar me diga, seu numero é divisível por 2? ')
if(resposta1 == 'n'):
    resposta2 = input('o seu número é primo? ')
    if(resposta2 == 'n'):
        resposta4 = input('seu número multiplicado por qualquer outro dá ele mesmo? ')
        if(resposta4 == 's'):
            print('seu número é o 0')
        if(resposta4 == 'n'):
            print('seu número é o 1')
    if(resposta2 == 's'):
        resposta3 = input('os multiplos do seu número sempre acabam em 0 e ele mesmo? ')
        if(resposta3 == 's'):
            print( 'seu número é o 5')
        if(resposta3 == 'n'):
            print('seu número é o 3')
if(resposta1 == 's'):
        resposta5 = input('seu número é especial pois apesar de ser par ele só tem dois divisores? ')
        if(resposta5 == 's'):
            print('seu número é o 2')
        if(resposta5 == 'n'):
            print('seu número é o 4')
print('   ')
print('   ')
print("-------------------")
print('muito obrigado por jogar!')
        
        
    