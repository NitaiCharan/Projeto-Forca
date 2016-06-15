#include "biblioteca.h"
#define QUANTIDADEFACIL 3
#define QUANTIDADEDIFICIL 5

int acertou=false;
char digitada[2];
int naoTinha=true;
int idxVerificacao=0;
int idx=0;
int saidaDoWhile=1;



void mensagens(int QUANTIDADE,T_vetores *vetorUtilizado);
void verificaLetra(int quantidade,T_vetores *vetorUtilizado,int doisJogadores);
void verificaPalavras(int quantidade,T_vetores * vetorUtilizado,int doisJogadores,char dificuldade);

void geraRand(int qtd_palavras,T_vetores *vetorUtilizado,char dificuldade,int doisJogadores,char *);
void palavraDaVez(char dificuldade,T_vetores vetorUtilizado,int doisJogadores,char*);


void iniciarPartida(char dificuldade,int doisJogadores,char*strEscolhida, int jogoSalvo)
{
  int saidaErou;
  saidaDoWhile=1;

  T_vetores vetorUtilizado;
  vetorUtilizado.randomicoDaVez=0;

  vetorUtilizado.numerosRandomicos=malloc(sizeof(int)*1);
  memset(vetorUtilizado.numerosRandomicos,0,(sizeof(int)*1));

  vetorUtilizado.pontuacaoRanking =0;


  do
  {
    vetorUtilizado.randomicoDaVez++;
    iniciavetores(&vetorUtilizado,& idxVerificacao);
    palavraDaVez(dificuldade,vetorUtilizado,doisJogadores,strEscolhida);
    if(jogoSalvo)
    {
      retornoJogoSalvo(&vetorUtilizado);
      jogoSalvo=0;
    }

    if(dificuldade == 'F')
    {

      if(vetorUtilizado.randomicoDaVez<17)
      {
        saidaErou = 4;
        vetorUtilizado.numerosRandomicos=realloc(vetorUtilizado.numerosRandomicos,(sizeof(int))*(vetorUtilizado.randomicoDaVez+1));
        for (; vetorUtilizado.errou < QUANTIDADEFACIL && saidaDoWhile !=0 ;vetorUtilizado.errou++)
        {
          mensagens(QUANTIDADEFACIL,&vetorUtilizado);
          verificaLetra(QUANTIDADEFACIL,&vetorUtilizado,doisJogadores);
          verificaPalavras(QUANTIDADEFACIL,&vetorUtilizado,doisJogadores,dificuldade);
        }
      }
      else saidaDoWhile = 0;
    }
    else
    {
      saidaErou = 6;
      if(vetorUtilizado.randomicoDaVez<15)
      {
        vetorUtilizado.numerosRandomicos=realloc(vetorUtilizado.numerosRandomicos,(sizeof(int))*(vetorUtilizado.randomicoDaVez));
        for (; vetorUtilizado.errou < QUANTIDADEDIFICIL && saidaDoWhile !=0;vetorUtilizado.errou++)
        {
          mensagens(QUANTIDADEDIFICIL,&vetorUtilizado);
          verificaLetra(QUANTIDADEDIFICIL,&vetorUtilizado,doisJogadores);
          verificaPalavras(QUANTIDADEDIFICIL,&vetorUtilizado,doisJogadores,dificuldade);
        }

      }
      else saidaDoWhile = 0;
    }
    if(doisJogadores)saidaDoWhile=0;
    finalizavetores(&vetorUtilizado);
  } while(vetorUtilizado.errou <= saidaErou && saidaDoWhile!=0);
  free(vetorUtilizado.numerosRandomicos);
}


void mensagens(int QUANTIDADE,T_vetores *vetorUtilizado)
{

  int i=0;
  LIMPATELA;
  printf("Letras j� utilizadas: ");
  for(i=0; i<strlen(vetorUtilizado->letrasUtilizadas);i++){
    printf(" %c",vetorUtilizado->letrasUtilizadas[i]);
  }


  printf("\n\nPalavra: ");
  for(i=0; i<strlen(vetorUtilizado->palavraEscolhida);i++){
    printf(" %c",vetorUtilizado->letrasAcertadas[i]);
  }
  //#####################################################################
  printf("\n\npalavraEscolhida :%s\n", vetorUtilizado->palavraEscolhida);
  printf("letrasUtilizadas :%s \n", vetorUtilizado->letrasUtilizadas);
  printf("vetorUtilizado->letrasAcertadasComparacao :%s\n", vetorUtilizado->letrasAcertadasComparacao);
  printf("randomicoDaVez :%d\n", vetorUtilizado->randomicoDaVez);
  printf("Errou :%d\n", vetorUtilizado->errou);
  int nitai;
  printf("numerosRandomicos: ");
  for(nitai=0;nitai<vetorUtilizado->randomicoDaVez;nitai++)
  {
    printf("%d,", vetorUtilizado->numerosRandomicos[nitai]);
  }
  printf("\n");
  //getchar();
  //#####################################################################
  if (naoTinha==false){
    printf("\n\nLetra '%c' j� utilizada. Tente outra.\n",digitada[0]);//Verifica se letra tentara já foi tentada anteriormente
    naoTinha=true;
  }
  if(acertou==true){
    printf("\n\nBoa! A letra '%c' existe na palavra :%c\n",digitada[0],')');
    acertou=false;
  }
  else if(acertou==demo){
    printf("\n\nLetra '%c' n�o existe na palavra :%c\n",digitada[0],'(');
  }

  do {
    printf("\n\nEntre uma letra (0 para sair). %d tentativas restantes.\n>",QUANTIDADE - vetorUtilizado->errou);
    scanf("%s",digitada);
    //verifica se usuário colocou mais de uma letra
    if (strlen(digitada)>1)printf("\n\nOi? Isso n�o � uma letra.\n");
  } while(strlen(digitada)>1);
  flush();
}

void verificaLetra(int quantidade,T_vetores *vetorUtilizado,int doisJogadores)
{

  if(digitada[0]=='0')
  {
    if(!doisJogadores)
    {
      char escolha;
      //LIMPATELA;
      printf("\n\nDeseja salvar esta partida (S/N)?\n>");
      scanf("%c", &escolha);
      flush();

      if (escolha!='N')
      {
        salvarJogo(vetorUtilizado);
      }
    }
    saidaDoWhile = 0;
  }

  else
  {
    //verifica se letra esta dentro do vetor vetorUtilizado->letrasUtilizadas. Caso sim,não continua processo de verificação
    int j;
    for(j=0; j<strlen(vetorUtilizado->letrasUtilizadas);j++){
      if(vetorUtilizado->letrasUtilizadas[j]==digitada[0]) {
        naoTinha=false;
        vetorUtilizado->errou--;//Para não contar vez tentada
        break;
      }
    }
    if (naoTinha)
    {
      vetorUtilizado->letrasUtilizadas=realloc(vetorUtilizado->letrasUtilizadas,(idxVerificacao+1)*(sizeof(char)));
      vetorUtilizado->letrasUtilizadas[idxVerificacao+1]=0;
      vetorUtilizado->letrasUtilizadas[idxVerificacao]=digitada[0];

      idxVerificacao+=1;
      int i=0;
      for(idx=0;idx<strlen(vetorUtilizado->palavraEscolhida);idx++){
        if(vetorUtilizado->palavraEscolhida[idx]==digitada[0]){
          vetorUtilizado->letrasAcertadasComparacao[idx]=digitada[0];
          vetorUtilizado->letrasAcertadas[idx]=digitada[0];
          i++;
        }
      }


      if(i>0){
        vetorUtilizado->errou--;
        acertou=true;
      }
      else{
        acertou=demo;
      }
    }
  }
}

void verificaPalavras(int quantidade,T_vetores * vetorUtilizado,int doisJogadores,char dificuldade)
{
  int pontuacaoDificuldade;

  if(strcmp(vetorUtilizado->letrasAcertadasComparacao,vetorUtilizado->palavraEscolhida)==0)
  {
    printf("\nParab�ns! Voc� ganhou. A palavra era '%s'.\nPressione enter para continuar...",vetorUtilizado->palavraEscolhida);
    getchar();

    if (dificuldade=='F') pontuacaoDificuldade=1;
    else pontuacaoDificuldade=2;

    vetorUtilizado->pontuacaoRanking +=(pontuacaoDificuldade * 1000) + (((quantidade-(vetorUtilizado->errou))-1) * 100);


    acertou=false;
    vetorUtilizado->errou = quantidade;//atribuição de erro ser igual a QUANTIDADE para quebrar "for" da verificação. for (vetorUtilizado->errou=0; vetorUtilizado->errou < QUANTIDADEFACIL;vetorUtilizado->errou++)
  }
  if((vetorUtilizado->errou+1==quantidade)&& vetorUtilizado->errou!=666){
    printf("Jogo encerrado. Voc� perdeu. A palavra era '%s'.\nPressione enter para continuar...",vetorUtilizado->palavraEscolhida);
    getchar();
    verificaRanking(vetorUtilizado);
    acertou=false;
    vetorUtilizado->errou= quantidade+1;
  }
}

void flush()//Procedimento para tratar comparações em CHAR
{
    char c;
    do
    {
      c = getchar();
    }
    while (c != '\n' && c != EOF);
}
