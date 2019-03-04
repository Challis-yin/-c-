#include <iostream>
#include <list>
 
using namespace std;
 
class graph
{
public:
	graph(int v) :vertex(v){
		adj = new list<int>[v];
	}
 
	void addEdge(int v, int w);
	bool BFS(int vStart, int vEnd);
 
private:
	int vertex;
	list<int> *adj;
};
 
//v:边的首顶点；w：边的尾顶点
void graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

bool graph::BFS(int vStart, int vEnd)
{
	bool *visited = new bool[vertex];
	//memset(visited, false, vertex);
	//这里的意思应该是初始化visited数组
	for(int i=0;i<vertex;i++){
		visited[i]=false;
	} 
 
	list<int> queue;//利用链表构建一个队列
 
	visited[vStart] = true;//表示开始访问
	queue.push_back(vStart);//开始顶点入队
 
	list<int>::iterator iter;
 
	//队列中的顶点就是访问的顶点
	while (!queue.empty())
	{
		vStart = queue.front();//这里有个优先级，邻接表中链表的头节点优先级最高，依次降低
		queue.pop_front();//已访问顶点出队
 
		if (vStart == vEnd)//如果已访问的顶点恰好是指定目的顶点则表明有路径
			return true;
 
		//将与开始顶点最近的顶点，也就是链表中的顶点依次入队
		for (iter = adj[vStart].begin(); iter != adj[vStart].end(); ++iter)
		{
			if (!visited[*iter])
			{
				visited[*iter] = true;//标记即将访问，事实上，进入队列了就是要访问的
				queue.push_back(*iter);//从链表头节点到尾节点依次入队
			}
		}
	}
	return false;
}



