
#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100
typedef int Vertex;
typedef int WeightType;
typedef char DataType;
bool Visited[]={false};
 
//�ߵĶ���
typedef struct ENode * PtrToENode;
struct ENode{
	Vertex V1,V2;
	WeightType Weight;
}; 
typedef PtrToENode Edge;
 
 
//�ڽӵ�Ķ��� 
typedef struct AdjVNode * PtrToAdjVNode;
struct AdjVNode{
	Vertex AdjV;//�ڽӵ��±� 
	WeightType Weight;
	PtrToAdjVNode Next; 
}; 
 
//�����ͷ�ڵ�Ķ���
typedef struct Vnode{
	PtrToAdjVNode FirstEdge;
	DataType Data;
}AdjList[MaxVertexNum]; 
 
//ͼ���Ķ��� 
typedef struct GNode * PtrToGNode;
struct GNode {
	int Nv;			//������ 
	int Ne;			//���� 
	AdjList G;		//�ڽӱ� 
}; 
typedef PtrToGNode LGraph;
 
//��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ
LGraph CreateGraph(int VertexNum){
	Vertex V;
	LGraph Graph;
	
	Graph=(LGraph)malloc(sizeof(struct GNode));
	Graph->Nv=VertexNum;
	Graph->Ne=0;
	
	//��ʼ���ڽӱ�ͷָ��
	for(V=0;V<Graph->Nv;V++)
		Graph->G[V].FirstEdge=NULL;
	return Graph; 
} 
 
//�����
void InsertEdge(LGraph Graph,Edge E){
	PtrToAdjVNode NewNode;
	
	NewNode=(PtrToAdjVNode)malloc (sizeof(struct AdjVNode));
	NewNode->AdjV=E->V2;
	NewNode->Weight=E->Weight;
	NewNode->Next=Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge=NewNode;
	
	//��������ͼ����Ҫ�����<V2,V1>
	//λV1�����µ��ڽӵ�
	NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV=E->V1;
	NewNode->Weight=E->Weight;
	//��V1����V2�ı�ͷ
	NewNode->Next=Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge=NewNode; 
} 
 
LGraph BuildGraph(){
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv,i;
	
	printf("�����붥�����\n");
	scanf("%d",&Nv);
	Graph=CreateGraph(Nv);
	
	printf("�������\n");
	scanf("%d",&(Graph->Ne));
	if(Graph->Ne!=0){//����б� 
		E=(Edge)malloc(sizeof(struct ENode));
		for(i=0;i<Graph->Ne;i++){
			printf("����ߣ���ʽΪ����� �յ� Ȩ�ء�:\n ");
			scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
			InsertEdge(Graph,E);
		}
	}
	
	//������������ݵĻ�����������
	//for(V=0;V<Graph->Nv;V++)
	//	scanf("%c",&(Graph->G[V].Data));
	
	return Graph; 
}
 
//�ڽӱ�洢ͼ��������ȱ���
void Visit(Vertex V){
	printf("���ڷ��ʶ���%d\n",V);
} 
 
void DFS(LGraph Graph,Vertex V,void(*Visit)(Vertex)){
	PtrToAdjVNode W;
	
	Visit(V);
	Visited[V]=true;
	
	for(W=Graph->G[V].FirstEdge;W;W=W->Next){
		if(!Visited[W->AdjV])
			DFS(Graph,W->AdjV,Visit);
	}
}
 
int main()
{
	LGraph Graph;
	Graph = BuildGraph();
	int v=0;
	DFS(Graph,v,Visit);
	return 0;
}

