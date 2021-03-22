#include "instruction.h"
#include <stdlib.h>

struct instrucoes{
    int opCode;
    int end1;
    int end2;
    int end3;
};

Instrucoes *criarInstrucao (int opCode, int end1, int end2, int end3){
    Instrucoes *inst = malloc (sizeof(Instrucoes));
    inst->opCode = opCode;
    inst->end1 = end1;
    inst->end2 = end2;
    inst->end3 = end3;
    return inst;
}
int getOpCode (Instrucoes *inst){
    return inst->opCode;
}
int getEnd1 (Instrucoes *inst){
    return inst->end1;
}
int getEnd2 (Instrucoes *inst){
    return inst->end2;
}
int getEnd3 (Instrucoes *inst){
    return inst->end3;
}
Instrucoes *getInst (Instrucoes **inst, int i){
    return inst[i];
}
void apagarInst (Instrucoes *inst){
    free(inst);
}