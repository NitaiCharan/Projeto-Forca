#include "biblioteca.h"
char menuPrincipal();
#define true 1
#define false 0

void print_rpad(char* str, unsigned int columns);
void print_ranking(T_Recorde* ranking);

int main(int argc, char const *argv[]) {
  char escolhaMenu;
  char *strEscolhida=NULL;
  int doisJogadores=false;
  int jogoSalvo=true;
  char escolhaCNP='F';

  do {
    escolhaMenu=menuPrincipal();
    //selecionando escolhaMenu que é a escolha do usuário no menu
    switch (escolhaMenu) {

      case '1':
      {
        novaPartida();
        break;
      }
      case '2':
      {
        iniciarPartida(escolhaCNP,doisJogadores,strEscolhida,jogoSalvo);
        break;
      }
      case '3':
      {
        LIMPATELA;
        T_Recorde* ranking = NULL;
        ranking = obter_ranking();
        print_ranking(ranking);
        destruir_ranking(ranking);
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


void print_ranking(T_Recorde* ranking)
{
  printf("---------------------------\n");
  printf("           RANKING         \n");
  printf("---------------------------\n");

  if (ranking)
  {
    T_Recorde* recorde = ranking;
    int posicao = 1;

    while (recorde)
    {
      printf("#%02d %s", posicao++, recorde->nome);
      print_rpad(recorde->nome, 20);
      printf("%8u\n", recorde->pontuacao);

      recorde = recorde->prox;
    }
  }
  printf("\n");
  printf("Pressione enter para continuar...\n");
  getchar();
}

void print_rpad(char* str, unsigned int columns)
{
    int idx, len = columns - strlen(str);

    for (idx = 0; idx < len; idx++)
        printf(" ");
}
