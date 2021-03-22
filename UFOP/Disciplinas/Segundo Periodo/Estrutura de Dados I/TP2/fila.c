#include "fila.h"

struct fila{
    FilaNo *prim;
    FilaNo *ult;
};

struct filano{
    FilaNo *prox;
    int id;
    char *processo;
    time_t inclusao;
};

//Funções Fila

Fila *criaFilaVazia(){
    Fila *novo = malloc (sizeof(Fila));
    novo->prim = NULL;
    novo->ult = NULL;
    return novo;
}

FilaNo *criaFilaNo(char *processo, int id, time_t tempo){
    FilaNo *novo = malloc (sizeof(FilaNo));
    novo->id = id;
    strcpy(novo->processo, processo);
    novo->inclusao = tempo;
    novo->prox = NULL;
    return novo;
}

void inserePrimeiro (Fila *f, char *processo, int id, time_t tempo){ 
    FilaNo *aux = criaFilaNo(processo, id, tempo);
    f->prim = aux;
    f->ult = aux;
}
void insereFinal (Fila *f, char *processo, int id, time_t tempo){
    
    if (f->prim == NULL)
        inserePrimeiro(f, processo, id, tempo);
    else{
        FilaNo *aux = criaFilaNo(processo, id, tempo);
        f->ult->prox = aux;
        f->ult = aux;
    }
}

void removeInicio (Fila *f){
    if (f->prim == NULL)
        return;
    else{
        FilaNo *aux = f->prim;
        f->prim = f->prim->prox;
        free(aux);
    }
}

void imprimeFila (Fila *f){
    time_t end = time(NULL);
    for (FilaNo *aux = f->prim; aux != NULL; aux = aux->prox){
        printf ("ID: %d\tDESCRIPTION: %s\tTIME: %.1lf\n", aux->id, aux->processo, difftime(end, aux->inclusao));
    }
}

//sets

void setId (FilaNo *f, int id){
    f->id = id;
}

void setProcesso (FilaNo *f, char *processo){
    f->processo = processo;
}

void setInclusao (FilaNo *f, time_t tempo){
    f->inclusao = tempo;
}

//gets

int getId (FilaNo *f){
    return f->id;
}

char *getProcesso (FilaNo *f){
    return f->processo;
}

time_t getInclusao (FilaNo *f){
    return f->inclusao;
}
