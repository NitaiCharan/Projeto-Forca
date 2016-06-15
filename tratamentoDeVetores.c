#include"biblioteca.h"

void iniciavetores(T_vetores *vetorUtilizado,int *idxVerificacao)
{
  vetorUtilizado->palavraEscolhida=malloc(sizeof(char));
  vetorUtilizado->letrasUtilizadas=malloc(sizeof(char));
  vetorUtilizado->letrasAcertadasComparacao=malloc(sizeof(char));

  memset(vetorUtilizado->letrasUtilizadas,0,strlen(vetorUtilizado->letrasUtilizadas)*(sizeof(char)));

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
