#include "biblioteca.h"

#define ARQUIVO_RANK "ranking.dat"

void salvar_ranking(T_Recorde* ranking)
{
    FILE* arquivo = fopen(ARQUIVO_RANK, "wb");

    if (arquivo)
    {
        T_Recorde* recorde = ranking;
        int tam_ranking = 0;

        while (recorde)
        {
            tam_ranking++;
            recorde = recorde->prox;

            if (tam_ranking == MAX_RECORDES)
                break;
        }

        fwrite(&tam_ranking, sizeof(int), 1, arquivo);

        recorde = ranking;
        tam_ranking = 0;

        while (recorde)
        {
            int tam_nome = strlen(recorde->nome)+1;

            fwrite(&tam_nome, sizeof(int), 1, arquivo);
            fwrite(recorde->nome, sizeof(char), tam_nome, arquivo);
            fwrite(&(recorde->pontuacao), sizeof(int), 1, arquivo);

            recorde = recorde->prox;
            tam_ranking++;

            if (tam_ranking == MAX_RECORDES)
                break;
        }

        fclose(arquivo);
    }
}

int posicao_recorde(T_Recorde* ranking, unsigned int pontuacao)
{
    int posicao = 0;

    if (ranking)
    {
        T_Recorde* recorde = ranking;

        while (recorde)
        {
            if (recorde->pontuacao < pontuacao)
                break;
            recorde = recorde->prox;
            posicao++;
        }
    }

    return posicao;
}

int numero_recorde(unsigned int pontuacao)
{
    int numero = 0;

    if (pontuacao > 0)
    {
        T_Recorde* ranking = obter_ranking();

        numero = 1;

        if (ranking)
        {
            numero = posicao_recorde(ranking, pontuacao)+1;

            if (numero > MAX_RECORDES)
                numero = 0;

            destruir_ranking(ranking);
        }
    }

    return numero;
}

void inserir_recorde(char* nome, unsigned int pontuacao)
{
    if (nome && pontuacao)
    {
        T_Recorde* ranking = NULL;
        int posicao = 0;

        ranking = obter_ranking();
        posicao = posicao_recorde(ranking, pontuacao);

        if (posicao < MAX_RECORDES)
        {
            T_Recorde* recorde = NULL;
            T_Recorde *ant = NULL, *aux = NULL;
            int idx = 0;

            recorde = malloc(sizeof(T_Recorde));
            recorde->nome = malloc((strlen(nome)+1) * sizeof(char));
            strcpy(recorde->nome, nome);
            recorde->pontuacao = pontuacao;
            recorde->prox = NULL;

            aux = ranking;
            for (idx = 0; idx < posicao; idx++)
            {
                ant = aux;
                aux = aux->prox;
            }

            if (aux)
                recorde->prox = aux;

            if (ant)
                ant->prox = recorde;
            else
                ranking = recorde;

            salvar_ranking(ranking);
        }

        if (ranking)
        {
            destruir_ranking(ranking);
        }
    }
}

T_Recorde* obter_ranking()
{
    T_Recorde* ranking = NULL;
    FILE* arquivo = NULL;

    arquivo = fopen(ARQUIVO_RANK, "rb");
    if (arquivo)
    {
        int qtd_recordes = 0;
        int idx;
        T_Recorde* ant = NULL;

        fread(&qtd_recordes, sizeof(int), 1, arquivo);
        for (idx = 0; idx < qtd_recordes; idx++)
        {
            int tam_nome = 0;
            T_Recorde* recorde = NULL;

            recorde = malloc(sizeof(T_Recorde));

            fread(&tam_nome, sizeof(int), 1, arquivo);
            recorde->nome = malloc(sizeof(char) * tam_nome);
            fread(recorde->nome, sizeof(char), tam_nome, arquivo);
            fread(&(recorde->pontuacao), sizeof(int), 1, arquivo);

            recorde->prox = NULL;
            if (ant)
            {
                ant->prox = recorde;
            }

            if (idx == 0)
            {
                ranking = recorde;
            }

            ant = recorde;
        }
    }

    return ranking;
}

void destruir_ranking(T_Recorde* ranking)
{
    if (ranking)
    {
        T_Recorde* prox = ranking->prox;

        while (ranking)
        {
            if (ranking->nome)
                free(ranking->nome);

            free(ranking);
            ranking = prox;

            if (prox)
                prox = ranking->prox;
        }
    }
}
