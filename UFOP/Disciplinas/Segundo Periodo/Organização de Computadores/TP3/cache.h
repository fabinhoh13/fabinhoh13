#ifndef CACHE_H
#define CACHE_H

#include "bloco.h"

typedef struct cache Cache;

Cache* criaCache( int );
Cache* criaCache2( int );
void liberaCache( Cache* );
void liberaCache2( Cache* );
Bloco* getCacheBloco( Cache*, int );
void setCacheBloco( Cache*, Bloco*, int );
void setCacheBloco1( Cache*, Bloco*, int );
int getCacheTamanho( Cache* );
void setCacheTamanho( Cache*, int );
int getCacheHit( Cache* );
void setCacheHit( Cache* );
int getCacheMiss( Cache* );
void setCacheMiss( Cache* );
void printaCaches( Cache*, Cache*, Cache*, Cache* );
void setCacheBlocoNull( Cache* );

#endif