#include <stdio.h>
#include <stdlib.h>


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
void Insert(SqList *L,int size)
{
	int i;
	L->length = size;
	printf("输入%d个元素", size );
	for (i = 0; i < L->length; i++)
	{
		scanf_s("%d", &L->data[i]);
	}
}

void Quick(SqList *L,int low ,int high)
{
	int i , j , key;
	if (low < high)
	{
		key = L->data[low];
		i = low;
		j = high;
		while (i < j)
		{
			while (L->data[j] >= key && i < j)
				j--;
			if (i < j)
				L->data[i++] = L->data[j];
			while (L->data[i] <= key && i < j)
				i++;
			if (i < j)
				L->data[j--] = L->data[i];
		}
		L->data[i] = key;
		Quick(L, low, i - 1);
		Quick(L, i + 1, high);
	}

}

int main()
{
	int size;
	SqList L;
	printf("输入表的长度:");
	scanf_s("%d", &size);
	Insert(&L,size);
	Quick(&L,0,size-1);
	printf("\n快速排序后的元素:");
	Out(&L);
}