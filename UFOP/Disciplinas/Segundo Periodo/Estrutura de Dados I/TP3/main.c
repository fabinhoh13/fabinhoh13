#include "Huffman.h"
#include "hash.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ques1();
void ques2();

void main(){
    int op;
    scanf ("%d", &op);
    switch(op){
        case 1:{
            ques1();
            break;
        }
        case 2:{
            ques2();
            break;
        }
    }
}

void ques1(){
    char entrada[256], saida[256];
    printf ("Compressão\n");
    scanf ("%s", entrada);
    scanf ("%s", saida);
    compressao (entrada, saida);
    printf ("Descompressão\n");    
    scanf ("%s", entrada);
    scanf ("%s", saida);
    descompressao (entrada, saida);
}
void ques2(){
    THash* hash = criaHash( 26 );
    char palavra[31];
    
    FILE* arq = fopen( "3_porquinhos.txt", "rt" );
    
    while( feof( arq ) == 0 ) {
        fscanf( arq, "%s", palavra );

        for( int i = 0; i < strlen(palavra); i++ ) {
            if( (int)palavra[i] > 64  &&  (int)palavra[i] < 91 )
			    palavra[i] += 32;
        }

		if( (int)palavra[strlen( palavra ) - 1] < 97  ||  (int)palavra[strlen( palavra ) - 1] > 122 )
			palavra[strlen( palavra ) - 1] = '\0';

        if( (int)palavra[0] > 96  &&  (int)palavra[0] < 123 ) {
            if( !procuraHash(hash, palavra) ) {
                Palavra* word = criaPalavra( palavra );
                insereHash( hash, word );
            }
        }
    }

    fclose(arq);

    char c = 'A';
    
    for( int i = 0; i < 26; i++ ) {
        printf("Letra %c:\n", c);

        if( !printaHash(hash, i) )
            printf("Nao ha palavras com a letra %c\n", c);
        c += 1;
    }

    deletaHash( hash, 26 );
}