#include "../.h/tipoItem.h"
#include <stdlib.h>

struct tipoItem {
    int chave;
    long dado1;
    char dado2[500];
};

TipoItem** criaListItens(int tamanho) {
    TipoItem** listItens = malloc(tamanho * sizeof(TipoItem*));
    for(int i = 0; i < tamanho; i++)
        listItens[i] = malloc(sizeof(TipoItem));
    
    return listItens;
}

void setDadosExtras(TipoItem** listItens, int index) {
    listItens[index]->dado1 = rand();
    sprintf(listItens[index]->dado2, "Tentando escrever algo que possa parecer pertinente");
}

TipoItem* getListItens(TipoItem** listItens, int index) {
    return listItens[index];
}

void setListItens(TipoItem** listItens, TipoItem* item, int index) {
    listItens[index] = item;
}

void setListItensPeloIndice(TipoItem** listItens, int indice, int chave) {
    listItens[indice]->chave = chave;
}


void liberaListItens(TipoItem** listItens, int tamanho) {
    for(int i = 0; i < tamanho; i++)
        free(listItens[i]);
    free(listItens);
}

TipoItem* criaItem() {
    TipoItem* item = malloc(sizeof(TipoItem));
    return item;
}

int getItemChave(TipoItem* item) {
    return item->chave;
}

void setItemChave(TipoItem* item, int chave) {
    item->chave = chave;
}

void setItensAB (TipoItem ** itens, TipoItem *item){
    (*itens) = item;
}

void setItemAB (TipoItem **itens, int index, TipoItem *item){
    itens[index] = item;
}

void liberaItem(TipoItem* item) {
    free(item);
}

int readItem(FILE* arq, TipoItem* item) {
    return fread(item, sizeof(TipoItem), 1, arq);
}

void readItens(FILE* arq, TipoItem** listItens, int quantidade) {
    for(int i = 0; i < quantidade; i++)
        fread(listItens[i], sizeof(TipoItem), 1, arq);
}

void writeItem(FILE* arq, TipoItem** listItens, int tamanho) {
    for(int i = 0; i < tamanho; i++)
        fwrite(listItens[i], sizeof(TipoItem), 1, arq);
}

void seekItem(FILE* arq, int quantidade, int metodo) {
    fseek(arq, quantidade * sizeof(TipoItem), metodo);
}

unsigned long sizeofItem() {
    return sizeof(TipoItem);
}

void shuffle(TipoItem** listItens, int tamanho) {
    TipoItem* tmp;
    int j;

    for (int i = tamanho - 1; i > 0; i--) {
        j = rand() % (i + 1);
        tmp = listItens[j];
        listItens[j] = listItens[i];
        listItens[i] = tmp;
    }
}
