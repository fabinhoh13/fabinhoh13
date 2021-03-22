#include <stdlib.h>
#include <stdio.h>
#include <string.h>


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

    int mat;

    FILE *entrada = fopen("alunos.bin", "rb");
    FILE *saida = fopen ("temp.bin", "wb");

    fseek (entrada, 0, SEEK_SET);

    printf ("Digite a matricula a ser excluida fisicamente: ");
    scanf ("%d", &mat);

    

    while (fread (&alu, sizeof (Alunos), 1, entrada)){
        printf ("Aluno %d\n", alu.mat);
        if (mat != alu.mat)
            fwrite (&alu, sizeof(Alunos), 1, saida);
        else
            printf ("Not Found 404\n");
    }

    fclose(entrada);
    fclose(saida);

    remove("alunos.bin");
    rename("temp.bin", "alunos.bin");

}