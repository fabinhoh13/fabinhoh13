#include <stdlib.h>
#include <string.h>
#include "hash.h"

struct thash {
    int n;
    int tamanhoLista;
    Lista** list;
};

THash* criaHash( int tamanho ) {
    THash* aux = malloc( sizeof(THash) );

    aux->n = 0;
    aux->tamanhoLista = tamanho;
    aux->list = criaVetorLista( tamanho );

    for( int i = 0; i < tamanho; i++ )
        aux->list[i] = criaLista();

    return aux;
}

void deletaHash( THash* hash, int tamanho ) {
    for( int i = 0; i < tamanho; i++ )
        deletaLista( hash->list[i] );

    free( hash->list );
    free( hash );
}

ListaNo* procuraListaNoHash( THash* hash, char* palavra ) {
    int indice = ( (int)palavra[0] - 97 ) % 26;  
    ListaNo* aux;

    if( listaVazia( hash->list[indice] ) )
        return NULL;

    aux = getPrimeiro( hash->list[indice] );  

    while( getProximo( aux ) != NULL  &&  strcmp( palavra, getPalavra( getListaNoPalavra( aux ) ) ) != 0 )
        aux = getProximo( aux );

    if( strcmp(palavra, getPalavra( getListaNoPalavra( aux ) ) ) == 0 ) {
        acrescentaContador( getListaNoPalavra( aux ) );
        return aux;
    }

    else
        return NULL;
}

int procuraHash( THash* hash, char* palavra ) {
    ListaNo* aux = procuraListaNoHash( hash, palavra );

    if( aux == NULL )
        return 0;

    return 1;
}

int removeHash( THash* hash, Palavra* word ) {
    ListaNo* aux = procuraListaNoHash( hash, getPalavra( word ) );

    if( aux == NULL )
        return 0;

    char palavra[31];
    strcpy( palavra, getPalavra( word ) );
    int indice = ( (int)palavra[0] - 97 ) % 26; 

    if( deletaListaPalavra( hash->list[indice], palavra ) ) {
        hash->n--;
        return 1;
    }

    return 0;
}

bool printaHash( THash* hash, int indice ) {
    if( printaLista( hash->list[indice] ) )
        return true;

    else
        return false;
}

void insereHash( THash* hash, Palavra* word ) {
    char palavra[31];
    strcpy( palavra, getPalavra( word ) );

    if( procuraListaNoHash( hash, palavra ) == NULL ) {
        int indice = ( (int)palavra[0] - 97 ) % 26;
        inserePalavra( hash->list[indice], word );
        hash->n++;
    }
}