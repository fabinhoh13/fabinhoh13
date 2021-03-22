#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct fila Fila;
typedef struct filano FilaNo;

Fila *criaFilaVazia();

FilaNo *criaFilaNo(char *processo, int id, time_t tempo);
void inserePrimeiro (Fila *f, char *processo, int id, time_t tempo);
void insereFinal (Fila *f, char *processo, int id, time_t tempo);
void removeInicio (Fila *f);
void imprimeFila (Fila *f);

//sets

void setId (FilaNo *f, int id);
void setProcesso (FilaNo *f, char *processo);
void setInclusao (FilaNo *f, time_t tempo);

//gets

int getId (FilaNo *f);
char *getProcesso (FilaNo *f);
time_t getInclusao (FilaNo *f);

