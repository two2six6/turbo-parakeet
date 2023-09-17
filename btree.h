#include<iostream>
#include<malloc.h>
using namespace std;
#define MaxSize 100
typedef char elemtype;
typedef struct node
{
	elemtype data;
	struct node* lchild;
	struct node* rchild;
}btnode;
void createbtree(btnode*& b, char* str)
{
	btnode* st[MaxSize],*p{};
	int top = -1, k, j = 0; char ch;
	b = NULL;
	ch = str[j];
	while (ch != '\0')
	{
		switch (ch)
		{
		case'(':top++; st[top] = p; k = 1; break;
		case')':top--; break;
		case',':k = 2; break;
		default:p = (btnode*)malloc(sizeof(btnode));
			p->data = ch; p->lchild = p->rchild = NULL;
			if (b == NULL)
				b = p;
			else
			{
				switch (k)
				{
				case 1:st[top]->lchild = p; break;
				case 2:st[top]->rchild = p; break;
				}
			}
		}
		j++; ch = str[j];
	}
}
void destroy(btnode*& b)
{
	if (b != NULL)
	{
		destroy(b->lchild);
		destroy(b->rchild);
		free(b);
	}
}
btnode* findnode(btnode* b, elemtype x)
{
	btnode* p;
	if (b == NULL)
		return NULL;
	else if (b->data == x)
		return b;
	else
	{
		p = findnode(b->lchild, x);
		if (p != NULL)
			return p;
		else
			return findnode(b->rchild, x);
	}
}
btnode* lchildnode(btnode* p)
{
	return p->lchild;
}
btnode* rchildnode(btnode* p)
{
	return p->rchild;
}
int bthight(btnode* b)
{
	int lchildh, rchildh;
	if (b == NULL)
		return(0);
	else
	{
		lchildh = bthight(b->lchild);
		rchildh = bthight(b->rchild);
		return (lchildh > rchildh) ? (lchildh + 1) : (rchildh + 1);
	}
}
void dispbtree(btnode* b)
{
	if (b != NULL)
	{
		cout << b->data;
		if (b->lchild != NULL || b->rchild != NULL)
		{
			cout << "( ";
			dispbtree(b->lchild);
			if (b->rchild != NULL)
				cout << " , ";
			dispbtree(b->rchild);
			cout << " )";
		}
	}
}