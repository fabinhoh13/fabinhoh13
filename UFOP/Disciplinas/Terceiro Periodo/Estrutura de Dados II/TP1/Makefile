all: ./.o/geraBinarios.o ./.o/tipoItem.o ./.o/ArvoreBinaria.o ./.o/ArvoreB.o ./.o/Estatisticas.o ./.o/tipoPagina.o ./.o/acessoIndexado.o ./.o/tipoBEstrela.o ./.o/arvoreBEstrela.o ./.o/experimento.o main.c
	gcc -o main main.c ./.o/geraBinarios.o ./.o/tipoItem.o ./.o/ArvoreBinaria.o ./.o/ArvoreB.o ./.o/Estatisticas.o ./.o/tipoPagina.o ./.o/acessoIndexado.o ./.o/tipoBEstrela.o ./.o/arvoreBEstrela.o ./.o/experimento.o -Wall

./.o/geraBinarios.o: ./.c/geraBinarios.c
	gcc -o ./.o/geraBinarios.o -c ./.c/geraBinarios.c

./.o/tipoItem.o: ./.c/tipoItem.c
	gcc -o ./.o/tipoItem.o -c ./.c/tipoItem.c

./.o/ArvoreBinaria.o: ./.c/ArvoreBinaria.c
	gcc -o ./.o/ArvoreBinaria.o -c ./.c/ArvoreBinaria.c

./.o/ArvoreB.o: ./.c/ArvoreB.c
	gcc -o ./.o/ArvoreB.o -c ./.c/ArvoreB.c

./.o/Estatisticas.o: ./.c/Estatisticas.c
	gcc -o ./.o/Estatisticas.o -c ./.c/Estatisticas.c

./.o/tipoPagina.o: ./.c/tipoPagina.c
	gcc -o ./.o/tipoPagina.o -c ./.c/tipoPagina.c

./.o/acessoIndexado.o: ./.c/acessoIndexado.c
	gcc -o ./.o/acessoIndexado.o -c ./.c/acessoIndexado.c

./.o/tipoBEstrela.o: ./.c/tipoBEstrela.c
	gcc -o ./.o/tipoBEstrela.o -c ./.c/tipoBEstrela.c

./.o/arvoreBEstrela.o: ./.c/arvoreBEstrela.c
	gcc -o ./.o/arvoreBEstrela.o -c ./.c/arvoreBEstrela.c

./.o/experimento.o: ./.c/experimento.c
	gcc -o ./.o/experimento.o -c ./.c/experimento.c

clean:
	rm -f ./.o/*.o main

run:
	./main
