#include<iodtream>
using namespace std;
//
//第八题
//
void changeMax(const int & newElement)
{
	heap[1] = new Element;
	int n = sizeof(heap)/sizeof(heap[1]);
	int i = 1;
	int y = i;
	while((heap[i]<heap[2*i]||heap[i]<heap[2*i+1])&&(2*i+1>n||2*i>n)){
		if(2*i+1<n){
			if(heap[2*i]>heap[2*i+1]){
			int temp = heap[2*i];
			heap[2*i] = heap[i];
			heap[i] = temp;
			i = 2*i;
		}
			else{
				int temp = heap[2*i+1];
				heap[2*i+1] = heap[i];
				heap[i] = temp;
				i = 2*i+1;
			}
		}
		else
			if(heap[2*i]>heap[2*i+1]){
				int temp = heap[2*i];
				heap[2*i] = heap[i];
				heap[i] = temp;
				i = 2*i;
	}
 } 
//
//第十题 
//
int max(int * theHeap,int n)
{
	int max = theHeap[0];
	for(int i = 1;i<n;i++) {
		if(max<theHeap[i])
			max = theHeap[i];
	}
	return max;
}

int min(int * theHeap,int n)
{
	int max = theHeap[0];
	for(int i = 1;i<n;i++) {
		if(max>theHeap[i])
			max = theHeap[i];
	}
	return max;
}

void maxHeap::initialize(int* theHeap,int n)
{
	delete heap;
	heap = theHeap;
	
	heap[0] = max(heap,n);
//	
	for(int root = n/2;root>=1;root--){
		int rootElement = heap[root];
		int child = 2*root;
		while(child <= n)
		{
			if(child<n&&heap[child] < heap[child + 1])
				child++;
			if(rootElement>=heap[child])
				break;
			heap[child/2] = heap[child];
			child *= 2;
		}
		
		heap[child/2] = rootElement;
	}
	changeLength1D(heap,n,2*n);
	heap[n+1] = min(heap,n);
}
//
//第十二题 
// 
/*
a)
	不存在右高树
b)
	当高度为2时最多需要1步 等于log（w（x）+1）
	当高度为3时，最多需要2步，满足
	我们假设当高度为N时，满足条件
	当高度为N+1时 含有最多2的N+1次方个点，依旧满足题目要求
	所以可证得题目正确；
*/
//*********************c)
//构造一个最大右高树，并且给出不用递归的melt方法，非常难我觉得 
template <class T>
void maxWblt<T>::meld(binaryTreeNode<pair<int ,T>>* &x
					  binaryTreeNode<pair<int ,T>>* &y) 
	{
		if(y == NULL)
			return;
		if(x == NULL){
			x = y;
			return;
		}
		
		if(x->element.second<y->element.second)
			swap(x,y);
		for()
	}
	
	
	
	
//
//第十六题 
//
/*
	是稳定的
	因为后进树的值相同的元素不会有机会到达原元素之前
//*////////////////////////////////////////

//
//第十九题 
// 































