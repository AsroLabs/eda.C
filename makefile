main: main.c lib.c
	gcc -g -O0 -fno-omit-frame-pointer lib.c main.c -o main
