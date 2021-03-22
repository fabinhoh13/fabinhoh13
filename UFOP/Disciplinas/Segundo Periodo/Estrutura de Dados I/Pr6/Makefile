all:  ordenacao.o geraValores.o main.c
	gcc -o main main.c ordenacao.o geraValores.o
ordenacao.o: ordenacao.c
	gcc -o ordenacao.o -c ordenacao.c

geraValores.o: geraValores.c
	gcc -o geraValores.o -c geraValores.c

clean:
	rm -f *.o main

run:
	./main < input.txt > output.txt