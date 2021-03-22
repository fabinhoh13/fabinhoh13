#include "ordenacao.h"

void coutingSort(int *A, int n, int k){
	int i;

    int *B = malloc (n * sizeof (int));
    int *C = malloc (k * sizeof (int));

	for(i=0;i<n;i++) C[A[i]-1]++;

	for(i=1;i<k;i++) C[i] += C[i-1];

	for(i=n-1;i>=0;i--) {
		B[C[A[i]-1]-1] = A[i];
		C[A[i]-1]--;
	}
	for(i=0;i<n;i++) A[i] = B[i];
    free (B);
    free (C);
}

void radixsort(int *vetor, int tamanho){
    int i;
    int *b = calloc(tamanho, sizeof(int));;
    int maior = vetor[0];
    int exp = 1;

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
}