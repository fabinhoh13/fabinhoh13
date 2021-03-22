#include "funcao.h"
#include <stdio.h>

int main (){
	int x, y, resultado;
	scanf ("%d", &x);
	scanf ("%d", &y);
	resultado = calculaFuncao (x, y);
	printf ("Valor de x: %d\nValor de y: %d\nValor de f: %d\n", x, y, resultado);
	return 0;
}
