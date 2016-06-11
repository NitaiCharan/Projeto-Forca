#include "biblioteca.h"
#define QUANTIDADEFACIL 3
#define QUANTIDADEDIFICIL 5

char letrasAcertadas[21]="____________________\0";
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
} T_vetores;

void iniciaVetores(T_vetores *vetoreUtilisados);
void finalizaVetores(T_vetores *vetoreUtilisados);
void mensagens(int QUANTIDADE,T_vetores *vetoreUtilisados);
int verificaLetra(int quantidade,T_vetores *vetoreUtilisados,int doisJogadores);
int verificaPalavras(int quantidade,T_vetores * vetoreUtilisados,int doisJogadores);


void geraRand(int qtd_palavras,T_vetores *vetoreUtilisados,char dificuldade,int doisJogadores,char *);
void palavraDaVez(char dificuldade,T_vetores vetoreUtilisados,int doisJogadores,char*);

void iniciarPartida(char dificuldade,int doisJogadores,char*strEscolhida)
{
  int saidaErou;
  saidaDoWhile=1;

  T_vetores vetoreUtilisados;
  vetoreUtilisados.randomicoDaVez=0;


  do
  {
    vetoreUtilisados.randomicoDaVez++;
    iniciaVetores(&vetoreUtilisados);
    palavraDaVez(dificuldade,vetoreUtilisados,doisJogadores,strEscolhida);

    if(dificuldade == 'F')
    {
      if(vetoreUtilisados.randomicoDaVez<18)
      {
        saidaErou = 4;
        vetoreUtilisados.numerosRandomicos=realloc(vetoreUtilisados.numerosRandomicos,(sizeof(int))*(vetoreUtilisados.randomicoDaVez));
        for (vetoreUtilisados.errou=0; vetoreUtilisados.errou < QUANTIDADEFACIL && saidaDoWhile !=0 ;vetoreUtilisados.errou++)
        {
          mensagens(QUANTIDADEFACIL,&vetoreUtilisados);
          vetoreUtilisados.errou=verificaLetra(QUANTIDADEFACIL,&vetoreUtilisados,doisJogadores);
          vetoreUtilisados.errou=verificaPalavras(QUANTIDADEFACIL,&vetoreUtilisados,doisJogadores);
        }
      }
      else saidaDoWhile = 0;

    }
    else
    {
      saidaErou = 6;
      if(vetoreUtilisados.randomicoDaVez<16)
      {
        vetoreUtilisados.numerosRandomicos=realloc(vetoreUtilisados.numerosRandomicos,(sizeof(int))*(vetoreUtilisados.randomicoDaVez));
        for (vetoreUtilisados.errou=0; vetoreUtilisados.errou < QUANTIDADEDIFICIL && saidaDoWhile !=0;vetoreUtilisados.errou++)
        {
          mensagens(QUANTIDADEDIFICIL,&vetoreUtilisados);
          vetoreUtilisados.errou=verificaLetra(QUANTIDADEDIFICIL,&vetoreUtilisados,doisJogadores);
          vetoreUtilisados.errou=verificaPalavras(QUANTIDADEDIFICIL,&vetoreUtilisados,doisJogadores);
        }
      }
      else saidaDoWhile = 0;
    }
    if(doisJogadores)saidaDoWhile=0;
    finalizaVetores(&vetoreUtilisados);
  } while(vetoreUtilisados.errou <= saidaErou && saidaDoWhile!=0);

}

void palavraDaVez(char dificuldade,T_vetores vetoreUtilisados,int doisJogadores,char *strEscolhida)
{
  srand( (unsigned) time(NULL) );//criação da semente para o rand() com o tempo tatual
  if (dificuldade=='F')geraRand(17,&vetoreUtilisados,dificuldade,doisJogadores,strEscolhida);
  else geraRand(15,&vetoreUtilisados,dificuldade,doisJogadores,strEscolhida);

}

void geraRand(int qtd_palavras,T_vetores *vetoreUtilisados,char dificuldade,int doisJogadores,char *strEscolhida)
{
  char facil[][11] = {"melhor", "grande", "claro", "azul", "vermelho","preto", "branco", "casa", "tempo", "felicidade", "bondade", "vida","caneta", "cavalo", "trem", "golpe", "cosmos"};
  char dificil[][17] = {"procrastinar", "prolegomenos", "vicissitudes", "pernostico", "oprobrio", "idiossincrasia", "elucubracoes", "chistoso", "acrimonia", "combustivel", "concurso", "protesto", "governo", "paquiderme", "tamandare"};

  int saida=0;

  if(doisJogadores)
  {
    vetoreUtilisados->palavraEscolhida=realloc(vetoreUtilisados->palavraEscolhida,(1+strlen(strEscolhida))*sizeof(char));
    memcpy(vetoreUtilisados->palavraEscolhida,strEscolhida,(sizeof(char)*(strlen(strEscolhida)+1)));

    vetoreUtilisados->letrasAcertadasComparacao=realloc(vetoreUtilisados->letrasAcertadasComparacao,((strlen(vetoreUtilisados->palavraEscolhida)+1) * sizeof(char)));
    vetoreUtilisados->letrasAcertadasComparacao[strlen(vetoreUtilisados->palavraEscolhida)+1]=0;

    vetoreUtilisados->numerosRandomicos[(vetoreUtilisados->randomicoDaVez)-1]=0;
  }

  else if (!doisJogadores)
  {
    do {

      int idx2=0;
      int randomico=rand()%(qtd_palavras);
      for (idx2=0;idx2<vetoreUtilisados->randomicoDaVez;idx2++)
      {
        if (vetoreUtilisados->numerosRandomicos[idx2]==randomico)
        {
          idx2=0;
          randomico=rand()%(qtd_palavras);
        }
      }

      if(idx2==vetoreUtilisados->randomicoDaVez)
      {
        if (dificuldade=='F')
        {
          vetoreUtilisados->palavraEscolhida=realloc(vetoreUtilisados->palavraEscolhida,(1+strlen(facil[randomico+1]))*(sizeof(char)));
          strcpy(vetoreUtilisados->palavraEscolhida,facil[randomico]);
          vetoreUtilisados->palavraEscolhida[strlen(vetoreUtilisados->palavraEscolhida)+1]=0;

          vetoreUtilisados->letrasAcertadasComparacao=realloc(vetoreUtilisados->letrasAcertadasComparacao,((strlen(vetoreUtilisados->palavraEscolhida)+1) * sizeof(char)));
          vetoreUtilisados->letrasAcertadasComparacao[strlen(vetoreUtilisados->palavraEscolhida)+1]=0;
        }
        else if(dificuldade=='D')
        {
          vetoreUtilisados->palavraEscolhida=realloc(vetoreUtilisados->palavraEscolhida,strlen(dificil[randomico]+1)*(sizeof(char)));
          strcpy(vetoreUtilisados->palavraEscolhida,dificil[randomico]);
          vetoreUtilisados->palavraEscolhida[strlen(vetoreUtilisados->palavraEscolhida)+1]=0;

          vetoreUtilisados->letrasAcertadasComparacao=realloc(vetoreUtilisados->letrasAcertadasComparacao,((strlen(vetoreUtilisados->palavraEscolhida)+1) * sizeof(char)));
          vetoreUtilisados->letrasAcertadasComparacao[strlen(vetoreUtilisados->palavraEscolhida)+1]=0;
        }
        vetoreUtilisados->numerosRandomicos[(vetoreUtilisados->randomicoDaVez)-1]=randomico;
        saida=qtd_palavras;
      }
    } while(saida<qtd_palavras);
  }
}

void mensagens(int QUANTIDADE,T_vetores *vetoreUtilisados)
{
  int i=0;
  LIMPATELA;
  printf("Letras já utilizadas: ");
  for(i=0; i<strlen(vetoreUtilisados->letrasUtilizadas);i++){
    printf(" %c",vetoreUtilisados->letrasUtilizadas[i]);
  }


  printf("\n\nPalavra: ");
  for(i=0; i<strlen(vetoreUtilisados->palavraEscolhida);i++){
    printf(" %c",letrasAcertadas[i]);
  }
  //#####################################################################
  printf("\n\npalavraEscolhida :%s\n", vetoreUtilisados->palavraEscolhida);
  printf("letrasUtilizadas :%s \n", vetoreUtilisados->letrasUtilizadas);
  printf("letrasAcertadasComparacao :%s\n", vetoreUtilisados->letrasAcertadasComparacao);
  printf("randomicoDaVez :%d\n", vetoreUtilisados->randomicoDaVez);
  printf("Errou :%d\n", vetoreUtilisados->errou);
  int nitai;
  printf("numerosRandomicos: ");
  for(nitai=0;nitai<vetoreUtilisados->randomicoDaVez;nitai++)
  {
    printf("%d,", vetoreUtilisados->numerosRandomicos[nitai]);
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
    printf("\n\nEntre uma letra (0 para sair). %d tentativas restantes.\n>",QUANTIDADE - vetoreUtilisados->errou);
    scanf("%s",digitada);
    //verifica se usuário colocou mais de uma letra
    if (strlen(digitada)>1)printf("\n\nOi? Isso não é uma letra.\n");
  } while(strlen(digitada)>1);
  flush();
}

int verificaLetra(int quantidade,T_vetores *vetoreUtilisados,int doisJogadores)
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

        	lens=strlen(vetoreUtilisados->palavraEscolhida)+1;
        	fwrite(&lens,sizeof(int),1,listas);
        	//lens é utilizado para definir a quantidade de carcteres escritos em data.
        	fwrite(vetoreUtilisados->palavraEscolhida,sizeof(char),lens,listas);

        	lens=strlen(vetoreUtilisados->letrasUtilizadas)+1;
	        fwrite(&lens,sizeof(int),1,listas);
	        //lens é utilizado para definir a quantidade de carcteres escritos em data.bat
	        fwrite(vetoreUtilisados->letrasUtilizadas,sizeof(char),lens,listas);

	        lens=strlen(vetoreUtilisados->palavraEscolhida)+1;
	        fwrite(&lens,sizeof(int),1,listas);
	        //lens é utilizado para definir a quantidade de carcteres escritos em data.bat
	        fwrite(vetoreUtilisados->letrasAcertadasComparacao,sizeof(char),lens,listas);


          lens=strlen(letrasAcertadas)+1;
          fwrite(&lens,sizeof(int),1,listas);
          //lens é utilizado para definir a quantidade de carcteres escritos em data.bat
          fwrite(letrasAcertadas,sizeof(char),lens,listas);

	        fwrite(&(vetoreUtilisados->randomicoDaVez),sizeof(int),1,listas);
	        fwrite(vetoreUtilisados->numerosRandomicos,sizeof(int),vetoreUtilisados->randomicoDaVez,listas);

	        fwrite(&vetoreUtilisados->errou,sizeof(int),1,listas);
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
    //verifica se letra esta dentro do vetor vetoreUtilisados->letrasUtilizadas. Caso sim,não continua processo de verificação
    int j;
    for(j=0; j<strlen(vetoreUtilisados->letrasUtilizadas);j++){
      if(vetoreUtilisados->letrasUtilizadas[j]==digitada[0]) {
        naoTinha=0;
        vetoreUtilisados->errou--;//Para não contar vez tentada
        break;
      }
    }
    if (naoTinha)
    {
      vetoreUtilisados->letrasUtilizadas=realloc(vetoreUtilisados->letrasUtilizadas,(idxVerificacao+1)*(sizeof(char)));
      vetoreUtilisados->letrasUtilizadas[idxVerificacao+1]=0;
      vetoreUtilisados->letrasUtilizadas[idxVerificacao]=digitada[0];

      idxVerificacao+=1;
      int i=0;
      for(idx=0;idx<strlen(vetoreUtilisados->palavraEscolhida);idx++){
        if(vetoreUtilisados->palavraEscolhida[idx]==digitada[0]){
          vetoreUtilisados->letrasAcertadasComparacao[idx]=digitada[0];
          letrasAcertadas[idx]=digitada[0];
          i++;
        }
      }


      if(i>0){
        vetoreUtilisados->errou--;
        acertou=1;
      }
      else{
        acertou=666;
      }
    }
  }
  return vetoreUtilisados->errou;
}

int verificaPalavras(int quantidade,T_vetores * vetoreUtilisados,int doisJogadores){

  if(strcmp(vetoreUtilisados->letrasAcertadasComparacao,vetoreUtilisados->palavraEscolhida)==0)
  {
    printf("\nParabéns! Você ganhou. A palavra era '%s'.\nPressione enter para continuar...",vetoreUtilisados->palavraEscolhida);
    getchar();
    acertou=0;
    vetoreUtilisados->errou = quantidade;//atribuição de erro ser igual a QUANTIDADE para quebrar "for" da verificação. for (vetoreUtilisados->errou=0; vetoreUtilisados->errou < QUANTIDADEFACIL;vetoreUtilisados->errou++)
  }
  if((vetoreUtilisados->errou+1)==quantidade){
    printf("Jogo encerrado. Você perdeu. A palavra era '%s'.\nPressione enter para continuar...",vetoreUtilisados->palavraEscolhida);
    getchar();
    acertou=0;
    vetoreUtilisados->errou= quantidade+1;
  }
  return vetoreUtilisados->errou;
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
void iniciaVetores(T_vetores *vetoreUtilisados)
{
  vetoreUtilisados->palavraEscolhida=malloc(1);
  vetoreUtilisados->letrasUtilizadas=malloc(1);
  vetoreUtilisados->letrasAcertadasComparacao=malloc(1);
  vetoreUtilisados->numerosRandomicos=malloc(1);

  memset(vetoreUtilisados->palavraEscolhida,0,strlen(vetoreUtilisados->palavraEscolhida)*(sizeof(char)));
  memset(vetoreUtilisados->letrasAcertadasComparacao,0,strlen(vetoreUtilisados->letrasAcertadasComparacao)*(sizeof(char)));
  memset(vetoreUtilisados->letrasUtilizadas,0,strlen(vetoreUtilisados->letrasUtilizadas)*(sizeof(char)));
  memset(vetoreUtilisados->numerosRandomicos,0,(sizeof(char)));
  memset(vetoreUtilisados->letrasUtilizadas,' ',strlen(vetoreUtilisados->letrasUtilizadas)*(sizeof(char)));
  strcpy(letrasAcertadas, "____________________");
  idxVerificacao=0;
  vetoreUtilisados->errou=0;

}

void finalizaVetores(T_vetores *vetoreUtilisados)
{
  free(vetoreUtilisados->palavraEscolhida);
  free(vetoreUtilisados->letrasUtilizadas);
  free(vetoreUtilisados->letrasAcertadasComparacao);
  free(vetoreUtilisados->numerosRandomicos);
}
