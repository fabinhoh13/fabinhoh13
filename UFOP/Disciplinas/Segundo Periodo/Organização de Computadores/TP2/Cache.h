#include "BlocoMemoria.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct cache Cache;

Cache *criaCache (int tam);
int getCacheTamanho (Cache *aux);
void setCacheTamanho (Cache *aux, int tamanho);
int getCusto (Cache *aux);
void setCusto (Cache *aux, int custo);
int getCacheHit (Cache *aux);
void setCacheHit (Cache *aux, int cacheHit);
int getCacheMiss (Cache *aux);
void setCacheMiss (Cache *aux, int cacheMiss);
Cache *getCache (Cache **aux, int indice);
BlocoMemoria **getCacheBloco(Cache *aux);
void setAtualizado (Cache *aux);
int getAtualizado (Cache *aux);
void trocaCaches (Cache *primeiro, Cache *segundo, int endBloco);
void RAM_L3(BlocoMemoria **RAM, Cache *L3, int endBloco);
BlocoMemoria *getBlocoMenosAtualizado(Cache *aux);
