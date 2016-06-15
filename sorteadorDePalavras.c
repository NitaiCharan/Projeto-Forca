#include "biblioteca.h"
void geraRand(int qtd_palavras,T_vetores *vetorUtilizado,char dificuldade,int doisJogadores,char *);



void palavraDaVez(char dificuldade,T_vetores vetorUtilizado,int doisJogadores,char *strEscolhida)
{
  srand( (unsigned) time(NULL) );//criação da semente para o rand() com o tempo tatual
  if (dificuldade=='F')geraRand(17,&vetorUtilizado,dificuldade,doisJogadores,strEscolhida);
  else geraRand(15,&vetorUtilizado,dificuldade,doisJogadores,strEscolhida);

}

void geraRand(int qtd_palavras,T_vetores *vetorUtilizado,char dificuldade,int doisJogadores,char *strEscolhida)
{
  char facil[][11] = {"melhor", "grande", "claro", "azul", "vermelho","preto", "branco", "casa", "tempo", "felicidade", "bondade", "vida","caneta", "cavalo", "trem", "golpe", "cosmos"};
  char dificil[][17] = {"procrastinar", "prolegomenos", "vicissitudes", "pernostico", "oprobrio", "idiossincrasia", "elucubracoes", "chistoso", "acrimonia", "combustivel", "concurso", "protesto", "governo", "paquiderme", "tamandare"};

  int saida=0;

  if(doisJogadores)
  {
    vetorUtilizado->palavraEscolhida=realloc(vetorUtilizado->palavraEscolhida,(1+strlen(strEscolhida))*sizeof(char));
    memcpy(vetorUtilizado->palavraEscolhida,strEscolhida,(sizeof(char)*(strlen(strEscolhida)+1)));

    vetorUtilizado->letrasAcertadasComparacao=realloc(vetorUtilizado->letrasAcertadasComparacao,((strlen(vetorUtilizado->palavraEscolhida)+1) * sizeof(char)));
    vetorUtilizado->letrasAcertadasComparacao[strlen(vetorUtilizado->palavraEscolhida)+1]=0;

    vetorUtilizado->numerosRandomicos[(vetorUtilizado->randomicoDaVez)-1]=0;
  }

  else if (!doisJogadores)
  {
    do
    {

      int idx2=0;
      int randomico=rand()%(qtd_palavras);
      for (idx2=0;idx2<vetorUtilizado->randomicoDaVez;idx2++)
      {
        if (vetorUtilizado->numerosRandomicos[idx2]==randomico)
        {
          idx2=0;
          randomico=rand()%(qtd_palavras);
        }
      }

      if(idx2==vetorUtilizado->randomicoDaVez)
      {
        if (dificuldade=='F')
        {
          vetorUtilizado->palavraEscolhida=realloc(vetorUtilizado->palavraEscolhida,(1+strlen(facil[randomico+1]))*(sizeof(char)));
          strcpy(vetorUtilizado->palavraEscolhida,facil[randomico]);
          vetorUtilizado->palavraEscolhida[strlen(vetorUtilizado->palavraEscolhida)+1]=0;

        }
        else if(dificuldade=='D')
        {
          vetorUtilizado->palavraEscolhida=realloc(vetorUtilizado->palavraEscolhida,strlen(dificil[randomico]+1)*(sizeof(char)));
          strcpy(vetorUtilizado->palavraEscolhida,dificil[randomico]);
          vetorUtilizado->palavraEscolhida[strlen(vetorUtilizado->palavraEscolhida)+1]=0;
        }
        vetorUtilizado->letrasAcertadasComparacao=realloc(vetorUtilizado->letrasAcertadasComparacao,((strlen(vetorUtilizado->palavraEscolhida)+1) * sizeof(char)));
        vetorUtilizado->letrasAcertadasComparacao[strlen(vetorUtilizado->palavraEscolhida)+1]=0;
        memset(vetorUtilizado->letrasAcertadasComparacao,0,(strlen(vetorUtilizado->palavraEscolhida)+1)*(sizeof(char)));

        vetorUtilizado->numerosRandomicos[(vetorUtilizado->randomicoDaVez)-1]=randomico;
        saida=qtd_palavras;
      }
    } while(saida<qtd_palavras);
  }
}
