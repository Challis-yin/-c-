#include<iodtream>
using namespace std;
//
//�ڰ���
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
//��ʮ�� 
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
//��ʮ���� 
// 
/*
a)
	�������Ҹ���
b)
	���߶�Ϊ2ʱ�����Ҫ1�� ����log��w��x��+1��
	���߶�Ϊ3ʱ�������Ҫ2��������
	���Ǽ��赱�߶�ΪNʱ����������
	���߶�ΪN+1ʱ �������2��N+1�η����㣬����������ĿҪ��
	���Կ�֤����Ŀ��ȷ��
*/
//*********************c)
//����һ������Ҹ��������Ҹ������õݹ��melt�������ǳ����Ҿ��� 
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
//��ʮ���� 
//
/*
	���ȶ���
	��Ϊ�������ֵ��ͬ��Ԫ�ز����л��ᵽ��ԭԪ��֮ǰ
//*////////////////////////////////////////

//
//��ʮ���� 
// 































