#include <stdio.h>

int main (){
        int num, i, aux = 1;

        scanf ("%d", &num);

        for (i = 1; i <=num; i++){
                aux *=i;


        }
        printf ("%d\n", aux);
        return 0;
}