#include <stdlib.h>
#include <stdio.h>
#include "cpu.h"

void CPU( Cache* L1, Cache* L2, Cache* L3, Cache* RAM, Instrucao** inst, int hd ) {
    int indice = 0, pick = getInstrucaoOpcode( getInstrucao( inst, indice ) ), numero = 0, soma = 0;
    
    int** end = malloc( 3 * sizeof(int*));
    for( int i = 0; i < 3; i++ )
        end[i] = malloc( 2 * sizeof(int));

    double* valores = malloc( 2 * sizeof(double));

    FILE* HD = fopen("instrucoes.dat", "rb+");

    clock_t inicio, fim;
    inicio = clock();

    while( pick != -1 ) {
        end[0][0] = getEnderecoBloco( getInstrucaoEnd1( getInstrucao( inst, indice ) ) );
        end[0][1] = getEnderecoPalavra( getInstrucaoEnd1( getInstrucao( inst, indice ) ) );
        end[1][0] = getEnderecoBloco( getInstrucaoEnd2( getInstrucao( inst, indice ) ) );
        end[1][1] = getEnderecoPalavra( getInstrucaoEnd2( getInstrucao( inst, indice ) ) );
        end[2][0] = getEnderecoBloco( getInstrucaoEnd3( getInstrucao( inst, indice ) ) );
        end[2][1] = getEnderecoPalavra( getInstrucaoEnd3( getInstrucao( inst, indice ) ) );

        // printf("%d %d %d\n", end[0][0], end[1][0], end[2][0]);
        valores[0] = MMU( L1, L2, L3, RAM, HD, end[0] );
        organizaCache( L1 );
        organizaCache( L2 );
        organizaCache( L3 );
        organizaCache( RAM );

        valores[1] = MMU( L1, L2, L3, RAM, HD, end[1] );
        organizaCache( L1 );
        organizaCache( L2 );
        organizaCache( L3 );
        organizaCache( RAM );
        
        setMMU( L1, L2, L3, RAM, HD, end[2], ALU( valores, pick ) );
        organizaCache( L1 );
        organizaCache( L2 );
        organizaCache( L3 );
        organizaCache( RAM );
        
        // printaCaches( L1, L2, L3, RAM );

        int interrupcao = rand() % 10;
        
        // 30% de chance de interrupção
        
        if( interrupcao < 3 ) {
            soma += programaInterrupcao( L1, L2, L3, RAM, HD, hd ); 
            numero++;
        }
       
        indice++;
        pick = getInstrucaoOpcode( getInstrucao( inst, indice ) );
    }
    fim = clock();
    printf("L1 Hit: %d \nL2 Hit: %d \nL3 Hit: %d \nRAM Hit: %d \nHD Hit: %d\n", getCacheHit( L1 ), getCacheHit( L2 ), getCacheHit( L3 ), getCacheHit( RAM ), getCacheMiss( RAM ));
    printf("Numero de interrupcoes: %d\n", numero);
    printf("Numero de instrucoes extras: %d\n", soma);
    printf ("Tempo de eecução %lu\n", (fim - inicio) / CLOCKS_PER_SEC);
    
    /*for(int i = 0; i < 3; i++ )
        free(end[i]);
    free(end);
    free(valores);*/
    printf ("Tudo ok\n");
    fclose(HD);
}

double MMU( Cache* L1, Cache* L2, Cache* L3, Cache* RAM, FILE* HD, int* end ) {
    int i = 0;

    // Procurando na cache 1
    while( i < getCacheTamanho( L1 ) ) {
        if( getCacheBloco( L1, i ) == NULL )
            break;

        else if( getBlocoEndereco( getCacheBloco( L1, i ) ) == end[0] ) {
            setBlocoTime( getCacheBloco( L1, i ) );
            setCacheHit( L1 );
            return getBlocoPalavra( getCacheBloco( L1, i ), end[1] );
        } 

        else {
            i++;
            continue;
        }
    }

    setCacheMiss( L1 );
    i = 0;
    // Procurando na cache 2
    while( i < getCacheTamanho( L2 ) ) {
        if( getCacheBloco( L2, i ) == NULL )
            break;
        
        else if( getBlocoEndereco( getCacheBloco( L2, i ) ) == end[0] ) {
            Bloco* aux = getCacheBloco( L1, getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L1, getCacheBloco( L2, i ), getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L2, aux, i );
            setBlocoTime( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ) );
            setCacheHit( L2 );
            return getBlocoPalavra( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ), end[1] );
        } 

        else {
            i++;
            continue;
        }
    }

    setCacheMiss( L2 );
    i = 0;
    // Procurando na cache 3
    while( i < getCacheTamanho( L3 ) ) {
        if( getCacheBloco( L3, i ) == NULL )
            break;

        else if( getBlocoEndereco( getCacheBloco( L3, i ) ) == end[0] ) {
            Bloco* aux = getCacheBloco( L2, getCacheTamanho( L2 ) - 1 );
            setCacheBloco( L2, getCacheBloco( L3, i ), getCacheTamanho( L2 ) - 1 );
            setCacheBloco( L3, aux, i );
            aux = getCacheBloco( L1, getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L1, getCacheBloco( L2, getCacheTamanho( L2 ) - 1), getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L2, aux, getCacheTamanho( L2 ) - 1 );
            setBlocoTime( getCacheBloco( L1, getCacheTamanho( L1 ) - 1) );
            setCacheHit( L3 );
            return getBlocoPalavra( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ), end[1] );
        } 

        else {
            i++;
            continue;
        }
    }

    setCacheMiss( L3 );
    i = 0;

    //Procurando na RAM

    while( i < getCacheTamanho( RAM ) ) {
        if( getCacheBloco( RAM, i ) == NULL )
            break;

        else if( getBlocoEndereco( getCacheBloco( RAM, i ) ) == end[0] ) {
            Bloco* aux = getCacheBloco( L3, getCacheTamanho( L3 ) - 1 );
            setCacheBloco( L3, getCacheBloco( RAM, i ), getCacheTamanho( L3 ) - 1 );
            setCacheBloco( RAM, aux, i );
            //passei da RAM pra L3
            aux = getCacheBloco( L2, getCacheTamanho( L2 ) - 1 );
            setCacheBloco( L2, getCacheBloco( L3, getCacheTamanho( L3 ) - 1 ), getCacheTamanho( L2 ) - 1 );
            setCacheBloco( L3, aux, getCacheTamanho( L3 ) - 1 );
            //passei da L3 pra L2
            aux = getCacheBloco( L1, getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L1, getCacheBloco( L2, getCacheTamanho( L2 ) - 1 ), getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L2, aux, getCacheTamanho( L2 ) - 1 );
            //passei da L2 pra L1
            setBlocoTime( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ) );
            setCacheHit( RAM );
            return getBlocoPalavra( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ), end[1] );
        } 

        else {
            i++;
            continue;
        }
    }

    setCacheMiss( RAM );
    i = 0;
    
    // Ultimo caso indo no HD

    double* palavras = malloc (4 * sizeof (double));

    fseek( HD, 36 * (end[0] - 1), SEEK_SET );
    fread( palavras, sizeof(double), 4, HD );
    
    Bloco* HDBloco = criaBlocoHD( palavras, end[0] );

    for( int j = 0; j < getCacheTamanho( L1 ); j++ ) {
        if( getCacheBloco( L1, j ) == NULL ) {
            Bloco* aux = NULL;
            //Bloco do HD pra RAM
            setCacheBloco( RAM, HDBloco, 0 );
            setCacheBloco( L3, getCacheBloco( RAM, 0 ), 0 );
            setCacheBloco( RAM, aux, 0 );
            //RAM pra L3, L3 pra L2 e L2 pra L1
            setCacheBloco( L2, getCacheBloco( L3, 0 ), 0 );
            setCacheBloco( L3, aux, 0 );
            setCacheBloco( L1, getCacheBloco( L2, 0 ), j );
            setCacheBloco( L2, aux, 0 );
            setBlocoTime( getCacheBloco( L1, j ) );
            return getBlocoPalavra( getCacheBloco( L1, j ), end[1] );
        }
    }
    
    for( int j = 0; j < getCacheTamanho( L2 ); j++ ) {
        if( getCacheBloco( L2, j ) == NULL ) {
            Bloco* aux = NULL;
            //Bloco do HD pra RAM
            setCacheBloco( RAM, HDBloco, 0 );
            setCacheBloco( L3, getCacheBloco( RAM, 0 ), 0 );
            setCacheBloco( RAM, aux, 0 );
            //RAM pra L3, L3 pra L2 e L2 pra L1
            setCacheBloco( L2, getCacheBloco( L3, 0 ), j );
            setCacheBloco( L3, aux, 0 );
            aux = getCacheBloco( L1, getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L1, getCacheBloco( L2, j ), getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L2, aux, j );
            setBlocoTime( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ) );
            return getBlocoPalavra( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ), end[1] );
        }
    }

    

    for( int j = 0; j < getCacheTamanho( L3 ); j++ ) {
        if( getCacheBloco( L3, j ) == NULL ) {
            Bloco* aux = NULL;
            //Bloco do HD pra RAM
            setCacheBloco( RAM, HDBloco, 0 );
            setCacheBloco( L3, getCacheBloco( RAM, 0 ), j );
            setCacheBloco( RAM, aux, 0 );
            //RAM pra L3, L3 pra L2 e L2 pra L1
            aux = getCacheBloco( L2, getCacheTamanho( L2 ) - 1 );
            setCacheBloco( L2, getCacheBloco( L3, j ), getCacheTamanho( L2 ) - 1 );
            setCacheBloco( L3, aux, j );
            aux = getCacheBloco( L1, getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L1, getCacheBloco( L2, getCacheTamanho(L2) - 1), getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L2, aux, getCacheTamanho(L2) - 1 );
            setBlocoTime( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ) );
            return getBlocoPalavra( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ), end[1] );
        }
    }

    for( int j = 0; j < getCacheTamanho( RAM ); j++ ) {
        if( getCacheBloco( RAM, j ) == NULL ) {
            Bloco* aux = getCacheBloco( L3, getCacheTamanho( L3 ) - 1 );
            //Bloco do HD pra RAM
            setCacheBloco( RAM, HDBloco, j );
            setCacheBloco( L3, getCacheBloco( RAM, j ), getCacheTamanho( L3 ) - 1 );
            setCacheBloco( RAM, aux, j );
            //RAM pra L3, L3 pra L2 e L2 pra L1
            aux = getCacheBloco( L2, getCacheTamanho( L2 ) - 1 );
            setCacheBloco( L2, getCacheBloco( L3, getCacheTamanho(L3) - 1 ), getCacheTamanho( L2 ) - 1 );
            setCacheBloco( L3, aux, getCacheTamanho(L3) - 1 );
            aux = getCacheBloco( L1, getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L1, getCacheBloco( L2, getCacheTamanho(L2) - 1 ), getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L2, aux, getCacheTamanho(L2) - 1 );
            setBlocoTime( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ) );
            return getBlocoPalavra( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ), end[1] );
        }
    }

    // Todas as Caches cheias


    Bloco* aux1 = getCacheBloco( RAM, getCacheTamanho( RAM ) - 1 );

    if( getBlocoAtt( aux1 ) == true ){
        fseek( HD, 36 * getBlocoEndereco(aux1), SEEK_SET );
        for (i = 0; i < 4; i++)
            palavras[i] = getBlocoPalavra(aux1, i);

        fwrite (palavras, sizeof(double), 4, HD);
    }

    liberaBloco(aux1);

    setCacheBloco(RAM, HDBloco, getCacheTamanho(RAM) - 1);
    Bloco* aux = getCacheBloco( L3, getCacheTamanho( L3 ) - 1 );
    setCacheBloco( L3, getCacheBloco( RAM, getCacheTamanho(RAM) -1 ), getCacheTamanho( L3 ) - 1 );
    setCacheBloco (RAM, aux, getCacheTamanho (RAM) - 1);
    aux = getCacheBloco( L2, getCacheTamanho( L2 ) - 1 );
    setCacheBloco( L2, getCacheBloco( L3, getCacheTamanho( L3 ) - 1 ), getCacheTamanho( L2 ) - 1 );
    setCacheBloco( L3, aux, getCacheTamanho( L3 ) - 1 );
    aux = getCacheBloco( L1, getCacheTamanho( L1 ) - 1 );
    setCacheBloco( L1, getCacheBloco( L2, getCacheTamanho( L2 ) - 1 ), getCacheTamanho( L1 ) - 1 );
    setCacheBloco( L2, aux, getCacheTamanho( L2 ) - 1 );
    setBlocoTime( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ) );
    return getBlocoPalavra( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ), end[1] );

}

void setMMU( Cache* L1, Cache* L2, Cache* L3, Cache* RAM, FILE *HD, int* end, double valor ) {
    int i = 0;

    // Procurando na cache 1
    while( i < getCacheTamanho( L1 ) ) {
        if( getCacheBloco( L1, i ) == NULL )
            break;

        else if( getBlocoEndereco( getCacheBloco( L1, i ) ) == end[0] ) {
            setBlocoTime( getCacheBloco( L1, i ) );
            setCacheHit( L1 );
            setBlocoAttTrue( getCacheBloco( L1, i ) );
            setBlocoPalavra( getCacheBloco( L1, i ), valor, end[1] );
            return;
        } 

        else {
            i++;
            continue;
        }
    }

    setCacheMiss( L1 );
    i = 0;
    // Procurando na cache 2
    while( i < getCacheTamanho( L2 ) ) {
        if( getCacheBloco( L2, i ) == NULL )
            break;
        
        else if( getBlocoEndereco( getCacheBloco( L2, i ) ) == end[0] ) {
            Bloco* aux = getCacheBloco( L1, getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L1, getCacheBloco( L2, i ), getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L2, aux, i );
            setBlocoTime( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ) );
            setCacheHit( L2 );
            setBlocoAttTrue( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ) );
            setBlocoPalavra( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ), valor, end[1] );
            return;
        } 

        else {
            i++;
            continue;
        }
    }

    setCacheMiss( L2 );
    i = 0;
    // Procurando na cache 3
    while( i < getCacheTamanho( L3 ) ) {
        if( getCacheBloco( L3, i ) == NULL )
            break;

        else if( getBlocoEndereco( getCacheBloco( L3, i ) ) == end[0] ) {
            Bloco* aux = getCacheBloco( L2, getCacheTamanho( L2 ) - 1 );
            setCacheBloco( L2, getCacheBloco( L3, i ), getCacheTamanho( L2 ) - 1 );
            setCacheBloco( L3, aux, i );
            aux = getCacheBloco( L1, getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L1, getCacheBloco( L2, getCacheTamanho( L2 ) - 1), getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L2, aux, getCacheTamanho( L2 ) - 1 );
            setBlocoTime( getCacheBloco( L1, getCacheTamanho( L1 ) - 1) );
            setCacheHit( L3 );
            setBlocoAttTrue( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ) );
            setBlocoPalavra( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ), valor, end[1] );
            return;
        } 

        else {
            i++;
            continue;
        }
    }

    setCacheMiss( L3 );
    i = 0;

    //Procurando na RAM

    while( i < getCacheTamanho( RAM ) ) {
        if( getCacheBloco( RAM, i ) == NULL )
            break;

        else if( getBlocoEndereco( getCacheBloco( RAM, i ) ) == end[0] ) {
            Bloco* aux = getCacheBloco( L3, getCacheTamanho( L3 ) - 1 );
            setCacheBloco( L3, getCacheBloco( RAM, i ), getCacheTamanho( L3 ) - 1 );
            setCacheBloco( RAM, aux, i );
            //passei da RAM pra L3
            aux = getCacheBloco( L2, getCacheTamanho( L2 ) - 1 );
            setCacheBloco( L2, getCacheBloco( L3, getCacheTamanho( L3 ) - 1), getCacheTamanho( L2 ) - 1 );
            setCacheBloco( L3, aux, getCacheTamanho( L3 ) - 1 );
            //passei da L3 pra L2
            aux = getCacheBloco( L1, getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L1, getCacheBloco( L2, getCacheTamanho( L2 ) - 1), getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L2, aux, getCacheTamanho( L2 ) - 1 );
            //passei da L2 pra L1
            setBlocoTime( getCacheBloco( L1, getCacheTamanho( L1 ) - 1) );
            setCacheHit( RAM );
            setBlocoAttTrue( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ) );
            setBlocoPalavra( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ), valor, end[1] );
            return;
        } 

        else {
            i++;
            continue;
        }
    }

    setCacheMiss( RAM );
    i = 0;
    
    // Ultimo caso indo no HD

    double* palavras = malloc (4 * sizeof (double));

    fseek( HD, 36 * (end[0] - 1), SEEK_SET );
    fread( palavras, sizeof(double), 4, HD );
    
    Bloco* HDBloco = criaBlocoHD( palavras, end[0] );

    for( int j = 0; j < getCacheTamanho( L1 ); j++ ) {
        if( getCacheBloco( L1, j ) == NULL ) {
            Bloco* aux = NULL;
            //Bloco do HD pra RAM
            setCacheBloco( RAM, HDBloco, 0 );
            setCacheBloco( L3, getCacheBloco( RAM, 0 ), 0 );
            setCacheBloco( RAM, aux, 0 );
            //RAM pra L3, L3 pra L2 e L2 pra L1
            setCacheBloco( L2, getCacheBloco( L3, 0 ), 0 );
            setCacheBloco( L3, aux, 0 );
            setCacheBloco( L1, getCacheBloco( L2, 0 ), j );
            setCacheBloco( L2, aux, 0 );
            setBlocoTime( getCacheBloco( L1, j ) );
            setBlocoAttTrue( getCacheBloco( L1, j ) );
            setBlocoPalavra( getCacheBloco( L1, j ), valor, end[1] );
            return;
        }
    }
    
    for( int j = 0; j < getCacheTamanho( L2 ); j++ ) {
        if( getCacheBloco( L2, j ) == NULL ) {
            Bloco* aux = NULL;
            //Bloco do HD pra RAM
            setCacheBloco( RAM, HDBloco, 0 );
            setCacheBloco( L3, getCacheBloco( RAM, 0 ), 0 );
            setCacheBloco( RAM, aux, 0 );
            //RAM pra L3, L3 pra L2 e L2 pra L1
            setCacheBloco( L2, getCacheBloco( L3, 0 ), j );
            setCacheBloco( L3, aux, 0 );
            aux = getCacheBloco( L1, getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L1, getCacheBloco( L2, j ), getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L2, aux, j );
            setBlocoTime( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ) );
            setBlocoAttTrue( getCacheBloco( L1, getCacheTamanho(L1) - 1 ) );
            setBlocoPalavra( getCacheBloco( L1, getCacheTamanho(L1) - 1 ), valor, end[1] );
            return;
        }
    }

    

    for( int j = 0; j < getCacheTamanho( L3 ); j++ ) {
        if( getCacheBloco( L3, j ) == NULL ) {
            Bloco* aux = NULL;
            //Bloco do HD pra RAM
            setCacheBloco( RAM, HDBloco, 0 );
            setCacheBloco( L3, getCacheBloco( RAM, 0 ), j );
            setCacheBloco( RAM, aux, 0 );
            //RAM pra L3, L3 pra L2 e L2 pra L1
            aux = getCacheBloco( L2, getCacheTamanho( L2 ) - 1 );
            setCacheBloco( L2, getCacheBloco( L3, j ), getCacheTamanho( L2 ) - 1 );
            setCacheBloco( L3, aux, j );
            aux = getCacheBloco( L1, getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L1, getCacheBloco( L2, getCacheTamanho(L2) - 1), getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L2, aux, getCacheTamanho(L2) - 1 );
            setBlocoTime( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ) );
            setBlocoAttTrue( getCacheBloco( L1, getCacheTamanho(L1) - 1 ) );
            setBlocoPalavra( getCacheBloco( L1, getCacheTamanho(L1) - 1 ), valor, end[1] );
            return;
        }
    }

    for( int j = 0; j < getCacheTamanho( RAM ); j++ ) {
        if( getCacheBloco( RAM, j ) == NULL ) {
            Bloco* aux = getCacheBloco( L3, getCacheTamanho( L3 ) - 1 );
            //Bloco do HD pra RAM
            setCacheBloco( RAM, HDBloco, j );
            setCacheBloco( L3, getCacheBloco( RAM, j ), getCacheTamanho( L3 ) - 1 );
            setCacheBloco( RAM, aux, j );
            //RAM pra L3, L3 pra L2 e L2 pra L1
            aux = getCacheBloco( L2, getCacheTamanho( L2 ) - 1 );
            setCacheBloco( L2, getCacheBloco( L3, getCacheTamanho(L3) - 1 ), getCacheTamanho( L2 ) - 1 );
            setCacheBloco( L3, aux, getCacheTamanho(L3) - 1 );
            aux = getCacheBloco( L1, getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L1, getCacheBloco( L2, getCacheTamanho(L2) - 1 ), getCacheTamanho( L1 ) - 1 );
            setCacheBloco( L2, aux, getCacheTamanho(L2) - 1 );
            setBlocoTime( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ) );
            setBlocoAttTrue( getCacheBloco( L1, getCacheTamanho(L1) - 1 ) );
            setBlocoPalavra( getCacheBloco( L1, getCacheTamanho(L1) - 1 ), valor, end[1] );
            return;
        }
    }

    // Todas as Caches cheias


    Bloco* aux = getCacheBloco( RAM, getCacheTamanho( RAM ) - 1 );

    if (getBlocoAtt(aux) == true){
        fseek (HD, 36 * getBlocoEndereco(aux), SEEK_SET);
        for (i = 0; i < 4; i++){
            palavras[i] = getBlocoPalavra(aux, i);
        }
        fwrite (palavras, sizeof(double), 4, HD);
    }
    liberaBloco(aux);

    setCacheBloco(RAM, HDBloco, getCacheTamanho(RAM) - 1);
    aux = getCacheBloco( L3, getCacheTamanho( L3 ) - 1 );
    setCacheBloco( L3, getCacheBloco( RAM, getCacheTamanho(RAM) -1 ), getCacheTamanho( L3 ) - 1 );
    setCacheBloco (RAM, aux, getCacheTamanho (RAM) - 1);
    aux = getCacheBloco( L2, getCacheTamanho( L2 ) - 1 );
    setCacheBloco( L2, getCacheBloco( L3, getCacheTamanho( L3 ) - 1 ), getCacheTamanho( L2 ) - 1 );
    setCacheBloco( L3, aux, getCacheTamanho( L3 ) - 1 );
    aux = getCacheBloco( L1, getCacheTamanho( L1 ) - 1 );
    setCacheBloco( L1, getCacheBloco( L2, getCacheTamanho( L2 ) - 1 ), getCacheTamanho( L1 ) - 1 );
    setCacheBloco( L2, aux, getCacheTamanho( L2 ) - 1 );
    setBlocoTime( getCacheBloco( L1, getCacheTamanho( L1 ) - 1 ) );
    setBlocoAttTrue( getCacheBloco( L1, getCacheTamanho(L1) - 1 ) );
    setBlocoPalavra( getCacheBloco( L1, getCacheTamanho(L1) - 1 ), valor, end[1] );
    return;

}

double ALU( double* valores, int opcode ) {
    double valor;
    double* aritmeticMemory = malloc( 5 * sizeof(double));
    double** instMemory;
    double* oneInst;
    int decode, i = 0;

    switch ( opcode ) {
        case 1:
            instMemory = programaSoma( valores ); 
            oneInst = loadMachine( instMemory, i );
            decode = decodeMachine( oneInst );
            while( decode != -1 ) {
                executeMachine( oneInst, aritmeticMemory, decode );
                i++;
                oneInst = loadMachine( instMemory, i );
                decode = decodeMachine( oneInst );
            }
            break;
    
        case 2:
            instMemory = programaSubtracao( valores );
            oneInst = loadMachine( instMemory, i );
            decode = decodeMachine( oneInst );
            while( decode != -1 ) {
                executeMachine( oneInst, aritmeticMemory, decode );
                i++;
                oneInst = loadMachine( instMemory, i );
                decode = decodeMachine( oneInst );
            }
            break;
    }

    valor = aritmeticMemory[0];
    free(instMemory);
    free(aritmeticMemory);
    return valor;
}

void organizaCache( Cache* cch ) {
    int confere = 0;
    double* v = malloc( getCacheTamanho(cch) * sizeof(double));

    for( int i = 0; i < getCacheTamanho(cch); i++ ) {
        if( getCacheBloco( cch, i ) == NULL  &&  confere <= 1 )
            return;

        else if( getCacheBloco( cch, i ) == NULL  &&  confere > 1 )
            return;

        else {
            v[i] = getBlocoTime( getCacheBloco( cch, i ) );
            confere++;
        }
    }

    mergeSort( v, 0, confere - 1 );
    Cache* aux = criaCache( getCacheTamanho( cch ) );

    for( int i = 0; i < confere; i++ ) {
        for( int j = 0; j < confere; j++ ) {
            if( v[i] == getBlocoTime( getCacheBloco( cch, j ) ) ) {
                setCacheBloco( aux, getCacheBloco( cch, j ), i );
                break;
            }
        }
    }

    for( int i = 0; i < confere; i++ )
        setCacheBloco( cch, getCacheBloco( aux, i ), i );

    free(v);
}

void mergeSort( double* v, int inicio, int fim ) {
    if ( inicio < fim ) {
        int meio = (fim + inicio) / 2;

        mergeSort( v, inicio, meio );
        mergeSort( v, meio + 1, fim );

        mergeSortIntercala( v, inicio, meio, fim );
    }
}

void mergeSortIntercala( double* v, int inicio, int meio, int fim ) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    double* v1 = malloc( n1 * sizeof(double));
    double* v2 = malloc( n2 * sizeof(double));

    for( int i = 0; i < n1; i++ )
        v1[i] = v[inicio + i];

    for( int i = 0; i < n2; i++ )
        v2[i] = v[meio + 1 + i];

    int i = 0, j = 0, k = inicio;

    while( i < n1  &&  j < n2 ) {
        if( v1[i] >= v2[j] ) {
            v[k] = v1[i];
            i++;
        }

        else {
            v[k] = v2[j];
            j++;
        }
        k++;
    }

    while( i < n1 ) {
        v[k] = v1[i];
        i++;
        k++;
    }

    while( j < n2 ) {
        v[k] = v2[j];
        j++;
        k++;
    }

    free(v1);
    free(v2);
}