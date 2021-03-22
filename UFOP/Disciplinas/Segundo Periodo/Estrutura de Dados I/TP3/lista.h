#ifndef LISTA_H
#define LISTA_H

#include "word.h"
#include <stdbool.h>

typedef struct lista Lista;
typedef struct listaNo ListaNo;

Lista* criaLista();
Lista** criaVetorLista( int );
void deletaListaNo( ListaNo* );
void deletaLista( Lista* );
ListaNo* getPrimeiro( Lista* );
ListaNo* getProximo( ListaNo* );
Palavra* getListaNoPalavra( ListaNo* );
Palavra* procuraPalavra( Lista*, char* );
int listaVazia( Lista* );
bool deletaListaPalavra( Lista*, char* );
int printaLista( Lista* );
void inserePalavra( Lista*, Palavra* );
void deletaListaNoPalavra( Lista*, Palavra* );

#endif