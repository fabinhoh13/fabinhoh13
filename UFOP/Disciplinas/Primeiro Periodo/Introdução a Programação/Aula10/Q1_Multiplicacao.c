//Fabio Henrique Alves Fernandes
//19.1.4128
//Turma 64

#include <stdio.h>
#include <locale.h>

int main (){
    setlocale(LC_ALL, "");
	int m, p, q, n;
	//lendo as dimensões
	do{

        //ler as dimensões da primeira matriz
        printf ("Elementos da primeira matriz: ");
        do{
            scanf ("%d %d", &m, &p);
            if (m > 10 || p > 10 || m < 0 || p < 0)
                printf ("Digite um valor válido\n");
        }while (m > 10 || p > 10 || m < 0 || p < 0);


        // ler as dimensões da segunda matriz
        printf ("Elementos da primeira matriz: ");
        do{
            scanf ("%d %d", &n, &q);
            if (n > 10 || q > 10 || n < 0 || q < 0)
                printf ("Digite um valor válido\n");
        }while (n > 10 || q > 10 || n < 0 || q < 0);
        if (p != q)
            printf ("Digite um valor válido\n");
	}while (p != q);
	//ler as matrizes

	int A[m][p], B[n][q], C[m][q];

	//primeira matriz

	printf ("Ler a primeira matriz\n");
	for (int i = 0; i < m; i++){
		for (int j = 0; j < p; j++){
			printf ("L: %d C: %d=", i+1, j+1);
			scanf ("%d", &A[i][j]);
		}
	}


	//segunda matriz
	printf ("Ler a segunda matriz\n");

	for (int i = 0; i < n; i++){
		for (int j = 0; j < q; j++){
			printf ("L: %d C: %d=", i+1, j+1);
			scanf ("%d", &B[i][j]);
		}
	}

	//zerar a matriz resultante
	for (int i = 0; i < m; i++){
		for (int j = 0; j < q; j++){
			C[i][j] = 0;
		}
	}

	//calculo da matriz
	for (int i = 0; i < m; i++){
		for (int j = 0; j < p; j++){
			for (int k = 0; k < n; k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	printf ("\n\n");

	//imprimir a primeira matriz
	for (int i = 0; i < m; i++){
		for (int j = 0; j < p; j++){
			printf ("%d ", A[i][j]);
		}
		printf ("\n");
	}
	printf ("\n\n");

	//imprimir a segunda matriz
	for (int i = 0; i < n; i++){
		for (int j = 0; j < q; j++){
			printf ("%d ", B[i][j]);
		}
		printf ("\n");
	}
	printf ("\n\n");
	//imprimir a matriz resultante

	for (int i = 0; i < m; i++){
		for (int j = 0; j < q; j++){
			printf ("%d ", C[i][j]);
		}
		printf ("\n");
	}

	return 0;
}
