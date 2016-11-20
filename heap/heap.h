typedef struct heap {
	long size;
	long count;
	long *array;
} heap_t;

struct heap* heap_create(long size);
void heap_insert(heap_t *PQ, long item);
long heap_delete_top(heap_t *PQ);
void heap_print(heap_t *PQ, char *);


