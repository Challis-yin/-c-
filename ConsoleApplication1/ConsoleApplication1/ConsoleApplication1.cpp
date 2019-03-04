// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
//表头节点
struct vnode {
	char data;
	struct arcnode * firstarc;
};
//边节点
struct arcnode {
	int wt;
	int adjvex;
	struct arcnode *nextarc;
};

typedef struct arcnode * Arc;
//定义一个图
struct mgraph {
	struct vnode vexs[100];
	int vexsnum, arcnum;
} *g;
typedef struct mgraph* Graph;


int findadj(char vexs, Graph g) {
	int i;
	for (i = 1; i <= g->vexsnum; i++) {
		if (vexs == g->vexs[i].data)
			break;
	}
	return i;
}

Graph creategraph() {
	Graph g1;
	char vex;
	g1 = (Graph)malloc(sizeof(struct mgraph));
	g1->arcnum = 0;
	g1->vexsnum = 0;
	cout << "输入顶点，输入-代表结束\n";
	cin >> vex;    //输入顶点
	while (vex != '-') {         //输入-后循环结束
		g1->vexsnum++;
		g1->vexs[g1->vexsnum].data = vex;      //这里的结构数组vexs[]下标从1开始
		g1->vexs[g1->vexsnum].firstarc = NULL;
		cout << "输入下一个顶点，输入-代表结束\n";
		cin >> vex;         //%c前面加空格防止读取回车
	}
	int i;
	int w;           //边的权重
	int adjvex;    //顶点的下标
	char avex;    //边的另一个顶点
	Arc p, b;
	for (i = 1; i <= g1->vexsnum; i++) {
		cout << "输入";
		cout << (char)(g1->vexs[i].data);
		cout << "的相邻顶点，输入-代表结束" << endl;
		//g1->vexs[i].data;
		cin >> avex;
		while (avex != '-') {    //输入-后循环结束
			adjvex = findadj(avex, g1);
			cout << "输入边";
			cout << g1->vexs[i].data;
			cout << "的权重\n";
			//  g1->vexs[i].data,avex;
			cin >> w;
			b = (Arc)malloc(sizeof(struct arcnode));
			b->adjvex = adjvex;
			b->wt = w;
			b->nextarc = NULL;
			//链表追加结点
			p = g1->vexs[i].firstarc;
			if (p != NULL) {
				while (p->nextarc != NULL)
					p = p->nextarc;
				p->nextarc = b;
			}
			else
				g1->vexs[i].firstarc = b;
			g1->arcnum++;
			cout << "输入";
			cout << g1->vexs[i].data;
			cout << "的相邻顶点，输入-代表结束";//,g1->vexs[i].data);
			cin >> avex;
		}
	}
	return g1;
}

//
//输出
//

void printg(Graph g)
{
	int i, k;
	Arc p;
	cout << "********邻接表**********" << endl;
	int nn = g->vexsnum;
	for (int i = 0; i < nn; i++)
	{
		cout << "eeee";
		cout << g->vexs[i].data;
		p = g->vexs[i].firstarc;
		while (p != NULL)
		{
			cout << "->    ";
			k = p->adjvex;
			cout << g->vexs[k].data;
			cout << " ";
			cout << p->wt;
			cout << "     ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "************************\n";
	cout << "顶点总数为:   ";
	cout << g->vexsnum << endl;
	cout << "边的总条数为:  ";
	cout << g->arcnum << endl;
}

int main()
{
	g = creategraph();
	cout << g->vexs[0].data;
	//printg(g);
	//cout << "Hello world!" << endl;
	return 0;
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
