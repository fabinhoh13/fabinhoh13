// Aluno:F�bio Henrique Alves Fernandes
// Matr�cula: 19.1.4128

#include <stdio.h>

void main (){
    double nota, media, maior = 0.0, menor = 11.0, soma = 0.0; int cont = 0;

    do{
        printf ("DIGITE UMA NOTA(ou uma nota negativa para sair): ");
        scanf ("%lf", &nota);
        if (nota < 0)
            break;
        if (nota > maior)
            maior = nota;
        if (nota < menor)
            menor = nota;
        soma += nota;
        cont++;
         }while (nota > 0.0);
    media = soma / cont;
    printf ("\nA MEDIA DAS %d NOTAS �: %.2lf\n", cont, media);
    printf ("A MAIOR NOTA �: %.2lf\n", maior);
    printf ("A MENOR NOTA �: %.2lf\n", menor);
}
