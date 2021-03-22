
#include "endereco.h"
#include "morador.h"
#include "republica.h"
#include "faxina.h"
#include "funcoes_uteis.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Prototipos de funçoes uteis
void variaveisMorador (char*, char*, char*, int*, char*, char*);
void getsEndereco (Republica *);
void getsMorador (Republica *);
void getsFaxina (Republica *, int);

void setsEndereco (Republica *);
void setsMorador (Republica *);
void setsFaxina (Republica *, int);

int main()
{
  int qtdMax, areaFax, qtdMorador;

  // Pergunta Quantidade Maxima de Moradores e a Quantidade de areas da casa
  printf ("Quantidade maxima de moradores e de áreas da rep\n");
  scanf("%d %d", &qtdMax, &areaFax);

  printf ("Quantidade de moradores\n");
  //Pergunta a quantidade de Moradores
  scanf("%d", &qtdMorador);

  //Cria Endereço
  printf ("End Rep\n");
  char rua[200], complemento[50], bairro[100], cidade[200], estado[200], pais[200];
  int numero;
  long int cep;

  getchar();
  printf ("Rua ");
  fgets( rua, 200, stdin );
  rua[strlen(rua) - 1] = '\0';
  printf ("nro ");
  scanf("%d", &numero);
  getchar();
  printf ("complemento ");
  fgets( complemento, 50, stdin );
  complemento[strlen(complemento) - 1] = '\0';
  printf ("bairro ");
  fgets( bairro, 100, stdin );
  bairro[strlen(bairro) - 1] = '\0';
  printf ("cep ");
  scanf("%ld", &cep);
  getchar();
  printf ("cidade ");
  fgets( cidade, 200, stdin );
  cidade[strlen(cidade) - 1] = '\0';
  printf ("estado\n");
  fgets( estado, 200, stdin );
  estado[strlen(estado) - 1] = '\0';
  printf ("pais ");
  fgets( pais, 200, stdin );
  pais[strlen(pais) - 1] = '\0';

  Endereco* end = criarEndereco (rua, numero, bairro, complemento, cidade, estado, pais, cep);

  // Cria Moradores
  printf ("dados morador\n");
  char nomeM[102], apelidoM[22], cidadeM[32], cursoM[52], dataIngresso[12];
  int idadeM;

  Morador** mrd = malloc ( qtdMorador * sizeof(Morador*));
  getchar();
  for( int i = 0; i < qtdMorador; i++ ) {
    printf ("nomeM ");
    fgets( nomeM, 102, stdin );
    nomeM[strlen(nomeM) - 1] = '\0';
    printf ("apelido ");
    fgets( apelidoM, 22, stdin );
    apelidoM[strlen(apelidoM) - 1] = '\0';
    printf ("cidadeM ");
    fgets( cidadeM, 32, stdin );
    cidadeM[strlen(cidadeM) - 1] = '\0';
    printf ("idade ");
    scanf("%d", &idadeM);
    getchar();
    printf ("curso ");
    fgets( cursoM, 52, stdin );
    cursoM[strlen(cursoM) - 1] = '\0';
    printf ("dataI ");
    fgets( dataIngresso, 12, stdin );
    dataIngresso[strlen(dataIngresso) - 1] = '\0';

    Morador* morador = criarMorador( nomeM, apelidoM, cidadeM, idadeM, cursoM, dataIngresso );
    setMorador( mrd, morador, i );
    getchar();
  }

  // Cria as Faxinas e Designa a cada Morador
  printf ("dados faxina\n");
  srand(time(NULL));
  char areaF[32];
  int selecionado = rand() % qtdMorador, qtdArea;
  printf ("qtdArea ");
  scanf ("%d", &qtdArea);
  getchar();
  Faxina** fxn = malloc ( qtdArea * sizeof(Faxina*));
  for( int i = 0; i < qtdArea; i++ ) {
    printf ("area ");
    fgets( areaF, 32, stdin );
    areaF[strlen(areaF) - 1] = '\0';

    Faxina* faxina = criarFaxina( areaF, getMorador( mrd, rotacaoFaxina( &selecionado, qtdMorador )));
    setFaxina( fxn, faxina, i );
  }
  getchar();
  // Cria a Republica
  printf ("dados rep\n");
  char nomeR[200], criaData[12];
  printf ("nomeRep ");
  fgets( nomeR, 200, stdin );
  nomeR[strlen(nomeR) - 1] = '\0';
  printf ("dataC ");
  fgets( criaData, 12, stdin );
  criaData[strlen(criaData) - 1] = '\0';
  
  Morador** cpy = malloc ( qtdMorador * sizeof(Morador*));
    for ( int i = 0; i < qtdMorador; i++ )
        setMorador(cpy, getMorador(mrd, i), i );


  Morador **organizado = organizaMorador (mrd, cpy, qtdMorador);

  Republica* rep = criaRepublica ( organizado, nomeR, end, criaData, qtdMorador, qtdMax, fxn );
  
  
  // Menu
  getc(stdin);
  
  int opcao, selecao, idade;
  printf ("op\n");
  do {
    menuPrincipal();
    getc(stdin);
    scanf("%d", &opcao);
    printf ("%d\n", opcao);
    // Opçoes disponiveis no Menu
    switch( opcao ) {
      // Adicionar
      case 1:
        variaveisMorador( nomeM, apelidoM, cidadeM, &idade, cursoM, dataIngresso );
        Morador* novoMorador = criarMorador( nomeM, apelidoM, cidadeM, idade, cursoM, dataIngresso );
        if (adicionarMorador(rep, novoMorador) == 1)
          printf ("Morador adicionado com sucesso\n");
        else
          printf ("Republica cheia\n");
        
        break;

      // Get
      case 2:
        menuTAD();
        scanf("%d", &selecao);

        // Seleciona qual TAD mostrar
        switch( selecao ) {
          // Endereco
          case 1:
            getsEndereco (rep);
            break;

          // Morador
          case 2:
            getsMorador (rep);
            break;

          // Faxina
          case 3:
            getsFaxina (rep, qtdArea);
            break;

          default:
            printf("Opcao Invalida!!");
        }
        break;

      // Set
      case 3:
        menuTAD();
        scanf("%d", &selecao);
        // Seleciona qual TAD alterar
        switch( selecao ) {
          // Endereco
          case 1:
            setsEndereco(rep);
            break;

          // Morador
          case 2:
            setsMorador(rep);
            break;

          // Faxina
          case 3:
            setsFaxina(rep, qtdArea);
            break;
          default:
            printf("Opcao Invalida!!");
        }
        break;

      
      // Sair geral
      case 4:
        system ("clear");
        printf ("Obrigado por usar\n");
        break;

      default:
        printf("Opcao invalida!!\n");
    }
  } while ( opcao != 4 );

  return 0;
}

// Implementação de funçoes uteis

void getsEndereco ( Republica* end ) {
  int opcao;
  menuEndereco();
  scanf("%d", &opcao);
  switch ( opcao ) {
    // Rua
    case 1:
      printf("%s\n", getEndRua(getRepEndereco(end)));
      break;

    // Numero
    case 2:
      printf("%d\n", getEndNumero(getRepEndereco(end)));
      break;

    // Complemento
    case 3:
      printf("%s\n", getEndComplemento(getRepEndereco(end)));
      break;

    // Bairro
    case 4:
      printf("%s\n", getEndBairro(getRepEndereco(end)));
      break;

    // Cep
    case 5:
      printf("%ld\n", getEndCep(getRepEndereco(end)));
      break;

    // Cidade
    case 6:
      printf("%s\n", getEndCidade(getRepEndereco(end)));
      break;

    // Estado
    case 7:
      printf("%s\n", getEndEstado(getRepEndereco(end)));
      break;

    // Pais
    case 8:
      printf("%s\n", getEndPais(getRepEndereco(end)));
      break;

    default:
      printf("Opcao Invalida!!\n");
  }
}

void getsMorador (Republica *mrd){
    printf ("Qual o apelido do morador a ser mostrado\n");
    menuMorador();
    char nome[102];
    fgets (nome, 102, stdin);
    nome[strlen(nome)-1] = '\0';
    int retorno;

    Morador *buscado = buscaMoradorApelido(mrd, nome, &retorno);
    if (buscado == NULL){
        printf ("Morador não encontrado\n");
        return;
    }
    int op;
    scanf ("%d", &op);

    switch (op){
    case 1:{
        printf ("Nome: %s\n", getMoradorNome(buscado));
        break;
    }
    case 2:{
        printf ("Apelido: %s\n", getMoradorApelido(buscado));
        break;
    }
    case 3:{
        printf ("Idade: %d\n", getMoradorIdade(buscado));
        break;
    }
    case 4:{
        printf ("Data de Ingresso: %s\n", getMoradorData(buscado));
        break;
    }

    case 5:{
        printf ("Curso: %s\n", getMoradorCurso(buscado));
        break;
    }
    case 6:{
        printf ("Cidade: %s\n", getMoradorCidade(buscado));
        break;
    }
    
    default:
        printf ("Opção Inválida!!!\n");
        break;
    }
}
void getsFaxina (Republica *rep, int qtdArea){
    printf ("Digite a area a ser buscada\n");
    char area[32];
    fgets (area, 32, stdin);
    area[strlen(area)-1] = '\0';
    int retorno;
    Faxina *buscado = buscaFaxinaArea(rep, area, qtdArea, &retorno);
    if (buscado == NULL){
        printf ("Area não encontrada\n");
        return;
    }
    printf ("1 - Morador designado\n");
    printf ("2 - Area\n");
    printf ("3 - Situação\n");
    int op;
    scanf ("%d", &op);

    switch (op){
    case 1:{
        printf ("Apelido do morador: %s\n", getMoradorApelido(getFaxinaMorador(buscado)));
        break;
    }
    case 2:{
        printf ("Area: %s\n", getFaxinaArea(buscado));
        break;
    }
    case 3:{
        int situacao = getFaxinaSituacao(buscado);
        if (situacao)
          printf ("Área Limpa\n");
        else
          printf ("Área Suja\n");
        break;
    }
    default:
        printf ("Opção Inválida!!!\n");
        break;
    }
}

void setsEndereco (Republica *rep){
  menuEndereco();
  int opcao;
  scanf("%d", &opcao);
  char rua[200], complemento[50], bairro[100], cidade[200], estado[200], pais[200];
  int numero;
  long int cep;

  switch ( opcao ) {
    // Rua
    case 1:{
      fgets (rua, 200, stdin);
      rua[strlen(rua)-1] = '\0';
      setEndRua(getRepEndereco(rep), rua);
      break;
    }

    // Numero
    case 2:
      scanf ("%d", &numero);
      setEndNumero(getRepEndereco(rep), numero);
      break;

    // Complemento
    case 3:
      fgets (complemento, 50, stdin);
      complemento[strlen(complemento)-1] = '\0';
      setEndComplemento(getRepEndereco(rep), complemento);
      break;

    // Bairro
    case 4:
      fgets (bairro, 100, stdin);
      bairro[strlen(bairro)-1] = '\0';
      setEndBairro(getRepEndereco(rep), bairro);
      break;

    // Cep
    case 5:
      scanf ("%ld", &cep);
      setEndCep(getRepEndereco(rep), cep);
      break;

    // Cidade
    case 6:
      fgets (cidade, 200, stdin);
      cidade[strlen(cidade)-1] = '\0';
      setEndCidade(getRepEndereco(rep), cidade);
      break;

    // Estado
    case 7:
      fgets (estado, 200, stdin);
      estado[strlen(estado)-1] = '\0';
      setEndEstado(getRepEndereco(rep), estado);
      break;

    // Pais
    case 8:
      fgets (pais, 200, stdin);
      pais[strlen(pais)-1] = '\0';
      setEndPais(getRepEndereco(rep), pais);
      break;

    default:
      printf("Opcao Invalida!!\n");
  }
}

void setsMorador (Republica *rep){
  printf ("Qual o apelido do morador a ser atualizado\n");
  
  char apelido[22];
  char cidade[32];
  int idade;
  char curso[52];
  char dataIngresso[12];
  char nome[102];

  int indice;

  fgets (apelido, 102, stdin);
  apelido[strlen(apelido)-1] = '\0';
  Morador *buscado = buscaMoradorApelido(rep, apelido, &indice);
  if (buscado == NULL){
    printf ("Morador não encontrado\n");
    return;
  }
  menuMorador();
  int op;
  scanf ("%d", &op);

  switch (op){
    //Nome
    case 1:{
        fgets (nome, 102, stdin);
        nome[strlen(nome)-1] = '\0';
        setMoradorNome(getRepMorador(rep, indice), nome);
        break;
    }
    //Apelido
    case 2:{
        fgets (apelido, 22, stdin);
        apelido[strlen(apelido)-1] = '\0';
        setMoradorApelido(getRepMorador(rep, indice), apelido);
        break;
    }
    //Idade
    case 3:{
        scanf ("%d", &idade);
        setMoradorIdade(getRepMorador(rep, indice), idade);
        break;
    }
    //Data de Ingresso
    case 4:{
        fgets (dataIngresso, 12, stdin);
        dataIngresso[strlen(dataIngresso)-1] = '\0';
        setMoradorData(getRepMorador(rep, indice), dataIngresso);
        break;
    }
    //Curso
    case 5:{
        fgets (curso, 52, stdin);
        curso[strlen(curso)-1] = '\0';
        setMoradorCurso(getRepMorador(rep, indice), curso);
        break;
    }
    //Cidade
    case 6:{
        fgets (cidade, 32, stdin);
        cidade[strlen(cidade)-1] = '\0';
        setMoradorCidade(getRepMorador(rep, indice), cidade);
        break;
    }
    
    default:
        printf ("Opção Inválida!!!\n");
        break;
  }
}

void setsFaxina (Republica *rep, int qtdArea){
    printf ("Digite a area a ser atualizada\n");
    char area[32];
    fgets (area, 32, stdin);
    area[strlen(area)-1] = '\0';
    
    
    int indice;
    Faxina *buscado = buscaFaxinaArea(rep, area, qtdArea, &indice);
    if (buscado == NULL){
        printf ("Area não encontrada\n");
        return;
    }
    printf ("1 - Nome da área\n");
    printf ("2 - Situação da área\n");
    int op;
    scanf ("%d", &op);

    switch (op){
    case 1:{
        fgets (area, 32, stdin);
        area[strlen(area)-1] = '\0';
        setFaxinaArea(getRepFaxina(rep, indice), area);
        break;
    }
    case 2:{
        int situacao;
        printf ("1 - Área Limpa\n");
        printf ("0 - Área Suja\n");
        scanf ("%d", &situacao);
        setFaxinaSituacao(getRepFaxina(rep, indice), situacao);
        break;
    }
    default:
        printf ("Opção Inválida!!!\n");
        break;
    }
}