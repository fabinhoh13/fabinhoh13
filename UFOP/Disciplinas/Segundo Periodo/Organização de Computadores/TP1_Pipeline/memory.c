#include "memory.h"

#include <stdlib.h>
#include <time.h>

struct memoria{
    int *RAM;
    int tamanho;
};

Memoria *criarRAM (int tamanho){
    Memoria *mem = malloc (sizeof(Memoria*));
    srand(time(NULL));
    mem->RAM = malloc (tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++){
        mem->RAM[i] = rand() % 100;
    }
    mem->tamanho = tamanho;
    return mem;
}

int getMemory (Memoria *mem, int indice){
    return mem->RAM[indice];  
}

void setMemory (Memoria *mem, int indice, int a){
    mem->RAM[indice] = a;
}

/*void apagarMem (Memoria *mem){
    for (int i = 0; i < mem->tamanho; i++){
        free (mem->RAM[i]);
    }
    free (mem);
}*/


void printMemory (Memoria *mem, int indice){
    printf ("%d\n", mem->RAM[indice]);
}