#include "Machine.h"

void machine (Instrucao **inst, Cache *L1, Cache *L2, Cache *L3, BlocoMemoria **RAM){
    //int end1 = 0, end2 = 0, end3 = 0, sub = 0, sum = 0;
    int opCode = 0; 
    int pc = 0;
    Instrucao *umaInstrucao;

    
    while (opCode != -1){
        umaInstrucao = loadP (inst, pc);
        opCode = decodeP (umaInstrucao);
        executeP (L1, L2, L3, RAM, umaInstrucao);
        printf ("Execução %d\n", pc);
        pc++;
    }
}