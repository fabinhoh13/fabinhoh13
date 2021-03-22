#ifndef GERABINARIOS_H
#define GERABINARIOS_H

#include <stdio.h>

/* Gera um arquivo binario de acordo com o tamanho especificado, que vai de 1 ate o tamanho. O nome do arquivo sera 
    determinado de acordo com o tamanho passado via parametro
    
    Parametro: 
    tamanhoArq(int) - Tamanho do arquivo */
void arqOrdenadoCrescente(int);

/* Gera um arquivo binario de acordo com o tamanho especificado, que vai de tamanho ate 1. O nome do arquivo sera 
    determinado de acordo com o tamanho passado via parametro
    
    Parametro: 
    tamanhoArq(int) - Tamanho do arquivo */
void arqOrdenadoDecrescente(int);

/* Gera um arquivo binario de acordo com o tamanho especificado, que é desordenado de maneira aleatoria. O nome do arquivo 
    sera determinado de acordo com o tamanho passado via parametro
    
    Parametro: 
    tamanhoArq(int) - Tamanho do arquivo */
void arqDesordenadoAleatoriamente(int);

#endif