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
//��ʮ���� ***���Ǽ���ֻ�мӼ��˳����� 
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
				cout<<"ջ��������";
			}
		}
	}
	if(!s->empty())
		return s->top();
	else
		throw Nomem();
}
//
//��ʮ���� ������ǰ����������һ���� 
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
//�ڶ�ʮ�� 
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
//�İ�һʮ��ҳ 
//38��
//
/*
1.
	�����u�����ϣ���Ϊÿ�����Ͻ���һ��Ԫ�أ��������м��ϵ�
	��Ԫ�ظ���С��u+1.
2.
	��Ϊÿ������Ԫ�ز���ͬ����������Ƕ�����һ�����ϵ��У����Ժϲ���Ҫn-1��
3.
	��Ϊ�ϲ����ڶ���֮N�Σ����Դ��ڵ�Ԫ�ؼ���
4.
	���ϲ�N��ʱ����Ҫ���ļ��ٵ�Ԫ�ؼ��ϣ����İ취���ǵ�Ԫ�ؼ����뵥Ԫ�ؼ��Ϻϲ�
	���Ա��ʽ���� 
*/ 

//
//����ʮ���� 
// 

//
//����ʮ����
//

//
//����ʮ���� 
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













