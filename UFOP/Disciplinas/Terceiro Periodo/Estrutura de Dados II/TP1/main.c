#include <stdio.h>
#include <stdlib.h>
#include "./.h/acessoIndexado.h"
#include "./.h/arvoreBEstrela.h"
#include "./.h/ArvoreBinaria.h"
#include "./.h/ArvoreB.h"

int main(int argc, char** argv) {
    if(argc < 5) {
        printf("Argumentos de entrada insuficiente! O arquivo deve ser executado da seguinte forma:\n");
        printf("./main <metodo> <quantidade> <situação> <chave> [-P]\n");
    }

    int metodo = atoi(argv[1]);
    int tamanhoArq = atoi(argv[2]);
    int situacao = atoi(argv[3]);
    int chave = atoi(argv[4]);
    char nomeArq[40];

    switch(metodo) {
    case 1:
        if(situacao != 1)
            printf("O acesso sequencial indexado deve ser utilizado apenas com arquivos ordenados!\n");

        else
            mainAcessoSequencialIndexado(tamanhoArq, chave);            
        break;

    case 2:
        switch(situacao) {
            case 1:
                arqOrdenadoCrescente(tamanhoArq);
                sprintf(nomeArq, "./bin/%d-crescente.bin", tamanhoArq);
                FILE* arqCrescente = fopen(nomeArq, "rb");
                TPArvBin(arqCrescente, chave);
                fclose(arqCrescente);
                break;

            case 2:
                arqOrdenadoDecrescente(tamanhoArq);
                sprintf(nomeArq, "./bin/%d-decrescente.bin", tamanhoArq);
                FILE* arqDecrescente = fopen(nomeArq, "rb");
                TPArvBin(arqDecrescente, chave);
                fclose(arqDecrescente);
                break;

            case 3:
                arqDesordenadoAleatoriamente(tamanhoArq);
                sprintf(nomeArq, "./bin/%d-aleatorio.bin", tamanhoArq);
                FILE* arqAleatorio = fopen(nomeArq, "rb");
                TPArvBin(arqAleatorio, chave);
                fclose(arqAleatorio);
                break;
            
            default:
                printf("O arquivo selecionado não existe em nosso caso de teste!\n");
                break;
        }
        break;

    case 3:
        switch(situacao) {
            case 1:
                arqOrdenadoCrescente(tamanhoArq);
                sprintf(nomeArq, "./bin/%d-crescente.bin", tamanhoArq);
                FILE* arqCrescente = fopen(nomeArq, "rb");
                ArvBTP(arqCrescente, chave);
                fclose(arqCrescente);
                break;

            case 2:
                arqOrdenadoDecrescente(tamanhoArq);
                sprintf(nomeArq, "./bin/%d-decrescente.bin", tamanhoArq);
                FILE* arqDecrescente = fopen(nomeArq, "rb");
                ArvBTP(arqDecrescente, chave);
                fclose(arqDecrescente);
                break;

            case 3:
                arqDesordenadoAleatoriamente(tamanhoArq);
                sprintf(nomeArq, "./bin/%d-aleatorio.bin", tamanhoArq);
                FILE* arqAleatorio = fopen(nomeArq, "rb");
                ArvBTP(arqAleatorio, chave);
                fclose(arqAleatorio);
                break;
            
            default:
                printf("O arquivo selecionado não existe em nosso caso de teste!\n");
                break;
        }
        break;
    
    case 4:
        mainArvoreBEstrela(tamanhoArq, situacao, chave);
        break;

    default:
        printf("O metodo escolhido não existe!\n");
        break;
    }

    return 0;
}