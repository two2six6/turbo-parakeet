#pragma once
#include<iostream>
#include<malloc.h>
#include<stdio.h>
using namespace std;
typedef double elemtype;
typedef struct
{
	elemtype data[100];
	int top;
}sqstack;
void initstack(sqstack*& s)
{
	s = (sqstack*)malloc(sizeof(sqstack));
	s->top = -1;
}
void destroy(sqstack*& s)
{
	free(s);
}
bool stackempty(sqstack* s)
{
	return (s->top == -1);
}
bool push1(sqstack*& s, elemtype e)
{
	if (s->top == 99)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}
bool pop1(sqstack*& s, elemtype& e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}
bool gettop1(sqstack* s, elemtype& e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}
/*bool push1(sqstack*& s, double e)
{
	if (s->top == 99)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}
bool pop1(sqstack*& s, double& e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}
bool gettop1(sqstack* s, double& e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}*/
/*void trans(char* exp, char postexp[])
{
	char e;
    sqstack* Optr;			//���������ջָ��
	initstack(Optr);			//��ʼ�������ջ
	int i = 0;				//i��Ϊpostexp���±�
	while (*exp!='\0')			//exp���ʽδɨ����ʱѭ��
	{
		switch (*exp)
		{
		case '(':				//�ж�Ϊ������
			push(Optr,'e');		//�����Ž�ջ
			exp++;			//����ɨ�������ַ�
			break;
		case ')':		   	//�ж�Ϊ������
			pop(Optr,e);	    	//��ջԪ��e
			while (e != '(')	    	//��Ϊ'('ʱѭ��
			{
				postexp[++i] = e;		//��e��ŵ�postexp��
				pop(Optr,e);	   	//������ջԪ��e
			}
			exp++;		     	//����ɨ�������ַ�
			break;
		case '+':				//�ж�Ϊ�ӻ����
		case '-':
			while (!stackempty(Optr))		//ջ����ѭ��
			{
				gettop(Optr,e);			//ȡջ��Ԫ��e
				if (e != '(')			//e����'('
				{
					postexp[i++] = e;		//��e��ŵ�postexp��
					pop(Optr,e);		//��ջԪ��e
				}
				else				//e��'(ʱ�˳�ѭ��
					break;
			}
			push(Optr, *exp);		//��'+'��'-'��ջ
			exp++;				//����ɨ�������ַ�
			break;
		case '*':				//�ж�Ϊ'*'��'/'��
		case '/':
			while (!stackempty(Optr))	//ջ����ѭ��
			{
				gettop(Optr,e);	//ȡջ��Ԫ��e
				if (e == '*' || e == '/')
				{
					postexp[i++] = e;	//��e��ŵ�postexp��
					pop(Optr,e);	//��ջԪ��e
				}
				else			//eΪ��'*'��'/'�����ʱ�˳�ѭ��
					break;
			}
			push(Optr,* exp);		//��'*'��'/'��ջ
			exp++;			//����ɨ�������ַ�
			break;
		default:				//���������ַ�
			while (*exp >= '0' && *exp <= '9') //�ж�Ϊ�����ַ�
			{
				postexp[i++] = *exp;
				exp++;
			}
			postexp[i++] = '#';	  	//��#��ʶһ����ֵ������
		}
	}
	while (!stackempty(Optr))	  	//��ʱexpɨ����ϣ�ջ����ʱѭ��
	{
		pop(Optr,e);		 	//��ջԪ��e
		postexp[i++] = e;	  		//��e��ŵ�postexp��
	}
	postexp[i] = '\0';		  	//��postexp���ʽ��ӽ�����ʶ
	destroy(Optr);	  		//����ջ
}*/
double compvalue(char* postexp)
{
	double d, a, b, c, e;
	sqstack* Opnd;			//���������ջ
	initstack(Opnd);			//��ʼ��������ջ
	while (*postexp != '\0')		//postexp�ַ���δɨ����ʱѭ��
	{
		switch (*postexp)
		{
		case '+':				//�ж�Ϊ'+'��
			pop1(Opnd,a);			//��ջԪ��a
			pop1(Opnd,b);			//��ջԪ��b
			c = b + a;				//����c
			push1(Opnd,c);			//��������c��ջ
			break;
		case '-':			//�ж�Ϊ'-'��
			pop1(Opnd,a);		//��ջԪ��a
			pop1(Opnd,b);		//��ջԪ��b
			c = b - a;			//����c
			push1(Opnd,c);		//��������c��ջ
			break;
		case '*':			//�ж�Ϊ'*'��
			pop1(Opnd,a);		//��ջԪ��a
			pop1(Opnd,b);		//��ջԪ��b
			c = b * a;			//����c
			push1(Opnd,c);		//��������c��ջ
			break;
		case '/':			//�ж�Ϊ'/'��
			pop1(Opnd,a);		//��ջԪ��a
			pop1(Opnd,b);		//��ջԪ��b
			if (a != 0)
			{
				c = b / a;			//����c
				push1(Opnd,c);		//��������c��ջ
				break;
			}
			else
			{
				printf("\n\t�������!\n");
				exit(0);			//�쳣�˳�
			}
			break;
		default:			//���������ַ�
			d = 0;			//ת���ɶ�Ӧ����ֵ��ŵ�d��
			while (*postexp >= '0' && *postexp <= '9')
			{
				d = 10 * d + *postexp - '0';
				postexp++;
			}
			push1(Opnd,d);	//����ֵd��ջ
			break;
		}
		postexp++;		//�������������ַ�
	}
	gettop1(Opnd,e);		//ȡջ��Ԫ��e
	destroy(Opnd);		//����ջ
	return e;			//����e
}