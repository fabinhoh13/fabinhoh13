//Fábio Henrique Alves Fernandes
//19.1.4128
//Turma 64

#include <stdio.h>

int main(){

    int vetor[7];

    for (int i = 0; i < 7; i++){
        printf ("Leia o numero %d\n", i+1);
        scanf ("%d", &vetor[i]);
    }
    int procura;
    printf ("Digite o numero a ser procurado\n");
    scanf ("%d", &procura);

    for (int i = 0; i < 7; i++){
        if (vetor[i] == procura){
            printf ("Achamos o numero %d na posicao %d\n", procura, i+1);
        }
    }
    return 0;
}

