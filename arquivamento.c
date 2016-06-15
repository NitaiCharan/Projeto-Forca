#include "biblioteca.h"


void salvarJogo(T_vetores *vetorUtilizado)
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


    lens=(strlen(vetorUtilizado->letrasAcertadas))+1;
    fwrite(&lens,sizeof(int),1,listas);
    fwrite(vetorUtilizado->letrasAcertadas,sizeof(char),lens,listas);

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



void retornoJogoSalvo(T_vetores *vetorUtilizado)
{
  FILE *arq=NULL;
  if ((arq=fopen("dados.dat","rb")))
  {
    int len;

    fread(&len,sizeof(int),1,arq);
    fread(vetorUtilizado->palavraEscolhida,sizeof(char),len,arq);

    fread(&len,sizeof(int),1,arq);
    fread(vetorUtilizado->letrasUtilizadas,sizeof(char),len,arq);

    fread(&len,sizeof(int),1,arq);
    fread(vetorUtilizado->letrasAcertadasComparacao,sizeof(char),len,arq);

    fread(&len,sizeof(int),1,arq);
    fread(vetorUtilizado->letrasAcertadas,sizeof(char),len,arq);

    fread(&(vetorUtilizado->randomicoDaVez),sizeof(int),1,arq);
    fread(vetorUtilizado->numerosRandomicos,sizeof(int),vetorUtilizado->randomicoDaVez,arq);

    fread(&(vetorUtilizado->errou),sizeof(int),1,arq);
    fclose(arq);
  }
}
