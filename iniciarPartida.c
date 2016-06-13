#include "biblioteca.h"
#define QUANTIDADEFACIL 3
#define QUANTIDADEDIFICIL 5

char letrasAcertadas[]="________________________________________\0";
int acertou=0;
char digitada[2];
int naoTinha=1;
int idxVerificacao=0;
int idx=0;
int saidaDoWhile=1;

typedef struct
{
  char *palavraEscolhida;
  char *letrasUtilizadas;
  char *letrasAcertadasComparacao;
  int *numerosRandomicos;
  int randomicoDaVez;
  int errou;
} T_vetors;

void iniciavetors(T_vetors *vetorUtilizado);
void finalizavetors(T_vetors *vetorUtilizado);
void mensagens(int QUANTIDADE,T_vetors *vetorUtilizado);
int verificaLetra(int quantidade,T_vetors *vetorUtilizado,int doisJogadores);
int verificaPalavras(int quantidade,T_vetors * vetorUtilizado,int doisJogadores);
void retornoJogoSalvo(T_vetors *vetorUtilizado);

void geraRand(int qtd_palavras,T_vetors *vetorUtilizado,char dificuldade,int doisJogadores,char *);
void palavraDaVez(char dificuldade,T_vetors vetorUtilizado,int doisJogadores,char*);
void iniciarPartida(char dificuldade,int doisJogadores,char*strEscolhida, int jogoSalvo)
{
  int saidaErou;
  saidaDoWhile=1;

  T_vetors vetorUtilizado;
  vetorUtilizado.randomicoDaVez=0;

  vetorUtilizado.numerosRandomicos=malloc(sizeof(int)*28);
  memset(vetorUtilizado.numerosRandomicos,0,(sizeof(int)*28));

  do
  {
    vetorUtilizado.randomicoDaVez++;
    iniciavetors(&vetorUtilizado);
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
        vetorUtilizado.numerosRandomicos=realloc(vetorUtilizado.numerosRandomicos,(sizeof(int))*(vetorUtilizado.randomicoDaVez));
        for (; vetorUtilizado.errou < QUANTIDADEFACIL && saidaDoWhile !=0 ;vetorUtilizado.errou++)
        {
          mensagens(QUANTIDADEFACIL,&vetorUtilizado);
          vetorUtilizado.errou=verificaLetra(QUANTIDADEFACIL,&vetorUtilizado,doisJogadores);
          vetorUtilizado.errou=verificaPalavras(QUANTIDADEFACIL,&vetorUtilizado,doisJogadores);
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
          vetorUtilizado.errou=verificaLetra(QUANTIDADEDIFICIL,&vetorUtilizado,doisJogadores);
          vetorUtilizado.errou=verificaPalavras(QUANTIDADEDIFICIL,&vetorUtilizado,doisJogadores);
        }
      }
      else saidaDoWhile = 0;
    }
    if(doisJogadores)saidaDoWhile=0;
    finalizavetors(&vetorUtilizado);
  } while(vetorUtilizado.errou <= saidaErou && saidaDoWhile!=0);
  free(vetorUtilizado.numerosRandomicos);
}

void palavraDaVez(char dificuldade,T_vetors vetorUtilizado,int doisJogadores,char *strEscolhida)
{
  srand( (unsigned) time(NULL) );//criação da semente para o rand() com o tempo tatual
  if (dificuldade=='F')geraRand(17,&vetorUtilizado,dificuldade,doisJogadores,strEscolhida);
  else geraRand(15,&vetorUtilizado,dificuldade,doisJogadores,strEscolhida);

}

void geraRand(int qtd_palavras,T_vetors *vetorUtilizado,char dificuldade,int doisJogadores,char *strEscolhida)
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
    do {

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

          vetorUtilizado->letrasAcertadasComparacao=realloc(vetorUtilizado->letrasAcertadasComparacao,((strlen(vetorUtilizado->palavraEscolhida)+1) * sizeof(char)));
          vetorUtilizado->letrasAcertadasComparacao[strlen(vetorUtilizado->palavraEscolhida)+1]=0;
        }
        else if(dificuldade=='D')
        {
          vetorUtilizado->palavraEscolhida=realloc(vetorUtilizado->palavraEscolhida,strlen(dificil[randomico]+1)*(sizeof(char)));
          strcpy(vetorUtilizado->palavraEscolhida,dificil[randomico]);
          vetorUtilizado->palavraEscolhida[strlen(vetorUtilizado->palavraEscolhida)+1]=0;

          vetorUtilizado->letrasAcertadasComparacao=realloc(vetorUtilizado->letrasAcertadasComparacao,((strlen(vetorUtilizado->palavraEscolhida)+1) * sizeof(char)));
          vetorUtilizado->letrasAcertadasComparacao[strlen(vetorUtilizado->palavraEscolhida)+1]=0;
        }
        vetorUtilizado->numerosRandomicos[(vetorUtilizado->randomicoDaVez)-1]=randomico;
        saida=qtd_palavras;
      }
    } while(saida<qtd_palavras);
  }
}

void mensagens(int QUANTIDADE,T_vetors *vetorUtilizado)
{

  int i=0;
  LIMPATELA;
  printf("Letras já utilizadas: ");
  for(i=0; i<strlen(vetorUtilizado->letrasUtilizadas);i++){
    printf(" %c",vetorUtilizado->letrasUtilizadas[i]);
  }


  printf("\n\nPalavra: ");
  for(i=0; i<strlen(vetorUtilizado->palavraEscolhida);i++){
    printf(" %c",letrasAcertadas[i]);
  }
  //#####################################################################
  printf("\n\npalavraEscolhida :%s\n", vetorUtilizado->palavraEscolhida);
  printf("letrasUtilizadas :%s \n", vetorUtilizado->letrasUtilizadas);
  printf("letrasAcertadasComparacao :%s\n", vetorUtilizado->letrasAcertadasComparacao);
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
  if (naoTinha==0){
    printf("\n\nLetra '%c' já utilizada. Tente outra.\n",digitada[0]);//Verifica se letra tentara já foi tentada anteriormente
    naoTinha=1;
  }
  if(acertou==1){
    printf("\n\nBoa! A letra '%c' existe na palavra :%c\n",digitada[0],')');
    acertou=0;
  }
  else if(acertou==666){
    printf("\n\nLetra '%c' não existe na palavra :%c\n",digitada[0],'(');
  }

  do {
    printf("\n\nEntre uma letra (0 para sair). %d tentativas restantes.\n>",QUANTIDADE - vetorUtilizado->errou);
    scanf("%s",digitada);
    //verifica se usuário colocou mais de uma letra
    if (strlen(digitada)>1)printf("\n\nOi? Isso não é uma letra.\n");
  } while(strlen(digitada)>1);
  flush();
}

int verificaLetra(int quantidade,T_vetors *vetorUtilizado,int doisJogadores)
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

        FILE *listas = NULL;
        listas = fopen("dados.dat","wb"); // Abertura do arquivo dados.txt

        //Verificando se o arquivo existe, se existir entra no if
        if(listas)
        {

        	int lens;

        	lens=strlen(vetorUtilizado->palavraEscolhida)+1;
        	fwrite(&lens,sizeof(int),1,listas);
        	fwrite(vetorUtilizado->palavraEscolhida,sizeof(char),lens,listas);

        	lens=strlen(vetorUtilizado->letrasUtilizadas)+1;
	        fwrite(&lens,sizeof(int),1,listas);
	        fwrite(vetorUtilizado->letrasUtilizadas,sizeof(char),lens,listas);

          lens=strlen(vetorUtilizado->palavraEscolhida)+1;
	        fwrite(&lens,sizeof(int),1,listas);
	        fwrite(vetorUtilizado->letrasAcertadasComparacao,sizeof(char),lens,listas);

          lens=strlen(letrasAcertadas)+1;
          fwrite(&lens,sizeof(int),1,listas);
          fwrite(letrasAcertadas,sizeof(char),lens,listas);

	        fwrite(&(vetorUtilizado->randomicoDaVez),sizeof(int),1,listas);

	        fwrite(vetorUtilizado->numerosRandomicos,sizeof(int),vetorUtilizado->randomicoDaVez,listas);

	        fwrite(&(vetorUtilizado->errou),sizeof(int),1,listas);

          vetorUtilizado->errou=666;
		    }

        else
        {
          printf("Erro na abertura do arquivo\n");
          exit(1);
        }
        fclose(listas);
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
        naoTinha=0;
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
          letrasAcertadas[idx]=digitada[0];
          i++;
        }
      }


      if(i>0){
        vetorUtilizado->errou--;
        acertou=1;
      }
      else{
        acertou=666;
      }
    }
  }
  return vetorUtilizado->errou;
}

int verificaPalavras(int quantidade,T_vetors * vetorUtilizado,int doisJogadores){

  if(strcmp(vetorUtilizado->letrasAcertadasComparacao,vetorUtilizado->palavraEscolhida)==0)
  {
    printf("\nParabéns! Você ganhou. A palavra era '%s'.\nPressione enter para continuar...",vetorUtilizado->palavraEscolhida);
    getchar();
    acertou=0;
    vetorUtilizado->errou = quantidade;//atribuição de erro ser igual a QUANTIDADE para quebrar "for" da verificação. for (vetorUtilizado->errou=0; vetorUtilizado->errou < QUANTIDADEFACIL;vetorUtilizado->errou++)
  }
  if((vetorUtilizado->errou+1==quantidade)&& vetorUtilizado->errou!=666){
    printf("Jogo encerrado. Você perdeu. A palavra era '%s'.\nPressione enter para continuar...",vetorUtilizado->palavraEscolhida);
    getchar();
    acertou=0;
    vetorUtilizado->errou= quantidade+1;
  }
  return vetorUtilizado->errou;
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
void iniciavetors(T_vetors *vetorUtilizado)
{
  vetorUtilizado->palavraEscolhida=malloc(sizeof(char)*80);
  vetorUtilizado->letrasUtilizadas=malloc(sizeof(char)*80);
  vetorUtilizado->letrasAcertadasComparacao=malloc(sizeof(char)*80);
  memset(vetorUtilizado->palavraEscolhida,0,strlen(vetorUtilizado->palavraEscolhida)*(sizeof(char)));
  memset(vetorUtilizado->letrasAcertadasComparacao,0,strlen(vetorUtilizado->letrasAcertadasComparacao)*(sizeof(char)));
  memset(vetorUtilizado->letrasUtilizadas,0,strlen(vetorUtilizado->letrasUtilizadas)*(sizeof(char)));
  memset(vetorUtilizado->letrasUtilizadas,' ',strlen(vetorUtilizado->letrasUtilizadas)*(sizeof(char)));
  strcpy(letrasAcertadas, "________________________________________");
  idxVerificacao=0;
  vetorUtilizado->errou=0;
}

void finalizavetors(T_vetors *vetorUtilizado)
{
  free(vetorUtilizado->palavraEscolhida);
  free(vetorUtilizado->letrasUtilizadas);
  free(vetorUtilizado->letrasAcertadasComparacao);
}

void retornoJogoSalvo(T_vetors *vetorUtilizado)
{
  FILE *arq=NULL;
  if (arq=fopen("dados.dat","rb"))
  {
    int len;

    fread(&len,sizeof(int),1,arq);
    fread(vetorUtilizado->palavraEscolhida,sizeof(char),len,arq);

    fread(&len,sizeof(int),1,arq);
    fread(vetorUtilizado->letrasUtilizadas,sizeof(char),len,arq);

    fread(&len,sizeof(int),1,arq);
    fread(vetorUtilizado->letrasAcertadasComparacao,sizeof(char),len,arq);

    fread(&len,sizeof(int),1,arq);
    fread(letrasAcertadas,sizeof(char),len,arq);

    fread(&(vetorUtilizado->randomicoDaVez),sizeof(int),1,arq);
    fread(vetorUtilizado->numerosRandomicos,sizeof(int),vetorUtilizado->randomicoDaVez,arq);

    fread(&(vetorUtilizado->errou),sizeof(int),1,arq);
    fclose(arq);
  }
}
