#include "pipeline.h"


Instrucoes *loadP (Instrucoes ** inst, int pc){
    if (pc >= 0)
        return getInst(inst, pc);
    else
        return NULL;
}

int decodeP (Instrucoes *inst){
    if (inst != NULL)
        return getOpCode(inst);
    else
        return -1;
}

void executeP (Memoria *mem, Instrucoes *inst, int pc){
    int opCode = getOpCode(inst);
    int end1 = getEnd1(inst);
    int end2 = getEnd2(inst);
    int end3 = getEnd3(inst);
    int sum, sub;
    switch (opCode){
            case 0:{
                sum = getMemory(mem, end1) + getMemory(mem, end2);
                setMemory (mem, end3, sum);
                //printf ("Soma: %d\n", sum);
                break;
            }
            case 1:{
                sub = getMemory(mem, end1) - getMemory(mem, end2);
                setMemory (mem, end3, sub);
                //printf ("Sub: %d\n", sub);
                break;
            }
            case 2:{
                setMemory (mem, end2, end1);
                break;
            }
            case -1:{
                printMemory (mem, 0);
            }
    }
}