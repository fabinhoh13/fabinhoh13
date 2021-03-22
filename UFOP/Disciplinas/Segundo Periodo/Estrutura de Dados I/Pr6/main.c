#include "geraValores.h"
#include "ordenacao.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimeVetor (int *v, int tam);

int main (){
    srand (time(NULL));
    int tamanho;

    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo=localtime( &rawtime );
    printf("Data de inicio do programa: %s\n\n\n", asctime (timeinfo) );

    
    scanf ("%d", &tamanho);
    for (int i = 0; i < 4; i++){
        switch (i){
            case 0:{
                int *crescente = geraCrescente(tamanho);
                int *decrescente = geraDecrescente(tamanho);
                int *aleatorio = geraAleatorio(tamanho);
                printf ("Bubble Sort\n\n");
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de inicio(Aleatório): %s", asctime (timeinfo) );
                bubble (aleatorio, tamanho);
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de término(Aleatório): %s\n", asctime (timeinfo) );

                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de inicio(Crescente): %s", asctime (timeinfo) );
                bubble (crescente, tamanho);
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de término(Crescente): %s\n", asctime (timeinfo) );
                
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de inicio(Decrescente): %s", asctime (timeinfo) );
                bubble (decrescente, tamanho);
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de término(Decrescente): %s\n", asctime (timeinfo) );
                
                
                
                free(crescente);
                free(decrescente);
                free(aleatorio);
                break;
            }

            case 1:{
                int *crescente = geraCrescente(tamanho);
                int *decrescente = geraDecrescente(tamanho);
                int *aleatorio = geraAleatorio(tamanho);
                printf ("Insertion Sort\n\n");
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de inicio(Aleatório): %s", asctime (timeinfo) );
                insertionBinary (aleatorio, tamanho);
                //imprimeVetor (aleatorio, tamanho);
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de término(Aleatório): %s\n", asctime (timeinfo) );

                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de inicio(Crescente): %s", asctime (timeinfo) );
                insertionBinary (crescente, tamanho);
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de término(Crescente): %s\n", asctime (timeinfo) );
                
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de inicio(Decrescente): %s", asctime (timeinfo) );
                insertionBinary (decrescente, tamanho);
                //imprimeVetor (decrescente, tamanho);
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de término(Decrescente): %s\n", asctime (timeinfo) );
                
                
                
                free(crescente);
                free(decrescente);
                free(aleatorio);
                break;
            }

            case 2:{
                int *crescente = geraCrescente(tamanho);
                int *decrescente = geraDecrescente(tamanho);
                int *aleatorio = geraAleatorio(tamanho);
                printf ("Selection Sort\n\n");
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de inicio(Aleatório): %s", asctime (timeinfo) );
                selection (aleatorio, tamanho);
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de término(Aleatório): %s\n", asctime (timeinfo) );

                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de inicio(Crescente): %s", asctime (timeinfo) );
                selection (crescente, tamanho);
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de término(Crescente): %s\n", asctime (timeinfo) );
                
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de inicio(Decrescente): %s", asctime (timeinfo) );
                selection (decrescente, tamanho);
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de término(Decrescente): %s\n", asctime (timeinfo) );
                
                
                
                free(crescente);
                free(decrescente);
                free(aleatorio);
                break;
            }

            case 3:{
                int *crescente = geraCrescente(tamanho);
                int *decrescente = geraDecrescente(tamanho);
                int *aleatorio = geraAleatorio(tamanho);
                printf ("Merge Sort\n\n");
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de inicio(Aleatório): %s", asctime (timeinfo) );
                mergeSort (aleatorio, tamanho);
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de término(Aleatório): %s\n", asctime (timeinfo) );

                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de inicio(Crescente): %s", asctime (timeinfo) );
                mergeSort (crescente, tamanho);
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de término(Crescente): %s\n", asctime (timeinfo) );
                
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de inicio(Decrescente): %s", asctime (timeinfo) );
                mergeSort (decrescente, tamanho);
                time ( &rawtime );
                timeinfo=localtime( &rawtime );
                printf("Data de término(Decrescente): %s\n", asctime (timeinfo) );
                
                
                
                free(crescente);
                free(decrescente);
                free(aleatorio);
                break;
            }
        }
    }
    return 0;
}

void imprimeVetor (int *v, int tam){
    for (int i = 0; i < tam; i++){
        printf ("%d ", v[i]);
    }
    printf ("\n");
}