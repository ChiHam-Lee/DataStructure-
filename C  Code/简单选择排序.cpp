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

void Insert(SqList *L)
{
	int size,i;
	printf("输入线性表的元素个数:");
	scanf_s("%d", &size);
	L->length = size;
	printf("\n输入%d个数字", size);
	for (i = 0; i < L->length; i++)
	{
		scanf_s("%d", &L->data[i]);
	}
	printf("表中的元素为:");
	Out(L);
	printf("\n");
}



void SelectSort(SqList *L)
{
	int i, j, min;
	for (i = 0; i < L->length; i++)
	{
		min = i;
		for (j = i+1; j < L->length; j++)
		{
			if (L->data[min] > L->data[j])
				min = j;
		}
		if (i != min)
			swap(L->data[i], L->data[min]);
	}
}

int main()
{
	SqList L;
	Insert(&L);
	SelectSort(&L);
	printf("简单选择排序之后的序列为:");
	Out(&L);
}