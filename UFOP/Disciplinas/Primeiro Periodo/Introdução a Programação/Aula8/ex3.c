//Aluno: Fábio Henrique Alves Fernandes
//Matricula: 19.1.4128


#include <stdio.h>

int main (){
	int x, y;
	do {
		printf ("Digite os valores de x e y: ");
		scanf ("%d %d", &x, &y);
		 if (x > y){
		 	printf ("Erro: x deve ser menor que y.\n\n");
		 	}
		 else if (x % 2 != 0 || y % 2 != 0){
		 	printf ("Apenas números pares são aceitos.\n\n");
		 	}
		 else {
		 	printf ("\n\n");
			for (int i = 0; i < ((y-x)/2+1); i++){
		
				 for (int j = 0; j < ((y - x)/2 - i); j++){
				 	printf (" ");
				 	}
				 for (int j = 0; j < (x + (i*2)); j++){
				 	printf ("*");
				 	}
			 printf ("\n");
			}
		}
		continue;
	}while (x > y && x % 2 != 0 && y % 2 != 0);
	return 0;
}

