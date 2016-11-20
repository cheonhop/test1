#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

static void swap (long *array, int x, int y)
{
	long temp = array[x];
	array[x] = array[y];
	array[y] = temp;
	return;
}

struct heap* heap_create(long size)
{
	struct heap *temp = malloc(sizeof(struct heap));
	if (!temp)
		return NULL;

	temp->array = malloc(sizeof(long) * size);
	if (!temp->array)
		return NULL;

	return temp;
}

void heap_insert(heap_t *PQ, long item)
{
	int i;
	if (PQ->count >= PQ->size)
	{
	//increas heap
	}

	PQ->array[PQ->count] = item;
	i = PQ->count;
	while (i>0 && (PQ->array[(i-1)/2] < item))
	{
		PQ->array[i] = PQ->array[(i-1)/2];
		i = (i - 1) / 2;
	}

	PQ->array[i] = item;
	PQ->count++;

	//heap_print(PQ, "in");
}

static void heap_down(heap_t *PQ, long index)
{
	long left = index * 2 + 1;
	long right = index * 2 + 2;
	long count = PQ->count;
	long max = PQ->array[index];
	long max_index = index;

	if (left < count && max < PQ->array[left])
	{
		max = PQ->array[left];
		max_index = left;
	}
	if (right < count && max < PQ->array[right])
	{
		max = PQ->array[right];
		max_index = right;
	}

	if (index != max_index)
	{
		swap(PQ->array,index,max_index);
		heap_down(PQ, max_index);
	}
}

long heap_delete_top(heap_t *PQ)
{
	long count = PQ->count;
	swap(PQ->array,0,count-1);
	PQ->count--;

	heap_down(PQ, 0);

	return PQ->array[PQ->count];
}

void heap_print(heap_t *PQ, char *pre)
{
	long i;
	if (pre)
		printf ("%s ", pre);
	for (i=0;i<PQ->count;i++)
		printf ("%ld ", PQ->array[i]);
	printf ("\n");
}

void heap_build(heap_t *PQ)
{
	long i = ((PQ->count - 1) -1) /2 ;

	for (;i>=0;i--)
		heap_down(PQ, i);
}
