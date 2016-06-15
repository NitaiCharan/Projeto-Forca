#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#define true 1
#define false 0
#define demo 666
#define MAX_RECORDES 10
typedef struct
{
  char *palavraEscolhida;
  char *letrasUtilizadas;
  char *letrasAcertadasComparacao;
  int *numerosRandomicos;
  char letrasAcertadas[41];
  int randomicoDaVez;
  int errou;
  long unsigned int pontuacaoRanking;
} T_vetores;

typedef struct S_Recorde
{
    char* nome;
    unsigned int pontuacao;
    struct S_Recorde* prox;
} T_Recorde;



/* Retorna 0 se não for recorde ou número de 1 a MAX_RECORDES */
int numero_recorde(unsigned int pontuacao);

/* Adiciona um recorde no ranking */
void inserir_recorde(char* nome, unsigned int pontuacao);

/* Retorna ponteiro para primeiro recorde e quantidade de recordes em qtd */
T_Recorde* obter_ranking();

/* Destrói um ranking obtido em obter_ranking */
void destruir_ranking(T_Recorde* ranking);


void flush();//Procedimento para tratar comparações em CHAR
void novaPartida();
void iniciarPartida(char ,int,char*,int);
void retornoJogoSalvo(T_vetores *vetorUtilizado);
void salvarJogo(T_vetores *vetorUtilizado);
void iniciavetores(T_vetores *vetorUtilizado,int *idxVerificacao);
void finalizavetores(T_vetores *vetorUtilizado);
void verificaRanking(T_vetores * vetorUtilizado);


#if defined(_WIN32) || defined(WIN32)
#define LIMPATELA system("cls")
#else
#define LIMPATELA system("clear")
#endif
