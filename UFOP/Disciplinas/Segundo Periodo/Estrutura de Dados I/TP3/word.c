#include <stdlib.h>
#include <string.h>
#include "word.h"

struct palavra {
    int contador;
    char palavra[31];
};

Palavra* criaPalavra( char* palavra ) {
    Palavra* aux = malloc( sizeof(Palavra) );
    aux->contador = 1;
    strcpy( aux->palavra, palavra );

    return aux;
}

void deletaPalavra( Palavra* word ) {
    free( word );
}

int getContador( Palavra* word ) {
    return word->contador;
}

void setContador( Palavra* word, int contador ) {
    word->contador = contador;
}

char* getPalavra( Palavra* word ) {
    return word->palavra;
}

void setPalavra( Palavra* word, char* palavra ) {
    strcpy( word->palavra, palavra );
}

void acrescentaContador( Palavra* word ) {
    word->contador++;
}