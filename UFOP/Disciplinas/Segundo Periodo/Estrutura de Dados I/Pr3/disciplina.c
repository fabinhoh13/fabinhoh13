#include "disciplina.h"
#include <stdlib.h>
#include <string.h>

struct disciplina{
    char nomeD[101];
    char cursoD[101];
    char codD [10];
    int CHD;
    int salaD;
};

Disciplina* criarD (char* nome, char* cod, int ch, char* curso, int sala){
    Disciplina* dis = malloc (sizeof(Disciplina));
    strcpy (dis->nomeD, nome);
    strcpy (dis->codD, cod);
    strcpy (dis->cursoD, curso);
    dis->CHD = ch;
    dis->salaD = sala;
    return (dis);
}
void apagarD (Disciplina* dis){
    free(dis);
}
void atualizarNomeD (Disciplina* dis, char* nome){
    strcpy (dis->nomeD, nome);
}
void atualizarCodD (Disciplina* dis, char* cod){
    strcpy (dis->codD, cod);
}
void atualizarCursoD (Disciplina* dis, char* curso){
    strcpy (dis->cursoD, curso);
}
void atualizarCHD (Disciplina* dis, int ch){
    dis->CHD = ch;
}
void atualizarSalaD (Disciplina* dis, int sala){
    dis->salaD = sala;
}

Disciplina* getDisciplina(Disciplina **dis, int i){
    return dis[i];
}

char* lerDNome (Disciplina* dis){
    return dis->nomeD;
}

char* lerDCurso (Disciplina* dis){
    return dis->cursoD;
}

char* lerDCod (Disciplina* dis){
    return dis->codD;
}

int lerDSala (Disciplina* dis){
    return dis->salaD;
}

int lerDCH (Disciplina* dis){
    return dis->CHD;
}
