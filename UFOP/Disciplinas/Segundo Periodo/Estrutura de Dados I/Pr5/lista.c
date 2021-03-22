#include "lista.h"

struct lista{
    ListaNo *prim;
    ListaNo *ultimo;
};

Lista* lst_cria (void){
    Lista *new = malloc (sizeof(Lista));
    new->prim = NULL;
    new->ultimo = NULL;
    return new;
}

void lst_libera (Lista *l){
    ListaNo *p = l->prim;
    while (p != NULL){
        ListaNo *t = getNoProx(p);
        no_libera(p);
        p = t;
    }
    free (l);
}

void lst_insere_inicio (Lista *l, int conteudo){
    ListaNo *novo = no_cria();
    ListaNo *aux  = l->prim;
    setDadoNo (novo, conteudo);
    if (aux == NULL){
        l->prim = novo;
        l->ultimo = novo;
        setNoProx(novo, NULL);
    }
    else{
        l->prim = novo;
        setNoProx (novo, aux);
    }
}

void lst_insere_final (Lista *l, int conteudo){
    ListaNo *novo = no_cria();
    ListaNo *aux  = l->ultimo;
    setDadoNo (novo, conteudo);
    if (l->prim == NULL && l->ultimo == NULL){
        l->prim = novo;
        l->ultimo = novo;
        setNoProx(novo, NULL);
    }
    else{
        setNoProx (novo, aux);
        l->ultimo = novo;
        setNoProx (novo, NULL);
    }
}

int pertence_lista (Lista *l, int valor){
    if (pertence_no(l->prim, valor))
        return 1;
    else
        return 0;
}

int pertence_no (ListaNo* n, int valor){
    if (getDadoNo(n) == valor)
        return 1;
    else{
        if (getNoProx(n) != NULL)
            return pertence_no (getNoProx(n), valor);
        else
            return 0;
    }
}


void remove_lista (Lista *l, int valor){
    remove_no(l->prim, valor);
}

void remove_no (ListaNo *n, int valor){
    ListaNo *temp;
    if (n!=NULL){
        if (getDadoNo(n) == valor){
            temp = n;
            n = getNoProx(n);
            no_libera(temp);
        }
        else
            remove_no(getNoProx(n), valor);
    }
}

int lst_vazia (Lista* l){
    if (l->prim == NULL && l->ultimo == NULL)
        return 1;
    else
        return 0;
}

void lst_imprime (Lista *l){
    no_imprime (l->prim);
}

void no_imprime (ListaNo* n){
    if (n!=NULL){
        printf ("%d\n", getDadoNo(n));
        no_imprime(getNoProx(n));
    }
}

void lst_remove_inicio (Lista *l){
    ListaNo *aux  = l->prim;
    if (aux != NULL){
        l->prim = getNoProx(aux);
        no_libera(aux);
        
    }
    else{
        return;
    }
}
