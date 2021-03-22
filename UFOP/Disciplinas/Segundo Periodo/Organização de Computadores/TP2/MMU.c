#include "MMU.h"

BlocoMemoria *MMU (Cache *L1, Cache *L2, Cache *L3, BlocoMemoria **RAM, int endBloco){
    int hitL1=0, hitL2=0, hitL3=0;
    //int *cont;
    
    //Cache 1
    //printf ("Cache1\n");
    for (int i  = 0; i < getCacheTamanho(L1); i++){
        BlocoMemoria *aux = get1Bloco (getCacheBloco(L1), i);
        int endB = getEnderecoBloco (aux);
        if (endB == endBloco){
            printf ("encontrado na L1\n");
            setCacheHit(L1, 1);
            hitL1++;
            atualizarBlocoAtuazliacao(get1Bloco (getCacheBloco(L1), i));
            return aux;
        }
    }
    setCacheMiss(L1, 1);
    
    //Cache 2
    //printf ("Cache2\n");
    
    for (int i = 0; i < getCacheTamanho(L2); i++){
        BlocoMemoria *aux = get1Bloco (getCacheBloco(L2), i);
        int endB = getEnderecoBloco (aux);
        if (endB == endBloco){
            printf ("encontrado na L2\n");
            setCacheHit(L2, 1);
            hitL2++;
            atualizarBlocoAtuazliacao(get1Bloco (getCacheBloco(L2), i));
            trocaCaches (L2, L1, endBloco);

            return aux;
        }
    }
    setCacheMiss(L2, 1);

    //Cache 3
    //printf ("Cache3\n");

    for (int i = 0; i < getCacheTamanho(L3); i++){
        BlocoMemoria *aux = get1Bloco (getCacheBloco(L3), i);
        int endB = getEnderecoBloco (aux);
        if (endB == endBloco){
            printf ("encontrado na L3\n");
            setCacheHit(L3, 1);
            hitL3++;
            atualizarBlocoAtuazliacao(get1Bloco (getCacheBloco(L3), i));
            
            trocaCaches(L3, L2, endBloco);
            trocaCaches(L2, L1, endBloco);
            //printf ("Foi pra L1\n");
            
            return aux;
        }
    }
    setCacheMiss(L3, 1);

    //RAM

    for (int i = 0; i < 100; i++){
        if (endBloco == getEnderecoBloco(get1Bloco(RAM, i))){
            //hitRAM++;
            printf ("encontrado na RAM\n");
            //int endB = getEnderecoBloco (get1Bloco(RAM, i));
            atualizarBlocoAtuazliacao(get1Bloco(RAM, i));

            //hitRAM(cont);
            printf ("Da RAM pra L3\n");
            RAM_L3 (RAM, L3, endBloco);
            printf ("Da L3 pra L2\n");
            trocaCaches(L3, L2, endBloco);
            printf ("Da L2 pra L1\n");
            trocaCaches(L2, L1, endBloco);

            return get1Bloco(RAM, i);
        }
    }
    printf ("Hit L1 %d\n", hitL1);
    printf ("Hit L2 %d\n", hitL2);
    printf ("Hit L3 %d\n", hitL3);
    //printf ("Hit RAM %d\n", hitRAM);
    return NULL;
}

void salvar(Cache *L1, Cache *L2, Cache *L3, BlocoMemoria **RAM, int endBloco, int endP, int resultado){
    int *cont;
    //Cache 1

    for (int i  = 0; i < getCacheTamanho(L1); i++){
        BlocoMemoria *aux = get1Bloco (getCacheBloco(L1), i);
        int endB = getEnderecoBloco (aux);
        if (endB == endBloco){
            printf ("Tá na L1\n");
            setCacheHit(L1, 1);
            atualizarBlocoAtuazliacao(get1Bloco (getCacheBloco(L1), i));
            //printf ("ATT L1 %d Bloco %d", getAtualizacaoBloco(get1Bloco(getCacheBloco(L1), i)), endBloco);
            setPalavra(get1Bloco(getCacheBloco(L1), i), resultado, endP);
            return;
        }
    }
    setCacheMiss(L1, 1);
    
    //Cache 2
    
    for (int i = 0; i < getCacheTamanho(L2); i++){
        BlocoMemoria *aux = get1Bloco (getCacheBloco(L2), i);
        int endB = getEnderecoBloco (aux);
        if (endB == endBloco){
            printf ("Tá na L2\n");
            setCacheHit(L2, 1);
            atualizarBlocoAtuazliacao(get1Bloco (getCacheBloco(L2), i));
            //printf ("ATT L2 %d Bloco %d", getAtualizacaoBloco(get1Bloco(getCacheBloco(L2), i)), endBloco);
            setPalavra(get1Bloco(getCacheBloco(L2), i), resultado, endP);
            trocaCaches (L2, L1, endBloco);

            return;
        }
    }
    setCacheMiss(L2, 1);

    //Cache 3

    for (int i = 0; i < getCacheTamanho(L3); i++){
        BlocoMemoria *aux = get1Bloco (getCacheBloco(L3), i);
        int endB = getEnderecoBloco (aux);
        if (endB == endBloco){
            printf ("Tá na L3\n");
            setCacheHit(L3, 1);
            //printf ("Cache Hit OK\n");
            atualizarBlocoAtuazliacao(get1Bloco (getCacheBloco(L3), i));
            //printf ("ATT L3 %d Bloco %d", getAtualizacaoBloco(get1Bloco(getCacheBloco(L3), i)), endBloco);
            //printf ("Att Hit OK\n");

            setPalavra(get1Bloco(getCacheBloco(L3), i), resultado, endP);
            //printf ("Set OK\n");

            trocaCaches(L3, L2, endBloco);
            printf ("Da L3 pra L2\n");
            trocaCaches(L2, L1, endBloco);
            printf ("Da L2 pra L1\n");
            
            return;
        }
    }
    setCacheMiss(L3, 1);

    //RAM

    for (int i = 0; i < 100; i++){
        if (endBloco == getEnderecoBloco(get1Bloco(RAM, i))){
            printf ("Tá na RAM\n");
            //int endB = getEnderecoBloco (get1Bloco(RAM, i));
            atualizarBlocoAtuazliacao(get1Bloco(RAM, i));
            //hitRAM(cont);
            setPalavra(get1Bloco(RAM, i), resultado, endP);

            RAM_L3 (RAM, L3, endBloco);
            printf ("Da RAM pra L3\n");
            trocaCaches(L3, L2, endBloco);
            printf ("Da L3 pra L2\n");
            trocaCaches(L2, L1, endBloco);
            printf ("Da L2 pra L1\n");

            return;
        }
    }
}

/*
void passaBlocos(BlocoMemoria* b, Cache* c1, Cache* c2){
    BlocoMemoria* aux = b;
    // bloco menos atualizado da "menor" cache recebe o novo bloco
    // bloco "vazio" na outra cache recebe esse bloco
    BlocoMemoria* aux2 = getBlocoMenosAtualizado(c1);
    b = aux2;
    aux2 = aux;
}

*/
void hitRAM (int *cont){
    printf ("Entrei aqui\n");
    *cont += 1;

}