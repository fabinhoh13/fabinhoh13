void comandos(char **jogo, int linha, int coluna, int *nL, int *nC, int maiorL, int maiorC, int **cabecalhoL, int **cabecalhoC);
void menu();
void mudaNonograma(char **jogo, char a, char b, int l, int c, char oper);
void imprimeNonograma(char **jogo, int l, int c, int *nL, int *nC, int maiorL, int maiorC, int **cabecalhoL, int **cabecalhoC);
int verifica (char **pronto, int l, int c, int *nL, int *nC, int **cL, int **cC);
int salvaEstado (char local[], char **jogo, int **cL, int **cC, int *nL, int *nC, int l, int c);
void resolver(char **jogo, int l, int c, int *nL, int *nC, int **cL, int **cC);