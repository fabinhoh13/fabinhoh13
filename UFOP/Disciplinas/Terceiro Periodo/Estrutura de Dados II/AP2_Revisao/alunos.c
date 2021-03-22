#include <stdio.h>
#include <stdlib.h>

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

    FILE *entrada = fopen("alunos.txt", "r");
    FILE *saida = fopen ("alunos.bin", "wb");

    while (fscanf (entrada, "%d %[a-z A-Z] %lf %lf %lf %d %[\n]", &alu.mat, alu.nome, &alu.nota1, &alu.nota2, &alu.nota3, &alu.faltas)!= EOF){
        fwrite(&alu, sizeof(Alunos), 1, saida);
        
    }

    fclose (entrada);
    fclose (saida);
    
}