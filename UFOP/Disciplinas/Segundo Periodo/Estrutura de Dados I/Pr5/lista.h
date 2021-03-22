#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdio.h>

#include "listaNo.h"

typedef struct lista Lista;

Lista* lst_cria (void);
void lst_libera (Lista *l);
void lst_insere_inicio (Lista *l, int conteudo);
void lst_insere_final (Lista *l, int conteudo);
int pertence_lista (Lista *l, int valor);
int pertence_no (ListaNo* n, int valor);
void remove_lista (Lista *l, int valor);
void remove_no (ListaNo *n, int valor);
int lst_vazia (Lista* l);
void lst_imprime (Lista *l);
void no_imprime (ListaNo* n);
void lst_remove_inicio (Lista *l);

#endif