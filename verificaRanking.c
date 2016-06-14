#include "biblioteca.h"

void verificaRanking(T_vetores *vetorUtilizado,char dificuldade)
{
    unsigned int pontuacao;
    int recorde;
    int pontuacaoDificuldade;
    int valorErrou;

    if (dificuldade=='F'){
      pontuacaoDificuldade=1;
      valorErrou = 4;
    }
    else
    {
      pontuacaoDificuldade=2;
      valorErrou = 6;
    }
    pontuacao=(pontuacaoDificuldade * 100) + ((vetorUtilizado->errou+valorErrou) * 100);


    recorde = numero_recorde(pontuacao);
    if (recorde > 0)
    {
        char nome[64];
        printf("\n\nParabéns! Você quebrou o recorde #%d\n", recorde);
        printf("Qual é o seu nome? ");
        scanf("%s", nome);
        inserir_recorde(nome, pontuacao);
    }
    else
    {
        printf("Você não quebrou um recorde :(\n");
    }
}
