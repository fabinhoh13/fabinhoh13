#include "BlocoMemoria.h"
#include "Endereco.h"
#include "Instrucao.h"
#include "Cache.h"
#include "MMU.h"
#include "Pipeline.h"
#include "Machine.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main(){
    Cache *L1, *L2, *L3;
    BlocoMemoria **RAM;
    int tamanhoRam, tamanhoL1, tamanhoL2, tamanhoL3, cont = 0;
    Instrucao **inst;
    srand(time(NULL));

    //hitRAM(&cont);

    tamanhoRam = 100;
    tamanhoL1 = 16;
    tamanhoL2 = 32;
    tamanhoL3 = 64;

    RAM = malloc (tamanhoRam * sizeof(BlocoMemoria *));
    for (int i = 0; i < tamanhoRam; i++){
        RAM[i] = criaBlocoMemoria();
    }
    printf ("OkCriaBloco\n");
    
    preencheRAM(RAM, tamanhoRam);

    printf ("Ok Preenche Ram\n");

    L1 = criaCache(tamanhoL1);
    printf ("OkL1\n");
    L2 = criaCache(tamanhoL2);
    printf ("OkL2\n");
    L3 = criaCache(tamanhoL3);
    printf ("OkL3\n");

    inst = criarVetorDeInstrucao (tamanhoRam);
    printf ("OkInst\n");

    machine(inst, L1, L2, L3, RAM);
    printf ("OkMachine\n");
    
    //hitRAM(&cont);

    printf ("TamRam = %d, TamL1 = %d, TamL2 = %d, TamL3 = %d\n", tamanhoRam, tamanhoL1, tamanhoL2, tamanhoL3);

    printf ("L1 Hits %d \t Miss %d\n", getCacheHit(L1), getCacheMiss(L1));
    printf ("L2 Hits %d \t Miss %d\n", getCacheHit(L2), getCacheMiss(L2));
    printf ("L3 Hits %d \t Miss %d\n", getCacheHit(L3), getCacheMiss(L3));
    //printf ("RAM Hit %d\n", cont);

}

