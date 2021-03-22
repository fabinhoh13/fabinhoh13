#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno {
  char nome[101];
  long int CPF;
  int matricula;
  char curso[31];
  char dataIngresso[11];
};

Aluno* criarAluno ( char* nome, long int CPF, int matricula, char* curso, char* dataIngresso ) {
  Aluno* aux = malloc ( sizeof(Aluno));
  strcpy(aux->nome, nome);
  aux->CPF = CPF;
  aux->matricula = matricula;
  strcpy(aux->curso, curso);
  strcpy(aux->dataIngresso, dataIngresso);
  return aux;
}

void removerAluno ( Aluno* alun ) {
  free(alun);
}

void atualizarNomeAluno ( Aluno* alun, char* nome ) {
  strcpy(alun->nome, nome);
}

void atualizarCpfAluno ( Aluno* alun, long int CPF ) {
  alun->CPF = CPF;
}

void atualizarMatriculaAluno ( Aluno* alun, int matricula) {
  alun->matricula = matricula;
}

void atualizarCursoAluno ( Aluno* alun, char* curso ) {
  strcpy(alun->curso, curso);
}
void atualizarDataAluno ( Aluno* alun, char* dataIngresso ) {
  strcpy (alun->dataIngresso, dataIngresso);
}

char* lerAlunoNome (Aluno* alun){
  return alun->nome;
}
long int lerAlunoCPF (Aluno* alun){
  return alun->CPF;
}
int lerAlunoMat (Aluno* alun){
  return alun->matricula;
}
char* lerAlunoCurso (Aluno* alun){
  return alun->curso;
}
char *lerAlunoDI (Aluno* alun){
  return alun->dataIngresso;
}

Aluno* getAluno (Aluno* alun){
  return alun;
}