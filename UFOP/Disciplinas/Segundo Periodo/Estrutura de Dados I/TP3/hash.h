#ifndef HASH_H
#define HASH_H

#include "lista.h"

typedef struct thash THash;

THash* criaHash( int );
void deletaHash( THash*, int );
ListaNo* procuraListaNoHash( THash*, char* );
int procuraHash( THash*, char* );
int removeHash( THash*, Palavra* );
bool printaHash( THash*, int );
void insereHash( THash*, Palavra* );

#endif