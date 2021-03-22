#ifndef REPUBLICA_H
#define REPUBLICA_H

#include "morador.h"
#include "endereco.h"
#include "faxina.h"
#include "funcoes_uteis.h"

#include <stdlib.h>
#include <string.h>


typedef struct republica Republica;

Republica *criaRepublica (Morador **moradores, char *nome, Endereco *end, char *dataRep, int numeroMoradores, int quantMax, Faxina **fax);

void excluirRepublica (Republica *rep, int qtdFxn);

void setRepNome (Republica *rep, char* nomeRep);
char *getRepNome (Republica *rep);
void setRepData (Republica *rep, char* dataRep);
char *getRepData (Republica *rep);
void setRepQuantidade (Republica *rep, int quant);
int getRepQuantidade (Republica *rep);
Morador *getRepMorador (Republica *rep, int indice);
void setRepMorador (Republica *rep, Morador *mrd, int indice);
Endereco *getRepEndereco (Republica *rep);
void setRepEndereco (Republica *rep, Endereco *end);
Faxina *getRepFaxina (Republica *rep, int indice);
void setRepFaxina (Republica *rep, Faxina *fax, int indice);
int adicionarMorador ( Republica*, Morador* );
void excluirRepMorador ( Republica*, Morador* );
Morador *buscaMorador (Republica *rep, char *nome);
int excluirMoradorRep_Nome (Republica *rep, char *nome);
Morador *buscaMoradorApelido (Republica *rep, char *nome, int *retorno);
Faxina *buscaFaxinaArea (Republica *rep, char *area, int qntArea, int *retorno);

#endif
