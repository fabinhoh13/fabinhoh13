/*
	Fábio Henrique Alves Fernandes
	19.1.4128
	Turma 64
*/

#include <stdio.h>
#include <stdlib.h>

int multiplicaMatrizes(int ***R, int **A, int n, int m, int **B, int p, int q){

	if (m == p){	
		*R = malloc (n * sizeof (int*));
		for (int i = 0; i < n; i ++){
			(*R)[i] = calloc (q, sizeof (int));
			for (int j = 0; j < q; j++){
				for (int k = 0; k < m; k++){
					(*R)[i][j] += A[i][k] * B[k][j];

		        }
			}
		}
		return 1;
	}
	else
		return 0;
}


int main (int argv, char **argc){
	int n, m, p, q;
	printf ("Digite os tamanhos da matriz A: "); 
	scanf ("%d %d", &n, &m);
	
	printf ("Digite os dados da matriz A:\n");
	
	int **A = malloc (n * sizeof (int*));
	for (int i = 0; i < n; i++)
	{
		A[i] = malloc (m * sizeof (int));
		
		for (int j = 0; j < m; j++)
		{
			scanf ("%d", &A[i][j]);
		}
	}




	printf ("\nDigite os tamanhos da matriz B: "); 
	scanf ("%d %d", &p, &q);
	
	
	printf ("Digite os dados da matriz B:\n");
	
	
	int **B = malloc (p * sizeof (int*));
	for (int i = 0; i < p; i++)
	{
		B[i] = malloc (q * sizeof (int));
		
		for (int j = 0; j < q; j++)
		{
			scanf ("%d", &B[i][j]);
		}
	}
	int **Matriz;
	if (multiplicaMatrizes(&Matriz, A, n, m, B, p, q)){
		printf ("\n\nResultado de A x B:\n");
		for (int i = 0; i < n; i++){
			for (int j = 0; j < q; j++){
				printf ("%d ", Matriz[i][j]);
			}
			printf ("\n");
		}
	}
	else 
		printf ("Não Há solução\n");
			
	free (A);
	free (B);
	free (Matriz);	 
	
	return 0;
}

