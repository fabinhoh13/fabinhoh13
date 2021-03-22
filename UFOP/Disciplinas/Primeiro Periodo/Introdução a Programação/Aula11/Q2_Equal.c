#include <stdio.h>

typedef struct {
	int numerador;
	int denominador;
	} Racional;
	
int equal (Racional r1, Racional r2);
int mdc (int x, int y);

int main (){
	Racional r1, r2;
	printf ("Digite numerador e denominador de r1: ");
	scanf ("%d %d", &r1.numerador, &r1.denominador);
	printf ("Digite numerador e denominador de r2: ");
	scanf ("%d %d", &r2.numerador, &r2.denominador);
	
	if (equal(r1, r2))
		printf ("r1 e r2 são iguais!\n");
	else
		printf ("r1 e r2 são diferentes!\n");
	return 0;
}

int equal (Racional r1, Racional r2){
	int num1 = r1.numerador/mdc(r1.numerador, r1.denominador);
	int num2 = r2.numerador/mdc(r2.numerador, r2.denominador);
	int dem1 = r1.denominador/mdc(r1.numerador, r1.denominador);
	int dem2 = r2.denominador/mdc(r2.numerador, r2.denominador);
	
	if (num1/dem1 == num2/dem2)
		return 1;
	else
		return 0;
}

int mdc(int x, int y) {
	int resto = x % y;

	while (resto != 0) {
		x = y;
		y = resto;
		resto = x % y;
	}
    
	return y;
}

