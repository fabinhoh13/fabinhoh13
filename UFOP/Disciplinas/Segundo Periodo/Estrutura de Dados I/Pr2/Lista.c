#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define rad 0.0174532925


void questao1();
void questao2();
void questao3();
void questao4();
long double fatorial (int num);
long double converter (int graus);
void pesquisa (int **matriz, int linha, int coluna, float *retorno, int *maior, int *menor);

int main (){

    int questao;
    //scanf ("%d", &questao);
    for (questao = 1; questao <= 4; questao++){
        switch (questao)
        {
            case 1:
            {   
                printf ("Questão 1\n\n");
                questao1();
                break;
            }
            case 2:
            {
                printf ("\nQuestão 2\n\n");
                questao2();
                break;
            }
            case 3:
            {
                printf ("\nQuestão 3\n\n");
                questao3();
                break;
            }
            case 4:
            {
                printf ("\nQuestão 4\n\n");
                questao4();
                break;
            }
        }
    }
}

long double converter (int graus){
    return (long double)graus * rad;
}

long double fatorial (int num){
    int i;
    long double aux = 1;

        for (i = 1; i <=num; i++){
                aux *=(long double)i;
        }
    return aux;
}

void pesquisa (int **matriz, int linha, int coluna, float *retorno, int *maior, int *menor){
    int i, j;
    int total = 0;
    *maior = 0;
    *menor = 1000000;
    for (i = 0; i < linha; i++){
        for (j = 0; j < coluna; j++){
            if (matriz[i][j] > *maior)
                *maior = matriz[i][j];
            if (matriz[i][j] < *menor)
                *menor = matriz[i][j];
            total += matriz[i][j];
            
        }
    }

    *retorno = (double)total / ((double)linha * (double)coluna); 
}

void questao1(){
    int i, j, z, x, n;
    long double cos = 1;
    int contador = 2;

    scanf ("%d", &z);

    for (i = 0; i < z; i++){
        
        scanf ("%d %d", &x, &n);
        
        for (j = 0; j < n; j++){
            
            if (j % 2 == 0){
                cos -= (pow(converter(x), contador)/(long double)fatorial(contador));
                
            }
            else {
                cos += (pow(converter(x), contador)/(long double)fatorial(contador));
                
            }
            contador+=2;
        }
        printf ("%.2Lf %d %.5Lf\n", converter(x), n, cos);
        cos = 1.0;
        contador = 2;
    }

}

void questao2(){

    int n, i, j, M, supera = 0;
    double Xa, Da, Ra, Xb, Rb;
    double criancaA, criancaB;
    
    scanf ("%d", &n);

    for (i = 0; i < n; i++){
        scanf ("%lf %lf %lf %lf %lf %d", &Xa, &Da, &Ra, &Xb, &Rb, &M);
        
        criancaA = Xa;
        for (j = 0; j < M; j++){
            criancaB = Xb * (pow(1 + Rb/100, j+1));

            criancaA = criancaA + criancaA * (Ra/100);
            criancaA += Da; 

            if (criancaA < criancaB && supera == 0)
                supera = j+1;
        }
        
        
        if (Ra < Rb && criancaA < criancaB)
            printf ("%.2lf %.2lf %d\n", criancaA, criancaB, supera);
        else if (Ra > Rb)
            printf ("Rendimento de B inválido\n");
        else
            printf ("%.2lf %.2lf B nao supera A\n", criancaA, criancaB);    
    }


}
void questao3(){
    int **matriz, i, j, k, n, linha, coluna;

    int maior, menor;
    float media;

    scanf ("%d", &n);

    for (i = 0; i < n; i++){

        
        scanf ("%d %d", &linha , &coluna);
        
        matriz = malloc (linha * sizeof (int*));

        for (j = 0; j < linha; j++){
            matriz[j] = malloc (coluna * sizeof (int));
            for (k = 0; k < coluna; k++){
                scanf ("%d", &matriz[j][k]);
            }
        }

        pesquisa (matriz, linha, coluna, &media, &maior, &menor);
        printf ("%d %d %.3lf\n", maior, menor, media);
        for (j = 0; j < linha; j++){
            free(matriz[j]);
        }
        free (matriz);
    }
}



void questao4(){
    int ques, nAlunos, **rAlunos;
    int i, j, cont=0;

    scanf ("%d %d", &ques, &nAlunos);

    rAlunos = malloc ((nAlunos + 1) * sizeof (int*));
    rAlunos[0] = malloc (ques * sizeof (int));
    for (i = 1; i < nAlunos + 1; i++){
        rAlunos[i] = malloc ((ques + 1) * sizeof (int));
    }

    for (i = 0; i < ques; i++){
        scanf ("%d", &rAlunos[0][i]);
    }

    for (i = 1; i < nAlunos + 1; i++){
        for (j = 0; j < ques + 1; j++){
            scanf ("%d", &rAlunos[i][j]);
            if (rAlunos[i][j] == rAlunos[0][j])
                cont++;
            
        }
        printf ("%d %d\n", rAlunos[i][ques], cont);
        cont = 0;
    }
    for (i = 0; i < nAlunos + 1; i++){
            free(rAlunos[i]);
        }
        free (rAlunos);
}
