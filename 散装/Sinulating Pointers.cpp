#include<iostream>
using namespace std;
/*
ģ��ָ�� 
*/
template <class T>
class SimNode 
{
	friend SimSpace<T>
	private:
		T data;
		int link;
};

template <class T>
class SimSpace
{
	public:
		SimSpace(int MaxSpaceSize = 100);
		~SimSpace(){delete [] node;}
		int Allocate();
		void Deallocate(int& i);
	private:
		int NumberOfNode,first;
		SimNode<T> *node;
};

/*
	���졢�������� 
*/

template <class T>
SimSpace<T>::SimSpace(int MaxSpaceSize)
{
	NumberOfNodes = MaxSpaceSize;
	node = new SimNode<T> [NumberOfNode];
	for(int i = 0;i<NumberOfNodes-1;i++){
		node[i].link = i+1;
	}
	node[NumberOfNodes-1].link = -1;
	first = 0;
}

/*
�����³�Ա 
*/

template <class T>
int SimSpace<T>::Allocate()
{
	if(first==-1) throw OutOfBounds();
	int i = first;
	first = node[i].link;
	
	return i;
}

/*
 ������� 
*/

template <class T>
int SimSpace<T>::Deallocate(int& i)
{
	node[i].link = first;
	first = i;
	i = -1;
}

/*

*/

template <class T>









































