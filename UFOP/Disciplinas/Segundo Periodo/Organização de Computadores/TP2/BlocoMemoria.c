#include "BlocoMemoria.h"

struct blocomem{
    int *palavras;
    int end;
    int atualizacao;
    time_t tempo;
};

BlocoMemoria *criaBlocoMemoria (){
    BlocoMemoria *new = malloc (sizeof(BlocoMemoria));
    
    new->palavras = malloc (4 * sizeof(int));
    new->atualizacao = 0;
    new->end = -1;
    new->tempo = time(NULL);
    
    return new;
}

int getPalavra (BlocoMemoria *aux, int indice){
    return aux->palavras[indice];
}
void setPalavra (BlocoMemoria *aux, int palavra, int indice){
    aux->palavras[indice] = palavra;
}

int *getPalavras (BlocoMemoria *aux){
    return aux->palavras;
}
void setPalavras (BlocoMemoria *aux, int *palavras){
    aux->palavras = palavras;
}

int getEnderecoBloco (BlocoMemoria *aux){
    return aux->end;
}
void setEnderecoBloco (BlocoMemoria *aux, int end){
    aux->end = end;
}

BlocoMemoria *get1Bloco (BlocoMemoria **vetor, int indice){
    return vetor[indice];
}

void set1Bloco (BlocoMemoria **vetor, BlocoMemoria *novo, int indice){
    vetor[indice] = novo;
}

void atualizarBlocoAtuazliacao(BlocoMemoria* aux){
    aux->atualizacao+= 1;
}

void zeraBlocoAtuazliacao(BlocoMemoria* aux){
    aux->atualizacao = 0;
}

int getAtualizacaoBloco (BlocoMemoria *bloco){
    return bloco->atualizacao;
}

time_t getTempoBloco (BlocoMemoria *bloco){
    return bloco->tempo;
}

void setTempoBLoco (BlocoMemoria *bloco, time_t tempo){
    bloco->tempo = tempo;
}

void preencheRAM (BlocoMemoria **RAM, int tam){
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < 4; j++){
            RAM[i]->palavras[j] = rand() % 10000;
        }
        RAM[i]->end = i;
    }
}
