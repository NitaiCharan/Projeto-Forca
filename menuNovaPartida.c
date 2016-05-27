#include "biblioteca.h"
//Tratamento do menu principal e a escolha do usuário
char menuIniciar();
char escolhaMINP;


char NovaPartida(){
  escolhaMINP = menuIniciar();
  switch (escolhaMINP)
  {
    case '1':
    {
      break;
    }
    case '2':
    {
      break;
    }
  }
}


char menuIniciar()
{
  char escolhaMenu,i='0';//variavel para quardar escolha do usuário no menu
  do {
    LIMPATELA;
    printf("----------------------------\n");
    printf("       NOVA PARTIDA\n");
    printf("----------------------------\n\n");

    printf("1- UM JOGADOR\n");
    printf("2- DOIS JODADORES\n");
    printf("3- VOLTAR\n\n");

    if (i=='1') {
      printf("DESCULPE, A OPÇÃO DIGITADA É INVÁLIDA\n\n");
    }

    printf("OPÇÃO DESEJADA:");
    scanf("%c",&escolhaMenu);
    flush();

    if (escolhaMenu <'1' || escolhaMenu >'3')i='1';
  } while(escolhaMenu <'1' || escolhaMenu >'3');
  return escolhaMenu;
}
