# Forca

###Descrição
Deverá ser implementado, em linguagem C, um Jogo da Forca em linha de comando.
###Requisitos
O programa deverá exibir o seguinte menu principal:
```C
            ---------------------------
                  JOGO DA FORCA
            ---------------------------
              1- INICIAR PARTIDA
              2- CONTINUAR PARTIDA
              3- RANKING GERAL
              4- SAIR DO JOGO
  
              OPÇÃO DESEJADA:
```
Caso uma opção inválida seja digitada (diferente de 1, 2, 3 e 4), a mensagem “DESCULPE, A OPÇÃO DIGITADA É INVÁLIDA.” deverá ser exibida e novamente deverá ser aguardada a digitação de uma opção com a frase “OPÇÃO DESEJADA: “.

As opções deverão funcionar da seguinte forma:
##1. INICIAR NOVA PARTIDA
```C
            ---------------------------
                  NOVA PARTIDA
            ---------------------------
              1- UM JOGADOR
              2- DOIS JODADORES
              3- VOLTAR
  
              OPÇÃO DESEJADA:
```
###1.1. UM JOGADOR
Iniciar nova partida do Jogo da Forca, sorteando aleatoriamente uma palavra de acordo com o grau de dificuldade a ser configurado.
```C
            ---------------------------
                    DIFICULDADE
            ---------------------------
              F- FÁCIL
              D- DIFÍCIL
  
              OPÇÃO DESEJADA:
```
A dificuldade determinará o conjunto de palavras que serão utilizadas no sorteio da nova partida. As palavras que devem participar do sorteio são as seguintes (novas podem ser adicionadas):

* **Fácil**: melhor, grande, claro, azul, vermelho, preto, branco, casa, tempo, felicidade, bondade, vida, caneta, cavalo, trem, golpe, cosmos

* **Difícil**: procrastinar, prolegomenos, vicissitudes, pernostico, oprobrio, idiossincrasia, elucubracoes, chistoso, acrimonia, combustivel, concurso, protesto, governo, paquiderme, tamandare

O usuário terá 5 e 3 tentativas nos modos fácil e difícil, respectivamente. A interface da partida deverá ser como a ilustrada a seguir:
```C
            Letras já utilizadas:
            Palavra: _ _ _ _
            
            Entre uma letra (0 para sair). 5 tentativas restantes.
            > a
            
            Boa! A letra 'a' existe na palavra :)
            
            Letras já utilizadas: a
            Palavra: _ a _ a
            
            Entre uma letra (0 para sair). 5 tentativas restantes.
            > z

            A letra 'z' não existe na palavra :(

            Letras já utilizadas: a z
            Palavra: _ a _ a
            
            Entre uma letra (0 para sair). 4 tentativas restantes.
            >
```
Caso o jogador esgote o número de tentativas, deverá ser exibida uma mensagem como a seguir:

```C
            Letras já utilizadas: a z e f g
            Palavra: _ a _ a
            
            Entre uma letra (0 para sair). 1 tentativa restante.
            > x
            
            Letra 'x' não existe na palavra :(
            
            Jogo encerrado. Você perdeu. A palavra era 'casa'.
            Pressione enter para continuar...
```
Caso o usuário entre com uma letra já utilizada, deverá ser exibida uma mensagem como a seguir:

```C
            Letras já utilizadas: a z e f g
            Palavra: _ a _ a
            
            Entre uma letra (0 para sair). 1 tentativa restante.
            > e
            
            Letra 'e' já utilizada. Tente outra.
            
            Entre uma letra (0 para sair). 1 tentativa restante.
            >
```
Caso o usuário complete a palavra da partida, deverá ser exibida uma mensagem como a seguir:

```C
            Letras já utilizadas: a c
            Palavra: c a _ a
            
            Entre uma letra (0 para sair). 5 tentativas restantes.
            > s
            
            Boa! A letra 's' existe na palavra :)
            
            Parabéns! Você ganhou. A palavra era 'casa'.
            Pressione enter para continuar...
```
Caso o usuário entre com um valor que não seja uma letra minúscula de 'a' a 'z', deverá ser exibida uma mensagem como a seguir:

```C
            Letras já utilizadas: a c
            Palavra: c a _ a
            
            Entre uma letra (0 para sair). 5 tentativas restantes.
            > casa
            
            Oi? Isso não é uma letra.
            Entre uma letra (0 para sair). 1 tentativa restante.
            >
```
Caso o usuário entre com o valor 0, o usuário deverá ser questionado se deseja salvar o jogo para que possa continuar posteriormente, da seguinte forma:

```C
            Deseja salvar esta partida (S/N)?
            >
```

####Situações especiais:
1 – Quando o jogador acertar a palavra, uma pontuação deverá ser atribuída e uma nova palavra sorteada (não pode haver repetição). A pontuação de cada fase deverá ser calculada assim:
DIFICULDADE 1 * 1000 + TENTATIVAS_RESTANTES * 100

Fácil = 1 e Difícil = 2

2 – Quando não existirem palavras a sortear, a partida deverá ser encerrada, voltando para o menu inicial.
3 – Quando o jogo for encerrado (jogador errou a palavra ou não existirem mais palavras a sortear naquele nível de dificuldade), o jogo deverá verificar se a pontuação total do usuário o coloca dentro das 10 primeiras posições do ranking. Caso positivo, deverá ser solicitado o nome do jogador, desta forma:

```C
            É um novo recorde! Você está na posição no1 do ranking.
            Qual o seu nome?
            > Eduardo
```

###1.2. DOIS JOGADORES
Iniciar nova partida do Jogo da Forca, utilizando uma palavra digitada por um dos jogadores, da seguinte forma:

```C
            Entre com a palavra a ser utilizada nesta partida.
            > casa
```

Após a entrada da palavra, a tela deverá ser limpa e o jogo deve funcionar nos mesmos moldes da modalidade “um jogador”, porém sem a possibilidade de salvar a partida, fase e ranking.

##2. CONTINUAR PARTIDA
Esta opção só deverá ser exibida caso exista uma partida salva. Deverá carregar a partida do ponto exato onde o jogador havia parado (pontuação, palavras já utilizadas, letras, já utilizadas, tentativas restantes e etc).

##3. RANKING GERAL
Deverá exibir os 10 recordes de pontuação, da seguinte maneira:

```C
            ---------------------------
                      RANKING
            ---------------------------

			#01 Eduardo			   1000
            #02 Zezinho			    850
            #03 Luisinho			750
            #04 Huguinho			400
  
            Pressione enter para continuar...
```

Caso não existam recordes para exibir, deverá ser exibido:

```C
            ---------------------------
                      RANKING
            ---------------------------

			Nenhum registro a exibir.
  
            Pressione enter para continuar...
```
O ranking deverá ser persistido, de tal forma que seja mantido mesmo que o jogo seja encerrado.
##4. SAIR DO JOGO
Encerrar o jogo, fechando a aplicação.
