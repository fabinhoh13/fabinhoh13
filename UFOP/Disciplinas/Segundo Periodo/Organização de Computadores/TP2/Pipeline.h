#include "Instrucao.h"
#include "Cache.h"
#include "MMU.h"
#include "BlocoMemoria.h"
#include "Endereco.h"


#include <stdio.h>
#include <stdlib.h>

Instrucao *loadP (Instrucao**, int);
int decodeP (Instrucao*);
void executeP (Cache *L1, Cache *L2, Cache *L3, BlocoMemoria **RAM, Instrucao *inst);
