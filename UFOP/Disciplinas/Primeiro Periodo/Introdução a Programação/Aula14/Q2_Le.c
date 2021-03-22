/*
    Fabio Henrique Alves Fernandes
    19.1.4128
    Turma 64
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
	char nome[50];
	double nota;
	double freq;
}Aluno;


int main (){
    setlocale (LC_ALL, "");
    char local[50];
    printf ("Digite o nome do arquivo: "); scanf ("%s", local);
	FILE *data = fopen(local, "rb");
	int n, cont = 0;
	double notaM = 0.0, freqM = 0.0;

	fread (&n, sizeof(int), 1, data);


	Aluno *v = malloc (n * sizeof (Aluno));

    fread (v, sizeof(Aluno), n, data);
	for (int i = 0; i < n; i++){
		notaM += v[i].nota;
		freqM += v[i].freq;
		if (v[i].nota > 6.0 && v[i].freq > 75.0){
			cont++;}
	}
	notaM /= (double)n;
	freqM /= (double)n;
    double apro = (double) cont / (double)n * 100.0;
	printf ("\nNota media: %.1lf\n", notaM);
	printf ("Frequencia media: %.0lf %\n", freqM);
	printf ("Percentual de aprovação: %.0lf %\n", apro);

	printf ("\nNomes dos alunos com nota acima da nota media:\n");

	for (int i = 0; i < n; i++){
		if (v[i].nota >= notaM)
			printf ("%s\n", v[i].nome);
	}
	fclose(data);
	free(v);
	return 0;
}
