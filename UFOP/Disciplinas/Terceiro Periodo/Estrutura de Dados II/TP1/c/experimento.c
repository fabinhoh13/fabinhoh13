#include "../.h/experimento.h"
#include <stdio.h>

struct experimento {
    long leitura;
    long comparacoes;
    clock_t inicio;
};

Experimento* criaExperimento() {
    Experimento* casos = malloc(sizeof(Experimento));
    return casos;
}

void liberaExperimento(Experimento* casos) {
    free(casos);
}

void resetaExperimento(Experimento* casos) {
    casos->leitura = 0;
    casos->comparacoes = 0;
    casos->inicio = clock();
}

void printaResultados(Experimento* casos, char* situacao, int opcao) {
    printf("%s\n", situacao);
    printf("Quantidade de leitura: %ld\n", getExperimentoLeitura(casos));
    printf("Quantidade de comparações: %ld\n", getExperimentoComparacoes(casos));
    printf("Tempo gasto: %.4lf %s\n\n", getExperimentoTempoTotal(casos, opcao), opcao ? "milisegundos" : "segundos");
}

long getExperimentoLeitura(Experimento* casos) {
    return casos->leitura;
}

long getExperimentoComparacoes(Experimento* casos) {
    return casos->comparacoes;
}

clock_t getExperimentoInicio(Experimento* casos) {
    return casos->inicio;
}

void incrementaExperimentoLeitura(Experimento* casos) {
    casos->leitura++;
}

void incrementaExperimentoComparacoes(Experimento* casos) {
    casos->comparacoes++;
}

/* Retorna o tempo total de execução no momento que a função é chamada, caso o argumento opção 
    seja 0 é retornado o valor em segundos, caso seja 1 é retornado o valor em milisegundos */
double getExperimentoTempoTotal(Experimento* casos, int opcao) {
    clock_t tempoTotal = clock() - casos->inicio;
    if(opcao)
        return (double)tempoTotal / (CLOCKS_PER_SEC/ 1000);

    return (double)tempoTotal / CLOCKS_PER_SEC;
}

