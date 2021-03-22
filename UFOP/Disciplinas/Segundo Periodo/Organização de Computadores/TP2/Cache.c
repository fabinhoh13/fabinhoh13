#include "Cache.h"

struct cache{
    BlocoMemoria **bloco;
    int tamanho;
    int cacheHit;
    int cacheMiss;
    int atualizado;
};

Cache *criaCache (int tam){
    Cache *new = malloc (sizeof(Cache));
    new->tamanho = tam;
    new->cacheHit = 0;
    new->cacheMiss = 0;
    new->atualizado = 0;
    new->bloco = malloc (tam * sizeof (BlocoMemoria*));
    for (int i = 0; i < tam; i++) new->bloco[i] = criaBlocoMemoria();
    return new;
}

int getCacheTamanho (Cache *aux){
    return aux->tamanho;;
}
void setCacheTamanho (Cache *aux, int tamanho){
    aux->tamanho = tamanho;
}


int getCacheHit (Cache *aux){
    return aux->cacheHit;
}
void setCacheHit (Cache *aux, int cacheHit){
    aux->cacheHit += cacheHit;
}

int getCacheMiss (Cache *aux){
    return aux->cacheMiss;
}
void setCacheMiss (Cache *aux, int cacheMiss){
    aux->cacheMiss += cacheMiss;
}


Cache *getCache (Cache **aux, int indice){
    return aux[indice];
}

void setAtualizado (Cache *aux){
    if (!aux->atualizado)
        aux->atualizado = 1;
    else
        return;
}

int getAtualizado (Cache *aux){
    return aux->atualizado;
}

BlocoMemoria **getCacheBloco(Cache *aux){
    return aux->bloco;
}



void trocaCaches (Cache *primeiro, Cache *segundo, int endBloco){
    int indice = 0;
    int menoratt = getAtualizacaoBloco(get1Bloco(getCacheBloco(segundo), 0));

    time_t final = time(NULL);

    float maiorTemp = difftime (final, getTempoBloco(get1Bloco(getCacheBloco(segundo), 0)));

    for (int i = 0; i < getCacheTamanho(segundo); i++){
        if (getEnderecoBloco(get1Bloco(getCacheBloco(segundo), i)) == -1){
            printf ("Achei Vazio\n");
            indice = i;
            break;
        }else if (getAtualizacaoBloco(get1Bloco(getCacheBloco(segundo), i)) < menoratt && difftime (final, getTempoBloco(get1Bloco(getCacheBloco(segundo), i))) > maiorTemp){
            menoratt = getAtualizacaoBloco(get1Bloco(getCacheBloco(segundo), i));
            maiorTemp = difftime (final, getTempoBloco(get1Bloco(getCacheBloco(segundo), i)));
            indice = i;
        }
    }

    for (int i = 0; i < getCacheTamanho(primeiro); i++){
        if (getEnderecoBloco(get1Bloco(getCacheBloco(primeiro), i)) == endBloco){
            BlocoMemoria *aux = get1Bloco(getCacheBloco(primeiro), i);
            set1Bloco (getCacheBloco(segundo), get1Bloco(getCacheBloco(primeiro), i), indice);
            set1Bloco (getCacheBloco(primeiro), aux, i);
            //zeraBlocoAtuazliacao(get1Bloco(getCacheBloco(segundo), indice));
            //zeraBlocoAtuazliacao(get1Bloco(getCacheBloco(primeiro), i));
            break;
        }
    }

    

}

void RAM_L3(BlocoMemoria **RAM, Cache *L3, int endBloco){
    int indice = 0;
    int menoratt = getAtualizacaoBloco(get1Bloco(getCacheBloco(L3), 0));

    time_t final = time(NULL);

    float maiorTemp = difftime (final, getTempoBloco(get1Bloco(RAM, 0)));

    for (int i = 0; i < getCacheTamanho(L3); i++){
        if (getEnderecoBloco(get1Bloco(getCacheBloco(L3), i)) == -1){
            indice = i;
            break;
        }else if (getAtualizacaoBloco(get1Bloco(getCacheBloco(L3), i)) < menoratt && difftime (final, getTempoBloco(get1Bloco(RAM, i))) > maiorTemp){
            menoratt = getAtualizacaoBloco(get1Bloco(getCacheBloco(L3), i));
            maiorTemp = difftime (final, getTempoBloco(get1Bloco(RAM, i)));
            indice = i;
        }
    }

    for (int i = 0; i < 100; i++){
        if (getEnderecoBloco(get1Bloco(RAM, i)) == endBloco){
            BlocoMemoria *aux = get1Bloco(RAM, i);
            set1Bloco(RAM, get1Bloco(getCacheBloco(L3), indice), i);
            set1Bloco (getCacheBloco(L3), aux, indice);
            //zeraBlocoAtuazliacao(get1Bloco(getCacheBloco(L3), indice));
            //zeraBlocoAtuazliacao(get1Bloco(RAM, i));
            break;
        }
    }
}

/*
BlocoMemoria *getBlocoMenosAtualizado(Cache *aux){
    int menor = getAtualizacaoBloco(aux->bloco[0]);
    int indice = 0;
    for(int i = 1; i < aux->tamanho;i++){
      if(menor > getAtualizacaoBloco(aux->bloco[i]))
        menor = getAtualizacaoBloco(aux->bloco[i]);
        indice = i;
    }
    return aux->bloco[indice];
}
*/