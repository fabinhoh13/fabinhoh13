#include <stdio.h>
#include <stdlib.h>


int main (){
    char mat[10];
    char nome[101];
    int faltas;
    double nota1, nota2, nota3;
    double media = 0.0;

    FILE *alunos = fopen ("alunos.txt", "r");
    FILE *conceitos = fopen ("conceitos.txt", "w");

    if (alunos == NULL && conceitos == NULL){
        printf ("Arquivos não abertos\n");
        exit(1);
    }
    
    while (fscanf (alunos, "%[0-9] %[a-z A-Z] %lf %lf %lf %d %[\n]", mat, nome, &nota1, &nota2, &nota3, &faltas)!= EOF){
        media = (nota1 + nota2 + nota3) / 3.0;
        if (faltas > 18)
            fprintf (conceitos, "%s %s F\n", mat, nome);
        else if (media < 6.0)
            fprintf (conceitos, "%s %s R\n", mat, nome);
        else if (media < 7.5)
            fprintf (conceitos, "%s %s C\n", mat, nome);
        else if (media < 9.0)
            fprintf (conceitos, "%s %s B\n", mat, nome);
        else
            fprintf (conceitos, "%s %s A\n", mat, nome);
    }

    fclose(alunos);
    fclose(conceitos);
    return (0);
}