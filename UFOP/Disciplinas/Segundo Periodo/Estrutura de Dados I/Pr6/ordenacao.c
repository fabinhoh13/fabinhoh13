#include "ordenacao.h"

void selection (int *v , int tam){
    int i, j, Min;
    int aux;
    for (i = tam-1; i >= 0; i--) {
        Min = i;
        for (j = tam - 1; j >= i; j--){
            if ( v[j] < v[Min]){
                Min = j;
            }
        
            if (i != Min) {
                aux = v[Min];
                v[Min] = v[i];
                v[i] = aux;
            }
        }
    }
}

void mergeSort (int *v , int tam ) {
    mergeSort_ordena (v , 0, tam -1) ;
}


void mergeSort_ordena (int *v , int esq , int dir ) {
    if ( esq >= dir )
        return;
    int meio = ( esq + dir ) / 2;
    mergeSort_ordena (v , esq , meio );
    mergeSort_ordena (v , meio +1 , dir );
    mergeSort_intercala (v , esq , meio , dir );
return;
}

void mergeSort_intercala (int *v ,int esq ,int meio ,int dir ) {
    int i , j , k;
    int a_tam = meio - esq +1;
    int b_tam = dir - meio ;
    int *a = malloc ( sizeof (int) * a_tam ) ;
    int *b = malloc ( sizeof ( int ) * b_tam ) ;
    for (i = 0; i < a_tam ; i ++) 
        a[i] = v[i+ esq ];
    for (i = 0; i < b_tam ; i ++) 
        b[i] = v[i+ meio +1];
    for (i = 0, j = 0 , k = esq ; k <= dir ; k ++) {
        if (i == a_tam ) 
            v[k] = b[j ++];
        else if ( j == b_tam ) 
            v[k] = a[i++];
        else if ( a[i] < b[j]) 
            v[k] = a[i++];
        else 
            v [k] = b[j ++];
    }
    free (a) ; free (b );
}


void bubble (int *v, int tam){
    int trocas, aux;
    for (int i = 0; i < tam; i++){
        trocas = 0;
        for (int j = 1; j < tam-i; j++){
            
            if(v[j] < v[j-1]){
                aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
                trocas++;
            }
        }
        if (trocas==0)
            break;
    }
}

int buscaBinaria (int *v, int esq, int dir, int num){
    int meio = (esq + dir)/2;

    if (esq >= dir)
        return (num>v[esq])?esq+1:esq;

    
    if (v[meio] == num)
        return meio+1;
    else{
        if (v[meio] < num)
            return buscaBinaria(v, meio+1, dir, num);
        return buscaBinaria (v, esq, meio-1, num);
    }
}

void insertionBinary (int *v, int tam){
    int j, aux, sel;

    for (int i = 1; i < tam; i++){
        j = i-1;
        aux = v[i];

        sel = buscaBinaria (v, 0, j, aux);

        while (j >= sel && j >= 0){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }
}