#include "../.h/ArvoreBinaria.h"

struct no{
    TipoItem *valor;
    Node *direita;
    Node *esquerda;
};

// funções de balanceamento da arvore


int Altura(Node* pRaiz) {
    int Esq,Dir;
    if (pRaiz == NULL) return 0;
    Esq = Altura(pRaiz-> esquerda);
    Dir = Altura(pRaiz-> direita);
    if ( Esq > Dir ){
        return Esq + 1;
    }
    else {
        return Dir + 1;
    }
}

int FB (Node* pRaiz) {
    if (pRaiz == NULL)
    return 0;
    return Altura(pRaiz-> esquerda) - Altura(pRaiz-> direita);
}

void RSE(Node** ppRaiz) {
    Node *pAux;
    pAux = (*ppRaiz)->direita;
    (*ppRaiz)->direita = pAux->esquerda;
    pAux-> esquerda = (*ppRaiz);
    (*ppRaiz) = pAux;
}

void RSD (Node** ppRaiz) {
    Node *pAux;
    pAux = (*ppRaiz)->esquerda;
    (*ppRaiz)->esquerda = pAux->direita;
    pAux->direita = (*ppRaiz);
    (*ppRaiz) = pAux;
}

int BalancaEsquerda(Node** ppRaiz) {
    int fbe =  FB ( (*ppRaiz)->esquerda );
    if ( fbe >  0 ){
        RSD(ppRaiz);
        return 1;
    } else if (fbe <  0 ) {  //Rotação Dupla a Direita 
        RSE( &((*ppRaiz)->esquerda) );
        RSD( ppRaiz ); 
        return 1;
    }
    
    return 0;
}

int BalancaDireita(Node** ppRaiz) {

    int fbd = FB((*ppRaiz)->direita);
    if (fbd < 0) {
        RSE (ppRaiz);
        return 1;
    } else if (fbd > 0 ) { //Rotação Dupla a Esquerda
        RSD (&((*ppRaiz)->direita) );
        RSE(ppRaiz); 
        return 1;
    }
    return 0;
}

int Balanceamento(Node** ppRaiz){
    int fb = FB(*ppRaiz);
    if (fb >  1)
        return BalancaEsquerda(ppRaiz);
    else if(fb < -1)
        return BalancaDireita(ppRaiz);
    else 
        return 0;
}

int criaArvore(Node **r, TipoItem *arq, Estatistica *a){
    //Essa função insere os elementos de forma recursiva
    if (*r == NULL){ //Caso base
        *r = (Node*) malloc(sizeof(Node)); //Aloca memória para a estrutura
       (*r)->valor = criaItem(); // Aloco minha estrutura TipoItem
        setItemChave((*r)->valor, getItemChave(arq));//Guardo a estrutura dentro do nó
        (*r)->esquerda = NULL; // Subárvore à esquerda é NULL
        (*r)->direita = NULL; // Subárvore à direita é NULL
        incrementaComparacoesP(a);
        return 1;
    }
    
    else if ( getItemChave((*r)->valor) > getItemChave(arq)){ //Se o número for menor então vai pra esquerda
        if (criaArvore(&(*r)->esquerda, arq, a)){ //Percorre pela subárvore à esquerda
            incrementaComparacoesP(a);
            if (Balanceamento(r)){ //Faço o balanceamento da árvore
                return 0;
            }
            else{
                return 1;
            }
        }
    }
    else if (getItemChave((*r)->valor) < getItemChave(arq)){  //Se o número for maior então vai pra direita
        if (criaArvore(&(*r)->direita, arq, a)){ //Percorre pela subárvore à direita
            incrementaComparacoesP(a);
            if (Balanceamento(r)){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            return 0;
        }
    }
    else{
        return 0; // valor ja presente na arvore
    }
}

Node* buscaArvoreBinaria(int chave, Node* a, Estatistica *b){
    if(a == NULL || getItemChave(a->valor) == chave){
        return a;//caso base da minha recursão
    }
    if (chave > getItemChave(a->valor)){
        incrementaComparacoesP(b);
        return buscaArvoreBinaria(chave, a->direita, b);
    }//pesquisa do lado direito
    else{
        incrementaComparacoesP(b);
        return buscaArvoreBinaria(chave, a->esquerda, b);
    }//pesquisa do lado esquerdo
}


void apagarArvoreBinaria(Node *a){
    if(a->direita != NULL){
        apagarArvoreBinaria(a->direita);//apago os itens do lado direito do nó atual
    }
    if(a->esquerda != NULL){
        apagarArvoreBinaria(a->esquerda);//apago os itens do lado esquerdo do nó atual
    }
    free(a);
    return;
}

void TPArvBin(FILE *arq, int buscado){
    Estatistica *a = criaEst();
    Node *arv = NULL;
    TipoItem *aux = criaItem();
    rewind (arq);
    int num;
    clock_t t = clock();
    while(!feof(arq)){
        readItem(arq, aux);
        num = criaArvore (&arv, aux, a);
            
    }
    t = clock() - t;
    setTempoP (a, (((double)t)/((CLOCKS_PER_SEC/1000))));
    printf ("numero de comparações %d\ntempo de execução %.5lfs\n", getComparacoesP(a), getTempoP(a));
    Estatistica *b = criaEst();
    t = clock();
    Node *busca = buscaArvoreBinaria (buscado, arv, b);
    t = clock() - t;
    setTempoP (b, (((double)t)/((CLOCKS_PER_SEC/1000))));
    printf ("numero de comparações na busca %d\ntempo de execução da busca %.5lfs\n", getComparacoesP(b), getTempoP(b));
    if (busca == NULL){
        printf ("n achei\n");
        return;
    }else{
        printf ("achei %d\n", buscado);
    }
}

