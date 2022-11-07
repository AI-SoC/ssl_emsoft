fool1.o: fool1.c ssl.h
	gcc -c fool1.c

fool2.o: fool2.c ssl.h
	gcc -c fool2.c

main.o: main.c ssl.h
	gcc -c main.c

all: fool1.o fool2.o main.o
	gcc -o main main.o fool1.o fool2.o

