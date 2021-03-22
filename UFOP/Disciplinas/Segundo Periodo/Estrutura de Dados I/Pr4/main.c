#include "funcoes-recursivas.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    int tamanho, x, y, n;
    scanf ("%d", &tamanho);
    int *vetor = malloc (tamanho * sizeof (int));
    
    for (int i = 0; i < tamanho; i++){
        scanf ("%d", &vetor[i]);
    }

    int soma = somaArray (vetor, tamanho);
    printf ("%d\n", soma);
    inverteArray (vetor, tamanho);
    for (int i = 0; i < tamanho; i++){
        printf ("%d ", vetor[i]);
    }
    printf ("\n");
    scanf ("%d %d", &x, &y);
    printf ("%d\n", modDiv (x, y));
    scanf ("%d", &n);
    printf ("%d\n", somatorio(n));
}