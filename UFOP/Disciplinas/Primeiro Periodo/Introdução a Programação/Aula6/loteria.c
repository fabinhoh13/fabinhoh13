#include "loteria.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void leNumeros (int *num1, int *num2, int *num3){
	int a, b, c;
	scanf ("%d", &a);
	scanf ("%d", &b);
	scanf ("%d", &c);
	*num1 = a;
	*num2 = b;
	*num3 = c;
}

void sorteiaNum (int *nro1, int *nro2, int *nro3){
	srand(time(NULL));
	*nro1 = (rand() % 30) + 1;
	*nro2 = (rand() % 30) + 1;
	*nro3 = (rand() % 30) + 1;
}


void valorPremio (int num1, int num2, int num3, int rand1, int rand2, int rand3, int *total){
	*total = 0;
	
	if (num1 == rand1 || num1 == rand2 || num1 == rand3)
		*total = *total + 1;
	if (num2 == rand1 || num2 == rand2 || num2 == rand3)
		*total = *total + 1;
	if (num3 == rand1 || num3 == rand2 || num3 == rand3)
		*total = *total + 1;
}

void escreve (int total){
	if (total == 0)
		printf ("Voce não levou nada, sinto muito\n");
	if (total == 1)
		printf ("Voce levou R$1,00\n");
	if (total == 2)
		printf ("Voce levou R$1.000,0\n");
	if (total == 3)
		printf ("Voce levou R$100.000,0\n");
}
