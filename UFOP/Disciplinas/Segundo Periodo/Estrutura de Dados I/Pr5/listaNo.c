#include "listaNo.h"

struct no{
    int data;
    ListaNo *prox;
};

ListaNo *no_cria (void){
    ListaNo *new = malloc (sizeof (ListaNo));
    return new;
}

void no_libera (ListaNo *n){
    free(n);
}

int getDadoNo (ListaNo *n){
    return n->data;
}

void setDadoNo (ListaNo *n, int dado){
    n->data = dado;
}

void setNoProx (ListaNo *n, ListaNo *novo){
    n->prox = novo;
}

ListaNo *getNoProx (ListaNo *n){
    return n->prox;
}