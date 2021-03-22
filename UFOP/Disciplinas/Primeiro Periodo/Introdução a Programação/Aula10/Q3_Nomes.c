//Fabio Henrique Alves Fernandes
//19.1.4128
//Turma 64

#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){
    setlocale (LC_ALL,"");
	char nome[70];
	char pedaco[70];
	int cont = 0, tamanho, j=0;
	printf ("Digite o nome completo: ");
	gets(nome);
	tamanho = strlen (nome);
	//laço que pega da string a ultima palavra
	for (int i = 0; nome[i] != '\0'; i++){
        pedaco[cont] = nome[i];
        if (pedaco[cont] == ' '){
            cont = 0;
            j++; //contador que conta o numero de espaços
        }
        else
            cont++;
	}
	pedaco[cont] = ','; //adiciona a virgula depois da ultima palavra da string
	pedaco[cont + 1] = ' '; //adiciona um espaço após a virgula
	pedaco[cont + 2] = '\0'; //adiciona o indicativo de final da string
	nome[tamanho-cont] = '\0'; //corta a string principal até onde estava o ultimo nome
	strcat(pedaco, nome); //concatena as duas strings criadas
	printf ("\n");
	puts (pedaco);
	printf ("Total de letras: %d\n", tamanho-j);
	printf ("Total de letras do último sobrenome: %d\n", cont);

	return 0;
}
