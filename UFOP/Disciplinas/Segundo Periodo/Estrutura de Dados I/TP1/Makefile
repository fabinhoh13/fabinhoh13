all: morador.o endereco.o faxina.o republica.o funcoes_uteis.o main.c
	gcc -o main main.c morador.o endereco.o faxina.o republica.o funcoes_uteis.o -Wall

morador.o: morador.c
	gcc -o morador.o -c morador.c -Wall

endereco.o: endereco.c
	gcc -o endereco.o -c endereco.c -Wall

faxina.o: faxina.c
	gcc -o faxina.o -c faxina.c -Wall

republica.o: republica.c
	gcc -o republica.o -c republica.c -Wall

funcoes_uteis.o: funcoes_uteis.c
	gcc -o funcoes_uteis.o -c funcoes_uteis.c -Wall

clean:
	rm -f *.o main

run:
	./main < input.txt > output.txt
