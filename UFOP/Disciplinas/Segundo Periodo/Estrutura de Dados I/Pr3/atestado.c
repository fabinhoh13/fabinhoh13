#include <stdlib.h>
#include "aluno.h"
#include "disciplina.h"
#include "atestado.h"

struct atestado {
  Aluno* alun;
  Disciplina** dis;
};

Atestado* criarAtestado (Disciplina** dis, Aluno* aluno) {
  Atestado* atest = malloc(sizeof(Atestado));
  atest->dis = dis;
  atest->alun = aluno;
  return atest;
}

void removerAtestado ( Atestado* atest, int n) {
  removerAluno(atest->alun);
  for (int i = 0; i < n; i++){
    apagarD(getDisciplina(atest->dis, i));
  }
  free (atest);
}

void atualizarAtestadoD ( Atestado* atest, Disciplina* dis, int t) {
  atest->dis[t] = dis;
}

void atualizarAtestadoA ( Atestado* atest, Aluno* aluno) {
  atest->alun = aluno;
}

Disciplina* lerAtestadoD ( Atestado* atest, int t) {
  return atest->dis[t];  
}

Aluno* lerAtestadoA ( Atestado* atest) {
  return atest->alun;  
}