#include <stdio.h>
#include "func.h"

int main()
{
  int pos;
  char* palavra = "";
  int length = sizeFile();
  Dicionario **dicionario = criaDicionario(length);
  insereDicionario(dicionario);

  quicksort(dicionario, length);

  printDicionario(dicionario, length);

  palavra = OrdenaChave(palavra);
  palavra = deixaMinusculo(palavra);

  pos = BuscaBinaria(palavra, dicionario, 0, length);
  printf("\n\nPosição inicial dos Anagramas: %d\n", pos);

 
  ImprimeFaixa(palavra,dicionario,pos);


  return 0;
}

