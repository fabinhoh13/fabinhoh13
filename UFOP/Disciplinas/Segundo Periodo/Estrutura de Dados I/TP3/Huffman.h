#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "byte.h"


typedef struct listano ListaNode;
typedef struct lista Lista;
typedef struct arvore ArvoreNo;

Lista *criaListaA ();
ListaNode *criaListaNoA(ArvoreNo *noNovo);
ArvoreNo *CriaArvoreNo(int freq, byte c, ArvoreNo* esquerda, ArvoreNo* direita);
void insereListaA (Lista *l, ListaNode *n);
ArvoreNo *popMinLista(Lista *l);
void frequenciaBytes (FILE *arq, unsigned int *arrayBytes);
bool pegaCodigo(ArvoreNo *n, byte c, char *buffer, int tamanho);
ArvoreNo* criaArvoreHuffman (unsigned* arrayBytes);
void apagaHuffmanTree (ArvoreNo *n);
void compressao (char *arquivoEntrada, char *arquivoSaida);
void descompressao (char *arquivoEntrada, char *arquivoSaida);