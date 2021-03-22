#include "instruction.h"
#include "memory.h"
#include "machine.h"
#include "pipeline.h"

#include <stdlib.h>
#include <stdio.h>

void machine (Instrucoes **inst, Memoria *mem){
    int end1 = 0, end2 = 0, end3 = 0, sub = 0, sum = 0;
    int opCode = 0; 
    int pc = 0;
    Instrucoes *umaInstrucao;

    
    while (opCode != -1){
        umaInstrucao = loadP (inst, pc);
        opCode = decodeP (umaInstrucao);
        executeP (mem, umaInstrucao, pc);
        pc++;
    }
}