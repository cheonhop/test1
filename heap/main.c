#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

#define Dprintf 
int array_size;

void print_array(long *a, long count)
{
	//int size = 15;//sizeof(a)/sizeof(int);
	long i;
	for (i=0;i<count;i++)
		printf ("%ld ", (long)a[i]);
	printf ("\n");
}

void swap(int a[], int x, int y)
{
	int t;
	t=a[x];
	a[x]=a[y];
	a[y]=t;
}

long array[] = { 7,8,9,1,1,1,2,3,4,5,6 };

int main(int argc, char*argv[])
{
	int ret;
	int i;
	printf("size of array %ld\n", sizeof(array));
	array_size = (int)(sizeof(array)/sizeof(array[0]));

	print_array(array, array_size);

	heap_t *PQ = heap_create(array_size);

	//build heap 1
	for (i=0;i<array_size;i++)
		heap_insert(PQ, array[i]);
	heap_print(PQ, NULL);

	//heap sort
	for (i=0;i<array_size;i++)
		heap_delete_top(PQ);
	print_array(PQ->array, array_size);

	//build heap 2
	PQ->array = array;
	PQ->count = array_size;
	heap_build(PQ);

	heap_print(PQ, NULL);
	//printf ("top %ld\n", max);
	//heap_print(PQ, NULL);

	return 0;
}
