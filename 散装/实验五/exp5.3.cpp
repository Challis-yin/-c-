#include<iostream>
#include"exp5.2.0.h"
using namespace std;

int main()
{
	cout<<"������ͼ�Ķ�����"<<endl;
	int n;
	cin>>n;
	cin.sync();
	graph g(n);
	cout<<"������һ����"<<n<<"�������ͼ"<<endl;
	
	int start=0,end;
	while(start!=-1){
		cout<<"������ߵ�ͷ�ڵ��β�ڵ�(����������-1)"<<endl;

		cin>>start;
		if(start==-1)break;
		
		cin>>end;
		g.addEdge(start,end);
		cout<<"��ͼ������һ����"<<start<<"->"<<end<<endl;
		cin.sync();
	}
	
	/*
	graph g(4);
	g.addEdge(0, 1);//ע�͸��У�����������ͼ��ڶ�ͼ��ʾ
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);*/
 
    cout<<"����������Ŀ�궥��"<<endl;
    int s,e;
    cin.sync();
    cin>>s;
    cin>>e;
	if (g.BFS(s, e))
		cout << "yes" << endl;
	
	else 
		
		cout << "no" << endl;

	return 0;
}

