#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdlib.h>

void selection(int *v , int tam);
void mergeSort(int *v , int tam);
void mergeSort_ordena (int *v , int esq , int dir );
void mergeSort_intercala (int *v ,int esq ,int meio ,int dir );
void bubble (int *v, int tam);
int buscaBinaria (int *v, int esq, int dir, int num);
void insertionBinary (int *v, int tam);


#endif