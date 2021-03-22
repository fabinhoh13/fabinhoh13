#include "Times.h"

struct times{
    char nome[50];
    int pontos;
    int jogos;
    int vitorias;
    int derrotas;
    int empates;
    int saldoGols;
    int golsPro;
    int golsCon;
    int criterios;
};

Times *criarTimes (char nome[]){
    Times *novo = malloc (sizeof(Times));
    strcpy (novo->nome, nome);
    novo->criterios = 0;
    novo->pontos = 0;
    novo->jogos = 0;
    novo->vitorias = 0;
    novo->derrotas = 0;
    novo->empates = 0;
    novo->saldoGols = 0;
    novo->golsPro = 0;
    novo->golsCon = 0;
    return novo;
}

void removerTime (Times *t){
    free(t);
}

void removerTimes (Times **t, int tamanho){
    for (int i = 0; i < tamanho; i++)
        free(t[i]);
    free(t);
}

//Sets

void setNome (Times *t, char nome[]){
    strcpy(t->nome, nome);
}

void setJogos(Times *t, int jogos){
    t->jogos += jogos;
}

void setVitorias (Times *t, int vit){
    t->vitorias += vit;
}

void setDerrotas (Times *t, int der){
    t->derrotas += der;
}

void setEmpates (Times *t, int emp){
    t->empates += emp;
}

void setGolsPro (Times *t, int pro){
    t->golsPro += pro;
}

void setGolsCon (Times *t, int con){
    t->golsCon += con;
}


void setTime (Times **vetor, Times *time, int indice){
    vetor[indice] = time;
}

//Gets
char *getNome (Times *t){
    return t->nome;
}

int getPontos (Times *t){
    return t->pontos;
}

int getJogos (Times *t){
    return t->jogos;
}

int getVitorias (Times *t){
    return t->vitorias;
}

int getDerrotas (Times *t){
    return t->derrotas;
}

int getEmpates (Times *t){
    return t->empates;
}

int getGolsPro (Times *t){
    return t->golsPro;
}

int getGolsCon (Times *t){
    return t->golsCon;
}

int getSaldo (Times *t){
    return t->saldoGols;
}

int getCriterios (Times *t){
    return t->criterios;
}


Times *getTime (Times **vetor, int indice){
    return vetor[indice];
}

void atualizaPontos(Times *t){
    t->pontos = (t->empates) + (t->vitorias * 3);
    t->saldoGols = (t->golsPro) - (t->golsCon);
}

void organizaPorNomes (Times **vetor, int tamanho){
    char aux[50];

    for(int i = 1; i < tamanho; i++){
        for (int j = 0; j < tamanho - 1; j++){          
            if(strcmp(vetor[j]->nome, vetor[j+1]->nome) > 0){
                strcpy(aux, vetor[j]->nome);
                strcpy(vetor[j]->nome, vetor[j+1]->nome);
                strcpy(vetor[j+1]->nome, aux);
            }                               
        }      
    }
}

void atualizaCriterios (Times *t){
    t->criterios = (t->pontos * 10000) + (t->vitorias * 1000) + (t->saldoGols * 100);
}

void organizaPorCriterio(Times **v, int tamanho){

    //Usando o BubbleSort de forma decrescente

    int i, j, Min;
    int aux;
    for (i = tamanho-1; i >= 0; i--) {
        Min = i;
        for (j = tamanho - 1; j >= i; j--){
            if ( v[j]->criterios < v[Min]->criterios){
                Min = j;
            }
        
            if (i != Min) {
                aux = v[Min]->criterios;
                v[Min]->criterios = v[i]->criterios;
                v[i]->criterios = aux;
            }
        }
    }
}

int buscaNome (Times **t, char *nome, int tamanho){
    for (int i = 0; i < tamanho; i++){
        if(strcmp(nome, t[i]->nome) == 0)
            return i;
    }
    return -1;
}

