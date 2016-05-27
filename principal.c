#include "biblioteca.h"
char menuPrincipal();


int main(int argc, char const *argv[]) {
  char escolhaMenu;

  do {
    escolhaMenu=menuPrincipal();
    //selecionando escolhaMenu que é a escolha do usuário no menu
    switch (escolhaMenu) {

      case '1':
      {
        NovaPartida();
        break;
      }
      case '2':
      {
        break;
      }
      case '3':
      {
        break;
      }

    }
  } while(escolhaMenu!='4');
  return 0;
}

//Tratamento do menu principal e a escolha do usuário
char menuPrincipal(){
  char escolhaMenu,i='0';//variavel para quardar escolha do usuário no menu
  do {
    LIMPATELA;
    printf("----------------------------\n");
    printf("       JOGO DA FORCA\n");
    printf("----------------------------\n\n");

    printf("1- INICIAR NOVA PARTIDA\n");
    printf("2- CONTINUAR PARTIDA\n");
    printf("3- RANKING GERAL\n");
    printf("4- SAIR DO JOGO\n\n");

    if (i=='1') {
      printf("DESCULPE, A OPÇÃO DIGITADA É INVÁLIDA\n\n");
    }

    printf("OPÇÃO DESEJADA:");
    scanf("%c",&escolhaMenu);
    flush();

    if (escolhaMenu <'1' || escolhaMenu >'4')i='1';
  } while(escolhaMenu <'1' || escolhaMenu >'4');

  return escolhaMenu;
}
