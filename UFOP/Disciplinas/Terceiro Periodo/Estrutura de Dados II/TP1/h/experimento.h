#ifndef EXPERIMENTO_H
#define EXPERIMENTO_H

#include <stdlib.h>
#include <time.h>

typedef struct experimento Experimento;

/* Cria um ponteiro para a struct Experimento. Retorna o ponteiro da variavel criada */
Experimento* criaExperimento();

/* Libera o espaço de memoria alocado para a variavel casos

    
    Parametros:
    casos(Experimento*) - Variavel que sera liberada */
void liberaExperimento(Experimento*);

/* Inicializa todas as variaveis com valores iniciais para iniciar um novo experimento


    Parametros:
    casos(Experimento*) - Variavel que sera resetada */
void resetaExperimento(Experimento*);

/* Printa os resultados obtidos para a analise

    
    Parametros:
    casos(Experimento*) - Variavel contendo os dados obtidos

    situação(char*) - Refere-se ao arquivo binario utilizado, crescente, decrescente ou aleatorio
    
    opcao(int) - Opção referente a unidade utilizada para medir o tempo, 0 para segundos e 1
    para milisegundos */
void printaResultados(Experimento*, char*, int);

/* Obtém a quantidade atual de leituras

    
    Parametros:
    casos(Experimento*) - Variavel armazenadora */
long getExperimentoLeitura(Experimento*);

/* Obtém a quantidade atual de comparações

    
    Parametros:
    casos(Experimento*) - Variavel Armazenadora */
long getExperimentoComparacoes(Experimento*);

/* Obtém o clock que correponde ao tempo inicial de execução do metodo

    
    Parametros:
    casos(Experimento*) - Variavel armazenadora */
clock_t getExperimentoInicio(Experimento*);

/* Atualiza o valor de leitura, incrementa o valor em 1

    
    Parametros:
    casos(Experimento*) - Variavel armazenadora */
void incrementaExperimentoLeitura(Experimento*);

/* Atualiza o valor de comparações, incrementa o valor em 1

    
    Parametros:
    casos(Experimento*) */
void incrementaExperimentoComparacoes(Experimento*);

/* Obtém o tempo final de execução do teste

    
    Parametros:
    casos(Experimento*) - Variavel armazenadora
    
    opcao(int) - Determina se o retorno sera em segundos(0) ou milisegundos(1) */
double getExperimentoTempoTotal(Experimento*, int);

#endif