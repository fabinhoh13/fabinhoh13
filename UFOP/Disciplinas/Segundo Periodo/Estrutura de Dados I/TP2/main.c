#include "pilha.h"
#include "Times.h"
#include "fila.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define QUAD 0
#define LOS 1
#define TRAP 2

void questao1();
void questao2();
void questao3();


int main(){
    questao1();
    return 0;
}

void questao1(){
    Pilha *p = criaPilhaVazia();
    
    printf ("Quad\n");
    int lado;
    scanf ("%d", &lado);
    Quadrado *q = criaQuadrado(lado);
    push (p, q, QUAD);

    printf ("Los\n");
    int d1, d2;
    scanf ("%d %d", &d1, &d2);
    Losango *l = criaLosango(d1, d2);
    push (p, l, LOS);
    
    printf ("Trap\n");
    int b1, b2, h;
    scanf ("%d %d %d", &b1, &b2, &h);
    Trapezio *t = criaTrapezio(b1, b2, h);
    push (p, t, TRAP);

    float *areas = calcularArea(p);
    for (int i = 0; i < 3; i++){
        printf ("Area = %1.f\n", areas[i]);
    }
    //apagaPilha(p);
}

void questao2(){
    char time[50], timeA[50], timeB[50], hifen;
    int placarA, placarB, numTimes, numRodadas;
    
    
    scanf ("%d %d", &numTimes, &numRodadas);

    Times **t = malloc (numTimes * sizeof (Times*));

    printf ("Nome dos Times\n");

    for(int i = 0; i < numTimes; i++){
        scanf("%s", time);
        t[i] = criarTimes(time);
    }

    printf ("Jogos\n");
    int indA, indB;
    for (int i = 0; i < numRodadas; i++){
        getchar();
        scanf ("%s %d %c %d %s", timeA, &placarA, &hifen, &placarB, timeB);
        
        indA = buscaNome(t, timeA, numTimes);
        indB = buscaNome(t, timeB, numTimes);

        if (indA != -1 || indB != -1){
            if(placarA > placarB){
                setVitorias(getTime(t, indA), 1);
                setDerrotas(getTime(t, indB), 1);
                setJogos(getTime(t, indB), 1);
                setJogos(getTime(t, indA), 1);
                setGolsPro(getTime(t, indA), placarA);
                setGolsPro(getTime(t, indB), placarB);
                setGolsCon(getTime(t, indA), placarA);
                setGolsCon(getTime(t, indB), placarB);
            }else if (placarA < placarB){
                setVitorias(getTime(t, indB), 1);
                setDerrotas(getTime(t, indA), 1);
                setJogos(getTime(t, indB), 1);
                setJogos(getTime(t, indA), 1);
                setGolsPro(getTime(t, indA), placarA);
                setGolsPro(getTime(t, indB), placarB);
                setGolsCon(getTime(t, indA), placarA);
                setGolsCon(getTime(t, indB), placarB);
            }else{
                setEmpates(getTime(t, indA), 1);
                setEmpates(getTime(t, indB), 1);
                setJogos(getTime(t, indB), 1);
                setJogos(getTime(t, indA), 1);
                setGolsPro(getTime(t, indA), placarA);
                setGolsPro(getTime(t, indB), placarB);
                setGolsCon(getTime(t, indA), placarA);
                setGolsCon(getTime(t, indB), placarB);
            }
        }
        
    }
    printf ("Organizando por nome\n");
    organizaPorNomes(t, numTimes);
    
    printf ("Atualizando os pontos\n");
    for(int i = 0; i < numTimes; i++)
        atualizaPontos(getTime(t, i));
            
    printf ("Atualizando os critérios\n");
    for(int i = 0; i < numTimes; i++)
        atualizaCriterios(getTime(t, i));

    printf ("Organizando por critério\n");
        organizaPorCriterio(t, numTimes);

    printf ("Imprime Tabela\n\n");
    char nomePrinta[50];
    int pontoPrinta, jogosPrinta, golsPPrinta, golsCPrinta, sgPrinta;
    strcpy(nomePrinta, getNome(getTime(t, 0)));
    pontoPrinta = getPontos(getTime(t, 0));
    jogosPrinta = getJogos(getTime(t, 0));
    golsPPrinta = getGolsPro(getTime(t, 0));
    golsCPrinta = getGolsCon(getTime(t, 0));
    sgPrinta = getSaldo(getTime(t, 0));
    printf ("1.\t\t %s\t%d\t%d\t%d\t%d\t%d\n", nomePrinta ,pontoPrinta, jogosPrinta, golsPPrinta, golsCPrinta, sgPrinta);
    for (int i = 1; i < numTimes; i++){
        strcpy(nomePrinta, getNome(getTime(t, i)));
        pontoPrinta = getPontos(getTime(t, i));
        jogosPrinta = getJogos(getTime(t, i));
        golsPPrinta = getGolsPro(getTime(t, i));
        golsCPrinta = getGolsCon(getTime(t, i));
        sgPrinta = getSaldo(getTime(t, i));
        if (getCriterios(getTime(t, i)) == getCriterios(getTime(t, i-1))){
            printf ("  \t\t %s\t%d\t%d\t%d\t%d\t%d\n", nomePrinta ,pontoPrinta, jogosPrinta, golsPPrinta, golsCPrinta, sgPrinta);
        }
        else
            printf ("%d.\t\t %s\t%d\t%d\t%d\t%d\t%d\n", i+1 ,nomePrinta ,pontoPrinta, jogosPrinta, golsPPrinta, golsCPrinta, sgPrinta);
    }
    removerTimes(t, numTimes);
}

void questao3(){
    int nroMax = 5;
    int id[5] = {1, 2, 3, 4, 5};
    char processo[15];
    time_t inicio = time(NULL);
    Fila *n = criaFilaVazia();
    scanf("%s", processo);
    insereFinal(n, processo, id[0], inicio);
    for (int i = 1; i < nroMax; i++){
        scanf("%s", processo);
        insereFinal(n, processo, id[i], inicio);
    }
    imprimeFila(n);
}