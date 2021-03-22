all: BlocoMemoria.o Endereco.o Instrucao.o Cache.o MMU.o Pipeline.o Machine.o main.c
	gcc -o main main.c BlocoMemoria.o Endereco.o Instrucao.o Cache.o MMU.o Pipeline.o Machine.o

BlocoMemoria.o: BlocoMemoria.c
	gcc -o BlocoMemoria.o -c BlocoMemoria.c

Endereco.o: Endereco.c
	gcc -o Endereco.o -c Endereco.c

Instrucao.o: Instrucao.c
	gcc -o Instrucao.o -c Instrucao.c

Cache.o: Cache.c 
	gcc -o Cache.o -c Cache.c

MMU.o: MMU.c 
	gcc -o MMU.o -c MMU.c

Pipeline.o: Pipeline.c
	gcc -o Pipeline.o -c Pipeline.c

Machine.o: Machine.c 
	gcc -o Machine.o -c Machine.c

clean:
	rm -f *.o main

run:
	./main