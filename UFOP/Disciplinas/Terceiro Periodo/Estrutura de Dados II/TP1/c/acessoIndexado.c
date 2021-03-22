#include "../.h/acessoIndexado.h"
#define N 10

void mainAcessoSequencialIndexado(int tamanhoArq, int chave) {
    arqOrdenadoCrescente(tamanhoArq);

    char nomeArq[40];
    TipoPagina** page = criaArrayPagina(tamanhoArq);
    Experimento* casos = criaExperimento();
    TipoItem* item = criaItem();

    sprintf(nomeArq, "./bin/%d-crescente.bin", tamanhoArq);
    FILE* arqCrescente = fopen(nomeArq, "rb");
    resetaExperimento(casos);
    preencheArrayPagina(arqCrescente, page, casos);
    printaResultados(casos, "Criação das paginas", 1);

    resetaExperimento(casos);
    setItemChave(item, chave);
    int achou = pesquisaAcessoIndexado(page, tamanhoArq, arqCrescente, item, casos);
    printaResultados(casos, "Pesquisa da chave", 1);
    printf("%s\n", achou ? "Item encontrado com sucesso!\n" : "Item não pertence ao arquivo!\n");

    fclose(arqCrescente);

    liberaExperimento(casos);
    liberaArrayPagina(page, tamanhoArq);
}

int pesquisaAcessoIndexado(TipoPagina** listPage, int tamanhoArq, FILE* arq, TipoItem* item, Experimento* casos) {
    /* Etapa inicial que determina o tamanho da lista de paginas, é uma etapa bem recorrente,
         visto que estou alocando apenas o suficiente com o tamanho do arquivo */
    int tamanhoPage = (tamanhoArq / ITEM_PER_PAGE) + 1;
    int i = 0;

    // Procura pela pagina correspondente a chave procurada
    while(i < tamanhoPage && getChavePaginaPeloIndex(listPage, i) <= getItemChave(item)) {
        incrementaExperimentoComparacoes(casos);
        i++;
    }
    incrementaExperimentoComparacoes(casos);

    // Caso no qual a chave desejada é menor que a menor chave do arquivo
    if(i == 0){
        return 0;
    }

    else {
        int qtdItens;
        long deslocamento;
        if(i < tamanhoPage)
            qtdItens = ITEM_PER_PAGE;

        else {
            // Verificação de uma possível pagina nao completa
            seekItem(arq, 0, SEEK_END);
            qtdItens = (ftell(arq) / sizeofItem()) % ITEM_PER_PAGE;
        }

        deslocamento = (getPosicaoPaginaPeloIndex(listPage, i - 1) - 1) * ITEM_PER_PAGE;
        seekItem(arq, deslocamento, SEEK_SET);
        TipoItem** paginaAtual = criaListItens(qtdItens);
        readItens(arq, paginaAtual, qtdItens);

        // Contabiliza numero de leitura na pagina atual
        for(int j = 0; j < qtdItens; j++)
            incrementaExperimentoLeitura(casos);

        for(int j = 0; j < qtdItens; j++) {
            incrementaExperimentoComparacoes(casos);
            if(getItemChave(paginaAtual[j]) == getItemChave(item)) {
                liberaListItens(paginaAtual, qtdItens);
                return 1;
            }
        }

        liberaListItens(paginaAtual, qtdItens);
    }

    return 0;
}
