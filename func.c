#include <stdio.h>
#include <string.h>
#include "func.h"

Dicionario **criaDicionario(int size)
{
    //Pode so se retornar direto
    return (Dicionario **)calloc(size, sizeof(Dicionario *));
}


    
int BuscaBinaria(char* chave, Dicionario** dicionario, int e, int d){
    int flag = 1;
    int meio; 

    if( e <= d){
     meio  = (e + d) / 2;
        if (strcmp(dicionario[meio]->palavraOrdenada, chave)== 0)
        {
            while (flag == 1)
            {
                if (strcmp(dicionario[meio]->palavraOrdenada, chave) ==0)
                {
                    meio--; // retorna de posição enquanto for chave.
                }
                else
                    flag = 0;
            }
            return meio;
        }
        else{   
            if(strcmp(dicionario[meio]->palavraOrdenada, chave) < 0)
                return BuscaBinaria(chave, dicionario, meio + 1, d);
            else
                return BuscaBinaria(chave, dicionario, e, meio - 1);
            }
    } 
    return -1;
}

void ImprimeFaixa(char* chave, Dicionario** dicionario, int meio)
{

      //  printf("eeeeee%s ", dicionario[meio]->palavra);

    meio = meio +1;
    int i=0;

    while (strcmp(dicionario[meio]->palavraOrdenada, chave) == 0)
    {

        printf("Anagrama [%d] %s \n",i, dicionario[meio]->palavra);
        meio++;
        i++;
    }
}

//Const faz com que o ponteiro não possa ser alterado
Dicionario *inserePalavra(const char palavra[], const unsigned int pos)
{
  
    int c=0;
    char ch;
    int size = strlen(palavra);
    char *temp = calloc(size, sizeof(char));
    strcpy(temp, palavra);

   while (palavra[c] != '\0') {
      ch = temp[c];
      if (ch >= 'A' && ch <= 'Z')
         temp[c] = temp[c] + 32;
      c++;  
   }
    temp[size-1] = '\0';

    Dicionario *d = (Dicionario *)malloc(sizeof(Dicionario));
    d->palavra = temp;
    return d;
}


char *OrdenaPalavra(Dicionario *dicionario){

    unsigned long size = strlen(dicionario->palavra);
    char *temp = calloc(size, sizeof(char));

    strcpy(temp, dicionario->palavra);
    char aux;
    int n = strlen(temp);

    for (int i = 0; i < n; i++)
    {
        for (int j = (i+1) ; j < n; j++)
        {
            if ((int)temp[i] > (int)temp[j])
            {
                aux = temp[i];
                temp[i] = temp[j];
                temp[j] = aux;
            }
        }
    }
    return temp;

}


char *OrdenaChave(const char* chave){

    int size = strlen(chave);
    char *temp = calloc(size, sizeof(char));
    strcpy(temp, chave);
    char aux;
    int n = strlen(temp);
  
    for (int i = 0; i < n; i++)
    {
        for (int j = (i+1) ; j < n; j++)
        {
            if ((int)temp[i] > (int)temp[j])
            {
                aux = temp[i];
                temp[i] = temp[j];
                temp[j] = aux;
            }
        }
    }

    return temp;

}

int sizeFile()
{
    FILE *arquivo = fopen("br.txt", "r");
    int lines = 0;
    char palavra[255];
    char *linha;

    while (!feof(arquivo))
    {
        linha = fgets(palavra, 255, arquivo);
        if (linha)
            lines++;
    }
    fclose(arquivo);

    return lines;
}

void insereDicionario(Dicionario **dicionario)
{

    FILE *arquivo;
    char palavra[100];
    char *linha;
    unsigned int i = 0;

    arquivo = fopen("br.txt", "r");
    if (arquivo == NULL)
    {
        printf("arquivo vazio");
    }
    while (!feof(arquivo))
    {
        linha = fgets(palavra, 100, arquivo);
        if (linha)
        {
            dicionario[i] = inserePalavra(linha, i);
            dicionario[i]->palavraOrdenada = OrdenaPalavra(dicionario[i]);
            i++;
        }
    }
    fclose(arquivo);
}

//É uma boa pratica fazer uma funcao de printar o vetor
void printDicionario(Dicionario **dicionario, const int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("\npalavra %d : %s ", i, dicionario[i]->palavra);
        printf("palavra ordenada %d: %s \n",i, dicionario[i]->palavraOrdenada);
    }
}


void troca(char  **arg1, char  **arg2)
{
     char *tmp = *arg1;
    *arg1 = *arg2;
    *arg2 = tmp;
}

void quicksort(Dicionario** dicionario, unsigned int len) //quick sort swap(varredura)
{
    unsigned int i, pivo=0;

    if (len <= 1)
        return;

    troca(dicionario+((unsigned int)rand() % len), dicionario+len-1);  // troca para um valor qualquer menor que o valor chave

    for (i=0;i<len-1;++i) // reseta a chave pra zero e escaneia
    {
        if (strcmp(dicionario[i]->palavraOrdenada, dicionario[len-1]->palavraOrdenada) < 0) // strcmp retorna zero se dicionario[i]->palavraOrdenada for menor que  dicionario[len-1]->palavraOrdenada
            troca(dicionario+i, dicionario+pivo++);
    }

    // move a chave para seu lugar
    troca(dicionario+pivo, dicionario+len-1);

    // invoca a subsequencia recursiva
    quicksort(dicionario, pivo++);
    quicksort(dicionario+pivo, len - pivo);
}

char* deixaMinusculo(const char* palavra){
    int c=0;
    char ch;
    int size = strlen(palavra);
    char *temp = calloc(size, sizeof(char));
    strcpy(temp, palavra);

   while (palavra[c] != '\0') {
      ch = temp[c];
      if (ch >= 'A' && ch <= 'Z')
         temp[c] = temp[c] + 32;
      c++;  
   }

   return temp;
}

