#ifndef MORADOR_H
#define MORADOR_H

typedef struct morador Morador;

Morador* criarMorador ( char*, char*, char*, int, char*, char* );
void atualizarMoradores ( Morador**, Morador** );
void excluirMorador ( Morador**, int );
Morador* getMorador ( Morador**, int );
void setMorador ( Morador**, Morador*, int );
char* getMoradorNome ( Morador* );
void setMoradorNome ( Morador*, char* );
char* getMoradorApelido ( Morador* );
void setMoradorApelido ( Morador*, char* );
char* getMoradorCidade ( Morador* );
void setMoradorCidade ( Morador*, char* );
int getMoradorIdade ( Morador* );
void setMoradorIdade ( Morador*, int );
char* getMoradorCurso ( Morador* );
void setMoradorCurso ( Morador*, char* );
char* getMoradorData ( Morador* );
void setMoradorData ( Morador*, char* );
Morador** organizaMorador ( Morador**, Morador**, int );
void mergeSort ( int*, int, int );
void merge ( int*, int, int, int );

#endif
