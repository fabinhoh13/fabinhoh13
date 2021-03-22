//Fábio Henrique Alves Fernandes
//19.1.4128
//Turma 64

#include <stdio.h>

int main(){
    double prova1[15], prova2[15], media[15];
    printf ("Prova 1\n");
    for (int i = 0; i < 15; i++){
        printf ("Aluno %d: ", i+1);
        scanf ("%lf", &prova1[i]);
    }
    printf ("Prova 2\n");
    for (int i = 0; i < 15; i++){
        printf ("Aluno %d: ", i+1);
        scanf ("%lf", &prova2[i]);
    }
        //Tirar a media
    for (int i = 0; i < 15; i++){
        media[i] = (prova1[i] + prova2[i])/2.0;
        if (media[i] >= 60.0)
            printf ("Aluno %d Aprovado com %.1lf de media\n", i+1, media[i]);
        else
            printf ("Aluno %d Reprovado com %.1lf de media\n", i+1, media[i]);
    }
    return 0;
}



