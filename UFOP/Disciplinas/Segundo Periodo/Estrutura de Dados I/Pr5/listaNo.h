#ifndef LISTANO_H
#define LISTANO_H

#include <stdlib.h>


typedef struct no ListaNo;

ListaNo *no_cria (void);
void no_libera (ListaNo *n);
int getDadoNo (ListaNo *n);
void setDadoNo (ListaNo *n, int dado);
void setNoProx (ListaNo *n, ListaNo *novo);
ListaNo *getNoProx (ListaNo *n);

#endif