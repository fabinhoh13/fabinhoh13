#include <stdlib.h>
#include "instrucao.h"

struct instrucao {
    Endereco* add1;
    Endereco* add2;
    Endereco* add3;
    int opcode;
};

Instrucao* criaInstrucao( Endereco* add1, Endereco* add2, Endereco* add3, int opcode ) {
    Instrucao* aux = malloc(sizeof(Instrucao));

    aux->add1 = add1;
    aux->add2 = add2;
    aux->add3 = add3;
    aux->opcode = opcode;

    return aux;
}

Instrucao** criaInstrucao2( int count ) {
    Instrucao** aux = malloc( count * sizeof(Instrucao*));

    return aux;
}

void setInstrucao( Instrucao** inst, Instrucao* inst1, int indice ) {
    inst[indice] = inst1;
}

void liberaInstrucao( Instrucao* inst ) {
    liberaEndereco( inst->add1 );
    liberaEndereco( inst->add2 );
    liberaEndereco( inst-> add3 );
    free(inst); 
}

void liberaInstrucao2( Instrucao** inst, int count ) {
    for( int i = 0; i < count; i++ )
        liberaInstrucao( inst[i] );
    free(inst);
}

Instrucao* getInstrucao( Instrucao** inst, int indice ) {
    return inst[indice];
}

Endereco* getInstrucaoEnd1( Instrucao* inst ) {
    return inst->add1;
}

void setInstrucaoEnd1( Instrucao* inst, Endereco* add ) {
    inst->add1 = add;
}

Endereco* getInstrucaoEnd2( Instrucao* inst ) {
    return inst->add2;
}

void setInstrucaoEnd2( Instrucao* inst, Endereco* add ) {
    inst->add2 = add;
}

Endereco* getInstrucaoEnd3( Instrucao* inst ) {
    return inst->add3;
}

void setInstrucaoEnd3( Instrucao* inst, Endereco* add ) {
    inst->add3 = add;
}

int getInstrucaoOpcode( Instrucao* inst ) {
    return inst->opcode;
}

void setInstrucaoOpcode( Instrucao* inst, int opcode ) {
    inst->opcode = opcode;
}
