#include "../.h/tipoBEstrela.h"
#include <stdlib.h>

struct tipoBEstrela{
    TipoIntExt categoriaPagina;
    union {
        struct {
            int tamanhoInterno;
            int vetorChave[MM]; 
            TipoBEstrela* paginaInterna[MM + 1]; 
        } U0;
        struct {
            int tamanhoExterno;
            TipoItem* listItemExterno[MM2]; 
        } U1;
    } UU;
};

TipoBEstrela* criaBEstrela() {
    TipoBEstrela* arvore = malloc(sizeof(TipoBEstrela));

    arvore->UU.U0.tamanhoInterno = 0;
    arvore->UU.U1.tamanhoExterno = 0;

    return arvore;
}

void setEstrelaCategoriaPagina(TipoBEstrela* arvore, TipoIntExt categoria) {
    arvore->categoriaPagina = categoria;
}

void setEstrelaTamanhoInternoIncrementa(TipoBEstrela* arvore, int tamanho) {
    arvore->UU.U0.tamanhoInterno += tamanho;
}

void setEstrelaTamanhoInterno(TipoBEstrela* arvore, int tamanho) {
    arvore->UU.U0.tamanhoInterno = tamanho;
}

void setEstrelaVetorChave(TipoBEstrela* arvore, int index, int chave) {
    arvore->UU.U0.vetorChave[index] = chave;
}

void setEstrelaPaginaInterna(TipoBEstrela* arvore, int index, TipoBEstrela* filho) {
    arvore->UU.U0.paginaInterna[index] = filho;
}

void setEstrelaTamanhoExternoIncrementa(TipoBEstrela* arvore, int tamanho) {
    arvore->UU.U1.tamanhoExterno += tamanho;
}

void setEstrelaTamanhoExterno(TipoBEstrela* arvore, int tamanho) {
    arvore->UU.U1.tamanhoExterno = tamanho;
}

void setEstrelaListItemExterno(TipoBEstrela* arvore, int index, TipoItem* item) {
    setListItens(arvore->UU.U1.listItemExterno, item, index);
}

TipoIntExt getEstrelaCategoriaPagina(TipoBEstrela* arvore) {
    return arvore->categoriaPagina;
}

int getEstrelaTamanhoInterno(TipoBEstrela* arvore) {
    return arvore->UU.U0.tamanhoInterno;
}

int getEstrelaVetorChave(TipoBEstrela* arvore, int index) {
    return arvore->UU.U0.vetorChave[index];
}

TipoBEstrela* getEstrelaPaginaInterna(TipoBEstrela* arvore, int index) {
    return arvore->UU.U0.paginaInterna[index];
}

int getEstrelaTamanhoExterno(TipoBEstrela* arvore) {
    return arvore->UU.U1.tamanhoExterno;
}

TipoItem* getEstrelaListItemExterno(TipoBEstrela* arvore, int index) {
    return getListItens(arvore->UU.U1.listItemExterno, index);
}

int getChaveItemExterno(TipoBEstrela* arvore, int index) {
    return getItemChave(getListItens( arvore->UU.U1.listItemExterno, index ));
}

void liberaBEstrela(TipoBEstrela* arvore) {
    free(arvore);
}