// 
//ʵ��һ ���� 
//
#include<stdlib.h>
#include<iostream>
#include <time.h> 

using namespace std;
// 
//��������			Process exited after 7.638 seconds with return value 0 
// Process exited after 1.036 seconds with return value 0
void InsertSort(int data[], int size)
{
	for(int i=1;i<size;i++)
	{
		int temp=data[i],j;
		for(j=i;j>0&&temp<data[j-1];j--)
			data[j]=data[j-1];
		data[j]=temp;
	}
}

//
//ð������			Process exited after 8.677 seconds with return value 0
// Process exited after 3.208 seconds with return value 0

void bubbleSort(int* pData,int length)
{
    int temp;
    for(int i = 0;i != length;++i)
    {
        for (int j = 0; j != length; ++j)
        {
            if (pData[i] < pData[j])
            {
                temp = pData[i];
                pData[i] = pData[j];
                pData[j] = temp;
            }
        }
    }
}

//
//ѡ������ 			 Process exited after 7.071 seconds with return value 0
//Process exited after 1.496 seconds with return value 0

void selectSort(int a[], int n)
{
    int i = 0, j = 0, k = 0; 
    for (i=0; i < n-1; i++)
    {
        k = i;
        for (j=i+1; j < n; j++)
        {
            if (a[k] > a[j])
            {
                k = j;
            }
        }
	if (k != i)
		{
	    int tmp=a[k];
	    a[k]=a[i];
	    a[i]=tmp;
		}
    }
}

//
//��������			 Process exited after 5.497 seconds with return value 0	
//Process exited after 0.3603 seconds with return value 0

void quickSort(int num[], int l, int r) {
    if (l >= r) 
        return;
    int i = l, j = r, x = num[l];
    while (i < j) {
        while (i < j && num[j] >= x)
            j--;
        if (i < j)
            num[i++] = num[j];
        while (i < j && num[i] <= x)
            i++;
        if (i < j)
            num[j--] = num[i];
    }
    num[i] = x;     
    quickSort(num, l, i - 1);
    quickSort(num, i + 1, r);
}

//
//������ 			Process exited after 0.3396 seconds with return value 0
//

void MaxHeapify(int* a,int i,int low,int high)
{
    int l = 2*i+1;//�����±�Ϊi�Ľڵ�����ӽڵ�
    int r = 2*i+2;//�����±�Ϊi�Ľڵ�����ӽڵ�
    int largest;//����i,l,r(��i�����������ӽڵ�)֮�����������±�
    int temp;//���������е�����ʹ�õ���ʱ����
    //�ҵ����������������Ǹ������������Ǹ�����i���л���
    if (l<=high && a[l]>a[i])
    {
        largest = l;
    }
    else{
        largest = i;
    }

    if (r<=high && a[r]>a[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        MaxHeapify(a, largest,low,high);
    }
}

void HeapSort(int a[],int length)
{
    int temp;
    for (int i = length / 2-1; i >= 0; i--)
    {
        MaxHeapify(a, i, 0, length - 1);
    }
    for (int i = length - 1; i >= 1; i--)
    {
        temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        MaxHeapify(a, 0, 0, i-1);
    }
}

//
//�鲢����			Process exited after 0.9352 seconds with return value 0
//

void merge(int *data,int start,int end,int *result)
{
    int left_length = (end - start + 1) / 2 + 1;//�󲿷����������Ԫ�صĸ���
    int left_index = start;
    int right_index = start + left_length;
    int result_index = start;
    while(left_index < start + left_length && right_index < end+1)
    {
        //�Էֱ��Ѿ��ź�������������������кϲ�
        if(data[left_index] <= data[right_index])
            result[result_index++] = data[left_index++];
        else
            result[result_index++] = data[right_index++];
    }
    while(left_index < start + left_length)
        result[result_index++] = data[left_index++];
    while(right_index < end+1)
        result[result_index++] = data[right_index++];
}

void merge_sort(int *data, int start, int end, int *result)
{
    if(1 == end - start)//���������ֻ������Ԫ�أ����������Ԫ�ؽ�������
    {
        if(data[start] > data[end])
        {
            int temp  = data[start];
            data[start] = data[end];
            data[end] = temp;
        }
        return;
    }
    else if(0 == end - start)//���ֻ��һ��Ԫ�أ���������
        return;
    else
    {
        //�������������䣬�ֱ�������������������
        merge_sort(data,start,(end-start+1)/2+start,result);
        merge_sort(data,(end-start+1)/2+start+1,end,result);
        //��ʼ�鲢�Ѿ��ź����start��end֮�������
        merge(data,start,end,result);
        //���������������ݸ��Ƶ�ԭʼ������ȥ
        for(int i = start;i <= end;++i)
            data[i] = result[i];
    }
}

int main(){
srand((unsigned)time(NULL)); 
int a[30000];
int k[30000];
for(int i = 0; i < 30000;i++ ) 
        a[i] = rand(); 
//InsertSort(a,30000);
//bubbleSort(a,30000);
//selectSort(a,30000);
//quickSort(a,0,30000);
//merge_sort(a,0,30000,k) ;
HeapSort(a,30000); 
//for(int i = 0;i<30000;i++)
//	cout<<a[i]<<"\t";
cout<<endl;
return 0;	return 0;
}























