#include "biblioteca.h"
char menuPrincipal();
#define true 1
#define false 0

void print_rpad(char* str, unsigned int columns);
void print_ranking(T_Recorde* ranking);

int main(int argc, char const *argv[]) {
  char escolhaMenu; //guarda a opÁ„o escolhida pelo usu·rio
  char *strEscolhida=NULL; //vai guardar a palavra da vez
  int doisJogadores=false;
  int jogoSalvo=true;
  char escolhaCNP='F';

  setlocale(LC_ALL,""); //funÁ„o para aparecer acentos nas palavras.

  do {
    escolhaMenu=menuPrincipal();
    //selecionando escolhaMenu que È a escolha do usu·rio no menu
    switch (escolhaMenu) {

      case '1': //se a escolha for 'iniciar nova partida'
      {
        novaPartida();
        break;
      }
      case '2': //se a escolha for 'continuar partida'
      {
        iniciarPartida(escolhaCNP,doisJogadores,strEscolhida,jogoSalvo);
        break;
      }
      case '3': //se a escolha for 'ranking'
      {
        LIMPATELA;
        T_Recorde* ranking = NULL;
        ranking = obter_ranking(); //funÁ„o 'obter_ranking' retorna uma estrutura de dados 'T_Recorde'
        print_ranking(ranking); //funÁ„o que imprime o ranking na tela
        destruir_ranking(ranking); //funÁ„o que destrÛi um ranking obtido em 'obter_ranking'
        break;
      }

    }
  } while(escolhaMenu!='4'); //se o usu·rio escolher a opÁ„o 4, ele quer sair do jogo, ent„o quebra o 'do while'
  return 0;
}

//Tratamento do menu principal e a escolha do usuÔøΩrio
char menuPrincipal(){
  char escolhaMenu,i='0';//variavel para quardar escolha do usuÔøΩrio no menu
  do {
    LIMPATELA;
    printf("----------------------------\n");
    printf("       JOGO DA FORCA\n");
    printf("----------------------------\n\n");

    printf("1- INICIAR NOVA PARTIDA\n");
    printf("2- CONTINUAR PARTIDA\n");
    printf("3- RANKING GERAL\n");
    printf("4- SAIR DO JOGO\n\n");

    if (i=='1')
    {
      printf("DESCULPE, A OP√á√ÉO DIGITADA √â INV√ÅLIDA\n\n");
    }

    printf("OP√á√ÉO DESEJADA:");
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

  if (ranking) //se existir um ranking - estrutura de dados salva num arquivo
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

  else //se n„o existir um ranking salvo
  {
    printf("\nNenhum registro a exibir.\n");
  }

  printf("\n");
  printf("Pressione enter para continuar...\n");
  getchar();
}

void print_rpad(char* str, unsigned int columns) //formatar a impress„o do ranking
{
    int idx, len = columns - strlen(str);

    for (idx = 0; idx < len; idx++)
        printf(" ");
}
