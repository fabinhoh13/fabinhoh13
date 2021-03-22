all: Huffman.o word.o lista.o hash.o main.c
	gcc -o main Huffman.o main.c word.o lista.o hash.o

Huffman.o: Huffman.c
	gcc -o Huffman.o -c Huffman.c

word.o: word.c
	gcc -o word.o -c word.c

lista.o: lista.c
	gcc -o lista.o -c lista.c

hash.o: hash.c
	gcc -o hash.o -c hash.c

clean:
	rm -f *.o main

run:
	./main
