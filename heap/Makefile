all: heapsort

heapsort: heap.o main.c
	gcc -o $@ $^

heap.o: heap.c heap.h
	gcc -c $<



