#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Dprintf 
int array_size;

void print_array(int *a)
{
	//int size = 15;//sizeof(a)/sizeof(int);
	int size = array_size;
	int i;
	for (i=0;i<size;i++)
		printf ("%d ", a[i]);
	printf ("\n");
}

void swap(int a[], int x, int y)
{
	int t;
	t=a[x];
	a[x]=a[y];
	a[y]=t;
}

int partition(int a[], int x, int y)
{
	int pivot_val = a[x];
	int l = x+1;
	int h = y;

	while (l<h)
	{
		while (a[l]<=pivot_val && l<h)
			l++;
		while (a[h]>pivot_val && l<h)
			h--;
		Dprintf (" ..  %d %d\n", l, h);
		swap(a, l, h);
		//l++;
		//h--;
	}
	Dprintf("before pivot swap ");
	//print_array(a);

	//if (x<l)
		swap(a,x,l-1);
	Dprintf("after pivot swap ");
	//print_array(a);
	
	return l-1;
}

int partition2(int a[], int x, int y)
{
	int pivot_val = a[x];
	int l = x+1;
	int h = y;

	while (l<h)
	{
		while (a[l]<=pivot_val)
			l++;
		while (a[h]>pivot_val)
			h--;
		Dprintf (" ..  %d %d\n", l, h);
		if (l<h)
		swap(a, l, h);
		//l++;
		//h--;
	}
	Dprintf("before pivot swap ");
	//print_array(a);

	//if (x<l)
		//swap(a,x,h);
	a[x]=a[h];
	a[h]=pivot_val;
	Dprintf("after pivot swap ");
	//print_array(a);
	
	return h;
}

void _quicksort(int a[], int x, int y)
{
	int p;
	Dprintf ("%d %d\n", x, y);
	if (x<y) {
		p = partition(a, x, y);
		Dprintf (" p %d\n",p);
		//print_array(a);
		_quicksort(a,x,p-1);
		_quicksort(a,p+1,y);
	}
}

void quicksort(int a[], int size)
{
	//int size = 15;//sizeof(a);///sizeof(int);
	//int size = sizeof(a);///sizeof(int);
	printf ("size %d\n", size);
	_quicksort(a,0,size-1);
}

void insertsort(int a[], int size)
{
	int i, j, temp;
	for (i=1;i<size;i++)
	{
		temp = a[i];
		//j = i-1;
		j = i;
		while (temp < a[j-1] && j > 0)
		{
				//a[j+1]=a[j];
			a[j]=a[j-1];
				j--;
		}
		a[j]=temp;
		//a[j+1] = temp;
	}
}

void selectionsort(int a[], int size)
{
	//find min and set the position
	int i, j;
	for (i=0;i<size;i++)
	{
		for (j=i+1;j<size;j++)
		{
			if (a[i]>a[j])
				swap(a, i, j);
		}
	}
}

void _merge(int a[], int x, int y)
{
	int i;
	int mid = x + (y-x)/2 + 1;
	int *temp=malloc(sizeof(int)*(y-x+1));
	int l,h;
	l=x;
	h=mid;
	i=0;

	printf ("merge %d, %d\n",x,y);
	
	while (l<=mid-1 && h<=y)
	{
		if (a[l]<=a[h])
		{
			temp[i]=a[l];
			printf("temp[%d]=a[%d]\n", i, l);
			l++;
			i++;
		}
		else
		{
			temp[i]=a[h];
			printf("temp[%d]=a[%d]\n", i, h);
			h++;
			i++;
		}
	}

	while (l<=mid-1)
	{
		printf("after, mid-1 %d, l:%d, temp[%d]=a[%d]\n", mid-1, l, i, l);
		temp[i++]=a[l++];
	}
	while (h<=y)
	{
		printf("after, h %d, y:%d, temp[%d]=a[%d]\n", h, y, i, h);
		temp[i++]=a[h++];
	}

	memcpy(&a[x],temp,sizeof(int)*(y-x+1));

	print_array(a);

	free(temp);
}

void _mergesort(int a[], int x, int y)
{
	if (x==y)
		return;
	printf ("%d, %d\n", x, y);
	_mergesort(a,x,x+(y-x)/2);
	_mergesort(a,x+(y-x)/2+1,y);
	_merge(a,x,y);
}

void mergesort(int a[], int size)
{
	_mergesort(a, 0, size-1);
}

void shellsort(int a[], int size)
{
	int h=(size/3)+1;
	int k;
	for (k=h;k>0;k--)
	{
	int i, j, temp;
	for (i=k;i<size;i++)
	{
		temp = a[i];
		j = i;
		while (temp < a[j-k] && j-k >= 0)
		{
				a[j]=a[j-k];
				j=j-k;
		}
		a[j] = temp;
	}
	}
}

int _binary_search_min(int a[], int x, int y)
{
	int mid = x + (y-x)/2;
	printf ("%d %d\n", x, y);

	if (x<y)
	{
		if (a[mid+1] < a[mid])
			return mid+1;
		if (a[x] > a[mid])
			return _binary_search_min(a, x, mid);
		else
			return _binary_search_min(a, mid+1, y);
	}
	return x;
}

int find_min_start (int a[], int size)
{
	return _binary_search_min(a, 0, size-1);	
}

#if 0
int array[] = {
  14,36,36,467,24,
  562,26,2,4,2,
  6,7,15,52,25,
};
#endif
int array[] = { 7,8,9,1,1,1,2,3,4,5,6 };

int main(int argc, char*argv[])
{
	int ret;
	printf("size of array %ld\n", sizeof(array));
	array_size = (int)(sizeof(array)/sizeof(array[0]));
	//print_array(array);
	//quicksort(array, array_size);
	//selectionsort(array, array_size);
	//insertsort(array, array_size);
	//print_array(array);
	//mergesort(array, array_size);
	//shellsort(array, array_size);
	//print_array(array);
	ret = find_min_start(array, array_size);
	printf ("find_min_start %d\n", ret);
}
