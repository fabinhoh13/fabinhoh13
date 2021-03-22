//Fábio Henrique Alves Fernandes
//19.1.4128
//Turma 64

#include <stdio.h>

int main(){

    int n;
    do {

        printf ("Digite o tamanho do vetor: ");
        scanf ("%d", &n);

    }while (n > 50 || n < 0);
    int vetor[n];

    for (int i = 0; i < n; i++){
        printf ("Posicao %d: ", i+1);
        scanf ("%d", &vetor[i]);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < vetor[i]; j++){
            printf ("*");
        }
        printf ("\n");
    }
    return 0;
}


