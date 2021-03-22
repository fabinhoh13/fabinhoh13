// Aluno:Fábio Henrique Alves Fernandes
// Matrícula: 19.1.4128

#include <stdio.h>

void main (){
    int contneg = 0, contpos = 0;
    double num;

    do{
        printf ("DIGITE UM NUMERO REAL (PARAR = 0): ");
        scanf ("%lf", &num);
        if (num > 0)
            contpos++;
        if (num < 0)
            contneg++;
         }while (num != 0);

    printf ("\nQUANTIDADE DE POSITIVOS DIGITADOS: %d\n", contpos);
    printf ("QUANTIDADE DE NEGATIVOS DIGITADOS: %d\n", contneg);
}
