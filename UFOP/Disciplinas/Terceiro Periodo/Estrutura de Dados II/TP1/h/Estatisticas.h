#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct estatistica Estatistica;

Estatistica* criaEst();
int getFreadP(Estatistica* est);
int getComparacoesP(Estatistica* est);
double getTempoP(Estatistica* est);
void setFreadP(Estatistica* est, int valor);
void setFomparacoesP(Estatistica* est, int valor);
void setTempoP(Estatistica* est, double valor);
void incrementaFreadP(Estatistica* est);
void incrementaComparacoesP(Estatistica* est);


#endif