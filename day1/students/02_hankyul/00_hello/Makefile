foo1.o: foo1.c ssl.h
	gcc -c foo1.c

foo2.o: foo2.c ssl.h
	gcc -c foo2.c

main.o: main.c ssl.h
	gcc -c main.c

clean:
	rm .\*.o
	rm main

all: foo1.o foo2.o main.o
	gcc -o main main.o foo1.o foo2.o