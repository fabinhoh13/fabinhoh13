#include "ordenacao.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define TAM 1000000

void imprimeVetor (int *v, int tam);


int main(){
    srand(time(NULL));
    int TAM;
    scanf ("%d", &TAM);
    
    int *vetorAleatorio1 = malloc (TAM * sizeof(int));
    int *vetorAleatorio2 = malloc (TAM * sizeof(int));
    int maior = 0;

    for (int i = 0; i < TAM; i++){
        vetorAleatorio1[i] = rand() % TAM;
        if (vetorAleatorio1[i] > maior)
            maior = vetorAleatorio1[i];
        vetorAleatorio2[i] = rand() % TAM;
    }    

    coutingSort(vetorAleatorio1, TAM, maior);
    //imprimeVetor(vetorAleatorio1, TAM);
    radixsort(vetorAleatorio2, TAM);
    //imprimeVetor(vetorAleatorio2, TAM);


    return 0;
}

void imprimeVetor (int *v, int tam){
    for (int i = 0; i < tam; i++){
        printf ("%d ", v[i]);
    }
    printf ("\n");
}