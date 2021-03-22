#include <stdio.h>
#include <string.h>
#define max 150

typedef struct{
	char nome[max];
	int matricula;
	double nota[max];
} Aluno;

Aluno encontraAluno(Aluno alunos[], int nAlunos, int matricula);

int main(){
	int n, m;
	double s[max];
	Aluno alunos[max];
	
	for (int i = 0; i < n; i++)
		s[i]=0.0;
		
	printf ("Digite a quantidade de alunos: ");
	scanf ("%d", &n);
	printf ("Digite a quantidade de notas: ");
	scanf ("%d", &m);


	for (int i = 0; i < n; i++){
		printf ("Digite o nome do aluno %d: ", i+1);
		getchar();
		fgets (alunos[i].nome, max, stdin);
		printf ("Digite a matrícula do aluno %d: ", i+1);
		scanf ("%d", &alunos[i].matricula);
		for (int j = 0; j < m; j++){
			printf ("Digite a nota %d do aluno %d: ", j+1, i+1);
			scanf ("%lf", &alunos[i].nota[j]);
			s[i]+=alunos[i].nota[j];
		}
	}

	double tot;
	for (int i = 0; i < n; i++)
		tot+=s[i];


	tot=tot/(int)n;
	printf ("\n\nMedia das notas: %.1lf\n\n\n", tot);

	int pesquisa;
	printf ("Digite a matrícula a ser pesquisada: ");
	scanf ("%d", &pesquisa);

	Aluno correto = encontraAluno(alunos, n, pesquisa);

	printf ("Aluno: ");
	puts (correto.nome);
	printf ("Matricula: %d\n", correto.matricula);
	
	double media;
	for (int i = 0; i < m; i++){
		media += correto.nota[i];
	}
	
	printf ("Média das notas %.1lf\n", media/(int)m);
	
	
	return 0;
}

Aluno encontraAluno(Aluno alunos[], int nAlunos, int matricula){
	for (int i = 0; i < nAlunos; i++){
		if (matricula == alunos[i].matricula)
			return alunos[i];
	}
}

