//Fabio Henrique Alves Fernandes
//19.1.4128
//Turma 64

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[100];
	double peso;
	double cal;
}Dieta;

Dieta *leDieta (char arquivo[], int *n){
	FILE *data = fopen (arquivo, "r");
	fscanf (data, "%d", n);
	Dieta *v = malloc (*n * sizeof (Dieta));

	for (int i = 0; i < *n; i++){
		fscanf (data, "%s %lf %lf", v[i].nome, &v[i].peso, &v[i].cal);
	}
	
	fclose(data);
	return v;
}
	

int main(){
	int n;
	char arquivo[100];
	double maior = 0.0;
	int con;
	printf ("Digite o nome do arquivo: "); scanf ("%s", arquivo);
	Dieta *v = leDieta(arquivo, &n);
	double *calgram = malloc (n * sizeof (double));
	
	for (int i = 0; i < n; i++){
		calgram[i] = v[i].cal / v[i].peso;
		if (calgram[i] > maior){
			maior = calgram[i];
			con = i;
		}
	}
	
	
	printf ("Alimento\t\tcal/grama\n");
	printf ("---------------------------------\n");
	for (int i = 0; i < n; i++){
		printf ("%s\t\t%.2lf", v[i].nome, calgram[i]);
		if (con==i)
			printf ("*");
		printf ("\n");
	}
	return 0;
}
	                       
