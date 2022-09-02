#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>
void Swap(int* p1, int* p2)
{
	assert(p1 && p2);
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//µ•Ã…≈≈–Ú
int PartSort(int* a, int left, int right)
{
	assert(a);
	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		if(left < right)
			Swap(&a[left], &a[right]);
	}
	int meeti = left;
	Swap(&a[meeti], &a[keyi]);
	return meeti;
}
//’˚ÃÂ≈≈–Ú
void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
	{
		return;
	}
	int keyi = PartSort(a, left, right);
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}


int main()
{
	int size = 10000000;
	int* arr = (int*)malloc(sizeof(int) * size);
	assert(arr);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % size;
	}
	QuickSort(arr, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}