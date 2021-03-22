//Aluno: Fábio Henrique Alves Fernandes
//Matricula: 19.1.4128


#include <stdio.h>
#include <locale.h>

int ehPrimo (int n);

int main (){
	int n;
	printf ("Digite um número: ");
	scanf ("%d", &n);
	if (ehPrimo(n))
		printf ("%d é um número primo!\n", n);
	else 
		printf ("%d NÃO é um número primo!\n", n);
	return 0;
}

int ehPrimo (int n){
	int resultado = 0;
	for (int i = 1; i <= n; i++){
		if (n % i == 0) 
			resultado++;
	}
	
	if (resultado == 2)
		return 1;
	else
		return 0;
}
	
