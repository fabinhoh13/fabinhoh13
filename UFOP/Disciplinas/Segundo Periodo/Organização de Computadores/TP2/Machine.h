#include "Instrucao.h"
#include "Pipeline.h"

#include <stdlib.h>
#include <stdio.h>


void machine (Instrucao **inst, Cache *L1, Cache *L2, Cache *L3, BlocoMemoria **RAM);