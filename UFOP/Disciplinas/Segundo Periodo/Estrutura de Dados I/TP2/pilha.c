#include "pilha.h"

struct pilha {
    PilhaNo* prim;
};

struct pilha_no{
    int tipo;
    PilhaNo *prox;
    void *info;
};


struct quadrado {
    int lado;
};
struct losango{
    int d1;
    int d2;
};
struct trapezio{
    int b1;
    int b2;
    int h;
};

enum {
    QUAD,
    LOS,
    TRAP
};

Pilha *criaPilhaVazia (){
    Pilha *novo = malloc (sizeof (Pilha));
    novo->prim = NULL;
    return novo;
}

Quadrado *criaQuadrado (int lado){
    Quadrado *novo = malloc (sizeof(Quadrado));
    novo->lado = lado;
    return novo;
}

Losango *criaLosango (int d1, int d2){
    Losango *novo = malloc (sizeof (Losango));
    novo->d1 = d1;
    novo->d2 = d2;
    return novo;
}

Trapezio *criaTrapezio (int b1, int b2, int h){
    Trapezio *novo = malloc (sizeof (Trapezio));
    novo->b1 = b1;
    novo->b2 = b2;
    novo->h = h;
    return novo;
}

int vazia (Pilha* p){
    if (p->prim == NULL)
        return 1;
    else
        return 0;
}

PilhaNo* insereInicio (PilhaNo* l, void *info, int tipo){
    PilhaNo* p = malloc(sizeof(PilhaNo));
    p->prox = l;
    p->info = info;
    p->tipo = tipo;
    return p;
}


PilhaNo* retiraInicio (PilhaNo* l){
    PilhaNo* p = l->prox;
    free(l);
    return p;
}

void apagaPilha (Pilha* p){
    while(p->prim != NULL)
        retiraInicio(p->prim);
}

void push (Pilha* p, void *v, int tipo){
    p->prim = insereInicio(p->prim, v, tipo);
}

void *pop (Pilha* p){
    void *v;
    if (vazia(p)) {
        return NULL;
    }
    v = p->prim->info;
    p->prim = retiraInicio(p->prim);
    return v;
}

int tamanho (Pilha *p){
    int i = 0;
    PilhaNo *aux = p->prim;
    while(aux != NULL){
        i++;
        aux = aux->prox;
    }
    return i;
}

float *calcularArea (Pilha *p){
    //int tam = tamanho(p);
    int i = 0;
    float *areas = malloc (3 * sizeof (float));
    if (vazia(p))
        return NULL;
    PilhaNo *aux = p->prim;
    while (aux != NULL){
        switch(aux->tipo){
            case QUAD:{
                Quadrado *q = aux->info;
                areas[QUAD] = q->lado * q->lado;
                //printf ("ok1\n");
                break;
            }
            case LOS:{
                Losango *l = aux->info;
                areas[LOS] = ((int)l->d1 * (int)l->d2) / 2.0;
                //printf ("ok2\n");
                break;
            }
            case TRAP:{
                Trapezio *t = aux->info;
                areas[TRAP] = (((int)t->b1 + (int)t->b2) * (int)t->h) / 2.0;
                //printf ("ok3\n");
                break;
            }
            
        }
        aux = aux->prox;
            i++;
    }
    return areas;
}

