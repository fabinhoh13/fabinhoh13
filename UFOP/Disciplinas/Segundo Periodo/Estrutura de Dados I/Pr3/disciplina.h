#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct disciplina Disciplina;

Disciplina* criarD (char*, char*, int, char*, int);
void apagarD (Disciplina*);
void atualizarNomeD (Disciplina*, char*);
void atualizarCodD (Disciplina*, char*);
void atualizarCursoD (Disciplina*, char*);
void atualizarCHD (Disciplina*, int);
void atualizarSalaD (Disciplina*, int);
Disciplina* getDisciplina(Disciplina **dis, int i);
char* lerDNome (Disciplina* dis);
char* lerDCurso (Disciplina* dis);
char* lerDCod (Disciplina* dis);
int lerDSala (Disciplina* dis);
int lerDCH (Disciplina* dis);

#endif
