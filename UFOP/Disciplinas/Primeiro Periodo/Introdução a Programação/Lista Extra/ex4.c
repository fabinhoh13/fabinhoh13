// Aluno:Fábio Henrique Alves Fernandes
// Matrícula: 19.1.4128

#include <stdio.h>


void main (){
	int fator = 1, x;
	printf ("DIGITE O VALOR DE N: ");
	scanf ("%d", &x);
	for (int i = x; i > 0; i--){
		fator = fator * i;
    }
    printf ("%d! = %d", x, fator);
}
