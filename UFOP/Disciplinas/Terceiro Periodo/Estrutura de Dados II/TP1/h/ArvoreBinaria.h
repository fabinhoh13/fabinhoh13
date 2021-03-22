#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tipoItem.h"
#include "Estatisticas.h"

typedef struct no Node;

//função de balanceamento
int Altura(Node* pRaiz);
//função de balanceamento
int FB (Node* pRaiz);
//função de balanceamento
void RSE(Node** ppRaiz);
//função de balanceamento
void RSD (Node** ppRaiz);
//função de balanceamento
int BalancaEsquerda(Node** ppRaiz);
//função de balanceamento
int BalancaDireita(Node** ppRaiz);
//função de balanceamento
int Balanceamento(Node** ppRaiz);

//função para criar uma arvore balanceada
int criaArvore(Node **r, TipoItem *arq, Estatistica *a);
//função de busca
Node* buscaArvoreBinaria(int chave, Node* a, Estatistica *b);
//função para apagar uma arvore
void apagarArvoreBinaria(Node *a);
//função específica do TP
void TPArvBin(FILE *arq, int buscado);




#endif