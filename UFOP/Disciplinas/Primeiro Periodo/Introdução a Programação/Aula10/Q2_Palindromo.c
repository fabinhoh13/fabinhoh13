//Fabio Henrique Alves Fernandes
//19.1.4128
//Turma 64

#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    setlocale (LC_ALL,"");
	char palavra[16];
	//declaro uma string contendo a palavra "FIM" para fazer a comparação
	char fim[] = "FIM";

	char inverso[16];

	//laço de repetição para que possamos digitar diversas palavras
	do{
	    //entrada da palavra a ser comparada
        printf ("Digite uma palavra ou FIM para sair: ");
		gets(palavra);

		//garantir interrução para caso for digitada a palavra "FIM"
		if (strcmp(palavra, fim) == 0)
            break;

        //funções que usei para pegar o inverso da string
		strcpy(inverso, palavra);
		strrev(inverso);

		//comparação entre a string digitada e seu inverso
        if (strcmp(palavra, inverso)==0)
            printf ("%s é um palindromo\n", palavra);
        else
            printf ("%s não é um palindromo\n", palavra);

	}while (strcmp(palavra, fim) != 0);

	return 0;
}
