PROVA: main.o filaMEU.o pilha.o
	gcc main.o filaMEU.o pilha.o -o PROVA

main.o: main.c
	gcc -c main.c

filaMEU.o: filaMEU.c filaMEU.h
	gcc -c filaMEU.c

pilha.o: pilha.c pilha.h
	gcc -c pilha.c
