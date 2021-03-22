#include "lista.h"
#include "listaNo.h"

#include <stdlib.h>
#include <stdio.h>

int main (){
    Lista *l = lst_cria();
    lst_insere_inicio(l, 1);
    lst_insere_final(l, 2);
    if (pertence_lista(l, 2))
        printf ("3 pertence a lista\n");
    else
        printf ("não pertence\n");
    lst_imprime (l);
    lst_libera(l);
    return 0;
    
}