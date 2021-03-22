#ifndef CPU_H
#define CPU_H

#include "program.h"
#include "cache.h"
#include "instrucao.h"

void CPU( Cache*, Cache*, Cache*, Cache*, Instrucao**, int );
double MMU( Cache*, Cache*, Cache*, Cache*, FILE*, int* );
void setMMU( Cache*, Cache*, Cache*, Cache*, FILE*, int*, double );
double ALU( double*, int );
void organizaCache( Cache* );
void mergeSortIntercala( double*, int, int, int );
void mergeSort( double*, int, int );

#endif