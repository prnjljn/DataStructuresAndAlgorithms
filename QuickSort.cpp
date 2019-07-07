#include<iostream>
using namespace std;
int Partition(int a[], int low, int high)
{
	int pivot, index, i;
	index = low;
	pivot = high;
	for(i=low; i < high; i++)
	{
		if(a[i] < a[pivot])
		{
			swap(&a[i], &a[index]);
			index++;
		}
	}
	swap(&a[pivot], &a[index]);

	return index;
}

int QuickSort(int a[], int low, int high)
{
	int pindex;
	if(low < high)
	{
		pindex = Partition(a, low, high);
		QuickSort(a, low, pindex-1);
		QuickSort(a, pindex+1, high);
	}
	return 0;
}
