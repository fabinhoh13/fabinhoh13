// Aluno:Fábio Henrique Alves Fernandes
// Matrícula: 19.1.4128

#include <stdio.h>
#include <math.h>

void main (){
    double x, xq = 0;
    int n;
    printf ("DIGITE O VALOR DE N: ");
    scanf ("%d", &n);

    for (int i = 1; i <= n; i++){
        printf ("DIGITE O VALOR DE X%d: ", i);
        scanf ("%lf", &x);
        xq += pow (x, 2);
    }


    printf ("\nMEDIA QUADRATICA: %.0lf\n", sqrt(xq/n));

}

