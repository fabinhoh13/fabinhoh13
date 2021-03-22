#ifndef TIPOBESTRELA_H
#define TIPOBESTRELA_H

#include "./tipoItem.h"
#include "./ArvoreB.h"

#define MM2 2*M

typedef enum { Interno, Externo } TipoIntExt;
typedef struct tipoBEstrela TipoBEstrela;

/* Responsável por cria um ponteiro para referenciar a variavel da struct TipoBEstrela */
TipoBEstrela* criaBEstrela();

/* Atualiza o valor de categoria 

    Parametros:
    arvore(TipoBEstrela) - Variavel que sera atualizada */
void setEstrelaCategoriaPagina(TipoBEstrela*, TipoIntExt);

/* Incrementa ao tamanho externo a quantidade determinada

    Parametros:
    arvore(TipoBEstrela) - Variavel que sera atualizada
    
    tamanho(int) - Quantidade que o sera incrementada */
void setEstrelaTamanhoInternoIncrementa(TipoBEstrela*, int);

/* Atualiza o valor de tamanho interno 

    Parametros:
    arvore(TipoBEstrela) - Variavel que sera atualizada
    
    tamanho(int) - Novo tamanho */
void setEstrelaTamanhoInterno(TipoBEstrela*, int);

/* Atualiza o valor da chave do vetor interno

    Parametros:
    arvore(TipoBEstrela) - Variavel que sera atualizada
    
    index(int) - Posição que o vetor se encontra
    
    chave(int) - Chave atualizada */
void setEstrelaVetorChave(TipoBEstrela*, int, int);

/* Atualiza a pagina da posição desejada

    Parametros:
    arvore(TipoBEstrela) - Variavel que sera atualizada
    
    index(int) - Posição da pagina desejada
    
    filho(TipoBEstrela*) - Pagina atualizada */
void setEstrelaPaginaInterna(TipoBEstrela*, int, TipoBEstrela*);

/* Incrementa ao valor do tamanho externo a quantidade determinada

    Parametros:
    arvore(TipoBEstrela) - Variavel que sera atualizada
    
    tamanho(int) - Quantidade determinada */
void setEstrelaTamanhoExternoIncrementa(TipoBEstrela*, int);

/* Atualiza o valor de tamanho externo

    Parametros:
    arvore(TipoBEstrela) - Variavel que sera atualizada 
    
    tamanho(int) - Novo tamanho */
void setEstrelaTamanhoExterno(TipoBEstrela*, int);

/* Atualiza o item da posição selecionada

    Parametros:
    arvore(TipoBEstrela) - Variavel que sera atualizada
    
    index(int) - Posição do item desejado
    
    item(TipoItem*) - Novo item */
void setEstrelaListItemExterno(TipoBEstrela*, int, TipoItem*);

/* Obtém a categoria atual da pagina. Retorna o enum correspondente da pagina

    Parametros:
    
    arvore(TipoBEstrela*) - Pagina selecionada */
TipoIntExt getEstrelaCategoriaPagina(TipoBEstrela*);

/* Obtém o tamanho interno da pagina. Retorna um inteiro referente ao tamanho

    Parametros:
    
    arvore(TipoBEstrela*) - Pagina selecionada */
int getEstrelaTamanhoInterno(TipoBEstrela*);

/* Obtém a chave referente a posição do vetor. Retorna um inteiro correspondente a chave

    Parametros:
    
    arvore(TipoBEstrela*) - Pagina selecionada
    
    index(int) - Posição do vetor desejado */
int getEstrelaVetorChave(TipoBEstrela*, int);

/* Obtém a pagina interna no indice especificado. Retorna uma outra pagina 

    Parametros:
    
    arvore(TipoBEstrela*) - Pagina selecionada
    
    index(int) - Posição da pagina em questão */
TipoBEstrela* getEstrelaPaginaInterna(TipoBEstrela*, int);

/* Obtém o tamanho externo. Retorna um inteiro

    Parametros:
    
    arvore(TipoBEstrela*) - Pagina selecionada */
int getEstrelaTamanhoExterno(TipoBEstrela*);

/* Obtém 

    Parametros:
    
    arvore(TipoBEstrela*) - Pagina selecionada */
TipoItem* getEstrelaListItemExterno(TipoBEstrela*, int);

/* Obtém a chave do item externo. Função criada para facilitar um código embolado. Retorna a chave do item

    Parametros:
    
    arvore(TipoBEstrela*) - Pagina selecionada 
    index(int) - Posição do item desejado   */
int getChaveItemExterno(TipoBEstrela*, int);

/* Libera a pagina que foi alocada

    Parametros:
    
    arvore(TipoBEstrela*) - Pagina alocada */
void liberaBEstrela(TipoBEstrela*);

#endif