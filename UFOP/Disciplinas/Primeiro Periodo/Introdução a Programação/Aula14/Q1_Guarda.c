/*
    Fabio Henrique Alves Fernandes
    19.1.4128
    Turma 64
*/
#include <stdio.h>
#include <stdlib.h>


typedef struct{
	char nome[50];
	double nota;
	double freq;
}Aluno;

void escreveArquivo (Aluno *v, int n){
	FILE *data = fopen ("alunos.dat", "wb");
	fwrite (&n, sizeof(int), 1, data);
	fwrite (v, sizeof(Aluno), n, data);
	fclose (data);
}


int main (){
	int n;
	printf ("Numero de alunos: ");
	scanf ("%d", &n);
	Aluno *alunos = malloc (n * sizeof (Aluno));


	for (int i = 0; i < n; i++){
		printf ("Primeiro nome: ");
		scanf ("%s", alunos[i].nome);
		printf ("Nota: ");
		scanf ("%lf", &alunos[i].nota);
		printf ("Frequencia: ");
		scanf ("%lf", &alunos[i].freq);

	}
	escreveArquivo(alunos, n);
	free(alunos);
	return 0;
}

