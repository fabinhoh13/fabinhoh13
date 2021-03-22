all: memory.o instruction.o oneprogram.o pipeline.o machine.o main.c
	gcc -o main main.c memory.o instruction.o oneprogram.o  pipeline.o machine.o

memory.o: memory.c
	gcc -o memory.o -c memory.c

instruction.o: instruction.c
	gcc -o instruction.o -c instruction.c

oneprogram.o: oneprogram.c 
	gcc -o oneprogram.o -c oneprogram.c

pipeline.o: pipeline.c
	gcc -o pipeline.o -c pipeline.c

machine.o: machine.c 
	gcc -o machine.o -c machine.c

clean:
	rm -f *.o main

run:
	./main