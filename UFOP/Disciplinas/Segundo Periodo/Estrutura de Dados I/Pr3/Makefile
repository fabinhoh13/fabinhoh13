all:  aluno.o disciplina.o atestado.o main.c
	gcc -o P3 main.c aluno.o disciplina.o atestado.o

aluno.o: aluno.c
	gcc -o aluno.o -c aluno.c

disciplina.o: disciplina.c
	gcc -o disciplina.o -c disciplina.c

atestado.o: atestado.c
	gcc -o atestado.o -c atestado.c

clean:
	rm -f *.o main

run:
	./P3 < input.txt > output.txt