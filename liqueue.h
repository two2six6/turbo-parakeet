#include<malloc.h>
#include<iostream>
typedef char elemtype;
using namespace std;
typedef struct datanode
{
	elemtype data;
	struct datanode* next;
}datanode;
typedef struct
{
	datanode* front;
	datanode* rear;
}linkqunode;
void initqueue(linkqunode*& q)
{
	q = (linkqunode*)malloc(sizeof(linkqunode));
	q->front = q->rear = NULL;
}
void destroy(linkqunode*& q)
{
	datanode* p = q->front, * r;
	if (p != NULL)
	{
		r = p->next;
		while (r != NULL)
		{
			free(q);
			p = r; r = p->next;
		}
	}
	free(p);
	free(q);
}
bool queueempty(linkqunode* q)
{
	return (q->rear == NULL);
}
void enqueue(linkqunode*& q, elemtype e)
{
	datanode* p;
	p = (datanode*)malloc(sizeof(datanode));
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)
		q->front = q->rear = p;
	else
	{
		q->rear->next = p;
		q->rear = p;
	}
}
bool dequeue(linkqunode*& q, elemtype& e)
{
	datanode* t;
	if (q->rear == NULL)
		return false;
	t = q->front;
	if (q->front == q->rear)
		q->front = q->rear = NULL;
	else
		q->front = q->front->next;
	e = t->data;
	free(t);
	return true;
} 