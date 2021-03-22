#include "Pipeline.h"


Instrucao *loadP (Instrucao ** inst, int pc){
    if (pc >= 0)
        return getInstrucao(inst, pc);
    else
        return NULL;
}

int decodeP (Instrucao *inst){
    if (inst != NULL)
        return getOpCode(inst);
    else
        return -1;
}

void executeP (Cache *L1, Cache *L2, Cache *L3, BlocoMemoria **RAM, Instrucao *inst){
    //printf ("Entrei aqui\n");
    int opCode = getOpCode(inst);
    Endereco *end1 = getEnd1(inst);
    Endereco *end2 = getEnd2(inst);
    Endereco *end3 = getEnd3(inst);
    int sum, sub;
    switch (opCode){
            case 0:{
                int palavra1 = getPalavra(MMU(L1, L2, L3, RAM, getEndBloco(end1)), getEndPalavra(end1));
                //printf ("End 1: EndB %d EndP %d\n", getEndBloco(end1), getEndPalavra(end1));
                int palavra2 = getPalavra(MMU(L1, L2, L3, RAM, getEndBloco(end2)), getEndPalavra(end2));
                //printf ("End 2: EndB %d EndP %d\n", getEndBloco(end2), getEndPalavra(end2));
                sum = palavra1 + palavra2;
                printf ("soma %d\n", sum);
                //printf ("End 3: EndB %d EndP %d\n", getEndBloco(end3), getEndPalavra(end3));
                salvar (L1, L2, L3, RAM, getEndBloco(end3), getEndPalavra(end3), sum);
                //printf ("Salvou\n");
                break;
            }
            case 1:{
                int palavra1 = getPalavra(MMU(L1, L2, L3, RAM, getEndBloco(end1)), getEndPalavra(end1));
                //printf ("End 1: EndB %d EndP %d\n", getEndBloco(end1), getEndPalavra(end1));
                int palavra2 = getPalavra(MMU(L1, L2, L3, RAM, getEndBloco(end2)), getEndPalavra(end2));
                //printf ("End 2: EndB %d EndP %d\n", getEndBloco(end2), getEndPalavra(end2));
                sub = palavra1 - palavra2;
                //printf ("End 3: EndB %d EndP %d\n", getEndBloco(end3), getEndPalavra(end3));
                printf ("sub %d\n", sub);
                salvar (L1, L2, L3, RAM, getEndBloco(end3), getEndPalavra(end3), sub);
                //printf ("Salvou\n");
                break;
            }
    }
}