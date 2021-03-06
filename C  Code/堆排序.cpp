#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


typedef struct
{
	int data[100];
	int length;
}SqList;

void Out(SqList *L)
{
	int i;
	for (i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
}
void Insert(SqList *L, int size)
{
	int i;
	L->length = size;
	printf("输入%d个元素", size);
	for (i = 0; i < L->length; i++)
	{
		scanf_s("%d", &L->data[i]);
	}
}

void HeapAdjust(SqList *L,int small,int max)
{
	int m, i;
	m = L->data[small];
	for (i = 2 * small + 1; i <= max; i = i * 2 + 1 )//2*s+1为较大孩子结点
	{
		if (i < max&&L->data[i] < L->data[i + 1])
			i++;
		if (!(m < L->data[i]))
			break;
		L->data[small] = L->data[i];
		small = i;
	}
	L->data[small] = m;
}


void HeapSort(SqList *L)
{
	int i;
	for (i = L->length / 2-1; i >= 0; i--)
	{
		HeapAdjust(L,i,L->length -1 );
	}

	for (i = L->length - 1; i > 0; i--)
	{
		swap(L->data[i ], L->data[0]);
		HeapAdjust(L,0,i-1);
	}
	
}
int main()
{
	int size;
	SqList L;
	printf("输入表的长度:");
	scanf_s("%d", &size);
	Insert(&L, size);
	HeapSort(&L);
	printf("\n堆排序后的元素:");
	Out(&L);
}