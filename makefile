main: main.c
	gcc -g -O0 -fno-omit-frame-pointer ./lib/*.c main.c -o main

benchmark: benchmark.c
	gcc ./lib/*.c benchmark.c -o benchmark

rm: main
	rm -rf main