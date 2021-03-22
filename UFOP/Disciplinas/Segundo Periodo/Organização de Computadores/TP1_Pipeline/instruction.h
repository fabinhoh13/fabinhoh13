typedef struct instrucoes Instrucoes;

Instrucoes *criarInstrucao (int, int, int, int);
int getOpCode (Instrucoes*);
int getEnd1 (Instrucoes *);
int getEnd2 (Instrucoes *);
int getEnd3 (Instrucoes *);
Instrucoes *getInst (Instrucoes **, int);
void apagarInst (Instrucoes *);