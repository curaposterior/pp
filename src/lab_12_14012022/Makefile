#pierwszy makefile
SHELL = /bin/sh
CC = gcc
#AR = ar -ru
CLF = -g -DMY_DEBUG
#LIB = -L../lib -llista_powiazana -lm

lista: main.o lista_powiazana.o
	$(CC) -o lista main.o lista_powiazana.o
main.o: main.c lista_powiazana.h
	$(CC) -c main.c
lista_powiazana.o: lista_powiazana.c lista_powiazana.h
	$(CC) -c lista_powiazana.c
biblioteka:
	ar -ru lista_powiazana.a lista_powiazana.o
clean:
	rm -f *.o
