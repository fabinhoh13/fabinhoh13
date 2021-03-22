#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    FILE* arqE;
    FILE* arqS;

    char matricula[5];
    char nome[31];
    float nota_1, nota_2, nota_3, media;
    int faltas;
    char conceito, enter;

    // if (argc != 3){
    //     printf("Minimo de arquivos nao especificados!\n");
    //     exit(1);
    // }

    if ((arqE = fopen("alunos.txt", "r")) == NULL){
        printf("Nao foi possivel abrir o arquivo de entrada!\n");
        exit(1);
    }

    if ((arqS = fopen("conceitos.txt", "w+")) == NULL){
        printf("Nao foi possivel abrir o arquivo de saida!\n");
        exit(1);
    }

    // fscanf(arqE,"%s", matricula);
    // printf("%s\n", matricula);
    while (fscanf(arqE,"%[0-9] %[A-Z a-z] %f %f %f %d %[\n]", matricula, nome, &nota_1, &nota_2, &nota_3, &faltas, &enter) != EOF){

        printf("%s", matricula);

        media = (nota_1 + nota_2 + nota_3) / 3;

        if (faltas > 18){
            conceito = 'F';
        }
        else{
            if (media < 6){
                conceito = 'R';
            }
            else if (media >= 6 && media < 7.5){
               conceito = 'C'; 
            }
            else if (media >= 7.5 && media < 9){
               conceito = 'B'; 
            }
            else if (media >= 9 && media < 10){
               conceito = 'A'; 
            }
            else{conceito = 'N';}
        }

        fprintf(arqS, "%s %s %c\n", matricula, nome, conceito);

    }

    fclose(arqE);
    fclose(arqS);

    return 0;

}