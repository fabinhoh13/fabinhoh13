#include "../.h/geraBinarios.h"

#include <stdlib.h>
#include <unistd.h>
#include "../.h/tipoItem.h"

void arqOrdenadoCrescente(int tamanhoArq) {
    char nomeArq[40];
    sprintf(nomeArq, "./bin/%d-crescente.bin", tamanhoArq);
    
    if(access(nomeArq, F_OK)) {
        FILE* arqCrescente = fopen(nomeArq, "wb");

        TipoItem** listItens = criaListItens(tamanhoArq);
        for(int i = 0; i < tamanhoArq; i++) {
            setListItensPeloIndice(listItens, i, i + 1);
            setDadosExtras(listItens, i);
        }
        writeItem(arqCrescente, listItens, tamanhoArq);

        liberaListItens(listItens, tamanhoArq);
        fclose(arqCrescente);
    }
}

void arqOrdenadoDecrescente(int tamanhoArq) {
    char nomeArq[40];
    sprintf(nomeArq, "./bin/%d-decrescente.bin", tamanhoArq);

    if(access(nomeArq, F_OK)) {
        FILE* arqDecrescente = fopen(nomeArq, "wb");
        
        TipoItem** listItens = criaListItens(tamanhoArq);
        for(int i = 0; i < tamanhoArq; i++) {
            setListItensPeloIndice(listItens, i, tamanhoArq - i);
            setDadosExtras(listItens, i);
        }
        writeItem(arqDecrescente, listItens, tamanhoArq);

        liberaListItens(listItens, tamanhoArq);
        fclose(arqDecrescente);
    }
}

void arqDesordenadoAleatoriamente(int tamanhoArq) {
    char nomeArq[40];
    sprintf(nomeArq, "./bin/%d-aleatorio.bin", tamanhoArq);
    
    if(access(nomeArq, F_OK)) {
        FILE* arqAleatorio = fopen(nomeArq, "wb");

        TipoItem** listItens = criaListItens(tamanhoArq);
        for(int i = 0; i < tamanhoArq; i++) {
            setListItensPeloIndice(listItens, i, i + 1);
            setDadosExtras(listItens, i);
        }
        /* Função responsável por desordenar o vetor, deixando seus numeros em uma sequencia aleatoria 
            A sequencia aleatoria em questão sempre será a mesma para todos os casos de teste          */
        shuffle(listItens, tamanhoArq);
        writeItem(arqAleatorio, listItens, tamanhoArq);

        liberaListItens(listItens, tamanhoArq);
        fclose(arqAleatorio);
    }
}