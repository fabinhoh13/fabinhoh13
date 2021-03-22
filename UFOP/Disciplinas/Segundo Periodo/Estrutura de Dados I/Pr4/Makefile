all:  funcoes-recursivas.o main.c
	gcc -o main main.c funcoes-recursivas.o
funcoes-recursivas.o: funcoes-recursivas.c
	gcc -o funcoes-recursivas.o -c funcoes-recursivas.c

clean:
	rm -f *.o main

run:
	./main < input.txt > output.txt