#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct lista {
    ListaNo* primeiro;
};

struct listaNo {
    Palavra* word;
    ListaNo* proximo;
};

Lista* criaLista() {
    Lista* aux = malloc( sizeof(Lista) );
    aux->primeiro = NULL;

    return aux;
}

Lista** criaVetorLista( int tamanho ) {
    Lista** aux = malloc( tamanho * sizeof(Lista*) );

    return aux;
}

void deletaListaNo( ListaNo* list ) {
    deletaPalavra( list->word );
    free(list);
}

void deletaLista( Lista* list ) {
    ListaNo* aux = list->primeiro;
    ListaNo* prox;

    while( aux != NULL ) {
        prox = aux->proximo;
        deletaPalavra( aux->word );
        free( aux );
        aux = prox;
    }

    free(list);
}

ListaNo* getPrimeiro( Lista* list ) {
    return list->primeiro;
}

ListaNo* getProximo( ListaNo* list ) {
    return list->proximo;
}

Palavra* getListaNoPalavra( ListaNo* list ) {
    return list->word;
}

Palavra* procuraPalavra( Lista* list, char* palavra ) {
    for( ListaNo* aux = list->primeiro; aux != NULL; aux = aux->proximo ) {
        if( strcmp( getPalavra( aux->word ), palavra ) == 0 )
            return aux->word;    
    }

    return NULL;
}

int listaVazia( Lista* list ) {
    if( list->primeiro == NULL )
        return 1;

    else
        return 0;
}

bool deletaListaPalavra( Lista* list, char* palavra ) {
    Palavra* word = procuraPalavra( list, palavra );

    if( word == NULL )
        return false;

    else {
        deletaPalavra( word );
        deletaListaNoPalavra( list, word );

        return true;
    }
}

int printaLista( Lista* list ) {
    bool verifica = false;

    for( ListaNo* aux = list->primeiro; aux != NULL; aux = aux->proximo ) {
        printf("\nPalavra: %s\n", getPalavra( aux->word ) );
        printf("Repeticoes: %d\n", getContador( aux->word ) );    

        if( list->primeiro != NULL )
            verifica = true;
    }

    if( verifica )
        return 1;

    else
        return 0;
}

void inserePalavra( Lista* list, Palavra* word ) {
    ListaNo* aux = malloc( sizeof(ListaNo) );

    aux->word = word;
    aux->proximo = list->primeiro;
    list->primeiro = aux;
}

void deletaListaNoPalavra( Lista* list, Palavra* word ) {
    ListaNo* anterior = NULL;
    ListaNo* aux = list->primeiro;

    while( aux != NULL && aux->word != word ) {
        anterior = aux;
        aux = aux->proximo;
    }

    if( aux != NULL ) {
        if( anterior == NULL )
            list->primeiro = aux->proximo;

        else
            anterior->proximo = aux->proximo;

        deletaListaNo( aux );
    }
}