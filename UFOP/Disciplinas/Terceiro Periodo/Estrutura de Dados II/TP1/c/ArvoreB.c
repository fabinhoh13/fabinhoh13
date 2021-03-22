#include "../.h/ArvoreB.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct TipoRegistro {
    TipoChave Chave;
    long dado1;
    char dado2[500];
} TipoRegistro;


typedef struct TipoPaginas {
    short n;
    TipoRegistro r[MM];
    TipoApontador p[MM + 1];
} TipoPaginas;


void Inicializa (TipoApontador Arvore) {
    Arvore = NULL;
}

int Pesquisa (TipoRegistro *x, TipoApontador Ap){
    long i = 1;
    if (Ap == NULL){
        //printf ("Não existe\n");
        return 0;
    }
    while (i < Ap->n && x->Chave > Ap->r[i-1].Chave) i++;

    if (x->Chave == Ap->r[i-1].Chave){
        *x = Ap->r[i-1];
        return 1;
    }

    if (x->Chave < Ap->r[i-1].Chave)
        return Pesquisa (x, Ap->p[i-1]);
    else   
        return Pesquisa (x, Ap->p[i]);
}

void Imprime(TipoApontador arvore){
    int i = 0;
    if (arvore == NULL) 
        return;
    while (i <= arvore->n) {
        Imprime(arvore->p[i]);
        if (i != arvore->n)
        printf ("%d ", arvore->r[i].Chave);
        i++;
    }
    printf ("\n");
}


void InsereNaPagina (TipoApontador Ap, TipoRegistro Reg, TipoApontador ApDir){
    short nAchou;
    int k = Ap->n;
    if (k>0)
        nAchou = 1;
    while (nAchou){
        if (Reg.Chave >= Ap->r[k-1].Chave){
            nAchou = 0;
            break;
        }
        Ap->r[k] = Ap->r[k-1];
        Ap->p[k+1] = Ap->p[k];
        k--;
        if(k < 1)
            nAchou = 0;
    }
    Ap->r[k] = Reg;
    Ap->p[k+1] = ApDir;
    Ap->n++;

}

void Ins (TipoRegistro Reg, TipoApontador Ap, short *Cresceu, TipoRegistro *RegRetorno, TipoApontador *ApRetorno){
    long i = 1;
    long j;

    TipoApontador ApTemp;

    if (Ap == NULL){
        *Cresceu = 1;
        (*RegRetorno) = Reg;
        (*ApRetorno) = NULL;
        return;
    }

    while (i < Ap->n && Reg.Chave > Ap->r[i-1].Chave)
        i++;


    if (Reg.Chave == Ap->r[i-1].Chave){
        //printf ("Ja Existe\n");
        *Cresceu = 0;
        return;
    }

    if (Reg.Chave < Ap->r[i-1].Chave)
        i--;
    
    Ins(Reg, Ap->p[i], Cresceu, RegRetorno, ApRetorno);

    if(!*Cresceu)
        return;
    //pagina tem espaço
    if (Ap->n < MM){
        InsereNaPagina (Ap, *RegRetorno, *ApRetorno);
        *Cresceu = 0;
        return;
    }
    //Página tem que ser dividida
    ApTemp = (TipoApontador)malloc(sizeof(TipoPaginas));
    ApTemp->n = 0;
    ApTemp->p[0] = NULL;

    if (i < M+1){
        InsereNaPagina(ApTemp, Ap->r[MM-1], Ap->p[MM]);
        Ap->n --;
        InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
    }
    else
        InsereNaPagina(ApTemp, *RegRetorno, *ApRetorno);

    for (j = M + 2; j <= MM; j++){
        InsereNaPagina(ApTemp, Ap->r[j-1], Ap->p[j]);
    }

    Ap->n = M;
    ApTemp->p[0] = Ap->p[M+1];
    *RegRetorno = Ap->r[M];
    *ApRetorno = ApTemp;

}

void Insere (TipoRegistro Reg, TipoApontador *Ap){
    short Cresceu;
    TipoRegistro RegRetorno;
    TipoPaginas *ApRetorno, *ApTemp;

    Ins (Reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno);

    if (Cresceu){ //Verifico se a arvore cresceu olhando a altura pela raiz
        ApTemp = (TipoPaginas *) malloc (sizeof(TipoPaginas));
        ApTemp->n = 1;
        ApTemp->r[0] = RegRetorno;
        ApTemp->p[1] = ApRetorno;
        ApTemp->p[0] = *Ap;
        *Ap = ApTemp;
    }
}

void Reconstitui (TipoApontador ApPag, TipoApontador ApPai, int posPai, short *Diminuiu){
    TipoPaginas *Aux;
    long DispAux, j;
    if (posPai < ApPai->n){
        Aux = ApPai->p[posPai+1];
        DispAux = (Aux->n - M + 1) / 2;
        ApPag->r[ApPag->n] = ApPai->r[posPai];
        ApPag->p[ApPag->n + 1] = Aux->p[0];
        ApPag->n++;
        if (DispAux > 0){
            for(j = 1; j < DispAux; j++)
                InsereNaPagina(ApPag, Aux->r[j-1], Aux->p[j]);
            ApPai->r[posPai] = Aux->r[DispAux-1];
            Aux->n -= DispAux;
            for (j = 0; j < Aux->n; j++)
                Aux->r[j] = Aux->r[j+DispAux];
            for(j = 0; j <= Aux->n; j++)
                Aux->p[j] = Aux->p[j+DispAux];
            *Diminuiu = 0;
        }else{
            for(j = 1; j <= M; j++)
                InsereNaPagina (ApPag, Aux->r[j-1], Aux->p[j]);
            
            free(Aux);

            for (j = posPai + 1; j < ApPai->n; j++){
                ApPai->r[j-1] = ApPai->r[j];
                ApPai->p[j] = ApPai->p[j+1];
            }
            ApPai->n--;

            if (ApPai->n >= M)
                *Diminuiu = 0;
        }
    }else{
        Aux = ApPai->p[posPai-1];
        DispAux = (Aux->n - M + 1) / 2;
        for (j = ApPag->n; j >=1; j--)
            ApPag->r[j] = ApPag->r[j-1];
        
        ApPag->r[0] = ApPai->r[posPai-1];
        for (j = ApPag->n; j >= 0; j--)
            ApPag->p[j+1] = ApPag->p[j];
        
        ApPag->n++;

        if(DispAux > 0){
            for (j = 1; j < DispAux; j++)
                InsereNaPagina(ApPag, Aux->r[Aux->n-j], Aux->p[Aux->n - j +1]);
            ApPag->p[0] = Aux->p[Aux->n - DispAux +1];
            ApPai->r[posPai-1] = Aux->r[Aux->n - DispAux];
            Aux->n -= DispAux;
            *Diminuiu = 0;
        }else{
            for(j = 1; j <= M; j++)
                InsereNaPagina (Aux, ApPag->r[j-1], ApPag->p[j]);
            free (ApPag);
            ApPai->n--;
            if(ApPai->n >= M)
                *Diminuiu = 0;
        }
    }
}


void Antecessor (TipoApontador Ap, int Ind, TipoApontador ApPai, short *Diminuiu){
    if (ApPai->p[ApPai->n] != NULL){
        Antecessor (Ap, Ind, ApPai->p[ApPai->n], Diminuiu);
        if(*Diminuiu){
            Reconstitui(ApPai->p[ApPai->n], ApPai, (long)ApPai->n, Diminuiu);
            return;
        }
        Ap->r[Ind-1] = ApPai->r[ApPai->n - 1];
        ApPai->n--;
        if (ApPai->n < M)
            *Diminuiu = 1;
        else
            *Diminuiu = 0;
        
    }
}

void Ret (TipoChave Ch, TipoApontador *Ap, short *Diminuiu){
    long j;
    long Ind = 1;
    TipoApontador Pag;
    if (*Ap == NULL){
        *Diminuiu = 0;
        return;
    }
    Pag = *Ap;
    while(Ind < Pag->n && Ch > Pag->r[Ind-1].Chave)
        Ind++;
    if (Ch == Pag->r[Ind-1].Chave){
        if (Pag->p[Ind-1] == NULL){
            Pag->n--;
            if (Pag->n < M)
                *Diminuiu = 1;
            else
                *Diminuiu = 0;

            for(j = Ind; j <= Pag->n; j++){
                Pag->r[j-1] = Pag->r[j];
                Pag->p[j] = Pag->p[j+1];
            }
            return;
        }
        Antecessor (*Ap, Ind, Pag->p[Ind-1], Diminuiu);
        
        if(*Diminuiu)
            Reconstitui(Pag->p[Ind-1], *Ap, Ind-1, Diminuiu);
        
        return;
        
    }
    if (Ch > Pag->r[Ind-1].Chave)
        Ind++;
    Ret(Ch, &Pag->p[Ind-1], Diminuiu);
    if(*Diminuiu)
        Reconstitui(Pag->p[Ind-1], *Ap, Ind-1, Diminuiu);
}

void Retira (TipoChave Ch, TipoApontador *Ap){
    short Diminuiu;
    TipoApontador Aux;
    Ret(Ch, Ap, &Diminuiu);
    if (Diminuiu && (*Ap)->n == 0){
        Aux = *Ap;
        *Ap = Aux->p[0];
        free (Aux);
    }
}

void ArvBTP (FILE *arq, int buscado){
    rewind (arq);
    TipoApontador arv; 
    Inicializa(arv);

    TipoRegistro *reg = (TipoRegistro*)malloc(sizeof(TipoRegistro));
    while(!feof(arq)){
        fread(reg, sizeof(TipoRegistro), 1, arq);
        Insere(*reg, &arv); 
    }
    TipoRegistro *busca = (TipoRegistro*)malloc(sizeof(TipoRegistro));
    busca->Chave = buscado;
    if (Pesquisa (busca, arv))
        printf ("%d foi encontrado\n", busca->Chave);

    
}

