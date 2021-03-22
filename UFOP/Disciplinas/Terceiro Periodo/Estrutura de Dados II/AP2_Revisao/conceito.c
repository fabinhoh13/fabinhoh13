#include <stdlib.h>
#include <stdio.h>


typedef struct alunos{
    int faltas;
    char nome[101];
    int mat;
    double nota1;
    double nota2;
    double nota3;
}Alunos;


int main (){
    Alunos alu;
    double media = 0.0;
    FILE *alunos = fopen ("alunos.bin", "rb");
    FILE *conceitos = fopen ("conceitos.txt", "w");

    if (alunos == NULL && conceitos == NULL){
        printf ("Arquivos não abertos\n");
        exit(1);
    }
    
    while (fread(&alu, sizeof(Alunos), 1, alunos) == 1){
        media = (alu.nota1 + alu.nota2 + alu.nota3) / 3.0;
        if (alu.faltas > 18)
            fprintf (conceitos, "%d %s F\n", alu.mat, alu.nome);
        else if (media < 6.0)
            fprintf (conceitos, "%d %s R\n", alu.mat, alu.nome);
        else if (media < 7.5)
            fprintf (conceitos, "%d %s C\n", alu.mat, alu.nome);
        else if (media < 9.0)
            fprintf (conceitos, "%d %s B\n", alu.mat, alu.nome);
        else
            fprintf (conceitos, "%d %s A\n", alu.mat, alu.nome);
    }

    fclose (alunos);
    fclose (conceitos);
}