#include<iostream>
#include<sstream>
#include<string>
using namespace std;
//表结点
struct ArcNode {
    int adjvex;      //某条边指向的那个顶点的位置（一般是数组的下标）。
    ArcNode * next;  //指向下一个表结点
    int weight;      //边的权重
};

//头结点
struct Vnode {
    ArcNode * firstarc;  //第一个和该顶点依附的边 的信息
    string data;       //记录该顶点的信息。
};

//邻接表 
struct Graph_List {
    int vexnum;     //顶点个数
    int edge;       //边的条数
    Vnode * node;  //顶点表
};

//创建图，是一个重载函数
void createGraph(Graph_List &g) {
    cout << "请输入顶点数："<<"\n"<<"输入顶点边的个数：" << endl;
    cin >> g.vexnum;
    cin >> g.edge;
    g.node = new Vnode[g.vexnum];
    int i=0;
    string t;
    //注意这里stringstream也需要清空缓存
	//但是clear()函数并不能清空缓存，需要str("")即将缓存清成空字符串 
    for (i = 0; i < g.vexnum; i++) {
    	stringstream ss;
    	int j=i+1;
    	ss<<j;
    	ss>>t;
    	//ss.str("");
    	cout<<t<<endl;
        g.node[i].data = "v" + t;//std::to_string(i + 1);  //对每个顶点进行命名
        cout<<"加入顶点"<<g.node[i].data<<endl;
        g.node[i].firstarc = NULL;//初始化每个顶点的依附表结点
    }

    cout << "请输入每条边之间的顶点编号(顶点编号从1开始),以及该边的权重：" << endl;
    for (i = 0; i < g.edge; i++) {
        int start;
        int end;
        cin >> start;   //输入每条边的起点
        cin >> end;     //输入每条边的终点
        int weight;
        cin >> weight;

        ArcNode * next = new ArcNode;
        next->adjvex = end - 1;
        next->next = NULL;
        next->weight = weight;
        //如果第一个依附的边为空
        if (g.node[start - 1].firstarc == NULL) {
            g.node[start - 1].firstarc = next;
        }
        else {
            ArcNode * temp; //临时表结点
            temp = g.node[start - 1].firstarc;
            while (temp->next) {//找到表结点中start-1这个结点的链表的最后一个顶点
                temp = temp->next;
            }
            temp->next = next;  //在该链表的尾部插入一个结点


        }
        //因为无向图边是双向的
        ArcNode * next_2 = new ArcNode;
        next_2->adjvex = start - 1;
        next_2->weight = weight;
        next_2->next = NULL;

        //如果第一个依附的边为空
        if (g.node[end - 1].firstarc == NULL) {
            g.node[end - 1].firstarc = next_2;
        }
        else {
            ArcNode * temp; //临时表结点
            temp = g.node[end - 1].firstarc;
            while (temp->next) {//找到表结点中start-1这个结点的链表的最后一个顶点
                temp = temp->next;
            }
            temp->next = next_2;  //在该链表的尾部插入一个结点


        }
    }
}

void print(Graph_List g) {
    cout<<"图的邻接表："<<endl;
    for (int i = 0; i < g.vexnum; i++) {
        cout << g.node[i].data << " ";
        ArcNode * next;
        next = g.node[i].firstarc;
        while (next) {
            cout << "("<< g.node[i].data <<","<<g.node[next->adjvex].data<<")="<<next->weight << " ";
            next = next->next;
        }
        cout << "^" << endl;
    }
}

////作为记录边的信息，这些边都是达到end的所有边中，权重最小的那个
struct Assis_array {
    int start; //边的终点
    int end;  //边的起点
    int weight;  //边的权重
};

void Prim(Graph_List g, int begin) {
    cout << "图的最小生成树：" << endl;
    //close_edge这个数组记录到达某个顶点的各个边中的权重最大的那个边
    Assis_array *close_edge=new Assis_array[g.vexnum];
    int j;
    for (j = 0; j < g.vexnum; j++) {
        close_edge[j].weight = INT_MAX;
    }
    ArcNode * arc = g.node[begin - 1].firstarc;

    while (arc) {
        close_edge[arc->adjvex].end = arc->adjvex;
        close_edge[arc->adjvex].start = begin - 1;
        close_edge[arc->adjvex].weight = arc->weight;
        arc = arc->next;
    }
    //把起点的close_edge中的值设置为-1，代表已经加入到集合U了
    close_edge[begin - 1].weight = -1;
    //访问剩下的顶点，并加入依次加入到集合U
    for (j = 1; j < g.vexnum; j++) {
        int min = INT_MAX;
        int k;
        int index;
        //寻找数组close_edge中权重最小的那个边
        for (k = 0; k < g.vexnum; k++) {
            if (close_edge[k].weight != -1) {
                if (close_edge[k].weight < min) {
                    min = close_edge[k].weight;
                    index = k;
                }
            }
        }

        //输出对应的边的信息
        cout << g.node[close_edge[index].start].data
            << "-----"
            << g.node[close_edge[index].end].data
            << "="
            << close_edge[index].weight
            <<endl;
        //将权重最小的那条边的终点也加入到集合U
        close_edge[index].weight = -1;
        //更新我们的close_edge数组。            
        ArcNode * temp = g.node[close_edge[index].end].firstarc;
        while (temp) {
            if (close_edge[temp->adjvex].weight > temp->weight) {
                close_edge[temp->adjvex].weight = temp->weight;
                close_edge[temp->adjvex].start = index;
                close_edge[temp->adjvex].end = temp->adjvex;
            }
            temp = temp->next;
        }
    }

}

