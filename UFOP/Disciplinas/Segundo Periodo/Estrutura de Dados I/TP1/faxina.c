#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "faxina.h"

struct faxina{
    char area[32];
    Morador* mrd;
    int situacao;
};

void setFaxina ( Faxina** fxn, Faxina* fxn1, int count ) {
    fxn[count] = fxn1;
}

Faxina* criarFaxina ( char* area, Morador* mrd ) {
    Faxina* aux = malloc ( sizeof(Faxina));

    strcpy(aux->area, area);
    aux->mrd = mrd;
    // 0 - Sujo
    // 1 - Limpo
    aux->situacao = 0;

    return aux;
}

Faxina* getFaxina ( Faxina** fxn, int count ) {
    return fxn[count];
}

void excluirFaxina ( Faxina** fxn, int count ) {
    for( int i = 0; i < count; i++ )
        free(fxn[i]);

    free(fxn);
}

void rotacaoGeralFaxina ( Faxina** fxn, Morador** mrd, int* selecionado, int qtdArea, int qtdMorador ) {
    for ( int i = 0; i < qtdArea; i++ ) {
        (*selecionado)++;
        fxn[i]->mrd = getMorador( mrd, *selecionado % qtdMorador );
    }
}

char* getFaxinaArea ( Faxina* fxn ) {
    return fxn->area;
}

void setFaxinaArea ( Faxina* fxn, char* area ) {
    strcpy(fxn->area, area);
}

Morador* getFaxinaMorador ( Faxina* fxn ) {
    return fxn->mrd;
}

void setFaxinaMorador ( Faxina* fxn, Morador* mrd ) {
    fxn->mrd = mrd;
}

int getFaxinaSituacao ( Faxina* fxn ) {
    return fxn->situacao;
}

void setFaxinaSituacao ( Faxina* fxn, int situacao ) {
    fxn->situacao = situacao;
}

int rotacaoFaxina ( int* selecionado, int qtdMorador ) {
    (*selecionado)++;
    return (*selecionado) % qtdMorador;
}
