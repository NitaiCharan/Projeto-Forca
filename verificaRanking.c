#include "biblioteca.h"

void verificaRanking(T_vetores *vetorUtilizado)
{
    int recorde;



    recorde = numero_recorde(vetorUtilizado->pontuacaoRanking);
    if (recorde > 0)
    {
        char nome[64] = {0};
        char nome1[64]={0};
        printf("\n\nÉ um novo recorde! Você está na posição nº%d do ranking.\nQual é o seu nome? ", recorde);
        fgets(nome, (sizeof(char))*63, stdin);
        memcpy(nome1,nome,((strlen(nome))-1)*(sizeof(char)));

        inserir_recorde(nome1, vetorUtilizado->pontuacaoRanking);
    }
}
