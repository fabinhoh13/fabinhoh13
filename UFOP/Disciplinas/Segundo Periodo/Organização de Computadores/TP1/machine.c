#include "instruction.h"
#include "memory.h"
#include "machine.h"

#include <stdlib.h>
#include <stdio.h>

void machine (Instrucoes **inst, Memoria *mem){
    int end1 = 0, end2 = 0, end3 = 0, sub = 0, sum = 0;
    int opCode = 0; 
    int pc = 0;

    
    while (opCode != -1){
        opCode = getOpCode(inst[pc]);
        end1 = getEnd1(inst[pc]);
        end2 = getEnd2(inst[pc]);
        end3 = getEnd3(inst[pc]);
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
                printf ("\nFim de execução 'Halt'\n");
            }
        }
        pc++;
    }
}