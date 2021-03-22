#ifndef TIPOPAGINA_H
#define TIPOpAGINA_H

#include <stdio.h>
#include "experimento.h"

#define ITEM_PER_PAGE 7

typedef struct tipoPagina TipoPagina;

TipoPagina** criaArrayPagina(int);
void preencheArrayPagina(FILE*, TipoPagina**, Experimento*);
void liberaArrayPagina(TipoPagina**, int);

int getChavePaginaPeloIndex(TipoPagina**, int);
int getPosicaoPaginaPeloIndex(TipoPagina**, int);

#endif