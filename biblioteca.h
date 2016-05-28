#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


void flush();//Procedimento para tratar comparações em CHAR
char novaPartida();
void iniciarPartida(char);

#if defined(_WIN32) || defined(WIN32)
#define LIMPATELA system("cls")
#else
#define LIMPATELA system("clear")
#endif
