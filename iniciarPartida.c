#include "biblioteca.h"
#include "string.h"
#define QUANTIDADEFACIL 3
#define QUANTIDADEDIFICIL 5



void palavraDaVez(char);//Gerando paralava randomicamente
void mensagens(int,int);
void zeraLetras();//Zera letrasUtilizadas letrasAcertadas
int verificaLetra(int,int);//Verifica se letra analizada esta no vetor palavra
int verificaPalavras(int,int);//Verifica se o verto letrasAcertadas esta igual a palavraEscolhida. Caso sim, acaba o jogo

char facil[][11] = {"melhor", "grande", "claro", "azul", "vermelho","preto", "branco", "casa", "tempo", "felicidade", "bondade", "vida","caneta", "cavalo", "trem", "golpe", "cosmos"};
char dificil[][17] = {"procrastinar", "prolegomenos", "vicissitudes", "pernostico", "oprobrio", "idiossincrasia", "elucubracoes", "chistoso", "acrimonia", "combustivel", "concurso", "protesto", "governo", "paquiderme", "tamandare"};
char palavraEscolhida[17];//Variavel utilizada para gurdar palavra da vez
char letrasUtilizadas[25]="                        ";//Vetor que vai conter letras tentadas pelo usuário
char letrasAcertadas[21]="____________________";//Vetor que vai conter letras acertadas pelo usuário
char letrasAcertadasComparacao[17]="";//Vetor criado para comparar palavraEscolhida e verificar se usuário já acertou a palavraEscolhida
char digitada[2];//Vetor que vai conter letras que o usuário esta tentando
int idx=0;//Variavel usada para conter indice
int idxVerificacao=0;//Variavel usada na função verificaLetra com a utilidade ve mudar indice da letrasUtilizadas
int naoTinha=1;//Tem a função de verificar se letra vetra ja foi usada. Caso já, aparecerá mensagem na tela
int acertou=0;//Verifica se usuário acertou a letra. Caso sim, exibe a mensagem de acerto
int numerosRandomicos[17]={0};//Vetor vai conter todos os números gerado pela função rand() para escolhar palavraDaVez
int randomicoDaVez=0;//Contador de numoros gerados.
int limparandomico=0;//veriavel para controlar quando vetor numerosRandomicos e randomicoDaVez devem ser limpos

void iniciarPartida(char dificuldade){
  int errou =0;
  limparandomico=0;//para limpar vetor e Variavel randomicas todas vez que iniciarPartida vor processado
  do {
    zeraLetras();
    palavraDaVez(dificuldade);


    if(dificuldade == 'F'){
      if(randomicoDaVez<18)//para verificar se quantidade de numeros randomicos ultrapassou quantidade de palavras
      {
        for (errou=0; errou < QUANTIDADEFACIL;errou++){
          mensagens(QUANTIDADEFACIL,errou);
          errou=verificaLetra(errou,QUANTIDADEFACIL);
          errou=verificaPalavras(QUANTIDADEFACIL,errou);
        }
      }
      else errou =666;

    }
    else{
      if(randomicoDaVez<16)//para verificar se quantidade de numeros randomicos ultrapassou quantidade de palavras
      {
        for (errou=0; errou < QUANTIDADEDIFICIL;errou++){
          mensagens(QUANTIDADEDIFICIL,errou);
          errou=verificaLetra(errou,QUANTIDADEDIFICIL);
          errou=verificaPalavras(QUANTIDADEDIFICIL,errou);
        }
      }
      else errou =666;
    }
  } while(errou < 660);
}


//Função ira celecionar palavra escolhida randomicamente
void palavraDaVez(char dificuldade){
  srand( (unsigned) time(NULL) );//criação da semente para o rand() com o tempo tatual
  if (dificuldade == 'F')
  {
    /*
    Esta função so ecolhera um numero caso as vezes tentadas em gerar numeros randomicos for
    igual ao contador de vez que o programa foi processado(randomicoDaVez).
    */
    int saida=0;
    do {

      int idx2=0;
      int randomico=rand()%18;
      //printf("#############  idx2 %d == randomicoDaVez %d\n",idx2, randomicoDaVez);
      //getchar();

      for (idx2=0;idx2<randomicoDaVez;idx2++)
      {
        //printf("#############  numerosRandomicos %d == randomico %d\n",numerosRandomicos[idx2], randomico);
        //getchar();
        if (numerosRandomicos[idx2]==randomico)
        {
          idx2=0;
          randomico=rand()%18;
        }

      }

      //printf("#############  idx2 %d == randomicoDaVez %d\n",idx2, randomicoDaVez);
      //getchar();
      if(idx2==randomicoDaVez)
      {
        strcpy(palavraEscolhida,facil[randomico]);
        numerosRandomicos[randomicoDaVez]=randomico;
        randomicoDaVez++;
        saida=17;
      }
    } while(saida<17);
  }


  else
  {
    /*
    Esta função so ecolhera um numero caso as vezes tentadas em gerar numeros randomicos for
    igual ao contador de vez que o programa foi processado(randomicoDaVez).
    */

    int saida=0;
    do {
      int idx2=0;
      int randomico=rand()%16;
      for (idx2=0;idx2<randomicoDaVez;idx2++)
      {
        if (numerosRandomicos[idx2]==randomico)
        {
          idx2=0;
          randomico=rand()%16;
        }
      }

      if(idx2==randomicoDaVez)
      {
        strcpy(palavraEscolhida,dificil[randomico]);
        numerosRandomicos[randomicoDaVez]=randomico;
        randomicoDaVez++;
        saida=15;
      }
    } while(saida<15);
  }
}


void mensagens(int QUANTIDADE,int errou){
  int i=0;
  LIMPATELA;
  printf("Letras já utilizadas: ");
  for(i=0; i<strlen(letrasUtilizadas);i++){
    printf(" %c",letrasUtilizadas[i]);
  }


  printf("\n\nPalavra: ");
  for(i=0; i<strlen(palavraEscolhida);i++){
    printf(" %c",letrasAcertadas[i]);
  }
//#####################################################################
  printf("\n\n%s\n\n", palavraEscolhida);
  int idx1;
  for(idx1=0;idx1<randomicoDaVez;idx1++)
  {
    printf("%d,", numerosRandomicos[idx1]);
  }
  printf("\n\n");
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
    printf("\n\nEntre uma letra (0 para sair). %d tentativas restantes.\n>",QUANTIDADE - errou);
    scanf("%s",digitada);
    //verifica se usuário colocou mais de uma letra
    if (strlen(digitada)>1)printf("\n\nOi? Isso não é uma letra.\n");
  } while(strlen(digitada)>1);
  flush();
}


void zeraLetras(){
  strcpy(letrasUtilizadas,"                        ");
  strcpy(letrasAcertadas,"____________________");
  memset(letrasAcertadasComparacao,0,17*sizeof(char));
  idxVerificacao=0;
  if (limparandomico==0)
  {
    memset(numerosRandomicos,0,17*sizeof(char));
    randomicoDaVez=0;
    limparandomico=1;
  }
}


int verificaLetra(int errou,int quantidade){

  if(digitada[0]=='0')
  {
    char escolha;
    //LIMPATELA;
    printf("\n\nDeseja salvar esta partida (S/N)?\n>");
    scanf("%c", &escolha);
    flush();

	if (escolha!='N')
	{

		FILE *listas;
  		listas = fopen("dados.txt","w"); // Abertura do arquivo dados.txt

  		//Verificando se o arquivo existe
  		if(listas == NULL)
  		{
			printf("Erro na abertura do arquivo\n");
			exit(1);
  		}
		fprintf(listas, "%s\n", letrasUtilizadas); //Grava no arquivo dados.txt as letras j� utilizadas pelo us�ario.
		fprintf(listas, "%s\n", palavraEscolhida); //Grava no arquivo dados.txt a palavra da vez.
		fprintf(listas, "%s\n", letrasAcertadas);  //Grava no arquivo dados.txt as letras acertadas.
		fclose(listas);
	}

    return 666;

  }

  else
  {
    //verifica se letra esta dentro do vetor letrasUtilizadas. Caso sim,não continua processo de verificação
    int j;
    for(j=0; j<strlen(letrasUtilizadas);j++){
      if(letrasUtilizadas[j]==digitada[0]) {
        naoTinha=0;
        errou--;//Para não contar vez tentada
        break;
      }
    }
    if (naoTinha)
    {
      letrasUtilizadas[idxVerificacao]=digitada[0];

      idxVerificacao+=1;
      int i=0;
      for(idx=0;idx<strlen(palavraEscolhida);idx++){
        if(palavraEscolhida[idx]==digitada[0]){
          letrasAcertadasComparacao[idx]=digitada[0];
          letrasAcertadas[idx]=digitada[0];
          i++;
        }
      }


      if(i>0){
        errou--;
        acertou=1;
      }
      else{
        acertou=666;
      }
    }
  }

  return errou;
}


int verificaPalavras(int quantidade,int errou){


  if(strcmp(letrasAcertadasComparacao,palavraEscolhida)==0){
    printf("\nParabéns! Você ganhou. A palavra era '%s'.\nPressione enter para continuar...",palavraEscolhida);
    getchar();
    acertou=0;

    return quantidade;//atribuição de erro ser igual a QUANTIDADE para quebrar "for" da verificação. for (errou=0; errou < QUANTIDADEFACIL;errou++)
  }
  if((errou+1)==quantidade){
    printf("Jogo encerrado. Você perdeu. A palavra era '%s'.\nPressione enter para continuar...",palavraEscolhida);
    getchar();
    acertou=0;
    return quantidade;
  }
  return errou;
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
