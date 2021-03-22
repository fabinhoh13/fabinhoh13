#ifndef ARVOREBSTAR_H
#define ARVOREBSTAR_H

#include "tipoItem.h"
#include "tipoBEstrela.h"
#include "../.h/experimento.h"

/* Função principal da Arvore B* que cria os arquivos binarios, cria todoas as variaveis e printa os resultados. 


    Parametros: 
    tamanhoArq(int) - Tamanho do arquivo

    situacao(int) - Qual é o arquivo utilizado, 1 para arquivo crescente, 2 para arquivo decrescente e 3 para 
    arquivo aleatorio 
    
    chave(int)* - Chave que sera buscada no arquivo */
void mainArvoreBEstrela(int, int, int);

/* Função de criação da arvore, realiza a leitura dos itens e contabiliza a quantidade de de leitura dos arquivos 


    Parametros:
    arq(FILE*) - Arquivo utilizado para leitura da chaves
    
    arvore(TipoBEstrela**) - Ponteiro da arvore que sera criada
    
    tamanhoArq(int) - Tamanho do arquivo
    
    casos(Experimento*) - Responsável pela contabilização do numero de leitura, escrita e tempo de execução */
void criaArvoreBEstrela(FILE*, TipoBEstrela**, int, Experimento*);

/* Função de inserção dos itens na arvore, serve como base para a inserção da raiz da arvore, tanto no inicio quando ela esta vazia
    e quando a arvore cresce


    Parametros:
    item(TipoItem*) - Item que sera inserido na arvore
    
    arvore(TipoBEstrela**) - Ponteiro da arvore principal que recebera o item
    
    casos(Experimento*) - Responsável pela contabilização do numero de leitura, escrita e tempo de execução */
void insereElementoArvoreBEstrela(TipoItem*, TipoBEstrela**, Experimento*);

/* Função de inserção e criação de novos nós na arvore, funciona tanto para elementos internos e externos da arvore


    Parametros:
    item(TipoItem*) - Item que sera inserido na arvore
    
    arvore(TipoBEstrela**) - Ponteiro da arvore principal que recebera o item

    cresceu(short*) - Ponteiro que se refere ao estado de crescimento da arvore

    itemRetorno(TipoItem**) - Ponteiro do item que sera modificado, no caso do crescimento da arvore ele é 
    responsável por determinar a nova raiz
    
    arvRetorno(TipoBEstrela**) - Ponteiro da arvore que será criada no caso do crescimento da arvore principal
    
    casos(Experimento*) - Responsável pela contabilização do numero de leitura, escrita e tempo de execução */
void insArvoreBEstrela(TipoItem*, TipoBEstrela**, short*, TipoItem**, TipoBEstrela**, Experimento*);

/* Função de inserção definitiva dos itens na arvore, que insere os elementos apos terem sido reorganizados na etapa anterior


    Parametros:
    arvore(TipoBEstrela**) - Ponteiro da arvore principal que recebera o item
    
    item(TipoItem*) - Item que sera inserido na arvore
    
    arvDir(TipoBEstrela*) - Ponteiro referente a pagina que estara a direita do elemento que sera inserido

    casos(Experimento*) - Responsável pela contabilização do numero de leitura, escrita e tempo de execução */
void insereNaPaginaBEstrela(TipoBEstrela**, TipoItem*, TipoBEstrela*, Experimento*);

/* Função que procura a partir de um item a sua existência na arvore. Retorna 1 no caso de achar o elemento procurado e 0
    caso contrario


    Parametros:
    item(TipoItem*) - Item que sera pesquisado
    
    arvore(TipoBEstrela*) - Arvore principal
    
    casos(Experimento*) - Responsável pela contabilização do numero de leitura, escrita e tempo de execução */
int pesquisaArvoreBEstrela(TipoItem*, TipoBEstrela*, Experimento*);

#endif