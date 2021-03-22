#include <stdlib.h>
#include <stdio.h>


typedef struct endereco Endereco;

Endereco *criaEndereco(int endB, int endP);
int getEndBloco (Endereco *aux);
void setEndBloco (Endereco *aux, int endBloco);
int getEndPalavra (Endereco *aux);
void setEndPalavra (Endereco *aux, int endPalavra);
Endereco *getEndereco (Endereco **aux, int indice);
void setEndereco (Endereco **vetor, Endereco *novo, int indice);