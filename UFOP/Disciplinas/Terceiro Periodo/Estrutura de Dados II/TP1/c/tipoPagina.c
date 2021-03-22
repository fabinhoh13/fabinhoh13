#include "../.h/tipoPagina.h"
#include "../.h/tipoItem.h"
#include <stdlib.h>
#include <math.h>

struct tipoPagina {
    int chave;
    int posicao;
};

TipoPagina** criaArrayPagina(int tamanhoArq) {
    int tamanhoArray = ceil(tamanhoArq / ITEM_PER_PAGE) + 1;
    TipoPagina** listPages = malloc(tamanhoArray * sizeof(TipoPagina*));
    for(int i = 0; i < tamanhoArray; i++) 
        listPages[i] = malloc(sizeof(TipoPagina));
    
    return listPages;
}

void preencheArrayPagina(FILE* arq, TipoPagina** listPages, Experimento* casos) {
    TipoItem* item = criaItem();
    int index = 0;
    while(readItem(arq, item) == 1) {
        incrementaExperimentoLeitura(casos);
        listPages[index]->chave = getItemChave(item);
        listPages[index]->posicao = index + 1;
        index++;
        seekItem(arq, ITEM_PER_PAGE - 1, SEEK_CUR);
    }
    printf("\n");
}

void liberaArrayPagina(TipoPagina** listPage, int tamanhoArq) {
    int tamanhoPages = ceil(tamanhoArq / ITEM_PER_PAGE) + 1;
    for(int i = 0; i < tamanhoPages; i++)
        free(listPage[i]);
    free(listPage);
}

int getChavePaginaPeloIndex(TipoPagina** listPage, int index) {
    return listPage[index]->chave;
}

int getPosicaoPaginaPeloIndex(TipoPagina** listPage, int index) {
    return listPage[index]->posicao;
}