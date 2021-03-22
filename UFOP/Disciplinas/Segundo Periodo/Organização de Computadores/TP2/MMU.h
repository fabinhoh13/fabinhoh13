#include "BlocoMemoria.h"
#include "Cache.h"
#include "Endereco.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>


BlocoMemoria *MMU (Cache *L1, Cache *L2, Cache *L3, BlocoMemoria **RAM, int endBloco);
void salvar(Cache *L1, Cache *L2, Cache *L3, BlocoMemoria **RAM, int endBloco, int endP, int resultado);
void passaBlocos(BlocoMemoria* b, Cache* c1, Cache* c2);
void hitRAM (int *cont);
