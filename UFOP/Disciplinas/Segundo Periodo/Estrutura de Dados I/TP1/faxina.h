#ifndef FAXINA_H
#define FAXINA_H

#include "morador.h"

typedef struct faxina Faxina;

Faxina* criarFaxina ( char*, Morador* );
Faxina* getFaxina ( Faxina**, int );
void setFaxina ( Faxina**, Faxina*, int );
void excluirFaxina ( Faxina**, int );
void rotacaoGeralFaxina ( Faxina**, Morador**, int*, int, int );
char* getFaxinaArea ( Faxina* );
void setFaxinaArea ( Faxina*, char* );
Morador* getFaxinaMorador ( Faxina* );
void setFaxinaMorador ( Faxina*, Morador* );
int getFaxinaSituacao ( Faxina* );
void setFaxinaSituacao ( Faxina*, int );
int rotacaoFaxina ( int*, int );

#endif