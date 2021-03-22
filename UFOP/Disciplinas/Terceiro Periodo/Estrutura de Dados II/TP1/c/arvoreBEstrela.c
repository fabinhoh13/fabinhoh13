#include "../.h/arvoreBEstrela.h"
#include "../.h/geraBinarios.h"

#define N 10

void mainArvoreBEstrela(int tamanhoArq, int situacao, int chave) {
    char nomeArq[40];
    TipoBEstrela* arvore = criaBEstrela();
    Experimento* casos = criaExperimento();
    TipoItem* item = criaItem();
    int achou;

    switch(situacao) {
    case 1:
        arqOrdenadoCrescente(tamanhoArq);
        
        sprintf(nomeArq, "./bin/%d-crescente.bin", tamanhoArq);
        FILE* arqCrescente = fopen(nomeArq, "rb");
        
        arvore = NULL;
        resetaExperimento(casos);
        criaArvoreBEstrela(arqCrescente, &arvore, tamanhoArq, casos);
        printaResultados(casos, "Arquivo Crescente\nCriação da arvore", 1);

        resetaExperimento(casos);
        setItemChave(item, chave);
        achou = pesquisaArvoreBEstrela(item, arvore, casos);
        printaResultados(casos, "Pesquisa da chave", 1);
        printf("%s\n", achou ? "Item encontrado com sucesso!\n" : "Item não pertence ao arquivo!\n");
        
        fclose(arqCrescente);
        break;

    case 2:
        arqOrdenadoDecrescente(tamanhoArq);
        
        sprintf(nomeArq, "./bin/%d-decrescente.bin", tamanhoArq);
        FILE* arqDecrescente = fopen(nomeArq, "rb");

        arvore = NULL;
        resetaExperimento(casos);
        criaArvoreBEstrela(arqDecrescente, &arvore, tamanhoArq, casos);
        printaResultados(casos, "Arquivo Decrescente\nCriação da arvore", 1);

        resetaExperimento(casos);
        setItemChave(item, chave);
        achou = pesquisaArvoreBEstrela(item, arvore, casos);
        printaResultados(casos, "Pesquisa da chave", 1);
        printf("%s\n", achou ? "Item encontrado com sucesso!\n" : "Item não pertence ao arquivo!\n");
        
        fclose(arqDecrescente);
        break;

    case 3:
        arqDesordenadoAleatoriamente(tamanhoArq);
        
        sprintf(nomeArq, "./bin/%d-aleatorio.bin", tamanhoArq);
        FILE* arqAleatorio = fopen(nomeArq, "rb");

        arvore = NULL;
        resetaExperimento(casos);
        criaArvoreBEstrela(arqAleatorio, &arvore, tamanhoArq, casos);
        printaResultados(casos, "Arquivo Aleatorio\nCriação da arvore", 1);

        resetaExperimento(casos);
        setItemChave(item, chave);
        achou = pesquisaArvoreBEstrela(item, arvore, casos);
        printaResultados(casos, "Pesquisa da chave", 1);
        printf("%s\n", achou ? "Item encontrado com sucesso!\n" : "Item não pertence ao arquivo!\n");
        
        fclose(arqAleatorio);
        break;
    
    default:
        printf("A opção selecionada é de um arquivo inexistente dos casos de teste!\n");
        break;
    }

    liberaExperimento(casos);
    liberaItem(item);
    liberaBEstrela(arvore);
}

void criaArvoreBEstrela(FILE* arq, TipoBEstrela** arvore, int tamanhoArq, Experimento* casos) {
    // Aloca todas as posição necessárias para leitura e inserção dos elementos
    TipoItem** item = criaListItens(tamanhoArq);
    int i = 0;

    // Lê os elementos do arquivo
    while(readItem(arq, item[i]) == 1) {
        incrementaExperimentoLeitura(casos);
        insereElementoArvoreBEstrela(item[i], arvore, casos);
        i++;
    }

    incrementaExperimentoLeitura(casos);
    liberaListItens(item, tamanhoArq);
}

void insereElementoArvoreBEstrela(TipoItem* item, TipoBEstrela** arvore, Experimento* casos) {
    TipoBEstrela* temp = criaBEstrela();

    // Insere o primeiro elemento da arvore
    if(*arvore == NULL) {
        setEstrelaCategoriaPagina(temp, Externo);
        setEstrelaTamanhoExterno(temp, 1);
        setEstrelaListItemExterno(temp, 0, item);
        *arvore = temp;
        return;
    }

    else {
        short cresceu;
        TipoItem* itemRetorno;
        TipoBEstrela* arvRetorno;
        
        insArvoreBEstrela(item, arvore, &cresceu, &itemRetorno, &arvRetorno, casos);

        // Adiciona uma nova raiz a arvore
        if(cresceu) {
            setEstrelaCategoriaPagina(temp, Interno);
            setEstrelaTamanhoInterno(temp, 1);
            setEstrelaVetorChave(temp, 0, getItemChave(itemRetorno));
            setEstrelaPaginaInterna(temp, 1, arvRetorno);
            setEstrelaPaginaInterna(temp, 0, *arvore);
            *arvore = temp;
        }
    }
}

void insArvoreBEstrela(TipoItem* item, TipoBEstrela** arvore, short* cresceu, TipoItem** itemRetorno, TipoBEstrela** arvRetorno, Experimento* casos) {
    long i = 1;
    TipoBEstrela* temp;

    if(getEstrelaCategoriaPagina(*arvore) == Externo) {
        // Comparação entre as chaves para encontrar a posição do item no array
        while(i < getEstrelaTamanhoExterno(*arvore) && getItemChave(item) > getChaveItemExterno(*arvore, i - 1)) {
            incrementaExperimentoComparacoes(casos);
            i++;
        }
        incrementaExperimentoComparacoes(casos);

        incrementaExperimentoComparacoes(casos);
        // Não realiza nada na arvore, caso o item que desejamos inserir já esteja la
        if(getItemChave(item) == getChaveItemExterno(*arvore, i - 1)) {
            printf("Item presente na arvore!\n");
            *cresceu = 0;
            return;
        }

        incrementaExperimentoComparacoes(casos);
        // Retorna o indice para a posição desejada
        if(getItemChave(item) < getChaveItemExterno(*arvore, i - 1)) 
            i--;
        
        // Pagina com espaço suficiente para inserir o item
        if(getEstrelaTamanhoExterno(*arvore) < MM2) {
            *itemRetorno = item;
            insereNaPaginaBEstrela(arvore, *itemRetorno, *arvRetorno, casos);
            *cresceu = 0;
            return;
        }

        temp = criaBEstrela();
        setEstrelaCategoriaPagina(temp, Externo);

        *itemRetorno = item;
        *arvRetorno = NULL;

        // Realiza o emprestimo do elemento mais a direita
        if(i < M + 1) {
            insereNaPaginaBEstrela(&temp, getEstrelaListItemExterno(*arvore, MM2 - 1), *arvRetorno, casos);
            setEstrelaTamanhoExternoIncrementa(*arvore, -1);
            insereNaPaginaBEstrela(arvore, *itemRetorno, *arvRetorno, casos);
        }

        else 
            insereNaPaginaBEstrela(&temp, *itemRetorno, *arvRetorno, casos);

        for(long j = 1; j <= M; j++)
            insereNaPaginaBEstrela(&temp, getEstrelaListItemExterno(*arvore, MM2 - j), *arvRetorno, casos);

        setEstrelaTamanhoExterno(*arvore, M);
        *itemRetorno = getEstrelaListItemExterno(*arvore, M);
        *arvRetorno = temp;
        *cresceu = 1;
        return;
    }

    else {
        // Comparação entre as chaves para encontrar a chave dentro do array interno
        while(i < getEstrelaTamanhoInterno(*arvore) && getItemChave(item) > getEstrelaVetorChave(*arvore, i - 1)) {
            i++;
            incrementaExperimentoComparacoes(casos);
        }
        incrementaExperimentoComparacoes(casos);

        incrementaExperimentoComparacoes(casos);
        // Não realiza nada na arvore, caso o item que desejamos inserir já esteja la
        if(getItemChave(item) == getEstrelaVetorChave(*arvore, i - 1)) {
            printf("Item presente na arvore!\n");
            *cresceu = 0;
            return;
        }

        incrementaExperimentoComparacoes(casos);
        // Retorna o indice para a posição desejada
        if(getItemChave(item) < getEstrelaVetorChave(*arvore, i - 1))
            i--;

        TipoBEstrela* aux = criaBEstrela();
        aux = getEstrelaPaginaInterna(*arvore, i);

        insArvoreBEstrela(item, &aux, cresceu, itemRetorno, arvRetorno, casos);

        if(!*cresceu)
            return;

        // Pagina com o espaço suficiente para inserir o item
        if(getEstrelaTamanhoInterno(*arvore) < MM) {
            insereNaPaginaBEstrela(arvore, *itemRetorno, *arvRetorno, casos);
            *cresceu = 0;
            return;
        }

        temp = criaBEstrela();
        setEstrelaCategoriaPagina(temp, Interno);
        setEstrelaTamanhoInterno(temp, 0);
        setEstrelaPaginaInterna(temp, 0, NULL);

        TipoItem* itemTemp = criaItem();

        // Emprestimo
        if(i < M + 1) {
            setItemChave(itemTemp, getEstrelaVetorChave(*arvore, MM - 1));
            insereNaPaginaBEstrela(&temp, itemTemp, getEstrelaPaginaInterna(*arvore, MM), casos);
            setEstrelaTamanhoInternoIncrementa(*arvore, -1);
            insereNaPaginaBEstrela(arvore, *itemRetorno, *arvRetorno, casos);
        }

        // Inserção direta
        else 
            insereNaPaginaBEstrela(&temp, *itemRetorno, *arvRetorno, casos);

        for(long j = M + 2; j <= MM; j++) {
            setItemChave(itemTemp, getEstrelaVetorChave(*arvore, j - 1));
            insereNaPaginaBEstrela(&temp, itemTemp, getEstrelaPaginaInterna(*arvore, j), casos);
        }

        setEstrelaTamanhoInterno(*arvore, M);
        setEstrelaPaginaInterna(temp, 0, getEstrelaPaginaInterna(*arvore, M + 1));
        setItemChave(*itemRetorno, getEstrelaVetorChave(*arvore, M));
        *arvRetorno = temp;

        return;
    }
} 

void insereNaPaginaBEstrela(TipoBEstrela** arvore, TipoItem* item, TipoBEstrela* pagDireita, Experimento* casos) {
    short semPosicao = 0;
    int i;

    if(getEstrelaCategoriaPagina(*arvore) == Externo) {
        i = getEstrelaTamanhoExterno(*arvore);
        // Confere se existe posições validas dentro da pagina externa
        if(i > 0)
            semPosicao = 1;

        // Procura a posição certa para inserir o elemento na arvore
        while(semPosicao) {
            incrementaExperimentoComparacoes(casos);
            if(getItemChave(item) >= getChaveItemExterno(*arvore, i - 1)) {
                semPosicao = 0;
                break;
            }

            setEstrelaListItemExterno(*arvore, i, getEstrelaListItemExterno(*arvore, i - 1));
            i--;
            if(i < 1)
                semPosicao = 0;
        }

        // Insere definitivamente o elemento
        setEstrelaListItemExterno(*arvore, i, item);    
        setEstrelaTamanhoExternoIncrementa(*arvore, 1);
    }

    else {
        i = getEstrelaTamanhoInterno(*arvore);
        // Confere se existe posições validas dentro da pagina interna
        if(i > 0)
            semPosicao = 1;

        // Procura a posição certa para inserir o elemento na arvore
        while(semPosicao) {
            incrementaExperimentoComparacoes(casos);
            if(getItemChave(item) >= getEstrelaVetorChave(*arvore, i - 1)) {
                semPosicao = 0;
                break;
            }

            setEstrelaVetorChave(*arvore, i, getEstrelaVetorChave(*arvore, i - 1));
            setEstrelaPaginaInterna(*arvore, i + 1, getEstrelaPaginaInterna(*arvore, i));
            i--;
            if(i < 1)
                semPosicao = 0;
        }
    
        // Insere definitivamente o elemento
        setEstrelaVetorChave(*arvore, i, getItemChave(item));
        setEstrelaPaginaInterna(*arvore, i + 1, pagDireita);
        setEstrelaTamanhoInternoIncrementa(*arvore, 1);
    }
    
    return;
}

int pesquisaArvoreBEstrela(TipoItem* item, TipoBEstrela* arvore, Experimento* casos) {
    long i = 1;

    // Caso de arvore vazia
    if(arvore == NULL)
        return 0;

    if(getEstrelaCategoriaPagina(arvore) == Interno) {
        // Comparação entre as chaves para encontrar a chave dentro do array interno
        while(i < getEstrelaTamanhoInterno(arvore) && getItemChave(item) > getEstrelaVetorChave(arvore, i - 1)) {
            incrementaExperimentoComparacoes(casos);
            i++;
        }
        incrementaExperimentoComparacoes(casos);

        incrementaExperimentoComparacoes(casos);
        // Navegação entre as paginas internas ate que seja encontrada a referencia da pagina externa correspondente
        if(getItemChave(item) < getEstrelaVetorChave(arvore, i - 1))
            return pesquisaArvoreBEstrela(item, getEstrelaPaginaInterna(arvore, i - 1), casos);
        
        else
            return pesquisaArvoreBEstrela(item, getEstrelaPaginaInterna(arvore, i), casos);
    }

    else {
        // Comparação entre as chaves para encontrar a posição do item desejado
        while(i < getEstrelaTamanhoExterno(arvore) && getItemChave(item) > getChaveItemExterno(arvore, i - 1)) {
            incrementaExperimentoComparacoes(casos);
            i++;
        }
        incrementaExperimentoComparacoes(casos);

        incrementaExperimentoComparacoes(casos);
        if(getItemChave(item) == getChaveItemExterno(arvore, i - 1)) {
            return 1;
        }

        else
            return 0;
    }
}


