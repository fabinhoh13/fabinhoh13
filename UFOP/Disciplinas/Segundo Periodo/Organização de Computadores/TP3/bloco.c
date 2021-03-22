#include <stdio.h>
#include <stdlib.h>
#include "bloco.h"
#define N 50

struct bloco {
    double* palavras;
    int endBloco;
    _Bool att;
    double time;
};

Bloco* criaBloco() {
    Bloco* aux = malloc(sizeof(Bloco));
    
    double* palavras = malloc( 4 * sizeof(double));
    aux->palavras = palavras;
    aux->att = false;
    aux->time = 0.00;
    aux->endBloco = -1;

    return aux;
}

Bloco* criaBloco2( int endBloco ) {
    Bloco* aux = malloc(sizeof(Bloco));
    double* palavras = malloc( 4 * sizeof(double));

    for( int i = 0; i < 4; i++ )
        palavras[i] = rand() % N;

    aux->palavras = palavras;
    aux->att = false;
    aux->time = clock() / (double)CLOCKS_PER_SEC;
    aux->endBloco = endBloco;

    return aux;
}

Bloco** criaBloco3( int tamanho ) {
    Bloco** aux = malloc( tamanho * sizeof(Bloco*));
    for( int i = 0; i < tamanho; i++ )
        aux[i] = NULL;

    return aux;
}

Bloco** criaBloco4( int tamanho ) {
    Bloco** aux = malloc( tamanho * sizeof(Bloco*));
    for( int i = 0; i < tamanho; i++ )
        aux[i] = criaBloco2( i );

    return aux; 
}

void liberaBloco( Bloco* block ) {
    free(block->palavras);
    free(block);
}

void liberaBloco2( Bloco** block, int tamanho ) {
    int confere = 0;
    for(int i = 0; i < tamanho; i++ ) {
        if( block[i] != NULL ) {
            free(block[i]->palavras);
            free(block[i]);
            confere++;
        }
    }    

    if( confere != 0 )
        free(block);    
}

void liberaBloco3( Bloco** block ) {
    free(block);
}

Bloco* getBloco( Bloco** block, int indice ) {
    return block[indice];
}

void setBloco( Bloco** block, Bloco* block1, int indice ) {
    block[indice] = block1;
}

void setBloco1( Bloco** block, Bloco* block1, int indice ) {
    block1 = block[indice];
}

void setBlocoUnico( Bloco* block, Bloco* block1 ) {
    block = block1;
}


void setBlocoNull( Bloco* block ) {
    block = NULL;
}

double* getBlocoPalavras( Bloco* block ) {
    return block->palavras;
}

void setBlocoPalavras( Bloco* block, double* conteudo ) {
    block->palavras = conteudo;
}

double getBlocoPalavra( Bloco* block, int indice ) {
    return block->palavras[indice];
}

void setBlocoPalavra( Bloco* block, double conteudo, int indice ) {
    block->palavras[indice] = conteudo;
}

int getBlocoEndereco( Bloco* block ) {
    return block->endBloco;
}

void setBlocoEndereco( Bloco* block, int conteudo ) {
    block->endBloco = conteudo;
}

_Bool getBlocoAtt( Bloco* block ) {
    return block->att;
}

void setBlocoAttTrue( Bloco* block ) {
    if( block->att == false )
        block->att = true;
}

void setBlocoAttFalse( Bloco* block ) {
    if( block->att == true )
        block->att = false;
}

double getBlocoTime( Bloco* block ) {
    return block->time;
}

void setBlocoTime( Bloco* block ) {
    block->time = clock() / (double)CLOCKS_PER_SEC;
}

void setBlocoTimeZero( Bloco* block ) {
    block->time = 0;
}

void printaBloco( Bloco* block, int count ) {
    if( block != NULL ) {
        double p1 = getBlocoPalavra( block, 0 );
        double p2 = getBlocoPalavra( block, 1 );
        double p3 = getBlocoPalavra( block, 2 );
        double p4 = getBlocoPalavra( block, 3 );

        printf("%d - %.0lf %.0lf %.0lf %.0lf\n", count + 1, p1, p2, p3, p4);
        printf("\n");
    }
}

Bloco *criaBlocoHD (double *palavras, int end){
    Bloco *novo = malloc (sizeof(Bloco));
    novo->att = false;
    novo->palavras = palavras;
    novo->endBloco = end; 
    novo->time = clock() / (double)CLOCKS_PER_SEC;
    return novo;
}