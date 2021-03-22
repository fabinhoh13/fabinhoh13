#include "loteria.h"

int main (){
	int num1, num2, num3, rand1, rand2, rand3, total;
	leNumeros (&num1, &num2, &num3);
	sorteiaNum (&rand1, &rand2, &rand3);
	valorPremio (num1, num2, num3, rand1, rand2, rand3, &total);
	escreve (total);
	return 0;
}

