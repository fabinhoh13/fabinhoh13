#ifndef ATESTADO_H
#define ATESTADO_H

typedef struct atestado Atestado;

Atestado* criarAtestado (Disciplina** dis, Aluno* aluno);
void removerAtestado (Atestado* atest, int n);
void atualizarAtestadoD (Atestado* atest, Disciplina* dis, int t);
void atualizarAtestadoA (Atestado* atest, Aluno* aluno);
Disciplina* lerAtestadoD (Atestado* atest, int t);
Aluno* lerAtestadoA (Atestado* atest);

#endif
