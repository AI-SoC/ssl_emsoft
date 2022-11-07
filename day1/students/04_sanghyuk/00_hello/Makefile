foo1.o: foo1.c ssl.h
	gcc -c foo1.c
foo2.o: foo2.c ssl.h
	gcc -c foo2.c
main.o: main.c ssl.h
	gcc -c main.c
all: foo1.o foo2.o main.o
#complie
#	gcc -c foo1.c
#	gcc -c foo2.c
#	gcc -c main.c
#linking
	gcc -o main main.o foo1.o foo2.o
