#include <stdlib.h>
#include "endereco.h"

struct endereco {
    int endBloco;
    int endPalavra;
};

Endereco* criaEndereco() {
    Endereco* aux = malloc(sizeof(Endereco));

    aux->endBloco = -1;
    aux->endPalavra = -1;

    return aux;
}

Endereco* criaEndereco2( int endBloco, int endPalavra ) {
    Endereco* aux = malloc(sizeof(Endereco));

    aux->endBloco = endBloco;
    aux->endPalavra = endPalavra;

    return aux;
}

void liberaEndereco( Endereco* add ) {
    free(add);
}

int getEnderecoBloco( Endereco* add ) {
    return add->endBloco;
}

void setEnderecoBloco( Endereco* add, int conteudo ) {
    add->endBloco = conteudo;
}

int getEnderecoPalavra( Endereco* add ) {
    return add->endPalavra;
}

void setEnderecoPalavra( Endereco* add, int conteudo ) {
    add->endPalavra = conteudo;
}