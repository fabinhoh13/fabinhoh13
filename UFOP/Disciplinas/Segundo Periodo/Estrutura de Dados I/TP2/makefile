all: pilha.o Times.o fila.o main.c
	gcc -o main main.c pilha.o Times.o fila.o -Wall

pilha.o: pilha.c
	gcc -o pilha.o -c pilha.c

Times.o: Times.c
	gcc -o Times.o -c Times.c

fila.o: fila.c
	gcc -o fila.o -c fila.c

clean:
	rm -f *.o main

run:
	./main < input.txt >output.txt
