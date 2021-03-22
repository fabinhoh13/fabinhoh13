#ifndef TIPOITEM_H
#define TIPOITEM_H

#include <stdio.h>

typedef struct tipoItem TipoItem;

TipoItem** criaListItens(int);
TipoItem* getListItens(TipoItem**, int);
void setDadosExtras(TipoItem**, int);
void setListItens(TipoItem**, TipoItem*, int);
void setListItensPeloIndice(TipoItem**, int, int);
void liberaListItens(TipoItem**, int);

TipoItem* criaItem();
int getItemChave(TipoItem*);
void setItemChave(TipoItem*, int);
void setItensAB (TipoItem **, TipoItem *);
void setItemAB (TipoItem **itens, int index, TipoItem *item);
void liberaItem(TipoItem*);

int readItem(FILE*, TipoItem*);
void readItens(FILE*, TipoItem**, int);
void writeItem(FILE*, TipoItem**, int);
void seekItem(FILE*, int, int);
unsigned long sizeofItem();

void shuffle(TipoItem**, int);

#endif