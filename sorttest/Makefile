all: sort heapsort

sort: 1.c
	gcc -o $@ $<

heapsort: heap/heap.o main.o
	gcc -o $@ $^

heap/heap.o: heap/heap.c heap/heap.h
	gcc -c $<



