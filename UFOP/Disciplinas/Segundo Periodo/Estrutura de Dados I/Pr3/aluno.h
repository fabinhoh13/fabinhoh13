#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

Aluno* criarAluno (char*, long int, int, char*, char*);
void removerAluno (Aluno*);

void atualizarNomeAluno (Aluno*, char*);
void atualizarCpfAluno (Aluno*, long int);
void atualizarMatriculaAluno (Aluno*, int);
void atualizarCursoAluno (Aluno*, char*);
void atualizarDataAluno (Aluno*, char*);

char* lerAlunoNome (Aluno*);
long int lerAlunoCPF (Aluno*);
int lerAlunoMat (Aluno*);
char* lerAlunoCurso (Aluno*);
char *lerAlunoDI (Aluno*);

Aluno* getAluno (Aluno*);
#endif
