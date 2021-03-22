#include "instruction.h"
#include "memory.h"
#include "machine.h"

#include <stdlib.h>
#include <stdio.h>

Instrucoes **sumProg (int num1, int num2, Memoria *mem){
    Instrucoes **inst = malloc (4 * sizeof(Instrucoes*));
    inst[0] = criarInstrucao (2, num1, 0, -1);
    inst[1] = criarInstrucao (2, num2, 1, -1);
    inst[2] = criarInstrucao (0, 0, 1, 0);
    inst[3] = criarInstrucao (-1, -1, -1, -1);
    return inst;
}

Instrucoes **subProg (int num1, int num2, Memoria *mem){
    Instrucoes **inst = malloc (4 * sizeof(Instrucoes*));
    inst[0] = criarInstrucao (2, num1, 0, -1);
    inst[1] = criarInstrucao (2, num2, 1, -1);
    inst[2] = criarInstrucao (1, 0, 1, 0);
    inst[3] = criarInstrucao (-1, -1, -1, -1);
    return inst;
}

Instrucoes **multProg (int num1, int num2, Memoria *mem){
    Instrucoes **inst = malloc ((num2+3) * sizeof(Instrucoes*));
    inst[0] = criarInstrucao (2, num1, 1, -1);
    inst[1] = criarInstrucao (2, 0, 0, -1);
    for (int i = 0; i < num2; i++){
        inst[i+2] = criarInstrucao (0, 1, 0, 0);
    }
    inst[num2+2] = criarInstrucao (-1, -1, -1, -1);
    return inst;
}

void potProg (int base, int exp, Memoria *mem){
    setMemory(mem, 0, base);
    for (int i = 0; i < exp-1; i++){
        machine(multProg(getMemory(mem, 0), base, mem),mem);
    }
}

//Divisão em construção

Instrucoes **divProg (int dividendo, int divisor, Memoria *mem){
    int i = 0;
    int resto = dividendo;
    Instrucoes **inst = malloc ((dividendo / divisor) + 4 * sizeof(Instrucoes*));
    inst[0] = criarInstrucao (2, dividendo, 0, -1);
    inst[1] = criarInstrucao (2, divisor, 1, -1);  
    while (resto >= divisor){
        inst[i+2] = criarInstrucao (1, 0, 1, 0);
        resto-=divisor;
        i++;
    }
    inst[i+2] = criarInstrucao (2, i, 0, -1);
    inst[i+3] = criarInstrucao (-1, -1, -1, -1);
    return inst;
}


void areaQuadProg (int lado, Memoria *mem){
    potProg(lado, 2, mem);
    printf ("Area Quadrado: %d\n", getMemory(mem, 0));
}

void areaRetProg (int base, int altura, Memoria *mem){
    machine(multProg (base, altura, mem), mem);
}
void areaTrian (int base, int altura, Memoria *mem){
    machine(multProg(base, altura, mem), mem);
    machine(divProg(getMemory(mem, 0), 2, mem),mem);
}
