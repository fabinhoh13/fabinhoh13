#ifndef BLOCO_H
#define BLOCO_H

#include <stdbool.h>
#include <time.h>

typedef struct bloco Bloco;

Bloco* criaBloco();
Bloco* criaBloco2( int );
Bloco** criaBloco3( int );
Bloco** criaBloco4( int );
void liberaBloco( Bloco* );
void liberaBloco2( Bloco**, int );
void liberaBloco3( Bloco** );
Bloco* getBloco( Bloco**, int );
void setBloco( Bloco**, Bloco*, int );
void setBloco1( Bloco**, Bloco*, int );
void setBlocoUnico( Bloco*, Bloco* );
void setBlocoNull( Bloco* );
double* getBlocoPalavras( Bloco* );
void setBlocoPalavras( Bloco*, double* );
double getBlocoPalavra( Bloco*, int );
void setBlocoPalavra( Bloco*, double, int );
int getBlocoEndereco( Bloco* );
void setBlocoEndereco( Bloco*, int );
_Bool getBlocoAtt( Bloco* );
void setBlocoAttTrue( Bloco* );
void setBlocoAttFalse( Bloco* );
double getBlocoTime( Bloco* );
void setBlocoTime( Bloco* );
void setBlocoTimeZero( Bloco* );
void printaBloco( Bloco*, int );
Bloco *criaBlocoHD (double *palavras, int end);

#endif