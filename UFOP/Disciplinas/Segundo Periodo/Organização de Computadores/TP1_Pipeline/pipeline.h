#include "instruction.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

Instrucoes *loadP (Instrucoes **, int);
int decodeP (Instrucoes *);
void executeP (Memoria *, Instrucoes *, int);
