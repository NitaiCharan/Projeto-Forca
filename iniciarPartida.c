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
int idxVerificao=0;//Variavel usada na função verificaLetra com a utilidade ve mudar indice da letrasUtilizadas
int naoTinha=1;//Tem a função de verificar se letra vetra ja foi usada. Caso já, aparecerá mensagem na tela
int acertou=0;//Verifica se usuário acertou a letra. Caso sim, exibe a mensagem de acerto


void iniciarPartida(char dificuldade){
  zeraLetras();
  palavraDaVez(dificuldade);


  int errou =0;
  if(dificuldade == 'F'){

    for (errou=0; errou < QUANTIDADEFACIL;errou++){
      mensagens(QUANTIDADEFACIL,errou);
      errou=verificaLetra(errou,QUANTIDADEFACIL);
      errou=verificaPalavras(QUANTIDADEFACIL,errou);
    }
  }
  else{
    for (errou=0; errou < QUANTIDADEFACIL;errou++){
      mensagens(QUANTIDADEDIFICIL,errou);
      errou=verificaLetra(errou,QUANTIDADEDIFICIL);
      errou=verificaPalavras(QUANTIDADEDIFICIL,errou);

    }
  }
}


//Função ira celecionar palavra escolhida randomicamente
void palavraDaVez(char dificuldade){
  srand( (unsigned) time(NULL) );//criação da semente para o rand() com o tempo tatual
  if (dificuldade == 'F') strcpy(palavraEscolhida,facil[rand()%17]) ;
  else strcpy(palavraEscolhida,dificil[rand()%15]);
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

  printf("\n\n%s\n\n", palavraEscolhida);
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
  int j;
  for (j=0;j < strlen(letrasUtilizadas);j++){
    letrasUtilizadas[j]=' ';
  }
  for (j=0;j < strlen(letrasAcertadas);j++){
    letrasAcertadas[j]='_';
  }
  for (j=0;j <= 20;j++){
    letrasAcertadasComparacao[j]=0;
  }
  idxVerificao=0;
}


int verificaLetra(int errou,int quantidade){

  if(digitada[0]=='0')
  {
    char escolha;
    //LIMPATELA;
    printf("\n\nDeseja salvar esta partida (S/N)?\n>");
    scanf("%c", &escolha);

    return quantidade+1;
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
      letrasUtilizadas[idxVerificao]=digitada[0];

      idxVerificao+=1;
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
