#include "aluno.h"
#include "disciplina.h"
#include "atestado.h"

#include <stdlib.h>
#include <stdio.h>

int main(){ 
    int i, j;

    Aluno *alunos;
    Disciplina **dis;
    Atestado **atest;

    char nomeA[201];
    char nomeD[201];
    char cursoA[101]; 
    char cursoD[101];
    char dataA[11];
    char codDis[20];
    int sala, CHD, mat, horas;
    long int CPF;

    int *nroDis; 
    int nroAte;

    int sum=0;


    printf ("Digite o numero de alunos\n");
    scanf ("%d", &nroAte);
    nroDis = malloc (nroAte * sizeof(int));
    atest = malloc (nroAte * sizeof(Atestado*));

    for (j = 0; j < nroAte; j++){
        printf ("Digite o numero de disciplinas\n");
        scanf ("%d", &nroDis[j]);
        getc(stdin);


        printf ("Digite o nome do aluno\n");
        fgets (nomeA, 201, stdin);
        printf ("Digite o curso do aluno\n");
        fgets (cursoA, 101, stdin);
        printf ("Digite a data de ingresso do aluno\n");
        fgets (dataA, 11, stdin);
        printf ("Digite o CPF do aluno\n");
        scanf ("%ld", &CPF);
        printf ("Digite a matricula do aluno\n");
        scanf ("%d", &mat);

        alunos = criarAluno(nomeA, CPF, mat, cursoA, dataA);
        
        
        dis = malloc(nroDis[j] * sizeof(Disciplina*));
        for (i = 0; i < nroDis[j]; i++){
            getc(stdin);
            printf ("Digite o nome da %da disciplina\n", i+1);
            fgets (nomeD, 201, stdin);
            printf ("Digite o curso da %da disciplina\n", i+1);
            fgets (cursoD, 101, stdin);
            printf ("Digite o código da %da disciplina\n", i+1);
            fgets (codDis, 20, stdin);
            printf ("Digite a carga horária da %da disciplina\n", i+1);
            scanf ("%d", &CHD);
            if (CHD > 4)
            {
                printf ("Carga Horária excede o limite, tente novamente\n\n");
                i--;
                continue;
            }
            sum+=CHD;
            printf ("Digite a sala da %da disciplina\n", i+1);
            scanf ("%d", &sala);
            dis[i] = criarD(nomeD, codDis, CHD, cursoD, sala);
            if (sum > 16){
                printf ("Soma da carga horária excede o limite, tente novamente\n\n");
                i=0;
            }
        }

        atest[j] = criarAtestado (dis, alunos);
    }
    char op;
    int mudanca;
    getc (stdin);
    printf ("Deseja fazer alguma alteração?\n");
    scanf ("%c", &op);
    while (op=='s' || op=='S'){
        getc(stdin);
        printf ("Qual a alteração desejada?\n\n");
        printf ("Alunos:\n");
        printf ("1)Nome do Aluno\n2)Curso\n3)CPF\n4)Matricula\n5)Data de Ingresso\n\n");
        printf ("Disciplina:\n");
        printf ("6)Nome da Disciplina\n7)Curso\n8)Codigo da Disciplina\n9)Carga Horária\n10)Sala\n\n");
        printf ("Leitura\n");
        printf ("11)Aluno\n12)Disciplina\n\n");
        scanf ("%d", &mudanca);
        int pos;
        int pos1;
        switch (mudanca){
            case 1:{
                printf ("Qual a posição do aluno a ser modificado?");
                scanf ("%d", &pos);
                printf ("Digite o nome:");
                fgets (nomeA, 201, stdin);
                atualizarNomeAluno(lerAtestadoA(atest[pos]), nomeA);
                break;
            }
            case 2:{
                printf ("Qual a posição do aluno a ser modificado?");
                scanf ("%d", &pos);
                printf ("Digite o curso:");
                fgets (cursoA, 101, stdin);
                atualizarCursoAluno(lerAtestadoA(atest[pos]), cursoA);
                break;
            }
            case 3:{
                printf ("Qual a posição do aluno a ser modificado?");
                scanf ("%d", &pos);
                printf ("Digite o CPF:");
                scanf ("%ld", &CPF);
                atualizarCpfAluno(lerAtestadoA(atest[pos]), CPF);
                break;
            }
            case 4:{
                printf ("Qual a posição do aluno a ser modificado?");
                scanf ("%d", &pos);
                printf ("Digite a matricula:");
                scanf ("%d", &mat);
                atualizarMatriculaAluno(lerAtestadoA(atest[pos]), mat);
                break;
            }
            case 5:{
                printf ("Qual a posição do aluno a ser modificado?");
                scanf ("%d", &pos);
                printf ("Digite a data de ingresso:");
                fgets (dataA, 11, stdin);
                atualizarDataAluno(lerAtestadoA(atest[pos]), dataA);
                break;
            }
            case 6:{
                printf ("Qual a posição do aluno a ser modificado?");
                scanf ("%d", &pos);
                printf ("Qual a posição da disciplina a ser modificada?");
                scanf ("%d", &pos1);
                printf ("Digite o nome:");
                fgets (nomeD, 201, stdin);
                atualizarNomeD(lerAtestadoD(atest[pos], pos1), nomeA);

                break;
            }
            case 7:{
                printf ("Qual a posição do aluno a ser modificado?");
                scanf ("%d", &pos);
                printf ("Qual a posição da disciplina a ser modificada?");
                scanf ("%d", &pos1);
                printf ("Digite o curso:");
                fgets (cursoD, 101, stdin);
                atualizarCursoD(lerAtestadoD(atest[pos], pos1), cursoD);
                break;
            }
            case 8:{
                printf ("Qual a posição do aluno a ser modificado?");
                scanf ("%d", &pos);
                printf ("Qual a posição da disciplina a ser modificada?");
                scanf ("%d", &pos1);
                printf ("Digite o codigo da disciplina:");
                fgets (codDis, 20, stdin);
                atualizarCodD(lerAtestadoD(atest[pos], pos1), codDis);
                break;
            }
            case 9:{
                printf ("Qual a posição do aluno a ser modificado?");
                scanf ("%d", &pos);
                printf ("Qual a posição da disciplina a ser modificada?");
                scanf ("%d", &pos1);
                printf ("Digite a carga horária:");
                scanf ("%d", &CHD);
                atualizarCHD(lerAtestadoD(atest[pos], pos1), CHD);
                break;
            }
            case 10:{
                printf ("Qual a posição do aluno a ser modificado?");
                scanf ("%d", &pos);
                printf ("Qual a posição da disciplina a ser modificada?");
                scanf ("%d", &pos1);
                printf ("Digite a sala:");
                scanf ("%d", &sala);
                atualizarSalaD(lerAtestadoD(atest[pos], pos1), sala);
                break;
            }
            case 11:{
                printf ("Qual a posição do aluno a ser lido?");
                scanf ("%d", &pos);
                printf ("Aluno: %s\n", lerAlunoNome(lerAtestadoA(atest[pos])));
                printf ("CPF: %ld\n", lerAlunoCPF(lerAtestadoA(atest[pos])));
                printf ("Curso: %s\n", lerAlunoCurso(lerAtestadoA(atest[pos])));
                printf ("Matricula: %d\n", lerAlunoMat(lerAtestadoA(atest[pos])));
                printf ("Data de Ingresso: %s\n", lerAlunoDI(lerAtestadoA(atest[pos])));
                break;
            }
            case 12:{
                printf ("Qual a posição do aluno a ser lido?");
                scanf ("%d", &pos);
                printf ("Qual a posição da disciplina a ser modificada?");
                scanf ("%d", &pos1);
                printf ("Disciplina: %s\n", lerDNome(lerAtestadoD(atest[pos], pos1)));
                printf ("Curso: %s\n", lerDCurso(lerAtestadoD(atest[pos], pos1)));
                printf ("Codigo da Disciplina: %s\n", lerDCod(lerAtestadoD(atest[pos], pos1)));
                printf ("Carga Horaria: %d\n", lerDCH(lerAtestadoD(atest[pos], pos1)));
                printf ("Sala: %d\n", lerDSala(lerAtestadoD(atest[pos], pos1)));
                break;
            }
            
            default:
                break;
        }
        printf ("Deseja fazer alguma outra alteração?\n");
        scanf ("%c", &op);
    }





    for (j = 0; j < nroAte; j++)
        removerAtestado (atest[j], nroDis[j]);
        
    return 0;
}