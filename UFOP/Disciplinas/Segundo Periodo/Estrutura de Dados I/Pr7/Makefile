all:  ordenacao.o main.c
	gcc -o main main.c ordenacao.o
ordenacao.o: ordenacao.c
	gcc -o ordenacao.o -c ordenacao.c

clean:
	rm -f *.o main

run:
	./main < input.txt > output.txt