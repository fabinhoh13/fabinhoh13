#include "Huffman.h"

struct listano {
    ArvoreNo *tree;
    ListaNode *prox;
};

struct lista{
    ListaNode *prim;
    int insercoes;
};

struct arvore{
    int frequencia;
    byte c;
    ArvoreNo *esquerda;
    ArvoreNo *direita;
};


Lista *criaListaA (){
    Lista *novo = malloc (sizeof(Lista));
    novo->prim = NULL;
    novo->insercoes = 0;
    return novo;
}

ListaNode *criaListaNoA(ArvoreNo *noNovo){
    ListaNode *novo = malloc (sizeof(ListaNode));
    novo->tree = noNovo;
    novo->prox = NULL;
    return novo;
}

ArvoreNo *CriaArvoreNo(int freq, byte c, ArvoreNo* esquerda, ArvoreNo* direita){
	ArvoreNo* node = malloc (sizeof(ArvoreNo));
	node->frequencia = freq;
	node->c = c;
	node->esquerda = esquerda;
	node->direita = direita;
	return node;
}

void insereListaA (Lista *l, ListaNode *n){
    if (!l->prim)
		l->prim = n;
	else if ( n->tree->frequencia < l->prim->tree->frequencia ){
		n->prox = l->prim;
		l->prim= n;
	} else {
		ListaNode* aux1 = l->prim->prox;
		ListaNode* aux2 = l->prim;

		while (aux1 && aux1->tree->frequencia <= n->tree->frequencia){
			aux2 = aux1;
			aux1 = aux2->prox;
		}
		aux2->prox = n;
		n->prox = aux1;
	}
	l->insercoes++;
}

ArvoreNo *popMinLista(Lista *l){
    ListaNode *aux = l->prim;
    ArvoreNo *aux2 = aux->tree;
    l->prim = aux->prox;
    free(aux);
    aux = NULL;
    l->insercoes--;
    return aux2;
}

void frequenciaBytes (FILE *arq, unsigned int *arrayBytes){
    byte c;
	while (fread(&c, 1, 1, arq) >= 1)
		arrayBytes[(byte)c]++;
	rewind(arq);
}

bool pegaCodigo(ArvoreNo *n, byte c, char *buffer, int tamanho){


    if (!(n->esquerda || n->direita) && n->c == c){
        buffer[tamanho] = '\0';
        return true;
    }
    
    else{
        
        bool encontrado = false;

        if (n->esquerda){
            buffer[tamanho] = '0';
            encontrado = pegaCodigo(n->esquerda, c, buffer, tamanho + 1);
        }

        if (!encontrado && n->direita){
            buffer[tamanho] = '1';
            encontrado = pegaCodigo(n->direita, c, buffer, tamanho + 1);
        }
        
        if (!encontrado){
            buffer[tamanho] = '\0';
        }
        
        return encontrado;
    }

}

ArvoreNo* criaArvoreHuffman (unsigned* arrayBytes){
	Lista* l = criaListaA();
	for (int i = 0 ; i < 256 ; i++)
		if (arrayBytes[i])
			insereListaA(l, criaListaNoA(CriaArvoreNo(i, arrayBytes[i], NULL, NULL)));
	while (l->insercoes > 1){
		ArvoreNo* esq = popMinLista(l);
		ArvoreNo* dir = popMinLista(l);
		ArvoreNo* sum = CriaArvoreNo('+', esq->frequencia + dir->frequencia, esq, dir);
		insereListaA(l, criaListaNoA(sum));
	}
	return popMinLista(l);
}

void apagaHuffmanTree (ArvoreNo *n){

    if (n==NULL) 
        return;
    else {
        ArvoreNo *esquerda = n->esquerda;
        ArvoreNo *direita = n->direita;
        free(n);
        apagaHuffmanTree(esquerda);
        apagaHuffmanTree(direita);
    }
}

int geraBit(FILE* arq, int posicao, byte* aux){
	(posicao % 8 == 0) ? fread(aux, 1, 1, arq) : NULL == NULL;
	return !!((*aux) & (1 << (posicao % 8)));
}

void compressao(char *arquivoEntrada, char *arquivoSaida){
    FILE *entrada = fopen(arquivoEntrada, "rb");
    FILE *saida = fopen(arquivoSaida, "wb");
    
    time_t inicio, final;
    inicio = time(NULL);
    
    unsigned arrayBytes[256] = {0};
    frequenciaBytes(entrada, arrayBytes);
    ArvoreNo *raiz = criaArvoreHuffman(arrayBytes);
    fwrite(arrayBytes, 256, sizeof(arrayBytes[0]), saida);
    fseek(saida, sizeof(unsigned int), SEEK_CUR);
    byte c;
    unsigned tamanho = 0;
    byte aux = 0;

    while (fread(&c, 1, 1, entrada) >= 1){
        char buffer[1024] = {0};
        pegaCodigo(raiz, c, buffer, 0);
        for (char *i = buffer; *i; i++){
            if (*i == '1')
                aux = aux | (1 << (tamanho % 8));
            
            tamanho++;

            if (tamanho % 8 == 0){
                fwrite(&aux, 1, 1, saida);
                aux = 0;
            }
        }
    }

    fwrite(&aux, 1, 1, saida);
    fseek(saida, 256 * sizeof(unsigned int), SEEK_SET);
    fwrite(&tamanho, 1, sizeof(unsigned), saida);
    fseek(entrada, 0L, SEEK_END);
    double tamanhoEntrada = ftell(entrada);
    fseek(saida, 0L, SEEK_END);
    double tamanhoSaida = ftell(saida);

    apagaHuffmanTree(raiz);
    
    final = time(NULL);
    double tempoGasto = (float) difftime (final, inicio);

    printf("Arquivo de entrada: %s (%g bytes)\nArquivo de saida: %s (%g bytes)\nTempo gasto: %gs\n", arquivoEntrada, tamanhoEntrada / 1000, arquivoSaida, tamanhoSaida / 1000, tempoGasto);
    printf("Taxa de compressao: %d%%\n", (int)((100 * tamanhoSaida) / tamanhoEntrada));

    fclose(entrada);
    fclose(saida);
}

void descompressao(char *arquivoEntrada, char *arquivoSaida){
    FILE *entrada = fopen(arquivoEntrada, "rb");
    FILE *saida = fopen(arquivoSaida, "wb");
    
    time_t inicio, final;

    inicio = time(NULL);

    unsigned listaBytes[256] = {0};

    fread(listaBytes, 256, sizeof(listaBytes[0]), entrada);

    ArvoreNo *raiz = criaArvoreHuffman(listaBytes);

    unsigned tamanho;
    fread(&tamanho, 1, sizeof(tamanho), entrada);

    unsigned posicao = 0;
    byte aux = 0;

    while (posicao < tamanho){
        ArvoreNo *nodeAtual = raiz;
        while (nodeAtual->esquerda || nodeAtual->direita){
            nodeAtual = geraBit(entrada, posicao++, &aux) ? nodeAtual->direita : nodeAtual->esquerda;
        }
        fwrite(&(nodeAtual->c), 1, 1, saida);
    }
    fseek(entrada, 0L, SEEK_END);
    double tamanhoEntrada = ftell(entrada);

    fseek(saida, 0L, SEEK_END);
    double tamanhoSaida = ftell(saida);

    apagaHuffmanTree(raiz);

    final = time(NULL);
    double tempoGasto = (float) difftime(final, inicio);

    printf("Arquivo de entrada: %s (%g bytes)\nArquivo de saida: %s (%g bytes)\nTempo gasto: %gs\n", arquivoEntrada, tamanhoEntrada / 1000, arquivoSaida, tamanhoSaida / 1000, tempoGasto);
    printf("Taxa de descompressao: %d%%\n", (int)((100 * tamanhoSaida) / tamanhoEntrada));

    fclose(saida);
    fclose(entrada);
}
