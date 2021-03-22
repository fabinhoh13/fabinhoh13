#include "funcoes-recursivas.h"


int somaArray (int *vetor, int tamanho){
    if (tamanho == 0)
        return 0;
    else
        return vetor[tamanho-1] + somaArray (vetor, tamanho-1);
}

void inverteArray (int *vetor, int tamanho){
    int aux;
    if (tamanho == 1)
        return;
    aux = vetor[0];
    vetor[0] = vetor [tamanho-1];
    vetor[tamanho-1] = aux;
    inverteArray (vetor+1, tamanho-2);
}

int modDiv (int x, int y){
    if (x == y)
        return 0;
    else if (x < y)
        return x;
    else 
        return modDiv (x-y, y);
}

int somatorio (int n){
    if (n == 0){
        return 0;
    }
    else if (n == 1)
        return 1;
    else
        return n + somatorio(n-1);
}