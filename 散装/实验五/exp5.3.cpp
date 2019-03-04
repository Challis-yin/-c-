#include<iostream>
#include"exp5.2.0.h"
using namespace std;

int main()
{
	cout<<"请输入图的顶点数"<<endl;
	int n;
	cin>>n;
	cin.sync();
	graph g(n);
	cout<<"创建了一个有"<<n<<"个顶点的图"<<endl;
	
	int start=0,end;
	while(start!=-1){
		cout<<"请输入边的头节点和尾节点(结束请输入-1)"<<endl;

		cin>>start;
		if(start==-1)break;
		
		cin>>end;
		g.addEdge(start,end);
		cout<<"向图中输入一条边"<<start<<"->"<<end<<endl;
		cin.sync();
	}
	
	/*
	graph g(4);
	g.addEdge(0, 1);//注释该行，构建的有向图如第二图所示
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);*/
 
    cout<<"请输入两个目标顶点"<<endl;
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

