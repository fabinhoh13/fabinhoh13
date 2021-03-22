#include <stdlib.h>
#include <stdio.h>
#include "cache.h"

struct cache {
    Bloco** block;
    int tamanho;
    int hit;
    int miss;
};

Cache* criaCache( int tamanho ) {
    Cache* aux = malloc(sizeof(Cache));

    Bloco** aux1 = criaBloco3( tamanho );
    aux->block = aux1;
    aux->tamanho = tamanho;
    aux->hit = 0;
    aux->miss = 0;

    return aux;
}

Cache* criaCache2( int tamanho ) {
    Cache* aux = malloc(sizeof(Cache));

    Bloco** aux1 = criaBloco4( tamanho );
    aux->block = aux1;
    aux->tamanho = tamanho;
    aux->hit = 0;
    aux->miss = 0;

    return aux;
}

void liberaCache( Cache* cch ) {
    liberaBloco2( cch->block, cch->tamanho );
    free(cch);
}

void liberaCache2( Cache* cch ) {
    liberaBloco3(cch->block);
    free(cch);
}

Bloco* getCacheBloco( Cache* cch, int indice ) {
    return getBloco( cch->block, indice );
}

void setCacheBloco( Cache* cch, Bloco* block, int indice ) {
    setBloco( cch->block, block, indice );
}

void setCacheBloco1( Cache* cch, Bloco* block, int indice ) {
    setBlocoUnico( block, getCacheBloco( cch, indice ) );
}

int getCacheTamanho( Cache* cch ) {
    return cch->tamanho;
}

void setCacheTamanho( Cache* cch, int tamanho ) {
    cch->tamanho = tamanho;
}

int getCacheHit( Cache* cch ) {
    return cch->hit;
}

void setCacheHit( Cache* cch ) {
    cch->hit += 1;
}

int getCacheMiss( Cache* cch ) {
    return cch->miss;
}

void setCacheMiss( Cache* cch ) {
    cch->miss += 1;
}

void printaCaches( Cache* L1, Cache* L2, Cache* L3, Cache* RAM ) {
    double p1, p2, p3, p4;
    int b;
    printf("\nCache L1: Cache Hit - %d   Cache Miss - %d\n\n", getCacheHit( L1 ), getCacheMiss( L1 ));
    for( int i = 0; i < L1->tamanho; i++ ) {
        if( getCacheBloco( L1, i ) == NULL )
            printf("Bloco %d Vazio\n", i + 1);

        else {
            b = getBlocoEndereco( getCacheBloco( L1, i ) );
            p1 = getBlocoPalavra( getCacheBloco( L1, i ), 0 );
            p2 = getBlocoPalavra( getCacheBloco( L1, i ), 1 );
            p3 = getBlocoPalavra( getCacheBloco( L1, i ), 2 );
            p4 = getBlocoPalavra( getCacheBloco( L1, i ), 3 );
            printf("Bloco %d:\nMain: %d   Palavra 1 - %.0lf   Palavra 2 - %.0lf  Palavra 3 - %.0lf  Palavra 4 - %.0lf\n", i + 1, b, p1, p2, p3, p4);
        }
    }

    printf("\nCache L2: Cache Hit - %d   Cache Miss - %d\n\n", getCacheHit( L2 ), getCacheMiss( L2 ));
    for( int i = 0; i < L2->tamanho; i++ ) {
        if( getCacheBloco( L2, i ) == NULL )
            printf("Bloco %d Vazio\n", i + 1);

        else {
            b = getBlocoEndereco( getCacheBloco( L2, i ) );
            p1 = getBlocoPalavra( getCacheBloco( L2, i ), 0 );
            p2 = getBlocoPalavra( getCacheBloco( L2, i ), 1 );
            p3 = getBlocoPalavra( getCacheBloco( L2, i ), 2 );
            p4 = getBlocoPalavra( getCacheBloco( L2, i ), 3 );
            printf("Bloco %d:\nMain: %d   Palavra 1 - %.0lf   Palavra 2 - %.0lf  Palavra 3 - %.0lf  Palavra 4 - %.0lf\n", i + 1, b, p1, p2, p3, p4);
        }
    }

    printf("\nCache L3: Cache Hit - %d   Cache Miss - %d\n\n", getCacheHit( L3 ), getCacheMiss( L3 ));
    for( int i = 0; i < L3->tamanho; i++ ) {
        if( getCacheBloco( L3, i ) == NULL )
            printf("Bloco %d Vazio\n", i + 1);

        else {
            b = getBlocoEndereco( getCacheBloco( L3, i ) );
            p1 = getBlocoPalavra( getCacheBloco( L3, i ), 0 );
            p2 = getBlocoPalavra( getCacheBloco( L3, i ), 1 );
            p3 = getBlocoPalavra( getCacheBloco( L3, i ), 2 );
            p4 = getBlocoPalavra( getCacheBloco( L3, i ), 3 );
            printf("Bloco %d:\nMain: %d   Palavra 1 - %.0lf   Palavra 2 - %.0lf  Palavra 3 - %.0lf  Palavra 4 - %.0lf\n", i + 1, b, p1, p2, p3, p4);
        }
    }

    printf("Memoria RAM: Cache Hit - %d   Cache Miss - %d\n\n", getCacheHit( RAM ), getCacheMiss( RAM ));
    for( int i = 0; i < RAM->tamanho; i++ ) {
        if( getCacheBloco( RAM, i ) == NULL )
            printf("Bloco %d Vazio\n", i + 1);

        else {
            b = getBlocoEndereco( getCacheBloco( RAM, i ) );
            p1 = getBlocoPalavra( getCacheBloco( RAM, i ), 0 );
            p2 = getBlocoPalavra( getCacheBloco( RAM, i ), 1 );
            p3 = getBlocoPalavra( getCacheBloco( RAM, i ), 2 );
            p4 = getBlocoPalavra( getCacheBloco( RAM, i ), 3 );
            printf("Bloco %d:\nMain: %d   Palavra 1 - %.0lf   Palavra 2 - %.0lf  Palavra 3 - %.0lf  Palavra 4 - %.0lf\n", i + 1, b, p1, p2, p3, p4);
        }
    }
}

void setCacheBlocoNull( Cache* cch ) {
    setBlocoNull( getBloco( cch->block, 0 ) );
}
