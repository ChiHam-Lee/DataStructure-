#include <stdio.h>
#define MAXSIZE 100

typedef int KeyType;
typedef char InfoType[10];
typedef struct
{
	KeyType Key;
	InfoType data;
}NodeType;
typedef NodeType SeqList[MAXSIZE];

int Search(SeqList R, int n, KeyType k)
{
	int low, high, mid;
	low = 1;
	high = n;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (k < R[mid].Key)
			high = mid - 1;
		else if (k > R[mid].Key)
			low = mid + 1;
		else
			return mid;
	}
	return 0;
}

int main()
{
	SeqList R;
	int n = 10, i;
	KeyType k;
	printf("输入序列内容(十个不同的数字):");
	for (i = 0; i<10; i++)
	{
		scanf("%d", &R[i].Key);
	}
	printf("序列为:");
	for (i = 0; i<n; i++)
	{
		printf("%d,", R[i].Key);
	}
	printf("\n请输入需要查找的关键字为:");
	scanf("%d", &k);
	printf("需要搜索的关键字为%d", k);
	if ((i = Search(R, n, k)) != -1)
	{
		printf("\n%d在序列的第%d位置\n", k, i+1);
	}
}

