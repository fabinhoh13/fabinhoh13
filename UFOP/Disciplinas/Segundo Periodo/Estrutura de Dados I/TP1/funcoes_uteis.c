#include "funcoes_uteis.h"

void variaveisMorador ( char* nomeM, char* apelidoM, char* cidadeM, int* idadeM, char* cursoM, char* dataIngresso ) {
  fgets( nomeM, 102, stdin );
  nomeM[strlen(nomeM) - 1] = '\0';
  fgets( apelidoM, 22, stdin );
  apelidoM[strlen(apelidoM) - 1] = '\0';
  fgets( cidadeM, 32, stdin );
  cidadeM[strlen(cidadeM) - 1] = '\0';
  scanf("%d", idadeM);
  getchar();
  fgets( cursoM, 52, stdin );
  cursoM[strlen(cursoM) - 1] = '\0';
  fgets( dataIngresso, 12, stdin );
  dataIngresso[strlen(dataIngresso) - 1] = '\0';
}





int busca_nome (char nome[], char **vetorNomes, int esq, int dir){
    if (esq > dir){
        return -1; //não encontrado
    }else{
        if (strcmp(nome, vetorNomes[esq]) == 0){
            return esq;
        }
        else{
            return busca_nome(nome, vetorNomes, esq+1, dir);
        }
    }
}


void menuPrincipal (void){
    printf ("1 - Atualizar um morador\n");
    printf ("2 - Mostrar\n");
    printf ("3 - Atualizar alguma outra coisa\n");
    //printf ("4 - Excluir\n");
}

void menuEndereco (void){
    printf ("1 - Rua\n");
    printf ("2 - Numero\n");
    printf ("3 - Complemento\n");
    printf ("4 - Bairro\n");
    printf ("5 - CEP\n");
    printf ("6 - Cidade\n");
    printf ("7 - Estado\n");
    printf ("8 - Pais\n");
}

void menuMorador (void){
    printf ("1 - Nome\n");
    printf ("2 - Apelido\n");
    printf ("3 - Idade\n");
    printf ("4 - Data de Ingresso\n");
    printf ("5 - Curso\n");
    printf ("6 - Cidade\n");
}

void menuTAD (void){
    printf ("1 - Endereço\n");
    printf ("2 - Morador\n");
    printf ("3 - Faxina\n");
}