#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAXSIZE 10

typedef struct
{
	int data[MAXSIZE];
	int length;
}SqList;//表




void Insert(SqList *L)
{
	L->length = MAXSIZE;
	printf("请输入%d个数字:", L->length);
	for (int i = 0; i < L->length; i++)
	{
		scanf_s("%d", &L->data[i]);
	}
}

void Out(SqList *L)
{
	int i;
	for (i = 0; i < MAXSIZE; i++)
	{
		printf("%d ", L->data[i]);
	}2
	printf("\n");
}
void GuluGulu1(SqList &L)
{
	Insert(&L);
	printf("表中的元素:");
	Out(&L);
	int i, j;
	for (i = 0; i < L.length; i++)
	{
		for (j = i + 1; j < L.length; j++)
		{
			if (L.data[i] > L.data[j])
				swap(L.data[i], L.data[j]);
		}
	}
	printf("冒泡排序1后的结果:");
	Out(&L);
}

void Gulugulu2(SqList &L)
{
	Insert(&L);
	printf("表中的元素:");
	Out(&L);
	int i, j;
	for (i = 0; i < L.length; i++)
	{
		for (j = L.length - 1; j >= i; j--)
		{
			if (L.data[j] < L.data[j - 1])
				swap(L.data[j], L.data[j - 1]);
		}
	}
	printf("冒泡排序2后的结果:");
	Out(&L);
}

void GuluGulu3(SqList &L)
{
	Insert(&L);
	printf("表中的元素:");
	Out(&L);
	int i, j;
	int flag = 1;
	for (i = 0; i < L.length && flag == 1; i++)
	{
		flag = 0;//将flag置为0
		for (j = L.length - 1; j >= i; j--)
		{
			if (L.data[j] < L.data[j - 1])
				swap(L.data[j], L.data[j - 1]);
			flag = 1;//发生数据交换就把flag置1
		}
	}
	printf("冒泡排序3后的结果:");
	Out(&L);
}

int main()
{
	SqList L;
	GuluGulu1(L);
	Gulugulu2(L);
	GuluGulu3(L);
}


