#include "../.h/Estatisticas.h"

typedef struct estatistica{

    // Pesquisa do arquivo
    int freadP;
    int comparacoesP;
    double tempoP;

} Estatistica;

Estatistica* criaEst(){
    Estatistica* aux = malloc(sizeof(Estatistica));
    aux->freadP = 0;
    aux->comparacoesP = 0;
    return aux;
}

int getFreadP(Estatistica* est){
    return est->freadP;
}

int getComparacoesP(Estatistica* est){
    return est->comparacoesP;
}

double getTempoP(Estatistica* est){
    return est->tempoP;
}

void setFreadP(Estatistica* est, int valor){
    est->freadP = valor;
}
void setFomparacoesP(Estatistica* est, int valor){
    est->comparacoesP = valor;
}
void setTempoP(Estatistica* est, double valor){
    est->tempoP = valor;
}

void incrementaFreadP(Estatistica* est){
    est->freadP++;
}
void incrementaComparacoesP(Estatistica* est){
    est->comparacoesP++;
}