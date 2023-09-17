#include<iostream>
#include<malloc.h>
#define maxsize 50;
using namespace std;
typedef char elemtype;
typedef struct lnode
{
	elemtype data;
	struct lnode* next;
}linknode;
void creatlistf(linknode*& l, elemtype a[], int n)//ͷ�巨
{
	linknode* s;
	l = (linknode*)malloc(sizeof(linknode));
	l->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (linknode*)malloc(sizeof(linknode));
		s->data = a[i];
		s->next = l->next;
		l->next = s;
	}
}
void creatlistr(linknode*& l, elemtype a[], int n)//β�巨
{
	linknode* s, * r;
	l = (linknode*)malloc(sizeof(linknode));
	l->next = NULL;
	r = l;
	for (int i = 0; i < n; i++)
	{
		s = (linknode*)malloc(sizeof(linknode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}
void initlist(linknode*& l)
{
	l = (linknode*)malloc(sizeof(linknode));
	l->next = NULL;
}
void destroy(linknode*& l)
{
	linknode* pre = l, * p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}
bool listempty(linknode*& l)
{
	return (l->next == NULL);
}
int listlength(linknode*& l)
{
	int i = 0;
	linknode* p = l;
	while (p->next != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}
void dislist(linknode*& l)
{
	linknode* p = l->next;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}
bool getelem(linknode*& l, int i, elemtype& e)
{
	int j = 0;
	linknode* p = l;
	if (i <= 0)
		return false;
	while (j < i && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		e = p->data;
		return true;
	}
}
int locateelem(linknode* l, elemtype e)
{
	int i = 1;
	linknode* p = l->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
		return 0;
	else
		return i;
}
bool listinsert(linknode*& l, int i, elemtype e)
{
	int j = 0;
	linknode* p = l, * s;
	if (i <= 0)
		return false;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		s = (linknode*)malloc(sizeof(linknode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}
bool listdelete(linknode*& l, int i, elemtype& e)
{
	int j = 0;
	linknode* p = l, * q;
	if (i <= 0)
		return false;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		q = p->next;
		if (q == NULL)
			return false;
		e = q->data;
		p->next = q->next;
		free(q);
		return true;
	}
}

