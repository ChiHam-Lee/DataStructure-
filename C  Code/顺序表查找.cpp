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

int Search(SeqList R,int n,KeyType k)
{
	int i;
    i = n;
    while(R[i].Key!=k)//ֱ�Ӵӱ�β���в��ң�����ÿ��ѭ�����ж�i�᲻�����n
    {
        i--;
    }
    return i;

}

int main()
{
    SeqList R;
    int n = 10,i;
    KeyType k ;
   printf("������������(ʮ����ͬ������):");
   for(i=0;i<10;i++)
   {
       scanf("%d",&R[i].Key);
   }
    printf("����Ϊ:");
    for(i=0;i<n;i++)
    {
        printf("%d,",R[i].Key);
    }
    printf("\n��������Ҫ���ҵĹؼ���Ϊ:");
    scanf("%d",&k);
    printf("��Ҫ�����Ĺؼ���Ϊ%d",k);
    if((i =Search(R,n,k))!=-1)
    {
        printf("\n%d�����еĵ�%dλ��",k,i+1);
    }
}

