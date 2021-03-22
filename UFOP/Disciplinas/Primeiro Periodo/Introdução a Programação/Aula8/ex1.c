//Aluno: Fábio Henrique Alves Fernandes
//Matricula: 19.1.4128


#include <stdio.h>

long long int fat (int n);
int main (){
	int n;
	printf ("Digite o valor de n: ");
	scanf ("%d", &n);
	printf ("%d! = %lld\n", n, fat(n));
	return 0;
}

long long int fat (int n){
	long long int fator = 1;
	for (int i = n; i > 0; i--){
		fator = fator * i;
	}
	return fator;
}
