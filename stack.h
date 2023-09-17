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
    sqstack* Optr;			//定义运算符栈指针
	initstack(Optr);			//初始化运算符栈
	int i = 0;				//i作为postexp的下标
	while (*exp!='\0')			//exp表达式未扫描完时循环
	{
		switch (*exp)
		{
		case '(':				//判定为左括号
			push(Optr,'e');		//左括号进栈
			exp++;			//继续扫描其他字符
			break;
		case ')':		   	//判定为右括号
			pop(Optr,e);	    	//出栈元素e
			while (e != '(')	    	//不为'('时循环
			{
				postexp[++i] = e;		//将e存放到postexp中
				pop(Optr,e);	   	//继续出栈元素e
			}
			exp++;		     	//继续扫描其他字符
			break;
		case '+':				//判定为加或减号
		case '-':
			while (!stackempty(Optr))		//栈不空循环
			{
				gettop(Optr,e);			//取栈顶元素e
				if (e != '(')			//e不是'('
				{
					postexp[i++] = e;		//将e存放到postexp中
					pop(Optr,e);		//出栈元素e
				}
				else				//e是'(时退出循环
					break;
			}
			push(Optr, *exp);		//将'+'或'-'进栈
			exp++;				//继续扫描其他字符
			break;
		case '*':				//判定为'*'或'/'号
		case '/':
			while (!stackempty(Optr))	//栈不空循环
			{
				gettop(Optr,e);	//取栈顶元素e
				if (e == '*' || e == '/')
				{
					postexp[i++] = e;	//将e存放到postexp中
					pop(Optr,e);	//出栈元素e
				}
				else			//e为非'*'或'/'运算符时退出循环
					break;
			}
			push(Optr,* exp);		//将'*'或'/'进栈
			exp++;			//继续扫描其他字符
			break;
		default:				//处理数字字符
			while (*exp >= '0' && *exp <= '9') //判定为数字字符
			{
				postexp[i++] = *exp;
				exp++;
			}
			postexp[i++] = '#';	  	//用#标识一个数值串结束
		}
	}
	while (!stackempty(Optr))	  	//此时exp扫描完毕，栈不空时循环
	{
		pop(Optr,e);		 	//出栈元素e
		postexp[i++] = e;	  		//将e存放到postexp中
	}
	postexp[i] = '\0';		  	//给postexp表达式添加结束标识
	destroy(Optr);	  		//销毁栈
}*/
double compvalue(char* postexp)
{
	double d, a, b, c, e;
	sqstack* Opnd;			//定义操作数栈
	initstack(Opnd);			//初始化操作数栈
	while (*postexp != '\0')		//postexp字符串未扫描完时循环
	{
		switch (*postexp)
		{
		case '+':				//判定为'+'号
			pop1(Opnd,a);			//出栈元素a
			pop1(Opnd,b);			//出栈元素b
			c = b + a;				//计算c
			push1(Opnd,c);			//将计算结果c进栈
			break;
		case '-':			//判定为'-'号
			pop1(Opnd,a);		//出栈元素a
			pop1(Opnd,b);		//出栈元素b
			c = b - a;			//计算c
			push1(Opnd,c);		//将计算结果c进栈
			break;
		case '*':			//判定为'*'号
			pop1(Opnd,a);		//出栈元素a
			pop1(Opnd,b);		//出栈元素b
			c = b * a;			//计算c
			push1(Opnd,c);		//将计算结果c进栈
			break;
		case '/':			//判定为'/'号
			pop1(Opnd,a);		//出栈元素a
			pop1(Opnd,b);		//出栈元素b
			if (a != 0)
			{
				c = b / a;			//计算c
				push1(Opnd,c);		//将计算结果c进栈
				break;
			}
			else
			{
				printf("\n\t除零错误!\n");
				exit(0);			//异常退出
			}
			break;
		default:			//处理数字字符
			d = 0;			//转换成对应的数值存放到d中
			while (*postexp >= '0' && *postexp <= '9')
			{
				d = 10 * d + *postexp - '0';
				postexp++;
			}
			push1(Opnd,d);	//将数值d进栈
			break;
		}
		postexp++;		//继续处理其他字符
	}
	gettop1(Opnd,e);		//取栈顶元素e
	destroy(Opnd);		//销毁栈
	return e;			//返回e
}