#include "biblioteca.h"

void verificaRanking(T_vetores *vetorUtilizado)
{
    int recorde;



    recorde = numero_recorde(vetorUtilizado->pontuacaoRanking);
    if (recorde > 0)
    {
        char nome[64] = {0};
        char nome1[64]={0};
        printf("\n\nParab�ns! Voc� quebrou o recorde #%d\n", recorde);
        printf("Qual � o seu nome? ");
        fgets(nome, (sizeof(char))*63, stdin);
        memcpy(nome1,nome,((strlen(nome))-1)*(sizeof(char)));
        
        inserir_recorde(nome1, vetorUtilizado->pontuacaoRanking);
    }
    else
    {
        printf("Voc� n�o quebrou um recorde :(\n");
    }
}
