#ifndef ACESSOINDEXADO_H
#define ACESSOINDEXADO_H

#include "./tipoItem.h"
#include "./tipoPagina.h"
#include "./experimento.h"
#include "geraBinarios.h"

/* Função principal responsável por organizar tudo necessário para a execução do algoritmo de acesso sequencial indexado
   
    Parametros: 
    tamanhoArq(int) - Tamanho do arquivo que sera usado para leitura
    
    chave(int) - chave na qual sera pesquisada */
void mainAcessoSequencialIndexado(int, int);

/* Função responsável de realizar a pesquisa de um determinado item dentro das paginas. Retorna 1 caso o item seja encontrado 
    e 0 caso contrario
    
    Parametros:
    listPage(TipoPagina**) - Vetor contendo todas as paginas já preenchidas de acordo com o arquivo

    tamanhoArq(int) - Tamanho do arquivo

    arq(FILE*) - Arquivo utilizado para pesquisar a chave apos ser encontrada em alguma das paginas 
    
    item(TipoItem*) - Item que sera pesquisado
    
    casos(Experimento*) - Responsável pela contabilização do numero de leitura, escrita e tempo de execução */
int pesquisaAcessoIndexado(TipoPagina**, int, FILE*, TipoItem*, Experimento*);

#endif