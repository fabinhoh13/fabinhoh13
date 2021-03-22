//Fábio Henrique Alves Fernandes
//19.1.4128
//Turma 64

#include <stdio.h>

int main(){

    int vetor[10], termo1 = 1, termo2 = 1, aux;
    printf("Sequencia de Fibonacci\n");
    vetor[0] = 1; vetor[1] = 1;

    for (int i = 2; i < 10; i++) {
        vetor[i] = vetor[i-1] + vetor[i-2];

    }
    for (int i = 0; i < 10; i++){
        printf ("%d ", vetor[i]);
    }
    return 0;
}

