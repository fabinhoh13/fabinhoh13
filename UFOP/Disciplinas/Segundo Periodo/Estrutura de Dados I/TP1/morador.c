#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "morador.h"

struct morador {
  char nome[102];
  char apelido[22];
  char cidade[32];
  int idade;
  char curso[52];
  char dataIngresso[12];
};

Morador* criarMorador ( char* nome, char* apelido, char* cidade, int idade, char* curso, char* dataIngresso ) {
  Morador* aux = malloc ( sizeof(Morador) );
  strcpy(aux->nome, nome);
  strcpy(aux->apelido, apelido);
  strcpy(aux->cidade, cidade);
  aux->idade = idade;
  strcpy(aux->curso, curso);
  strcpy(aux->dataIngresso, dataIngresso);

  return aux;
}

void atualizarMoradores ( Morador** mdr, Morador** att ) {
  mdr = att;
}

void excluirUmMorador (Morador *mrd){
  free (mrd);
}

void excluirMorador ( Morador** mrd, int qtdMorador ) {
  for ( int i = 0; i < qtdMorador; i++ )
    free(mrd[qtdMorador]);

  free(mrd);
}

Morador* getMorador ( Morador** mrd, int count ) {
	return mrd[count];
}

void setMorador ( Morador** mrd, Morador* mrd1, int count ) {
  mrd[count] = mrd1;
}

char* getMoradorNome ( Morador* mrd ) {
	return mrd->nome;
}

void setMoradorNome ( Morador* mrd, char* nome ) {
	strcpy( mrd->nome, nome );
}

char* getMoradorApelido ( Morador* mrd ) {
	return mrd->apelido;
}

void setMoradorApelido ( Morador* mrd, char* apelido ) {
	strcpy( mrd->apelido, apelido );
}

char* getMoradorCidade ( Morador* mrd ) {
	return mrd->cidade;
}

void setMoradorCidade ( Morador* mrd, char* cidade ) {
	strcpy( mrd->cidade, cidade );
}

int getMoradorIdade ( Morador* mrd ) {
	return mrd->idade;
}

void setMoradorIdade ( Morador* mrd, int idade ) {
	mrd->idade = idade;
}

char* getMoradorCurso ( Morador* mrd ) {
	return mrd->curso;
}

void setMoradorCurso ( Morador* mrd, char* curso ) {
	strcpy( mrd->curso, curso );
}

char* getMoradorData ( Morador* mrd ) {
	return mrd->dataIngresso;
}

void setMoradorData ( Morador* mrd, char* dataIngresso ) {
	strcpy( mrd->dataIngresso, dataIngresso );
}

Morador** organizaMorador ( Morador** mrd, Morador** cpy, int qtdMorador ) {
  int* v = malloc ( qtdMorador * sizeof(int));
  int tamanho, valor;

  for ( int i = 0; i < qtdMorador; i++ ) {
    int count = 0, multi = 1;
    tamanho = strlen( mrd[i]->dataIngresso );
    v[i] = 0;

    for( int j = 0; j < tamanho + 1; j++ ) {
      if ( mrd[i]->dataIngresso[j] == '/'  || tamanho == j ) {
        for ( int k = 0; k < count; k++ ) {
          valor = mrd[i]->dataIngresso[j - k - 1];
          v[i] += valor * multi;
          multi *= 10;
        }
        count = 0;
      }
      
      else
        count++;
    }
  }

  // Copiando vetor
  int* v1 = malloc ( qtdMorador * sizeof(int));
  for ( int i = 0; i < qtdMorador; i++ )
    v1[i] = v[i];

  mergeSort( v, 0, qtdMorador - 1);

  for( int i = 0; i < qtdMorador; i++ ) {
    for ( int j = 0; j < qtdMorador; j++ ) {
      if ( v[i] == v1[j] )
        cpy[i] = mrd[j];
    }
  }

  free(v);
  free(v1);

  return cpy;
}

void mergeSort ( int* v, int inicio, int fim ) {
  if ( inicio < fim ) {
    int meio = ( inicio + fim ) / 2;

    mergeSort(v, inicio, meio);
    mergeSort(v, meio + 1, fim);

    merge(v, inicio, meio, fim);
  }
}

void merge ( int* v, int inicio, int meio, int fim ) {
  int i, j, k;
  int n1 = meio - inicio + 1;
  int n2 = fim - meio;

  int* v1 = malloc ( n1 * sizeof(int));
  int* v2 = malloc ( n2 * sizeof(int));

  for ( i = 0; i < n1; i++ )
    v1[i] = v[inicio + i];

  for ( j = 0; j < n2; j++ )
    v2[j] = v[meio + 1 + j];

  i = 0, j = 0, k = inicio;

  while ( i < n1  &&  j < n2 ) {
    if ( v1[i] <= v2[j] ) {
      v[k] = v1[i];
      i++;
    }

    else {
      v[k] = v2[j];
      j++;
    }
    k++;
  }

  while ( i < n1 ) {
    v[k] = v1[i];
    i++;
    k++;
  }

  while ( j < n2 ) {
    v[k] = v2[j];
    j++;
    k++;
  }

  free(v1);
  free(v2);
}

