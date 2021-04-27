

typedef struct Dicionario
{
    char *palavra;
    char *palavraOrdenada;

} Dicionario;

int sizeFile();
int converte_letras(char c);
char *ordenaLinha(char palavra[]);
Dicionario **criaDicionario(int size);
void insereDicionario(Dicionario **dicionario);
void ImprimeFaixa(char* chave, Dicionario** dicionario, int meio);
int BuscaBinaria(char* chave, Dicionario** dicionario, int e, int d);
void printDicionario(Dicionario **dicionario, const int size);
char *OrdenaPalavra(Dicionario *dicionario);
Dicionario *inserePalavra(const char palavra[], const unsigned int pos);
void quicksort(Dicionario** dicionario, unsigned int len);
int separa (Dicionario** dicionario, int p, int r);
char *OrdenaChave(const char* chave);
char *deixaMinusculo(const char* palavra);
