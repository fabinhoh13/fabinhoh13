#include "geraValores.h"

int *geraCrescente (int tam){
    int *new = malloc (tam * sizeof (int));
    for (int i = 0; i < tam; i++){
        new[i] = i+1;
    }
    return new;
}

int *geraDecrescente (int tam){
    int *new = malloc (tam * sizeof (int));
    for (int i = 0; i < tam; i++){
        new[i] = tam - (i);
    }
    return new;
}

int *geraAleatorio (int tam){
    //srand (time(NULL));
    int *new = malloc (tam * sizeof (int));
    
    for (int i = 0; i < tam; i++){
            new[i] = (rand() % tam) + 1; 
    }
    return new;
}