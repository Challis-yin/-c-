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
 
//v:�ߵ��׶��㣻w���ߵ�β����
void graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

bool graph::BFS(int vStart, int vEnd)
{
	bool *visited = new bool[vertex];
	//memset(visited, false, vertex);
	//�������˼Ӧ���ǳ�ʼ��visited����
	for(int i=0;i<vertex;i++){
		visited[i]=false;
	} 
 
	list<int> queue;//����������һ������
 
	visited[vStart] = true;//��ʾ��ʼ����
	queue.push_back(vStart);//��ʼ�������
 
	list<int>::iterator iter;
 
	//�����еĶ�����Ƿ��ʵĶ���
	while (!queue.empty())
	{
		vStart = queue.front();//�����и����ȼ����ڽӱ��������ͷ�ڵ����ȼ���ߣ����ν���
		queue.pop_front();//�ѷ��ʶ������
 
		if (vStart == vEnd)//����ѷ��ʵĶ���ǡ����ָ��Ŀ�Ķ����������·��
			return true;
 
		//���뿪ʼ��������Ķ��㣬Ҳ���������еĶ����������
		for (iter = adj[vStart].begin(); iter != adj[vStart].end(); ++iter)
		{
			if (!visited[*iter])
			{
				visited[*iter] = true;//��Ǽ������ʣ���ʵ�ϣ���������˾���Ҫ���ʵ�
				queue.push_back(*iter);//������ͷ�ڵ㵽β�ڵ��������
			}
		}
	}
	return false;
}



