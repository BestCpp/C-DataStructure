#define _CRT_SECURE_NO_WARNINGS 1



//ð������
//void BubbleSort(int* a, int n)
//{
//	assert(a);
//	int flag = 0;
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - i - 1; j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				Swap(&a[j], &a[j + 1]);
//				flag = 1;
//			}
//		}
//		//�����һ�����Ϊ������ô�Ͳ���������
//		if (!flag)
//		{
//			break;
//		}
//	}
//}


//Hoare����������
//int PartSort1(int* a, int left, int right)
//{
//	assert(a);
//	//�ҵ���λ������ left ���н���
//	int mid = GetMidNum(a, left, right);
//	Swap(&a[left], &a[mid]);
//
//	int keyi = left;
//	while (left < right)
//	{
//		while (left < right && a[right] >= a[keyi])
//		{
//			right--;
//		}
//		while (left < right && a[left] <= a[keyi])
//		{
//			left++;
//		}
//		if (left < right)
//		{
//			Swap(&a[left], &a[right]);
//		}
//	}
//	int meeti = left;
//	Swap(&a[keyi], &a[meeti]);
//	return meeti;
//
//}


//�ڿӷ�
//int PartSort2(int* a, int left, int right)
//{
//	assert(a);
//	int mid = GetMidNum(a, left, right);
//	Swap(&a[left], &a[mid]);
//	int key = a[left];
//	int hole = left;
//	while (left < right)
//	{
//		while (left < right && a[right] >= key)
//		{
//			right--;
//		}
//		a[hole] = a[right];
//		hole = right;
//
//		while (left < right && a[left] <= key)
//		{
//			left++;
//		}
//		a[hole] = a[left];
//		hole = left;
//	}
//	a[hole] = key;
//	return hole;
//}


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "Stack.h"

//ֱ�Ӳ�������
void InsertSort(int* a,int n)
{
	assert(a);
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
void Print(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
void Swap(int* p1, int* p2)
{
	assert(p1 && p2);
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//����ȡ��
int GetMidNum(int* a, int left, int right)
{
	assert(a);
	int mid = (right + left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

int PartSort3(int* a, int left, int right)
{
	assert(a);
	int mid = GetMidNum(a, left, right);
	Swap(&a[left], &a[mid]);
	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}


//�ڿӷ�
int PartSort2(int* a, int left, int right)
{
	assert(a);
	int mid = GetMidNum(a, left, right);
	Swap(&a[left], &a[mid]);
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;

		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}


//��������ݹ�
//void QuickSort(int* a, int left, int right)
//{
//	assert(a);
//	if (left >= right)
//	{
//		return;
//	}
//	//STL��Դ�������ֵΪ 16
//	if (right - left <= 16)
//	{
//		InsertSort(a+left, right - left + 1);
//	}
//	else
//	{
//		//int keyi = PartSort1(a, left, right);
//		//int keyi = PartSort2(a, left, right);
//		int keyi = PartSort3(a, left, right);
//
//		QuickSort(a, left, keyi - 1);
//		QuickSort(a, keyi + 1, right);
//	}
//	
//}

//void QuickSort(int* a, int begin, int end)
//{
//	assert(a);
//	Stack st;
//	StackInit(&st);
//	StackPush(&st, end);
//	StackPush(&st, begin);
//	while (!StackEmpty(&st))
//	{
//		int left = StackTop(&st);
//		StackPop(&st);
//
//		int right = StackTop(&st);
//		StackPop(&st);
//
//		int keyi = PartSort3(a, left, right);
//		if (right > keyi + 1)
//		{
//			StackPush(&st, right);
//			StackPush(&st, keyi + 1);
//		}
//		if (keyi - 1 > left)
//		{
//			StackPush(&st, keyi - 1);
//			StackPush(&st, left);
//		}
//	}
//	StackDestroy(&st);
//}

//�ǵݹ��������
void QuickSort(int* a, int left, int right)
{
	assert(a);
	Stack st;
	StackInit(&st);
	//�����ң�������
	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);

		int right = StackTop(&st);
		StackPop(&st);

		/*if (left >= right)
		{
			continue;
		}*/

		int keyi = PartSort3(a, left, right);
		// [left, keyi-1] keyi [keyi+1,right]

		if (keyi+1 < right)
		{
			//�����ң�������
			StackPush(&st, right);
			StackPush(&st, keyi+1);
		}

		//�ٽ���������ջ
		if (left<keyi-1)
		{
			//�����ң�������
			StackPush(&st, keyi-1);
			StackPush(&st, left);
		}
	}

	StackDestroy(&st);
}
int main()
{
	int size = 1000000;
	int* arr = (int*)malloc(sizeof(int) * size);
	assert(arr);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
	}
	//BubbleSort(arr, size);
	QuickSort(arr, 0, size - 1);
	Print(arr, size);
	return 0;
}