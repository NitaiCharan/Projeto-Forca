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

void iniciavetors(T_vetors *vetorUtilizados);
void finalizavetors(T_vetors *vetorUtilizados);
void mensagens(int QUANTIDADE,T_vetors *vetorUtilizados);
int verificaLetra(int quantidade,T_vetors *vetorUtilizados,int doisJogadores);
int verificaPalavras(int quantidade,T_vetors * vetorUtilizados,int doisJogadores);
void retornoJogoSalvo(T_vetors *vetorUtilizados);

void geraRand(int qtd_palavras,T_vetors *vetorUtilizados,char dificuldade,int doisJogadores,char *);
void palavraDaVez(char dificuldade,T_vetors vetorUtilizados,int doisJogadores,char*);
void iniciarPartida(char dificuldade,int doisJogadores,char*strEscolhida, int jogoSalvo)
{
  int saidaErou;
  saidaDoWhile=1;

  T_vetors vetorUtilizados;
  vetorUtilizados.randomicoDaVez=0;

  vetorUtilizados.numerosRandomicos=malloc(sizeof(int)*28);
  memset(vetorUtilizados.numerosRandomicos,0,(sizeof(int)*28));

  do
  {
    vetorUtilizados.randomicoDaVez++;
    iniciavetors(&vetorUtilizados);
    palavraDaVez(dificuldade,vetorUtilizados,doisJogadores,strEscolhida);
    if(jogoSalvo)
    {
      retornoJogoSalvo(&vetorUtilizados);
      jogoSalvo=0;
    }

    if(dificuldade == 'F')
    {

      if(vetorUtilizados.randomicoDaVez<17)
      {
        saidaErou = 4;
        vetorUtilizados.numerosRandomicos=realloc(vetorUtilizados.numerosRandomicos,(sizeof(int))*(vetorUtilizados.randomicoDaVez));
        for (; vetorUtilizados.errou < QUANTIDADEFACIL && saidaDoWhile !=0 ;vetorUtilizados.errou++)
        {
          mensagens(QUANTIDADEFACIL,&vetorUtilizados);
          vetorUtilizados.errou=verificaLetra(QUANTIDADEFACIL,&vetorUtilizados,doisJogadores);
          vetorUtilizados.errou=verificaPalavras(QUANTIDADEFACIL,&vetorUtilizados,doisJogadores);
        }
      }
      else saidaDoWhile = 0;
    }
    else
    {
      saidaErou = 6;
      if(vetorUtilizados.randomicoDaVez<15)
      {
        vetorUtilizados.numerosRandomicos=realloc(vetorUtilizados.numerosRandomicos,(sizeof(int))*(vetorUtilizados.randomicoDaVez));
        for (; vetorUtilizados.errou < QUANTIDADEDIFICIL && saidaDoWhile !=0;vetorUtilizados.errou++)
        {
          mensagens(QUANTIDADEDIFICIL,&vetorUtilizados);
          vetorUtilizados.errou=verificaLetra(QUANTIDADEDIFICIL,&vetorUtilizados,doisJogadores);
          vetorUtilizados.errou=verificaPalavras(QUANTIDADEDIFICIL,&vetorUtilizados,doisJogadores);
        }
      }
      else saidaDoWhile = 0;
    }
    if(doisJogadores)saidaDoWhile=0;
    finalizavetors(&vetorUtilizados);
  } while(vetorUtilizados.errou <= saidaErou && saidaDoWhile!=0);
  free(vetorUtilizados.numerosRandomicos);
}

void palavraDaVez(char dificuldade,T_vetors vetorUtilizados,int doisJogadores,char *strEscolhida)
{
  srand( (unsigned) time(NULL) );//criação da semente para o rand() com o tempo tatual
  if (dificuldade=='F')geraRand(17,&vetorUtilizados,dificuldade,doisJogadores,strEscolhida);
  else geraRand(15,&vetorUtilizados,dificuldade,doisJogadores,strEscolhida);

}

void geraRand(int qtd_palavras,T_vetors *vetorUtilizados,char dificuldade,int doisJogadores,char *strEscolhida)
{
  char facil[][11] = {"melhor", "grande", "claro", "azul", "vermelho","preto", "branco", "casa", "tempo", "felicidade", "bondade", "vida","caneta", "cavalo", "trem", "golpe", "cosmos"};
  char dificil[][17] = {"procrastinar", "prolegomenos", "vicissitudes", "pernostico", "oprobrio", "idiossincrasia", "elucubracoes", "chistoso", "acrimonia", "combustivel", "concurso", "protesto", "governo", "paquiderme", "tamandare"};

  int saida=0;

  if(doisJogadores)
  {
    vetorUtilizados->palavraEscolhida=realloc(vetorUtilizados->palavraEscolhida,(1+strlen(strEscolhida))*sizeof(char));
    memcpy(vetorUtilizados->palavraEscolhida,strEscolhida,(sizeof(char)*(strlen(strEscolhida)+1)));

    vetorUtilizados->letrasAcertadasComparacao=realloc(vetorUtilizados->letrasAcertadasComparacao,((strlen(vetorUtilizados->palavraEscolhida)+1) * sizeof(char)));
    vetorUtilizados->letrasAcertadasComparacao[strlen(vetorUtilizados->palavraEscolhida)+1]=0;

    vetorUtilizados->numerosRandomicos[(vetorUtilizados->randomicoDaVez)-1]=0;
  }

  else if (!doisJogadores)
  {
    do {

      int idx2=0;
      int randomico=rand()%(qtd_palavras);
      for (idx2=0;idx2<vetorUtilizados->randomicoDaVez;idx2++)
      {
        if (vetorUtilizados->numerosRandomicos[idx2]==randomico)
        {
          idx2=0;
          randomico=rand()%(qtd_palavras);
        }
      }

      if(idx2==vetorUtilizados->randomicoDaVez)
      {
        if (dificuldade=='F')
        {
          vetorUtilizados->palavraEscolhida=realloc(vetorUtilizados->palavraEscolhida,(1+strlen(facil[randomico+1]))*(sizeof(char)));
          strcpy(vetorUtilizados->palavraEscolhida,facil[randomico]);
          vetorUtilizados->palavraEscolhida[strlen(vetorUtilizados->palavraEscolhida)+1]=0;

          vetorUtilizados->letrasAcertadasComparacao=realloc(vetorUtilizados->letrasAcertadasComparacao,((strlen(vetorUtilizados->palavraEscolhida)+1) * sizeof(char)));
          vetorUtilizados->letrasAcertadasComparacao[strlen(vetorUtilizados->palavraEscolhida)+1]=0;
        }
        else if(dificuldade=='D')
        {
          vetorUtilizados->palavraEscolhida=realloc(vetorUtilizados->palavraEscolhida,strlen(dificil[randomico]+1)*(sizeof(char)));
          strcpy(vetorUtilizados->palavraEscolhida,dificil[randomico]);
          vetorUtilizados->palavraEscolhida[strlen(vetorUtilizados->palavraEscolhida)+1]=0;

          vetorUtilizados->letrasAcertadasComparacao=realloc(vetorUtilizados->letrasAcertadasComparacao,((strlen(vetorUtilizados->palavraEscolhida)+1) * sizeof(char)));
          vetorUtilizados->letrasAcertadasComparacao[strlen(vetorUtilizados->palavraEscolhida)+1]=0;
        }
        vetorUtilizados->numerosRandomicos[(vetorUtilizados->randomicoDaVez)-1]=randomico;
        saida=qtd_palavras;
      }
    } while(saida<qtd_palavras);
  }
}

void mensagens(int QUANTIDADE,T_vetors *vetorUtilizados)
{

  int i=0;
  LIMPATELA;
  printf("Letras já utilizadas: ");
  for(i=0; i<strlen(vetorUtilizados->letrasUtilizadas);i++){
    printf(" %c",vetorUtilizados->letrasUtilizadas[i]);
  }


  printf("\n\nPalavra: ");
  for(i=0; i<strlen(vetorUtilizados->palavraEscolhida);i++){
    printf(" %c",letrasAcertadas[i]);
  }
  //#####################################################################
  printf("\n\npalavraEscolhida :%s\n", vetorUtilizados->palavraEscolhida);
  printf("letrasUtilizadas :%s \n", vetorUtilizados->letrasUtilizadas);
  printf("letrasAcertadasComparacao :%s\n", vetorUtilizados->letrasAcertadasComparacao);
  printf("randomicoDaVez :%d\n", vetorUtilizados->randomicoDaVez);
  printf("Errou :%d\n", vetorUtilizados->errou);
  int nitai;
  printf("numerosRandomicos: ");
  for(nitai=0;nitai<vetorUtilizados->randomicoDaVez;nitai++)
  {
    printf("%d,", vetorUtilizados->numerosRandomicos[nitai]);
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
    printf("\n\nEntre uma letra (0 para sair). %d tentativas restantes.\n>",QUANTIDADE - vetorUtilizados->errou);
    scanf("%s",digitada);
    //verifica se usuário colocou mais de uma letra
    if (strlen(digitada)>1)printf("\n\nOi? Isso não é uma letra.\n");
  } while(strlen(digitada)>1);
  flush();
}

int verificaLetra(int quantidade,T_vetors *vetorUtilizados,int doisJogadores)
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

        	lens=strlen(vetorUtilizados->palavraEscolhida)+1;
        	fwrite(&lens,sizeof(int),1,listas);
        	fwrite(vetorUtilizados->palavraEscolhida,sizeof(char),lens,listas);

        	lens=strlen(vetorUtilizados->letrasUtilizadas)+1;
	        fwrite(&lens,sizeof(int),1,listas);
	        fwrite(vetorUtilizados->letrasUtilizadas,sizeof(char),lens,listas);

          lens=strlen(vetorUtilizados->palavraEscolhida)+1;
	        fwrite(&lens,sizeof(int),1,listas);
	        fwrite(vetorUtilizados->letrasAcertadasComparacao,sizeof(char),lens,listas);

          lens=strlen(letrasAcertadas)+1;
          fwrite(&lens,sizeof(int),1,listas);
          fwrite(letrasAcertadas,sizeof(char),lens,listas);

	        fwrite(&(vetorUtilizados->randomicoDaVez),sizeof(int),1,listas);

	        fwrite(vetorUtilizados->numerosRandomicos,sizeof(int),vetorUtilizados->randomicoDaVez,listas);

	        fwrite(&(vetorUtilizados->errou),sizeof(int),1,listas);

          vetorUtilizados->errou=666;
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
    //verifica se letra esta dentro do vetor vetorUtilizados->letrasUtilizadas. Caso sim,não continua processo de verificação
    int j;
    for(j=0; j<strlen(vetorUtilizados->letrasUtilizadas);j++){
      if(vetorUtilizados->letrasUtilizadas[j]==digitada[0]) {
        naoTinha=0;
        vetorUtilizados->errou--;//Para não contar vez tentada
        break;
      }
    }
    if (naoTinha)
    {
      vetorUtilizados->letrasUtilizadas=realloc(vetorUtilizados->letrasUtilizadas,(idxVerificacao+1)*(sizeof(char)));
      vetorUtilizados->letrasUtilizadas[idxVerificacao+1]=0;
      vetorUtilizados->letrasUtilizadas[idxVerificacao]=digitada[0];

      idxVerificacao+=1;
      int i=0;
      for(idx=0;idx<strlen(vetorUtilizados->palavraEscolhida);idx++){
        if(vetorUtilizados->palavraEscolhida[idx]==digitada[0]){
          vetorUtilizados->letrasAcertadasComparacao[idx]=digitada[0];
          letrasAcertadas[idx]=digitada[0];
          i++;
        }
      }


      if(i>0){
        vetorUtilizados->errou--;
        acertou=1;
      }
      else{
        acertou=666;
      }
    }
  }
  return vetorUtilizados->errou;
}

int verificaPalavras(int quantidade,T_vetors * vetorUtilizados,int doisJogadores){

  if(strcmp(vetorUtilizados->letrasAcertadasComparacao,vetorUtilizados->palavraEscolhida)==0)
  {
    printf("\nParabéns! Você ganhou. A palavra era '%s'.\nPressione enter para continuar...",vetorUtilizados->palavraEscolhida);
    getchar();
    acertou=0;
    vetorUtilizados->errou = quantidade;//atribuição de erro ser igual a QUANTIDADE para quebrar "for" da verificação. for (vetorUtilizados->errou=0; vetorUtilizados->errou < QUANTIDADEFACIL;vetorUtilizados->errou++)
  }
  if((vetorUtilizados->errou+1==quantidade)&& vetorUtilizados->errou!=666){
    printf("Jogo encerrado. Você perdeu. A palavra era '%s'.\nPressione enter para continuar...",vetorUtilizados->palavraEscolhida);
    getchar();
    acertou=0;
    vetorUtilizados->errou= quantidade+1;
  }
  return vetorUtilizados->errou;
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
void iniciavetors(T_vetors *vetorUtilizados)
{
  vetorUtilizados->palavraEscolhida=malloc(sizeof(char)*80);
  vetorUtilizados->letrasUtilizadas=malloc(sizeof(char)*80);
  vetorUtilizados->letrasAcertadasComparacao=malloc(sizeof(char)*80);
  memset(vetorUtilizados->palavraEscolhida,0,strlen(vetorUtilizados->palavraEscolhida)*(sizeof(char)));
  memset(vetorUtilizados->letrasAcertadasComparacao,0,strlen(vetorUtilizados->letrasAcertadasComparacao)*(sizeof(char)));
  memset(vetorUtilizados->letrasUtilizadas,0,strlen(vetorUtilizados->letrasUtilizadas)*(sizeof(char)));
  memset(vetorUtilizados->letrasUtilizadas,' ',strlen(vetorUtilizados->letrasUtilizadas)*(sizeof(char)));
  strcpy(letrasAcertadas, "________________________________________");
  idxVerificacao=0;
  vetorUtilizados->errou=0;
}

void finalizavetors(T_vetors *vetorUtilizados)
{
  free(vetorUtilizados->palavraEscolhida);
  free(vetorUtilizados->letrasUtilizadas);
  free(vetorUtilizados->letrasAcertadasComparacao);
}

void retornoJogoSalvo(T_vetors *vetorUtilizados)
{
  FILE *arq=NULL;
  if (arq=fopen("dados.dat","rb"))
  {
    int len;

    fread(&len,sizeof(int),1,arq);
    fread(vetorUtilizados->palavraEscolhida,sizeof(char),len,arq);

    fread(&len,sizeof(int),1,arq);
    fread(vetorUtilizados->letrasUtilizadas,sizeof(char),len,arq);

    fread(&len,sizeof(int),1,arq);
    fread(vetorUtilizados->letrasAcertadasComparacao,sizeof(char),len,arq);

    fread(&len,sizeof(int),1,arq);
    fread(letrasAcertadas,sizeof(char),len,arq);

    fread(&(vetorUtilizados->randomicoDaVez),sizeof(int),1,arq);
    fread(vetorUtilizados->numerosRandomicos,sizeof(int),vetorUtilizados->randomicoDaVez,arq);

    fread(&(vetorUtilizados->errou),sizeof(int),1,arq);
    fclose(arq);
  }
}
