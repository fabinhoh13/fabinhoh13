#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#include "main.h"


int main(int argv, char *argc[]){
    setlocale (LC_ALL, "");
    FILE *dados;
    char carac;
    int linha, coluna, maiorL = 0, maiorC = 0;
    int erro = 0;


    //saber se estou passando o arquivo no momento da execu��o ou dentro do proprio programa
    if (argv == 1){
        char arq[50];
        printf ("Arquivo não digitado, por favor, digite o nome do arquivo do nonograma a ser jogado:\n");
        scanf ("%s", arq);
        dados = fopen (arq, "r");
        system ("clear");
    }
    else
        dados = fopen (argc[1], "r");

////////////////////////////////////////////////////////////////////////////////////////////////////////
  
    fscanf (dados, "%d %d", &linha, &coluna);
    

    int *sErroL = calloc (linha, sizeof (int));
    int *sErroC = calloc (coluna, sizeof (int));

    //verificação se a matriz é realmente 26x26
    if (linha > 26 && coluna > 26){
            printf ("Desculpa, não trabalhamos com nonogramas com dimens�es maiores que 26x26\n");
            erro = 1;
    }

    //iniciando a 
    int *nL = malloc (linha * sizeof(int));
    int **cabecalhoL = (int**) malloc (linha * sizeof(int*));
    for (int i = 0; i < linha; i++){
        fscanf (dados, "%d", &nL[i]);
        if (nL[i] > maiorL)
                maiorL = nL[i];
        cabecalhoL[i] = (int*) malloc(nL[i] * sizeof(int));
        for (int j = nL[i] - 1; j >= 0; j--){
            fscanf(dados, "%d", &cabecalhoL[i][j]);

            sErroL[i] += cabecalhoL[i][j];

            if (cabecalhoL[i][j] > linha){
                printf ("Ops, tem algo de errado com o cabe�alho. %d n�o condiz com as condi��es de dimens�o\n", cabecalhoL[i][j]);
                erro = 1;
            }
        }
    }
   
   
    int *nC = malloc (coluna * sizeof(int));
    int **cabecalhoC = malloc (coluna * sizeof(int*));
    for (int i = 0; i < coluna; i++){
        fscanf (dados, "%d", &nC[i]);
        if (nC[i] > maiorC)
                maiorC = nC[i];
        cabecalhoC[i] = malloc(nC[i] * sizeof(int));
        for (int j = 0; j < nC[i]; j++){
            fscanf(dados, "%d", &cabecalhoC[i][j]);

            sErroC[i] = cabecalhoC[i][j];

            if (cabecalhoC[i][j] > coluna){
                printf ("Ops, tem algo de errado com o cabeçaalho. %d n�o condiz com as condi��es de dimens�o\n", cabecalhoC[i][j]);
                erro = 1;
            }
        }
    }


    //verificação de erros
    for (int i = 0; i < linha; i++){
        if (sErroL[i] > coluna){
            printf ("Erro: posição %d do cabeçalho lateral não está de acordo\n", i+1);
            erro = 1;
        }
        else if (sErroL [i]+ (nL[i] - 1) > coluna){
            printf ("Erro: posição %d do cabeçalho lateral não está de acordo\n", i+1);
            erro = 1;
        }
    }

    for (int i = 0; i < coluna; i++){
        if (sErroC[i] > linha){
            printf ("Erro: posição %d do cabeçalho lateral não está de acordo\n", i+1);
            erro = 1;
        }
        else if (sErroC [i]+ (nC[i] - 1) > linha){
            printf ("Erro: posição %d do cabeçalho lateral não está de acordo\n", i+1);
            erro = 1;
        }
    }

    if (erro){
        printf ("\n\nDesculpa, não podemos iniciar o nonograma :(\n");
        return 0;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    char **jogo = malloc (linha * sizeof(char*));
    for (int i = 0; i < linha; i++){
        jogo[i] = malloc(coluna * sizeof(char));
        for (int j = 0; j < coluna; j++){
            fscanf(dados, "%c", &carac);
            if (carac != '\n' && carac != ' ' && carac != '\r')
                jogo[i][j] = carac;
            else
                j--;

        }
    }

    fclose(dados);
    free(sErroL);
    free(sErroC);



    menu();
    comandos(jogo, linha, coluna, nL, nC, maiorL, maiorC, cabecalhoL, cabecalhoC);
  
  
    free(nL);
    free(nC);

    for (int i = 0; i < linha; i++){
        if (cabecalhoL[i] != 0)
            free(cabecalhoL[i]);
    }
    for (int i = 0; i < coluna; i++){
        if (cabecalhoC[i] != 0)
            free(cabecalhoC[i]);
    }
    return 0;
}


