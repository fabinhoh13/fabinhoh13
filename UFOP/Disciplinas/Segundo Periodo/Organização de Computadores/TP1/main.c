#include <stdio.h>
#include <stdlib.h>

#include "memory.h"
#include "instruction.h"
#include "oneprogram.h"
#include "machine.h"

#define TAM_MAX 100

int main(){
    Memoria *mem;
    mem = criarRAM (TAM_MAX);
    int num1, num2, opcao;;
    
    do{
        scanf ("%d", &opcao);
        switch (opcao)
        {
        case 1:{
            printf ("\nSOMA\n Digite dois numeros\n");
            scanf ("%d %d", &num1, &num2);
            machine(sumProg(num1, num2, mem), mem);
            break;
        }
        case 2:{
            printf ("\n\nSUBTRAÇÃO\n Digite dois numeros\n\n");
            scanf ("%d %d", &num1, &num2);
            machine(subProg(num1, num2, mem), mem);
            break;
        }
        case 3:{
            printf ("\n\nMULTIPLICAÇÃO\n Digite dois numeros\n");
            scanf ("%d %d", &num1, &num2);
            machine(multProg(num1, num2, mem), mem);
            break;
        }
        case 5:{
            printf ("\nPOTENCIAÇÃO\nDigite a base e o expoente\n");
            scanf ("%d %d", &num1, &num2);
            potProg(num1, num2, mem);
            break;
        }
        case 6:{
            printf ("\nAREA RETANGULO\n Digite dois numeros\n");
            scanf ("%d %d", &num1, &num2);
            areaRetProg(num1, num2, mem);
            printf ("Area Retangulo: %d\n", getMemory(mem, 0));
            break;

        }

        case 4:{
            printf ("\nDIVISÃO\n Digite dois numeros\n");
            scanf ("%d %d", &num1, &num2);
            machine(divProg (num1, num2, mem), mem);
            //printf ("Resultado: %d\n", getMemory(mem, 0));
            break;
        }
        case 7:{
            printf ("ÁREA TRIANGULO\n Digite dois numeros\n");
            scanf ("%d %d", &num1, &num2);
            areaTrian (num1, num2, mem);
            printf ("Resultado: %d", getMemory(mem, 0));
            break;
        }
        
        default:
            //system ("clear");
            printf ("Opção não disponível\n");
            break;
        }
    }while (opcao!=0);

    
    
    
    
    
    
    /*
    printf ("\n\nDIVISÃO\n Digite dois numeros\n");
    scanf ("%d %d", &num1, &num2);
    machine(divProg(num1, num2, mem), mem);
    */
    return 0;
}