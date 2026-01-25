main: main.c
	gcc -g -O0 -fno-omit-frame-pointer main.c ./lib/*.c -o main

benchmark: benchmark.c
	gcc ./lib/*.c benchmark.c -o benchmark