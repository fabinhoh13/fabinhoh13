#include "funcao.h"




int calculaFuncao (int x, int y){
	if ((x >= 0) && (y >= 0))
		return x + y;
	else if ((x >= 0) && (y < 0))
		return x + (y * y);
	else if ((x < 0) && (y >= 0))
		return (x * x) + y;
	else
		return (x * x) + (y * y);
}	
