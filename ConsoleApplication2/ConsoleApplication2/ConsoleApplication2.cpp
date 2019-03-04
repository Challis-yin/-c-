// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo.h>
typedef struct Polynode
{
	int coef;
	int exp;
	struct Polynode *next;
}Polynode, *Polylist;
// 初始化多项式
bool InitPoly(Polylist *Poly) // 二级指针
{
	*Poly = (Polylist)malloc(sizeof(Polynode));  //产生头结点，并使L指向此头节点
	if (!(*Poly))   // 存储分配失败
		return false;
	(*Poly)->next = NULL;
	return true;
}

// 外插法建立一元多项式单链表,n代表多项式非零系数的个数
void PolyCreate(Polylist head, int n)
{
	Polynode *rear, *s;  //rear为尾指针，s为新结点指针
	int c, e;
	rear = head;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %d", &c, &e);
		s = (Polynode*)malloc(sizeof(Polynode));
		s->coef = c;
		s->exp = e;
		rear->next = s;  // 当前结点作为表尾插入
		rear = s;        //  插入的结点作为新的尾节点
	}
	rear->next = NULL;   // 将表尾的最后一个结点置为空

}

// 多项式相加
void Polyadd(Polylist polya, Polylist polyb)
{
	Polynode *p, *q, *pre, *temp;
	int sum;
	p = polya->next; // p指向polya第一个结点
	q = polyb->next; // q指向polyb第一个结点
	pre = polya;     // pre表示和多项式的尾节点,初始与polya相同
	while (p != NULL && q != NULL)
	{
		if (p->exp > q->exp)  // a的结点加入和多项式
		{
			pre->next = p;   // p所指的结点加入和多项式
			pre = p;         // pre向后移动，尾插
			p = p->next;     // 扫描下一个p
		}
		else if (p->exp == q->exp)  // 系数相等，对应系数相加
		{
			sum = p->coef + q->coef;
			if (sum != 0)
			{
				p->coef = sum;   // 修改p
				pre->next = p;   // 将p加入表尾
				pre = p;
				p = p->next;     // p向后移动
				temp = q;
				q = q->next;
				free(temp);      // 释放系数相同的q结点
			}
			else
			{
				// 系数相同情况
				temp = p;
				p = p->next;
				free(temp); // 释放原来p指针
				temp = q;
				q = q->next;
				free(temp);
			}
		}
		else
		{
			pre->next = q;  //将q加入到和多项式尾部
			pre = q;        // 将pre移动到q
			q = q->next;
		}
	}
	if (p != NULL)
		pre->next = p; // 将p剩余结点加入到和多项式
	else
		pre->next = q;
}

Polynode* In_reverseList(Polynode* H)
{
	if (H == NULL || H->next == NULL)//链表为空直接返回，而H->next为空是递归基
	{

		return H;
	}
	Polynode* newHead = In_reverseList(H->next); //一直循环到链尾 
	H->next->next = H;                       //翻转链表的指向
	H->next = NULL;                          //记得赋值NULL，防止链表错乱
	return newHead;                          //新链表头永远指向的是原链表的链尾
}
//
void PrintPoly(Polylist poly)
{
	Polynode *p;
	p = poly->next;
	std::cout << "(" << p->coef << "X^" << p->exp << ")+";
	p = p->next;
	while (p != NULL)
	{

		if (p->next != NULL)
			std::cout << "(" << p->coef << "X^" << p->exp << "）+";
		else
			std::cout << "(" << p->coef << "X^" << p->exp << ")";
		p = p->next;
	}
	printf("\n");

}
void PrintPoly2(Polynode* poly)
{
	//Polynode *p;
	//p = poly->next;
	std::cout << "(" << poly->coef << "X^" << poly->exp << ")+";
	poly = poly->next;
	//std::cout << "为空\n";
	while (poly != NULL)
	{
		//std::cout << "不为空\n";
		if (poly->next != NULL)
		{
			if (poly->next->next == NULL)
			{
				std::cout << "(" << poly->coef << "X^" << poly->exp << "）";
				goto part2;
			}
			else
				std::cout << "(" << poly->coef << "X^" << poly->exp << "）+";
		}
		else
			std::cout << "(" << poly->coef << "X^" << poly->exp << ")";
		poly = poly->next;
	}
part2:
	printf("\n");

}

int main()
{
	Polylist Polya, Polyb;
	int n, m;
	InitPoly(&Polya);
	InitPoly(&Polyb);
	std::cout << "输入第1个多项式的项数";
	std::cin >> n;
	std::cout << "请输入第1个多项式的各项";
	PolyCreate(Polya, n);
	std::cout << "输入第2个多项式的项数";
	std::cin >> m;
	std::cout << "请输入第2个多项式的各项";
	PolyCreate(Polyb, m);
	std::cout << "是否运行加法	1、0";
	int ppp;
	std::cin >> ppp;
	if(ppp == 1)
		Polyadd(Polya, Polyb);
	PrintPoly(Polya);
	std::cout << "倒置	0、1";
	std::cin >> ppp;
	if(ppp == 1)
		PrintPoly2(In_reverseList(Polya));


}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
