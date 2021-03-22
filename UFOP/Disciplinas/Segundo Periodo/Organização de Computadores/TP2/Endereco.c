#include "Endereco.h"

struct endereco{
    int endBloco;
    int endPalavra;
};

Endereco *criaEndereco(int endB, int endP){
    Endereco *new = malloc(sizeof(Endereco));
    new->endBloco = endB;
    new->endPalavra = endP;
    return new;
}

int getEndBloco (Endereco *aux){
    return aux->endBloco;
}
void setEndBloco (Endereco *aux, int endBloco){
    printf ("Endereço %d do bloco\n", endBloco);
    if (aux == NULL){
        printf ("Deu Ruim aqui\n");
        exit(0);
    }
    aux->endBloco = endBloco;
    printf ("Setado\n");
}

int getEndPalavra (Endereco *aux){
    return aux->endPalavra;
}
void setEndPalavra (Endereco *aux, int endPalavra){
    aux->endPalavra = endPalavra;
}

Endereco *getEndereco (Endereco **aux, int indice){
    return aux[indice];
}

void setEndereco (Endereco **vetor, Endereco *novo, int indice){
    vetor[indice]->endBloco = novo->endBloco;
    vetor[indice]->endPalavra = novo->endPalavra;
}