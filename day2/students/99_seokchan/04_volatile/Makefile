all:
	gcc -O3 -o main main.c
	./main

dump:  #disassemble
	objdump -d -S main.exe > main_dis.s
	