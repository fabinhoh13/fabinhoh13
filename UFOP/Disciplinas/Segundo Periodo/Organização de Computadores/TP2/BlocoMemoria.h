

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct blocomem BlocoMemoria;

BlocoMemoria *criaBlocoMemoria ();

int getPalavra (BlocoMemoria *aux, int indice);
void setPalavra (BlocoMemoria *aux, int palavra, int indice);

int *getPalavras (BlocoMemoria *aux);
void setPalavras (BlocoMemoria *aux, int *palavras);

int getEnderecoBloco (BlocoMemoria *aux);
void setEnderecoBloco (BlocoMemoria *aux, int end);
BlocoMemoria *get1Bloco (BlocoMemoria **vetor, int indice);
void set1Bloco (BlocoMemoria **vetor, BlocoMemoria *novo, int indice);
void zeraBlocoAtuazliacao(BlocoMemoria* aux);

int getAtualizacaoBloco (BlocoMemoria *bloco);
void atualizarBlocoAtuazliacao(BlocoMemoria* aux);

time_t getTempoBloco (BlocoMemoria *bloco);
void setTempoBLoco (BlocoMemoria *bloco, time_t tempo);

void preencheRAM (BlocoMemoria **RAM, int tam);