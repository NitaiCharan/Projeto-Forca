#include"biblioteca.h"

void iniciavetores(T_vetores *vetorUtilizado,int *idxVerificacao)
{
  vetorUtilizado->palavraEscolhida=malloc(sizeof(char)*80);
  vetorUtilizado->letrasUtilizadas=malloc(sizeof(char)*80);
  vetorUtilizado->letrasAcertadasComparacao=malloc(sizeof(char)*80);
  memset(vetorUtilizado->palavraEscolhida,0,strlen(vetorUtilizado->palavraEscolhida)*(sizeof(char)));
  memset(vetorUtilizado->letrasAcertadasComparacao,0,strlen(vetorUtilizado->letrasAcertadasComparacao)*(sizeof(char)));
  memset(vetorUtilizado->letrasUtilizadas,0,strlen(vetorUtilizado->letrasUtilizadas)*(sizeof(char)));
  memset(vetorUtilizado->letrasUtilizadas,' ',strlen(vetorUtilizado->letrasUtilizadas)*(sizeof(char)));
  strcpy(vetorUtilizado->letrasAcertadas, "________________________________________");
  *idxVerificacao=0;
  vetorUtilizado->errou=0;
}

void finalizavetores(T_vetores *vetorUtilizado)
{
  free(vetorUtilizado->palavraEscolhida);
  free(vetorUtilizado->letrasUtilizadas);
  free(vetorUtilizado->letrasAcertadasComparacao);
}
