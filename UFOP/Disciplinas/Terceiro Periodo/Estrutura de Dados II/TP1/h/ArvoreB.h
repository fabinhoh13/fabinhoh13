#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef ARVOREB_H
#define ARVOREB_H

#define M 2
#define MM M*2

//--- Definindo tipos ---

typedef int TipoChave;
typedef struct TipoRegistro TipoRegistro;
typedef struct TipoPaginas* TipoApontador;
typedef struct TipoPaginas TipoPaginas;


//--------Funções --------
//função de inicialização
void Inicializa (TipoApontador Arvore);
//função de pesquisa
int Pesquisa (TipoRegistro *x, TipoApontador Ap);
//função de caminhamento e de impressão dos dados em uma arvore
void Imprime(TipoApontador arvore);
//funções de inserção
void InsereNaPagina (TipoApontador Ap, TipoRegistro Reg, TipoApontador ApDir);
void Ins (TipoRegistro Reg, TipoApontador Ap, short *Cresceu, TipoRegistro *RegRetorno, TipoApontador *ApRetorno);
void Insere (TipoRegistro Reg, TipoApontador *Ap);
//funções de retirada de item
void Reconstitui (TipoApontador ApPag, TipoApontador ApPai, int posPai, short *Diminuiu);
void Antecessor (TipoApontador Ap, int Ind, TipoApontador ApPai, short *Diminuiu);
void Ret (TipoChave Ch, TipoApontador *Ap, short *Diminuiu);
void Retira (TipoChave Ch, TipoApontador *Ap);
//função específica do TP
void ArvBTP (FILE *arq, int buscado);

#endif
