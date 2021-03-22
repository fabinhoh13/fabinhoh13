#include "republica.h"

struct republica{
    Morador **vMoradores;
    char nomeRep[200];
    Endereco *endRep;
    char dataCria[12];
    int quantMorador;
    int quantMax;
    Faxina **fax;
};

Republica *criaRepublica (Morador **moradores, char *nome, Endereco *end, char *dataRep, int numeroMoradores, int quantMax, Faxina **fax){
    Republica *rep = malloc (sizeof(Republica));
    rep->vMoradores = malloc (quantMax * sizeof(Morador*));
    strcpy (rep->nomeRep, nome);
    for (int i = 0; i < numeroMoradores; i++){
        rep->vMoradores[i] = moradores[i];
    }
    rep->endRep = end;
    rep->quantMorador = numeroMoradores;
    rep->quantMax = quantMax;
    strcpy (rep->dataCria, dataRep);
    rep->fax = fax;
    return rep;
}

void excluirRepublica (Republica *rep, int qtdFxn){
    excluirMorador(rep->vMoradores, rep->quantMax);
    excluirFaxina(rep->fax, qtdFxn);
    excluirEndereco (rep->endRep);
    free(rep);
}

void setRepNome (Republica *rep, char* nomeRep){
    strcpy (rep->nomeRep, nomeRep);
}

char *getRepNome (Republica *rep){
    return rep->nomeRep;
}
void setRepData (Republica *rep, char* dataRep){
    strcpy (rep->dataCria, dataRep);
}

char *getRepData (Republica *rep){
    return rep->dataCria;
}
void setRepQuantidade (Republica *rep, int quant){
    rep->quantMorador = quant;
}

int getRepQuantidade (Republica *rep){
    return rep->quantMorador;
}

Morador *getRepMorador (Republica *rep, int indice){
    return getMorador (rep->vMoradores, indice);
}
void setRepMorador (Republica *rep, Morador *mrd, int indice){
    setMorador (rep->vMoradores, mrd, indice);
}

Endereco *getRepEndereco (Republica *rep){
    return rep->endRep;
}

void setRepEndereco (Republica *rep, Endereco *end){
    rep->endRep = end;
}

Faxina *getRepFaxina (Republica *rep, int indice){
    return getFaxina(rep->fax, indice);
}

void setRepFaxina (Republica *rep, Faxina *fax, int indice){
    setFaxina (rep->fax, fax, indice);
}

int adicionarMorador ( Republica* rep, Morador* mrd ) {
  if ( rep->quantMax != rep->quantMorador ) {
    setMorador( rep->vMoradores, mrd, rep->quantMorador );
    rep->quantMorador += 1;
    return 1;
  }

  else
    return 0;
    //printf("Quantidade de Moradores Maxima atingida!\n");
}


// Fazer Função de Excluir Morador da republica por busca binaria

int excluirMoradorRep_Nome (Republica *rep, char *nome){
  int quantidade = getRepQuantidade(rep);
  char **nomes = malloc (quantidade * sizeof (char*));
  for (int i = 0; i < quantidade; i++){
      nomes[i] = malloc (102 * sizeof (char));
      strcpy(nomes[i], getMoradorNome(getMorador(rep->vMoradores, i)));
  }
  int indice = busca_nome(nome, nomes, 0, quantidade-1);
  
  for (int i = 0; i < quantidade; i++)
    free (nomes[i]);
  free (nomes);

  if (indice >=0){
    rep->vMoradores[indice] = NULL;
    return 1;
  }
  else
    return 0;
}

Morador *buscaMorador (Republica *rep, char *nome){
  int quantidade = getRepQuantidade(rep);
  char **nomes = malloc (quantidade * sizeof (char*));
  for (int i = 0; i < quantidade; i++){
      nomes[i] = malloc (102 * sizeof (char));
      strcpy(nomes[i], getMoradorNome(getMorador(rep->vMoradores, i)));
  }
  int indice = busca_nome(nome, nomes, 0, quantidade-1);
  
  for (int i = 0; i < quantidade; i++)
    free (nomes[i]);
  free (nomes);

  if (indice >=0){
    return getMorador(rep->vMoradores, indice);
  }
  else
    return NULL;
}

Morador *buscaMoradorApelido (Republica *rep, char *nome, int *retorno){
  int quantidade = getRepQuantidade(rep);
  char **nomes = malloc (quantidade * sizeof (char*));
  for (int i = 0; i < quantidade; i++){
      nomes[i] = malloc (102 * sizeof (char));
      strcpy(nomes[i], getMoradorApelido(getMorador(rep->vMoradores, i)));
  }
  int indice = busca_nome(nome, nomes, 0, quantidade-1);
  
  for (int i = 0; i < quantidade; i++)
    free (nomes[i]);
  free (nomes);

  if (indice >=0){
    *retorno = indice;
    return getMorador(rep->vMoradores, indice);
  }
  else
    return NULL;
}

Faxina *buscaFaxinaArea (Republica *rep, char *area, int qntArea, int *retorno){
  char **areas = malloc (qntArea * sizeof (char*));
  for (int i = 0; i < qntArea; i++){
      areas[i] = malloc (32 * sizeof (char));
      strcpy(areas[i], getFaxinaArea(getFaxina(rep->fax, i)));
  }
  int indice = busca_nome(area, areas, 0, qntArea-1);
  
  for (int i = 0; i < qntArea; i++)
    free (areas[i]);
  free (areas);

  if (indice >=0){
    return getFaxina(rep->fax, indice);
  }
  else
    return NULL;
}