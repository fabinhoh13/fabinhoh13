/*
	Fábio Henrique Alves Fernandes
	19.1.4128
	Turma 64
*/

#include <stdio.h>
#include <stdlib.h>

int verificaQuadrado(int **matriz, int n)
{
  int *somaL = calloc (n, sizeof (int));
  int *somaC = calloc (n, sizeof (int));
  int somaP = 0, somaS = 0, aux = 0;
	for (int i = 0; i < n; i++){
		somaP += matriz[i][i];
		somaS += matriz[i][n-1-i];
		for (int j = 0; j < n; j++){
			somaL[i] += matriz[i][j];
			somaC[i] += matriz[j][i];
			
		}
	}

	for (int i = 0; i < n; i++){
	
		aux += (somaL[i] - somaC[i]);
	
	}
		if (aux == 0 && somaP == somaS)
			return 1;
		else 
			return 0;
	
	
	
	free (somaL);
	free (somaC);
}
int main(){
	int n, **matriz;
	printf ("Digite o valor de n: "); scanf ("%d", &n);
	
	matriz = malloc (n * sizeof (int*));
	
	printf ("Digite os valores da matriz n x n:\n");
	for (int i = 0; i < n; i++){
		matriz[i] = malloc (n * sizeof (int));
		for (int j = 0; j < n; j++){
			scanf ("%d", &matriz[i][j]);
		}
	}
	
	if (verificaQuadrado(matriz, n))
		printf ("Essa matriz é um quadrado magico!\n");
	else
		printf ("Essa matriz não é um quadrado magico!\n");
	
	for (int i = 0; i < n; i++)
		free(matriz[i]);
	free (matriz);
	
	return 0;
}

