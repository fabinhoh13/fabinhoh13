#include "endereco.h"

struct endereco {
    char rua[200], complemento[50], bairro[100], cidade[200], estado[200], pais[200];
    int numero;
    long int cep;
};

Endereco *criarEndereco (char *rua, int numero, char* bairro, char* complemento, char* cidade, char* estado, char *pais, long int cep){
    Endereco *end = malloc (sizeof (Endereco));
    end->numero = numero;
    end->cep = cep;
    strcpy (end->rua, rua);
    strcpy (end->bairro, bairro);
    strcpy (end->complemento, complemento);
    strcpy (end->cidade, cidade);
    strcpy (end->estado, estado);
    strcpy (end->pais, pais);
    return end;
}

void excluirEndereco (Endereco *end){
    free (end);
}

char *getEndRua (Endereco *end){
    return end->rua;
}
char *getEndBairro (Endereco *end){
    return end->bairro;
}
char *getEndComplemento (Endereco *end){
    return end->complemento;
}
char *getEndCidade (Endereco *end){
    return end->cidade;
}
char *getEndEstado (Endereco *end){
    return end->estado;
}
char *getEndPais (Endereco *end){
    return end->pais;
}
int getEndNumero (Endereco *end){
    return end->numero;
}
long int getEndCep (Endereco *end){
    return end->cep;
}

void setEndRua (Endereco *end, char *rua){
    strcpy(end->rua, rua);
}
void setEndBairro (Endereco *end, char *bairro){
    strcpy(end->bairro, bairro);
}
void setEndComplemento (Endereco *end, char *complemento){
    strcpy(end->complemento, complemento);
}
void setEndCidade (Endereco *end, char *cidade){
    strcpy(end->cidade, cidade);
}
void setEndEstado (Endereco *end, char *estado){
    strcpy(end->estado, estado);
}
void setEndPais (Endereco *end, char *pais){
    strcpy(end->pais, pais);
}
void setEndNumero (Endereco *end, int numero){
    end->numero = numero;
}
void setEndCep (Endereco *end, long int cep){
    end->cep = cep;
}
