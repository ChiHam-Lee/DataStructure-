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
	for (i = 1; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
}
void Insert(SqList *L)
{
	int i,size;
	printf("输入表的长度:");
	scanf_s("%d", &size);
	L->length = size;
	printf("输入%d个元素", size - 1);
	for (i = 1; i < L->length; i++)//data[0]做哨兵
	{
		scanf_s("%d", &L->data[i]);
	}
	printf("表中的元素为:");
	Out(L);
}

void InsertSort(SqList *L)
{
	int i, j;
	for (i = 1; i < L->length; i++)
	{
		if (L->data[i] < L->data[i - 1])
		{
			L->data[0] = L->data[i];
			for (j = i - 1 ; L->data[j] > L->data[0]; j--)
			{
				L->data[j + 1] = L->data[j];
			}
			L->data[j + 1] = L->data[0];
		}
		
	}
	printf("\n插入排序后的元素:");
	Out(L);
}

int main()
{
	SqList L;
	Insert(&L);
	InsertSort(&L);
}