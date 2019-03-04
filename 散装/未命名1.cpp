#include <iostream>
using namespace std;

template<class T>
T* copy(T* arr){
	int n = sizeof(arr) / sizeof(arr[0]);
	T * now = new T[n];
	for(int i = 0;i<n;i++){
		now[i] = arr[i];
	}
	return now;
} 
//
//第十四题 ***我们假设只有加减乘除运算 
//
template<class T>
int calculate(binaryTreeNode<T> *t)
{	char *zu = new char[100];
	int n = 0;
	if(t!=NULL){
		calculate(t->leftchild);
		calculate(t->rightchild);
		zu[n++] = t->value;
	} 
	arrayStack<int>* s = new arrayStack<int> (n);
	for(int i = 0;i<n;i++){
		if(zu[i]!="+"&&zu[i]!="*"&&zu[i]!="-"&&zu[i]!="/"){
			s->push(zu[i]);
		}
		else{
			try{
				int a = s->top();
				s->pop();
				int b = s->top();
				s->pop();
				s->push(a*b);
			}
			catch(stackEmpty()){
				cout<<"栈中无数据";
			}
		}
	}
	if(!s->empty())
		return s->top();
	else
		throw Nomem();
}
//
//第十九题 ，给定前序与中序构造一个树 
//
int* Find(int a,int *pre,int *inor)
{
	int *tree = new int[a];
	int n = 1;
	
}
int* find(int tree,int *pre,int *inor,int prestart,int preend,int instart,int inend,int &n)
{
	
}
//
//第二十题 
//
char* houxu(char* arr)
{
	int n = sizeof(arr) / sizeof(arr[0]);
	int c = 0; 
	char * now = new T[n]; 
	arrayStack<int>* s = new arrayStack<int> (n);
	for(int i = 0;i<n;i++){
		if(char[i]!="+"&&char[i]!="-"&&char[i]!="*"
		&&char[i]!="/"&&char[i]!="("&&char[i]!=")")
			now[c++] = char[i];
		try{
			if(s->empty()){
				s->push(arr[i]);
			}
			if(gety(arr[i])==0){
				while(gety(s->top())!=-1){
					now[c++] = s->top();
					s->pop();}
					s->pop();}
			else if(gety(arr[i])>gety(s->top()))
				if(arr[i]!=-1)
					now[c++] = arr[i];
			else{
				if(arr[i]!=-1){
					now[c++] = s->top();
					s->pop();
					s->push(arr[i]);
					}
				}
			}
			catch(NoMem()){
				cout<<"IsEmptyWhenYouNeed";
			}
		}
		return now;
	}

int gety(char x){
	if(x == "*"&&x=="/"){
		return 2;
	}
	else if(x=="+"&&x=="-")
		return 1;
	else if(x=="(")
		return -1;
	else if(x==")")
		return 0;
}
//
//四百一十五页 
//38题
//
/*
1.
	如果有u个集合，因为每个集合仅有一个元素，所以所有集合的
	总元素个数小于u+1.
2.
	因为每个集合元素不相同，最多的情况是都脸到一个集合当中，所以合并需要n-1次
3.
	因为合并少于二分之N次，所以存在单元素集合
4.
	当合并N次时，想要最快的减少单元素集合，最快的办法就是单元素集合与单元素集合合并
	所以表达式成立 
*/ 

//
//第三十九题 
// 

//
//第四十二题
//

//
//第四十五题 
// 
int find(int theElement)
{
	int root = theElement;
	while(!node[root].root){
		root = node[root].parent;
	}
	int currentNode = theElement;
	while (currentNode!=root){
		int father = node[currentNode].parent;
		node[currentNode].parent = nede[father].parent;
		currentNode = father;
	}
	
	return root;
} 













