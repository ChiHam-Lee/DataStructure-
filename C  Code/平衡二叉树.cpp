#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
	int data;
	int bf;//节点平衡因子
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;//二叉树结构

void Right(BiTree &p)
{
	BiTree L;
	L = p->lchild;
	p->lchild = L->rchild;
	L->rchild = p;
	p = L;
}

void Left(BiTree &p)
{
	BiTree R;
	R = p->rchild;
	p->rchild = R->lchild;
	R->lchild = p;
	p = R;
}

void LeftBalance(BiTree &T)
{
	BiTree L,Lr;
	L = T->lchild;
	switch (L->bf)
	{
	case 1:
		T->bf = L->bf = 0;
		Right(T);
		break;
	case -1:
		Lr = L->rchild;
		switch (Lr->bf)
		{
		case 1:
			T->bf = -1;
			L->bf = 0;
			break;
		case 0:
			T->bf = L->bf = 0;
			break;
		case -1:
			T->bf = 0;
			L->bf = 1;
			break;
		}
		Lr->bf = 0;
		Left(T->lchild);
		Right(T);
	}
}

void RightBalance(BiTree &T)
{
	BiTree R, Rl;
	R = T->rchild;
	switch (R->bf)
	{
	case -1:
		T->bf = R->bf = 0;
		Left(T);
		break;
	case 1:
		Rl = R->lchild;
		switch (Rl->bf)
		{
		case -1:
			T->bf = 1;
			R->bf = 0;
			break;
		case 0:
			T->bf = R->bf = 0;
			break;
		case 1:
			T->bf = 0;
			R->bf = -1;
			break;
		}
		Rl->bf = 0;
		Right(T->rchild);
		Left(T);
	}
}

int InserAVL(BiTree &T, int k, int &taller)
{
	if (!T)
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = k;
		T->rchild = T->lchild = NULL;
		T->bf = 0;
		taller = true;
	}

	else
	{
		if (k == T->data)
		{
			taller = false;
			printf("元素已存在");
			return false;
		}
		if (k < T->data)
		{
			if (taller)
			{
				switch (T->bf)
				{
				case 1:
					LeftBalance(T);
					taller = false;
					break;
				case 0:
					T->bf = 1;
					taller = true;
					break;
				case -1:
					T->bf = 0;
					taller = false;
					break;
				}
			}
		}
		else
		{
			if (taller)
			{
				switch (T->bf)
				{
				case 1:
					T->bf = 0;
					taller = false;
					break;
				case 0:
					T->bf = -1;
					taller = true;
					break;
				case -1:
					RightBalance(T);
					taller = false;
					break;
				}
			}
		}
	}
	return true;
}

void InOrder(BiTree T)
{
	InOrder(T->lchild);
	printf("%d ", T->data);
	InOrder(T->rchild);
}
int main()
{
	int  i;
	int a[10] = {3,2,1,4,5,6,7,10,9,8};
	BiTree T = NULL;
	int taller;
	printf("输入序列");
	for (i = 0; i < 10; i++)
	{
		//scanf_s("%d", &a);
		InserAVL(T, a[i], taller);
	}
	InOrder(T);
}