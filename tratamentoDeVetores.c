#include"biblioteca.h"

void iniciavetores(T_vetores *vetorUtilizado,int *idxVerificacao) //função que inicia os vetores da estrutura de dados
{
  //alocar dinamicamente os vetores
  vetorUtilizado->palavraEscolhida=malloc(sizeof(char));
  vetorUtilizado->letrasUtilizadas=malloc(sizeof(char));
  vetorUtilizado->letrasAcertadasComparacao=malloc(sizeof(char));

  //preencher com 0 o vetor de letrasUtilizadas
  memset(vetorUtilizado->letrasUtilizadas,0,strlen(vetorUtilizado->letrasUtilizadas)*(sizeof(char)));

  //preencher com _ as letrasAcertadas
  strcpy(vetorUtilizado->letrasAcertadas, "________________________________________");
  
  //zerar as variáveis de controle
  *idxVerificacao=0;
  vetorUtilizado->errou=0;
}

void finalizavetores(T_vetores *vetorUtilizado) 
{
  //função que dá um free nos vetores que foram alocados dinamicamente
  free(vetorUtilizado->palavraEscolhida);
  free(vetorUtilizado->letrasUtilizadas);
  free(vetorUtilizado->letrasAcertadasComparacao);
}
