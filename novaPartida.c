#include "biblioteca.h"
#define true 1
#define false 0
//Tratamento do menu principal e a escolha do usu√°rio
char menuIniciar();
char menuDificuldade();
char escolhaNP,escolhaCNP;//variavel que vai conter escolhas do do Menu Nova Partida

void novaPartida()
{
  char escolhaCNP='F'; //escolha da dificuldade
  int doisJogadores; //vari·vel de controle: para saber se È uma partida de dois jogadores ou n„o
  int jogoSalvo=false; //vari·vel de controle: para saber se o jogo foi salvo ou n„o

  escolhaNP = menuIniciar(); //a funÁ„o 'menuIniciar' retorna a escolha do usu·rio no menu de nova partida

  char *strEscolhida=NULL; //vetor que vai guardar a palavra da vez alocado dinamicamente

  switch (escolhaNP)
  {
    case '1': //se a opÁ„o for 'UM JOGADOR'
    {
      doisJogadores = false;
      escolhaCNP=menuDificuldade();
      iniciarPartida(escolhaCNP,doisJogadores,strEscolhida,jogoSalvo);
      break;
    }
    case '2': //se a opÁ„o for 'DOIS JOGADORES'
    {
      doisJogadores = true;
      char strJogadores[30]; //vetor que guarda temporariamente a palavra que o usu·rio digitar·
      printf("\nEntre com a palavra a ser utilizada nesta partida.\n>");
      fgets(strJogadores,(sizeof(char))*30,stdin); //recebe a palavra
      strJogadores[strlen(strJogadores)-1]=0; //coloca terminador nulo para que n„o pegue a quebra de linha

      strEscolhida=malloc((sizeof(char))*(strlen(strJogadores)+1)); //aloca dinamicamente o vetor que guardar· a palavra durante a partida
      memcpy(strEscolhida,strJogadores,(sizeof(char))*(strlen(strJogadores)+1)); //passa o que foi digitado pro vetor alocado dinamicamente


      iniciarPartida(escolhaCNP,doisJogadores,strEscolhida,jogoSalvo); //chama a funÁ„o de iniciar partida
      break;
    }
  }
}


char menuIniciar()
{
  char escolha='1';//variavel para quardar escolha do usu√°rio no menu
  do {
    LIMPATELA;
    printf("----------------------------\n");
    printf("       NOVA PARTIDA\n");
    printf("----------------------------\n\n");

    printf("1- UM JOGADOR\n");
    printf("2- DOIS JODADORES\n");
    printf("3- VOLTAR\n\n");

    if (escolha <'1' || escolha >'3') {
      printf("DESCULPE, A OP√á√ÉO DIGITADA ÔøΩ INVÔøΩLIDA\n\n");
    }

    printf("OP√á√ÉO DESEJADA:");
    scanf("%c",&escolha);
    flush();

  } while(escolha <'1' || escolha >'3');
  return escolha;
}
char menuDificuldade()
{
  char escolha,i='0';//variavel para quardar escolha do usu√°rio no menu
  do {
    LIMPATELA;
    printf("----------------------------\n");
    printf("       DIFICULDADE\n");
    printf("----------------------------\n\n");

    printf("F- F√ÅCIL\n");
    printf("D- DIF√çCIL\n\n");

    if (i=='1') {
      printf("DESCULPE, A OP√á√ÉO DIGITADA ÔøΩ INVÔøΩLIDA\n\n");
    }

    printf("OP√á√ÉO DESEJADA:");
    scanf("%c",&escolha);
    flush();

    if (escolha !='F' && escolha !='D')i='1';
  } while(escolha !='F' && escolha !='D');
  return escolha;
}
