//Fabio Henrique Alves Fernandes
//19.1.4128
//Turma 64

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[100];
	double nota;
	double freq;
}Aluno;


int main (){
	char arquivo[100];
	printf ("Digite o nome do arquivo: "); scanf("%s", arquivo);
	FILE *data = fopen(arquivo, "r");
	int n, cont = 0;
	double notaM = 0.0, freqM = 0.0;
	
	fscanf (data, "%d", &n);
	
	Aluno *a = malloc (n * sizeof (Aluno));
	
	for (int i = 0; i < n; i++){
		fscanf (data, "%s %lf %lf", a[i].nome, &a[i].nota, &a[i].freq);
		notaM += a[i].nota;
		freqM += a[i].freq;
		if (a[i].nota > 60.0 && a[i].freq > 75.0){
			cont++;}
	}
	notaM /= (int)n;
	freqM /= (int)n;
	
	printf ("\nNota media: %.1lf\n", notaM);
	printf ("Frequencia media: %.0lf%\n", freqM);
	printf ("Percentual de aprovação: %d%\n", (cont/n) * 100); 
	
	printf ("\nNomes dos alunos com nota acima da nota media:\n");
	
	for (int i = 0; i < n; i++){
		if (a[i].nota > notaM)
			printf ("%s\n", a[i].nome);
	}
	return 0;
}
