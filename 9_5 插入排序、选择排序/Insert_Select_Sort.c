#define _CRT_SECURE_NO_WARNINGS 1




//��������
//void InsertSort(int* a, int n)
//{
//	assert(a);
//	for (int i = 0; i < n - 1; i++)
//	{
//		int end = i;//��¼�Ӻ���ǰ�ȽϵĿ�ʼλ��
//		int tmp = a[end + 1];
//		//�� end<0 ʱ����Խ��
//		while (end >= 0)
//		{
//			//���tmp�ȱȽϵ�����С����ô����ͽ��и��ǵ���
//			//���ǵĻ�ͼ����tmp�ƶ����������ǵĴ������������ƶ�
//			if (tmp < a[end])
//			{
//				a[end + 1] = a[end];
//				end--;
//			}
//			else
//			{
//				break;
//			}
//		}
//		//����
//		a[end + 1] = tmp;
//	}
//}



//ϣ������
//void ShellSort(int* a, int n)
//{
//	assert(a);
//	int gap = n;//Ĭ�ϵ�һ�ε�gapΪn
//	while (gap > 1)
//	{
//		gap /= 2;//���μ�С���䣬���һ��gapһ��Ϊ 1
//
//		ֱ�Ӳ�������
//		for (int i = 0; i < n - gap; i++)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}
//}


//ѡ������
//void SelectSort(int* a, int n)
//{
//	assert(a);
//	int begin = 0;
//	int end = n - 1;
//	int maxi = begin;
//	int mini = end;
//	while (begin < end)
//	{
//		for (int i = begin + 1; i <= end; i++)
//		{
//			if (a[mini] > a[i])
//			{
//				mini = i;
//			}
//			if (a[maxi] < a[i])
//			{
//				maxi = i;
//			}
//		}
//		Swap(&a[begin], &a[mini]);
//
//		//���beginλ���Ϸŵ���������
//		//��ô��Ҫ�ı�һ��maxi��λ��
//		if (maxi == begin)
//		{
//			maxi = mini;
//		}
//		Swap(&a[end], &a[maxi]);
//		begin++;
//		end--;
//	}
//}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

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

void AdjustDown(int* heap, int n, int parent)
{
	assert(heap);
	int minchild = parent * 2 + 1;
	while (minchild < n)
	{
		if (minchild + 1 < n && heap[minchild + 1] > heap[minchild])
		{
			minchild++;
		}
		if (heap[minchild] > heap[parent])
		{
			Swap(&heap[minchild], &heap[parent]);
			parent = minchild;
			minchild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	assert(a);
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	while (n)
	{
		Swap(&a[0], &a[n - 1]);
		AdjustDown(a, n-1, 0);
		n--;
	}
}
int main()
{
	//��������Ĵ�С
	int size = 1000000;
	int* arr = (int*)malloc(sizeof(int) * size);
	assert(arr);

	//�����������ֵ
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
	}

	//InsertSort(arr, size);
	//ShellSort(arr, size);
	//SelectSort(arr, size);
	HeapSort(arr, size);
	Print(arr, size);
	return 0;
}