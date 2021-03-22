#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct times Times;


Times *criarTimes (char nome[]);
void removerTime (Times *t);
void removerTimes (Times **t, int tamanho);

//Sets

void setNome (Times *t, char nome[]);
void setJogos(Times *t, int jogos);
void setVitorias (Times *t, int vit);
void setDerrotas (Times *t, int der);
void setEmpates (Times *t, int emp);
void setGolsPro (Times *t, int pro);
void setGolsCon (Times *t, int con);
void setTime (Times **vetor, Times *time, int indice);

//Gets

char *getNome (Times *t);
int getPontos (Times *t);
int getJogos (Times *t);
int getVitorias (Times *t);
int getDerrotas (Times *t);
int getEmpates (Times *t);
int getGolsPro (Times *t);
int getGolsCon (Times *t);
int getSaldo (Times *t);
int getCriterios (Times *t);
Times *getTime (Times **vetor, int indice);

//Funcoes Uteis

void atualizaPontos(Times *t);
void organizaPorNomes (Times **vetor, int tamanho);
void atualizaCriterios (Times *t);
void organizaPorCriterio(Times **v, int tamanho);
int buscaNome (Times **t, char *nome, int tamanho);
