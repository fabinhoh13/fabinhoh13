#include <stdio.h>
#include <stdlib.h>

typedef struct pilha Pilha;
typedef struct pilha_no PilhaNo;
typedef struct quadrado Quadrado;
typedef struct losango Losango;
typedef struct trapezio Trapezio;



Pilha *criaPilhaVazia ();
Quadrado *criaQuadrado (int lado);
Losango *criaLosango (int d1, int d2);
Trapezio *criaTrapezio (int b1, int b2, int h);
int vazia (Pilha* p);
PilhaNo* insereInicio (PilhaNo* l, void *info, int tipo);
PilhaNo* retiraInicio (PilhaNo* l);
void apagaPilha (Pilha* p);
void push (Pilha* p, void *v, int tipo);
void *pop (Pilha* p);
int tamanho (Pilha *p);
float *calcularArea (Pilha *p);