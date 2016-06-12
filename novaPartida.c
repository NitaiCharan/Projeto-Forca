#include "biblioteca.h"
#define true 1
#define false 0
//Tratamento do menu principal e a escolha do usuário
char menuIniciar();
char menuDificuldade();
char escolhaNP,escolhaCNP;//variavel que vai conter escolhas do do Menu Nova Partida

void novaPartida()
{
  int doisJogadores;

  escolhaNP = menuIniciar();

  char *strEscolhida=NULL;

  switch (escolhaNP)
  {
    case '1':
    {
      doisJogadores = false;
      escolhaCNP=menuDificuldade();
      iniciarPartida(escolhaCNP,doisJogadores,strEscolhida);
      break;
    }
    case '2':
    {
      doisJogadores = true;
      char strJogadores[30];
      printf("\nEntre com a palavra a ser utilizada nesta partida.\n>");
      fgets(strJogadores,(sizeof(char))*30,stdin);
      strJogadores[strlen(strJogadores)-1]=0;

      strEscolhida=malloc((sizeof(char))*(strlen(strJogadores)+1));
      memcpy(strEscolhida,strJogadores,(sizeof(char))*(strlen(strJogadores)+1));

      iniciarPartida('F',doisJogadores,strEscolhida);
      break;
    }
  }
}


char menuIniciar()
{
  char escolha='1';//variavel para quardar escolha do usuário no menu
  do {
    LIMPATELA;
    printf("----------------------------\n");
    printf("       NOVA PARTIDA\n");
    printf("----------------------------\n\n");

    printf("1- UM JOGADOR\n");
    printf("2- DOIS JODADORES\n");
    printf("3- VOLTAR\n\n");

    if (escolha <'1' || escolha >'3') {
      printf("DESCULPE, A OPÇÃO DIGITADA É INVÁLIDA\n\n");
    }

    printf("OPÇÃO DESEJADA:");
    scanf("%c",&escolha);
    flush();

  } while(escolha <'1' || escolha >'3');
  return escolha;
}
char menuDificuldade()
{
  char escolha,i='0';//variavel para quardar escolha do usuário no menu
  do {
    LIMPATELA;
    printf("----------------------------\n");
    printf("       DIFICULDADE\n");
    printf("----------------------------\n\n");

    printf("F- FÁCIL\n");
    printf("D- DIFÍCIL\n\n");

    if (i=='1') {
      printf("DESCULPE, A OPÇÃO DIGITADA É INVÁLIDA\n\n");
    }

    printf("OPÇÃO DESEJADA:");
    scanf("%c",&escolha);
    flush();

    if (escolha !='F' && escolha !='D')i='1';
  } while(escolha !='F' && escolha !='D');
  return escolha;
}
