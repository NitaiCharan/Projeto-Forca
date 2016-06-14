#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define true 1
#define false 0
#define demo 666
typedef struct
{
  char *palavraEscolhida;
  char *letrasUtilizadas;
  char *letrasAcertadasComparacao;
  int *numerosRandomicos;
  char letrasAcertadas[41];
  int randomicoDaVez;
  int errou;
} T_vetores;


void flush();//Procedimento para tratar comparações em CHAR
void novaPartida();
void iniciarPartida(char ,int,char*,int);
void retornoJogoSalvo(T_vetores *vetorUtilizado);
void salvarJogo(T_vetores *vetorUtilizado);
void iniciavetors(T_vetores *vetorUtilizado,int *idxVerificacao);
void finalizavetors(T_vetores *vetorUtilizado);
void verificaPalavras(int quantidade,T_vetores * vetorUtilizado,int doisJogadores);



#if defined(_WIN32) || defined(WIN32)
#define LIMPATELA system("cls")
#else
#define LIMPATELA system("clear")
#endif
