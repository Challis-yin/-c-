
#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100
typedef int Vertex;
typedef int WeightType;
typedef char DataType;
bool Visited[]={false};
 
//边的定义
typedef struct ENode * PtrToENode;
struct ENode{
	Vertex V1,V2;
	WeightType Weight;
}; 
typedef PtrToENode Edge;
 
 
//邻接点的定义 
typedef struct AdjVNode * PtrToAdjVNode;
struct AdjVNode{
	Vertex AdjV;//邻接点下标 
	WeightType Weight;
	PtrToAdjVNode Next; 
}; 
 
//顶点表头节点的定义
typedef struct Vnode{
	PtrToAdjVNode FirstEdge;
	DataType Data;
}AdjList[MaxVertexNum]; 
 
//图结点的定义 
typedef struct GNode * PtrToGNode;
struct GNode {
	int Nv;			//定点数 
	int Ne;			//边数 
	AdjList G;		//邻接表 
}; 
typedef PtrToGNode LGraph;
 
//初始化一个有VertexNum个顶点但没有边的图
LGraph CreateGraph(int VertexNum){
	Vertex V;
	LGraph Graph;
	
	Graph=(LGraph)malloc(sizeof(struct GNode));
	Graph->Nv=VertexNum;
	Graph->Ne=0;
	
	//初始化邻接表头指针
	for(V=0;V<Graph->Nv;V++)
		Graph->G[V].FirstEdge=NULL;
	return Graph; 
} 
 
//插入边
void InsertEdge(LGraph Graph,Edge E){
	PtrToAdjVNode NewNode;
	
	NewNode=(PtrToAdjVNode)malloc (sizeof(struct AdjVNode));
	NewNode->AdjV=E->V2;
	NewNode->Weight=E->Weight;
	NewNode->Next=Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge=NewNode;
	
	//若是无向图，还要插入边<V2,V1>
	//位V1建立新的邻接点
	NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV=E->V1;
	NewNode->Weight=E->Weight;
	//将V1插入V2的表头
	NewNode->Next=Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge=NewNode; 
} 
 
LGraph BuildGraph(){
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv,i;
	
	printf("请输入顶点个数\n");
	scanf("%d",&Nv);
	Graph=CreateGraph(Nv);
	
	printf("读入边数\n");
	scanf("%d",&(Graph->Ne));
	if(Graph->Ne!=0){//如果有边 
		E=(Edge)malloc(sizeof(struct ENode));
		for(i=0;i<Graph->Ne;i++){
			printf("读入边，格式为“起点 终点 权重”:\n ");
			scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
			InsertEdge(Graph,E);
		}
	}
	
	//如果顶点有数据的话，读入数据
	//for(V=0;V<Graph->Nv;V++)
	//	scanf("%c",&(Graph->G[V].Data));
	
	return Graph; 
}
 
//邻接表存储图的深度优先遍历
void Visit(Vertex V){
	printf("正在访问顶点%d\n",V);
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

