#include "Endereco.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct instrucao Instrucao;

Instrucao *criarInstrucao (int opcode, int endB1, int endP1, int endB2, int endP2, int endB3, int endP3);
Endereco *getEnd1 (Instrucao *aux);
Endereco *getEnd2 (Instrucao *aux);
Endereco *getEnd3 (Instrucao *aux);
void setEnd1 (Instrucao *aux, Endereco *end);
void setEnd2 (Instrucao *aux, Endereco *end);
void setEnd3 (Instrucao *aux, Endereco *end);
Instrucao *getInstrucao(Instrucao **vetor, int indice);
void setInstrucao (Instrucao **vetor, Instrucao *new, int indice);
int getOpCode (Instrucao *aux);
void setOpCode (Instrucao *aux, int opCode);

Instrucao **criarVetorDeInstrucao (int tam);