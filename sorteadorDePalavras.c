#include "biblioteca.h"
void geraRand(int qtd_palavras,T_vetores *vetorUtilizado,char dificuldade,int doisJogadores,char *);


/*função responsável por chamar a função geraRand que vai sortear as palavras de acordo com a dificuldade*/
void palavraDaVez(char dificuldade,T_vetores vetorUtilizado,int doisJogadores,char *strEscolhida) 
{
  srand( (unsigned) time(NULL) );//criação da semente para o rand() com o tempo atual
  if (dificuldade=='F')geraRand(17,&vetorUtilizado,dificuldade,doisJogadores,strEscolhida); //de acordo com a dificuldade, passa a qtd de palavras
  else geraRand(15,&vetorUtilizado,dificuldade,doisJogadores,strEscolhida);

}

void geraRand(int qtd_palavras,T_vetores *vetorUtilizado,char dificuldade,int doisJogadores,char *strEscolhida)
{
  char facil[][11] = {"melhor", "grande", "claro", "azul", "vermelho","preto", "branco", "casa", "tempo", "felicidade", "bondade", "vida","caneta", "cavalo", "trem", "golpe", "cosmos"};
  char dificil[][17] = {"procrastinar", "prolegomenos", "vicissitudes", "pernostico", "oprobrio", "idiossincrasia", "elucubracoes", "chistoso", "acrimonia", "combustivel", "concurso", "protesto", "governo", "paquiderme", "tamandare"};

  int saida=0;

  if(doisJogadores) //se forem dois jogadores
  {
    vetorUtilizado->palavraEscolhida=realloc(vetorUtilizado->palavraEscolhida,(1+strlen(strEscolhida))*sizeof(char)); //realoca a palavra escolhida pro tamanho da palavra que o usuário digitou em srtEscolhida
    memcpy(vetorUtilizado->palavraEscolhida,strEscolhida,(sizeof(char)*(strlen(strEscolhida)+1))); //copia pra palavraEscolhida o que o usuário digitou

    vetorUtilizado->letrasAcertadasComparacao=realloc(vetorUtilizado->letrasAcertadasComparacao,((strlen(vetorUtilizado->palavraEscolhida)+1) * sizeof(char))); //realoca o vetor que guarda a palavra que for formada mediante as tentativas do usuário pro tamanho que a palavra tem
    vetorUtilizado->letrasAcertadasComparacao[strlen(vetorUtilizado->palavraEscolhida)+1]=0; //coloca terminador 0 no vetor de comparação

    vetorUtilizado->numerosRandomicos[(vetorUtilizado->randomicoDaVez)-1]=0; //coloca terminador 0 no vetor que guarda os numeros aleatorios ja utilizados
  }

  else if (!doisJogadores) //so for um só jogador
  {
    do
    {

      int idx2=0;
      int randomico=rand()%(qtd_palavras);
      for (idx2=0;idx2<vetorUtilizado->randomicoDaVez;idx2++)
      {
        if (vetorUtilizado->numerosRandomicos[idx2]==randomico) //se o número já tiver sido sorteado, escolhe outro
        {
          idx2=0;
          randomico=rand()%(qtd_palavras);
        }
      }

      if(idx2==vetorUtilizado->randomicoDaVez)
      {
        if (dificuldade=='F')
        {
          vetorUtilizado->palavraEscolhida=realloc(vetorUtilizado->palavraEscolhida,(1+strlen(facil[randomico+1]))*(sizeof(char)));  //realoca o vetor da palavra pro tamanho da palavra que foi sorteada
          strcpy(vetorUtilizado->palavraEscolhida,facil[randomico]); //copia a palavra sorteada pro vetor palavraEscolhida
          vetorUtilizado->palavraEscolhida[strlen(vetorUtilizado->palavraEscolhida)+1]=0; //coloca terminador 0

        }
        else if(dificuldade=='D')
        {
          vetorUtilizado->palavraEscolhida=realloc(vetorUtilizado->palavraEscolhida,strlen(dificil[randomico]+1)*(sizeof(char)));
          strcpy(vetorUtilizado->palavraEscolhida,dificil[randomico]);
          vetorUtilizado->palavraEscolhida[strlen(vetorUtilizado->palavraEscolhida)+1]=0;
        }
        vetorUtilizado->letrasAcertadasComparacao=realloc(vetorUtilizado->letrasAcertadasComparacao,((strlen(vetorUtilizado->palavraEscolhida)+1) * sizeof(char))); //realoca o vetor de comparacao pro tamanho da palavra escolhida
        vetorUtilizado->letrasAcertadasComparacao[strlen(vetorUtilizado->palavraEscolhida)+1]=0; //coloca terminador 0
        memset(vetorUtilizado->letrasAcertadasComparacao,0,(strlen(vetorUtilizado->palavraEscolhida)+1)*(sizeof(char))); //limpa o vetor de comparação

        vetorUtilizado->numerosRandomicos[(vetorUtilizado->randomicoDaVez)-1]=randomico; //joga o numero randomico dentro do vetor numerosRandomicos
        saida=qtd_palavras; //condicao de parada
      }
    } while(saida<qtd_palavras);
  }
}
