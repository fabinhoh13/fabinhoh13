all:  listaNo.o lista.o main.c
	gcc -o main main.c listaNo.o lista.o -Wall
listaNo.o: listaNo.c
	gcc -o listaNo.o -c listaNo.c

lista.o: lista.c
	gcc -o lista.o -c lista.c

clean:
	rm -f *.o main

run:
	./main < input.txt > output.txt