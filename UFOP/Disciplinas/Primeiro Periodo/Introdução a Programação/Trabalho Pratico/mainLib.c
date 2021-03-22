#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#include "main.h"


void imprimeNonograma(char **jogo, int l, int c, int *nL, int *nC, int maiorL, int maiorC, int **cabecalhoL, int **cabecalhoC){
    printf ("\n\n");

    for (int i = 0; i < maiorC; i++){
        for (int a = 0; a < maiorL; a++){
            printf ("   ");
        }
		for (int j = 0; j < c; j++){
			if (i - (maiorC - nC[j]) < 0){
                printf ("  ");
			}
			else
                printf ("%2d", cabecalhoC[j][i-(maiorC - nC[j])]);

		}
		printf ("\n");

	}
    for (int a = 0; a < maiorL; a++){
        printf ("   ");
        }
	for (int i = 0; i < c; i++){
        printf ("%2c", i+65);
	}

	printf("\n");
	for (int i = 0; i < l; i++){
		for (int j = maiorL - 1; j >= 0; j--){
			if (nL[i] > j)
                printf("%2d", cabecalhoL[i][j]);
            else
                printf("  ");
		}
		printf ("%2c", 65+i);


		for (int j = 0; j < c; j++){

            printf ("%2c", jogo[i][j]);
        }
        printf ("\n");
	}



    printf ("\n\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void mudaNonograma(char **jogo, char a, char b, int l, int c, char oper){
    int li, co;

    //Faço um case sensitive para as letras digitadas (sensibilidade entre maiuscula e minuscula)

    if (a >= 65 && a <= 90)
        li = a - 65;
    else if (a >= 97 && a <= 122)
        li = a - 97;

    if (b >= 65 && b <= 90)
        co = b - 65;
    else if (b >= 97 && b <= 122)
        co = b - 97;


    //imprimo uma mensagem de erro caso os dados de entrada extrapolem os limites
    if (co >= c || li >= l )
        printf ("Posição incorreta, tente novamente\nExtrapola os limites de %d x %d do nonograma\n", l, c);
    else{
        for (int i = 0; i < l; i++){
                for (int j = 0; j < c; j++){
                        if((li == i) && (co == j)){
                            jogo[i][j] = oper;
                        }
                }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int verifica (char **jogo, int l, int c, int *nL, int *nC, int **cL, int **cC){

    int *contL = calloc (l, sizeof(int));
    int *contC = calloc (c, sizeof(int));
    int *somL = calloc (l, sizeof (int));
    int *somC = calloc (c, sizeof (int));

    //Faço a contagem de quantos 'x' tenho em cada linha
    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
                if (jogo[i][j] == 'x')
                    contL[i]++;
        }
    }

    //Faço a contagem de quantos 'x' tenho em cada coluna
    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
                if (jogo[i][j] == 'x')
                    contC[j]++;

        }
    }

    //Faço a soma dos valores dos cabeçalhos
    //lateral
    for (int i = 0; i < l; i++){
        for (int j = 0; j < nL[i]; j++){
            somL[i] += cL[i][j];
        }
    }
    //superior
    for (int i = 0; i < c; i++){
        for (int j = 0; j < nC[i]; j++){
            somC[i] += cC[i][j];
        }
    }

    int linha = 0, coluna = 0;

    //vejo se as linhas estão completas
    for (int i = 0; i < l; i++){
        if (somL[i] == contL[i])
            linha++;
    }

    //vejo se as colunas estão completas
    for (int i = 0; i < c; i++){
        if (somC[i] == contC[i])
            coluna++;
    }

    free(contC);
    free(contL);
    free(somC);
    free(somL);

    if (linha == l && coluna == c)
        return 1;
    else
        return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void resolver(char **jogo, int l, int c, int *nL, int *nC, int **cL, int **cC){

    //resolvendo com as dicas das linhas
    for (int i = 0; i < l; i++){
        for (int j = 0; j < nL[i]; j++){
            if (cL[i][j] == l){
                for (int a = 0; a < l; a++){
                    for (int b = 0; b < c; b++){
                        if (a==i){
                            jogo[a][b] = 'x';
                        }
                    }
                }
            }

            if (cL[i][j] == l - 2){
                for (int a = 1; a < l; a++){
                    for (int b = 0; b < c-2; b++){
                        if (a==i){
                            jogo[a][b] = 'x';
                        }
                    }
                }
            }
        }
    }


    //resolvendo com as dicas das colunas
    for (int i = 0; i < c; i++){
        for (int j = 0; j < nC[i]; j++){
            if (cC[i][j] == c){
                for (int a = 0; a < l; a++){
                    for (int b = 0; b < c; b++){
                        if (i==b){
                            jogo[a][b] = 'x';
                        }
                    }
                }
            }

            if (cC[i][j] == c - 2){
                for (int a = 1; a < l-2; a++){
                    for (int b = 0; b < c; b++){
                        if (i==b){
                            jogo[a][b] = 'x';
                        }
                    }
                }
            }
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int salvaEstado (char local[], char **jogo, int **cL, int **cC, int *nL, int *nC, int l, int c){
    FILE *dados = fopen(local, "w");
    fprintf(dados, "%d %d\n", l, c);
    fprintf(dados, "\n");
    for (int i = 0; i < l; i++){
        fprintf (dados, "%d ", nL[i]);
        for (int j = 0; j < nL[i]; j++){
            fprintf(dados, "%d ", cL[i][j]);
        }
        fprintf(dados, "\n");
    }
    fprintf(dados, "\n");

    for (int i = 0; i < c; i++){
        fprintf (dados, "%d ", nC[i]);
        for (int j = 0; j < nC[i]; j++){
            fprintf(dados, "%d ", cC[i][j]);
        }
        fprintf(dados, "\n");
    }
    fprintf(dados, "\n");

    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
            fprintf (dados, "%c ", jogo[i][j]);
        }
        fprintf (dados,"\n");
    }
    if (fclose(dados) == 0)
        return 1;
    else
        return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menu(){
    printf ("\n\nBem vindo ao Nonograma!\n\n\n");


    printf ("Lista de Comandos: \n");
    printf ("Comando\t\tOpereção\tUso\n");
    printf ("x\t\tAB\t\tMarca x em AB\n");
    printf ("-\t\tCD\t\tMarca - em CD\n");
    printf (".\t\tFE\t\tMarca . em FE\n");
    printf ("salvar\t\tout.txr\t\tSalva o estado atual do jogo em out.txt\n");
    printf ("sair\t\t\t\tSai do jogo\n");

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void comandos (char **jogo, int linha, int coluna, int *nL, int *nC, int maiorL, int maiorC, int **cabecalhoL, int **cabecalhoC){
    imprimeNonograma(jogo, linha, coluna, nL, nC, maiorL, maiorC, cabecalhoL, cabecalhoC);
    char comando[100], opera[100];

    //MENU

    do{
        if (verifica(jogo, linha, coluna, nL, nC, cabecalhoL, cabecalhoC)){
            system ("clear");

            printf ("\n\n\n\nPARABÉNS!! VOCE TERMINOU COM SUCESSO O NONOGRAMA\n\n\n");
            imprimeNonograma(jogo, linha, coluna, nL, nC, maiorL, maiorC, cabecalhoL, cabecalhoC);

            break;

        }


	printf("Digite um comando: ");
        scanf ("%s", comando);
        if (strcmp(comando, "x")== 0){
            scanf ("%s", opera);
            system ("clear");
            mudaNonograma(jogo, opera[0], opera[1], linha, coluna, comando[0]);
            imprimeNonograma(jogo, linha, coluna, nL, nC, maiorL, maiorC, cabecalhoL, cabecalhoC);


        }
        else if (strcmp(comando, "-")== 0){
            scanf ("%s", opera);
            system ("clear");
            mudaNonograma(jogo, opera[0], opera[1], linha, coluna, comando[0]);
            imprimeNonograma(jogo, linha, coluna, nL, nC, maiorL, maiorC, cabecalhoL, cabecalhoC);
        }
        else if (strcmp(comando, ".")== 0){
            scanf ("%s", opera);
            system ("clear");
            mudaNonograma(jogo, opera[0], opera[1], linha, coluna, comando[0]);
            imprimeNonograma(jogo, linha, coluna, nL, nC, maiorL, maiorC, cabecalhoL, cabecalhoC);
        }
        else if (strcmp(comando, "salvar")== 0){
            scanf ("%s", opera);

            if (salvaEstado (opera, jogo, cabecalhoL, cabecalhoC, nL, nC, linha, coluna))
                printf ("Salvo com Sucesso em %s\n", opera);
            else
                printf ("Arquivo não salvo\n");
        }

        else if (strcmp(comando, "resolver")== 0){
            resolver(jogo, linha, coluna, nL, nC, cabecalhoL, cabecalhoC);
            printf("\n\nNONOGRAMA RESOLVIDO!!!!!\n\n");
            imprimeNonograma(jogo, linha, coluna, nL, nC, maiorL, maiorC, cabecalhoL, cabecalhoC);
            //break;

        }
        else if (strcmp(comando, "sair")== 0){
            system ("clear");
            printf ("\n\nObrigado por jogar <3\n");
        }
        else{
            system("clear");
            printf ("\n\nComando errado!!!!!\n");
            setbuf(stdin, NULL);
        }

    }while (strcmp(comando, "sair")!= 0);
}