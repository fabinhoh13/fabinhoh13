#include "Instrucao.h"

struct instrucao{
    Endereco *end1;
    Endereco *end2;
    Endereco *end3;
    int opCode;
};


Instrucao *criarInstrucao (int opcode, int endB1, int endP1, int endB2, int endP2, int endB3, int endP3){
    Instrucao *new = malloc (sizeof(Instrucao));
    
    new->opCode = opcode;

    Endereco *end1 = criaEndereco (endB1, endP1);
    Endereco *end2 = criaEndereco (endB2, endP2);
    Endereco *end3 = criaEndereco (endB3, endP3);

    setEnd1(new, end1);
    setEnd2(new, end2);
    setEnd3(new, end3);


    
    return new;
}

Endereco *getEnd1 (Instrucao *aux){
    return aux->end1;
}

Endereco *getEnd2 (Instrucao *aux){
    return aux->end2;
}

Endereco *getEnd3 (Instrucao *aux){
    return aux->end3;
}

void setEnd1 (Instrucao *aux, Endereco *end){
    aux->end1 = end;
}

void setEnd2 (Instrucao *aux, Endereco *end){
    aux->end2 = end;
}

void setEnd3 (Instrucao *aux, Endereco *end){
    aux->end3 = end;
}

Instrucao *getInstrucao(Instrucao **vetor, int indice){
    return vetor[indice];
}

void setInstrucao (Instrucao **vetor, Instrucao *new, int indice){
    vetor[indice]->opCode = new->opCode;
    vetor[indice]->end1 = new->end1;
    vetor[indice]->end2 = new->end2;
    vetor[indice]->end3 = new->end3;
}

int getOpCode (Instrucao *aux){
    return aux->opCode;
}

void setOpCode (Instrucao *aux, int opCode){
    aux->opCode = opCode;
}

Instrucao **criarVetorDeInstrucao (int tam){
    
    FILE *arquivo = fopen ("instrucoes.txt", "r");
    if (arquivo == NULL)
        exit(0);

    int opcode, endB1, endP1, endB2, endP2, endB3, endP3;

    Instrucao **vetor = malloc (tam * sizeof (Instrucao*));

    for (int i = 0; i < tam; i++){
        fscanf (arquivo, "%d", &opcode);
        fscanf (arquivo, "%d", &endB1);
        fscanf (arquivo, "%d", &endP1);
        fscanf (arquivo, "%d", &endB2);
        fscanf (arquivo, "%d", &endP2);
        fscanf (arquivo, "%d", &endB3);
        fscanf (arquivo, "%d", &endP3);
        vetor[i] = criarInstrucao (opcode, endB1, endP1, endB2, endP2, endB3, endP3);
    }
    fclose (arquivo);
    return vetor;
}