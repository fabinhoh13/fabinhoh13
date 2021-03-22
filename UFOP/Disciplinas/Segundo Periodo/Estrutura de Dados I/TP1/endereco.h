#ifndef ENDERECO_H
#define ENDERECO_H

#include <stdlib.h>
#include <string.h>

typedef struct endereco Endereco;

Endereco *criarEndereco (char*, int, char*, char*, char*, char*, char *, long int);

void excluirEndereco (Endereco*);

char *getEndRua (Endereco*);
char *getEndBairro (Endereco*);
char *getEndComplemento (Endereco*);
char *getEndCidade (Endereco*);
char *getEndEstado (Endereco*);
char *getEndPais (Endereco*);
int getEndNumero (Endereco*);
long int getEndCep (Endereco*);

void setEndRua (Endereco*, char*);
void setEndBairro (Endereco*, char*);
void setEndComplemento (Endereco*, char*);
void setEndCidade (Endereco*, char*);
void setEndEstado (Endereco*, char*);
void setEndPais (Endereco*, char*);
void setEndNumero (Endereco*, int);
void setEndCep (Endereco*, long int);

#endif