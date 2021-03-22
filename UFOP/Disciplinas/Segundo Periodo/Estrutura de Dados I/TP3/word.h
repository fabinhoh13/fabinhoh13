#ifndef WORD_H
#define WORD_H

typedef struct palavra Palavra;

Palavra* criaPalavra( char* );
void deletaPalavra( Palavra* );
int getContador( Palavra* );
void setContador( Palavra*, int );
char* getPalavra( Palavra* );
void setPalavra( Palavra*, char* );
void acrescentaContador( Palavra* );

#endif