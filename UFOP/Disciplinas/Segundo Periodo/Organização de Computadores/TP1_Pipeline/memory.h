#include <stdio.h>
typedef struct memoria Memoria;

Memoria *criarRAM (int);
int getMemory (Memoria *, int);
void setMemory (Memoria *, int, int);
void apagarMem (Memoria *);
void printMemory (Memoria *, int);