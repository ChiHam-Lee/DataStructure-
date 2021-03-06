#include <stdio.h>
#include<stdlib.h>
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;//先提供一个二叉树的结构

int Search(BiTree T, int k, BiTree f, BiTree *p)
{
	if (!T)
	{
		*p = f;
		return false;
	}
	if (k == T->data)
	{
		*p = T;
		return true;
	}
	else if (k < T->data)
	{
		return Search(T->lchild, k, T, p);
	}
	else
		return Search(T->rchild, k, T, p);

}

int Insert(BiTree &T, int i)
{

	if (!T)
	{
		T = (BiTree)malloc(sizeof(BiTNode));//为T分配空间
		T->data = i;//数据域赋值
		T->lchild = T->rchild = NULL;
	}
	if (i == T->data)
		return 0;
	else if (i < T->data)
		Insert(T->lchild, i);
	else
		Insert(T->rchild, i);
	return true;


}
int  Delete(BiTree &p)
{
	BiTree q, s;
	if (p->rchild == NULL)
	{
		q = p;
		p = p->lchild;//当右子树为空时，将它左孩子替换它，再free掉此结点
		free(q);
	}

	if (p->lchild == NULL)
	{
		q = p;
		p = p->rchild;////当左子树为空时，将它右孩子替换它，再free掉此结点
		free(q);
	}

	else//左右子树都不为空的情况
	{
		q = p;
		s = p->lchild;//将需要删除结点赋值给q，再将左孩子赋值给s
		while (s->rchild)//循环一直找到左子树的右节点的尽头
		{
			q = s;
			s = s->rchild;
		}
		p->data = s->data;
		if (q != p)
		{
			q->lchild = p->rchild;//重接左子树
		}
		else
			q->lchild = s->lchild;//重接右子树
		free(s);
	}
	return true;
}

int DeleteT(BiTree &T, int d)
{
	if (!T)
		printf("元素不存在");
	else
	{
		if (d == (T)->data)
		{
			return Delete(T);
		}
		else if (d < (T)->data)
			return DeleteT((T)->lchild, d);
		else
			return DeleteT((T)->rchild, d);
	}
}

void InOrder(BiTree T)
{
	if (T)
	{
		InOrder(T->lchild);
		printf("%d ", T->data);
		InOrder(T->rchild);
	}
}

int main()
{
	int a, j, i = 10;
	BiTree T = NULL, f, p;
	printf("输入元素:");
	while (i--)
	{
		scanf_s("%d", &a);
		Insert(T, a);
	}
	printf("输入的元素为(中序遍历):");
	InOrder(T);
	printf("\n");

	while (1)
	{
		printf("输入需要查找的元素:");
		scanf_s("%d", &a);
		if (Search(T, a, NULL, &p))
			printf("找到了\n");
		else
		{
			printf("没找到\n");
			printf("是否需要插入未找到的元素(是:1/否:0)");
			scanf_s("%d", &j);
			if (j == 0)
				return 0;
			else
				Insert(T, a);
			printf("插入后的序列为:");
			InOrder(T);
			printf("\n");
		}
		printf("是否需要删除某个元素?(是:1/否:0):");
		scanf_s("%d", &j);
		if (j == 1)
		{
			printf("输入需要删除的元素:");
			scanf_s("%d", &a);
			DeleteT(T, a);
			printf("删除后的序列为:");
			InOrder(T);
			printf("\n");
		}
	}

}

