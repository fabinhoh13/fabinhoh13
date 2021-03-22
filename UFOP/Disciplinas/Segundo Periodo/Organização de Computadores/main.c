#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void montarMemoriaRAM();
void montarMemoriaPrograma();
void maquina();
void multiplicacao(int multiplicando, int multiplicador);
int potencia (int base, int expo, int *RAM);

int RAM[1000];
int memoriaInstrucoes[1000][4];


int main(){
	srand(time(NULL));

	montarMemoriaRAM();
	montarMemoriaPrograma();
	
	maquina();

	int a, b;
	//printf("\n=== Multiplica��o ===\n");
	printf("Digite um multiplicando e um multiplicador: ");
	scanf("%d %d", &a, &b);
	
    multiplicacao(a, b);
	maquina();
	printf("Resultado: %d\n",RAM[1]);

	return 0;
}

void montarMemoriaRAM(){

	for(int i = 0 ; i < 100 ; i++){
		RAM[i] = (rand() % 101);
	}
}

void montarMemoriaPrograma(){


	for(int i=0 ; i<999 ; i++){
		memoriaInstrucoes[i][0] = rand() % 2;
		memoriaInstrucoes[i][1] = rand() % 100;
		memoriaInstrucoes[i][2] = rand() % 100;
		memoriaInstrucoes[i][3] = rand() % 100;
	}
		
	//Halt
	memoriaInstrucoes[999][0] = -1;
	memoriaInstrucoes[999][1] = -1;
	memoriaInstrucoes[999][2] = -1;
	memoriaInstrucoes[999][3] = -1;
}


void maquina(){
	//0 => opcode => Somar
	//1 => opcode => Subtrair
	//2 => opcode => Levar um valor para um endereço da RAM ("Salvar")
	//-1 => Halt

	
	int pc = 0;
	int opcode = -2;
	int end,end1,end2,end3;
	int conteudoRam1,conteudoRam2,valor;
	int resultado=0;

	while(opcode!=-1){ //Enquanto n�o for Halt...
		opcode = memoriaInstrucoes[pc][0];

		switch(opcode){
			case 0: //Somar
				end1 = memoriaInstrucoes[pc][1];
				end2 = memoriaInstrucoes[pc][2];
				end3 = memoriaInstrucoes[pc][3];

				//Buscando os dados na RAM
				conteudoRam1 = RAM[end1];
				conteudoRam2 = RAM[end2];

				//Salvando o resultado na RAM
				resultado = conteudoRam1 + conteudoRam2;
				RAM[end3] = resultado;
				
				printf("Somando: %d\n",resultado);
				break;
			
			case 1: //Subtrair
				end1 = memoriaInstrucoes[pc][1];
				end2 = memoriaInstrucoes[pc][2];
				end3 = memoriaInstrucoes[pc][3];

				//Buscando os dados na RAM
				conteudoRam1 = RAM[end1];
				conteudoRam2 = RAM[end2];
				
				//Salvando o resultado na RAM
				resultado = conteudoRam1 - conteudoRam2;
				RAM[end3] = resultado;
					
				printf("Subtraindo: %d\n",resultado);
				break;

			case 2: //Levando o valor "memoriaInstrucoes[pc][1]" para a RAM no endere�o "memoriaInstrucoes[pc][2]"
				valor = memoriaInstrucoes[pc][1];
				end = memoriaInstrucoes[pc][2];
				RAM[end] = valor;
				break;
		}
			
		pc++;
	}	
}

//Fun��o que cria as instru��es para uma multiplica��o
void multiplicacao(int multiplicando, int multiplicador){
    int** memoriaInstrucoes = malloc((multiplicador+3) * sizeof(int*));
	for(int i=0;i<(multiplicador+3);i++){
		memoriaInstrucoes[i] = malloc(4 * sizeof(int));
	}

	memoriaInstrucoes[0][0] = 2;
	memoriaInstrucoes[0][1] = multiplicando;
	memoriaInstrucoes[0][2] = 0;
	memoriaInstrucoes[0][3] = -1;

	memoriaInstrucoes[1][0] = 2;
	memoriaInstrucoes[1][1] = 0;
	memoriaInstrucoes[1][2] = 1;
	memoriaInstrucoes[1][3] = -1;
		
	for(int i=0; i<multiplicador;i++){
		memoriaInstrucoes[i+2][0] = 0;
		memoriaInstrucoes[i+2][1] = 0;
		memoriaInstrucoes[i+2][2] = 1;
		memoriaInstrucoes[i+2][3] = 1;
	}
		
	memoriaInstrucoes[multiplicador+2][0] = -1;
	memoriaInstrucoes[multiplicador+2][0] = -1;
	memoriaInstrucoes[multiplicador+2][0] = -1;
	memoriaInstrucoes[multiplicador+2][0] = -1;

}

int potencia (int base, int expo, int *RAM){
    int resultado = 0;
    for (int i = 0; i < expo; i++){
        //maquina(RAM, multiplicacao(base, base));
        resultado += RAM[1];
    }
    return resultado;
}