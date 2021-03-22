#ifndef INSTRUCAO_H
#define INSTRUCAO_H

#include "endereco.h"

typedef struct instrucao Instrucao;

Instrucao* criaInstrucao( Endereco*, Endereco*, Endereco*, int );
Instrucao** criaInstrucao2( int );
void setInstrucao( Instrucao**, Instrucao*, int );
void liberaInstrucao( Instrucao* );
void liberaInstrucao2( Instrucao**, int );
Instrucao* getInstrucao( Instrucao**, int );
Endereco* getInstrucaoEnd1( Instrucao* );
void setInstrucaoEnd1( Instrucao*, Endereco* );
Endereco* getInstrucaoEnd2( Instrucao* );
void setInstrucaoEnd2( Instrucao*, Endereco* );
Endereco* getInstrucaoEnd3( Instrucao* );
void setInstrucaoEnd3( Instrucao*, Endereco* );
int getInstrucaoOpcode( Instrucao* );
void setInstrucaoOpcode( Instrucao*, int );

#endif