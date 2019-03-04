// 
//实验一 排序 
//
#include<stdlib.h>
#include<iostream>
#include <time.h> 

using namespace std;
// 
//插入排序			Process exited after 7.638 seconds with return value 0 
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
//冒泡排序			Process exited after 8.677 seconds with return value 0
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
//选择排序 			 Process exited after 7.071 seconds with return value 0
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
//快速排序			 Process exited after 5.497 seconds with return value 0	
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
//堆排序 			Process exited after 0.3396 seconds with return value 0
//

void MaxHeapify(int* a,int i,int low,int high)
{
    int l = 2*i+1;//计算下标为i的节点的左子节点
    int r = 2*i+2;//计算下标为i的节点的右子节点
    int largest;//保存i,l,r(即i和它的左右子节点)之间的最大数的下标
    int temp;//交互数组中的数所使用的临时变量
    //找到三个数当中最大的那个数，将最大的那个数和i进行互换
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
//归并排序			Process exited after 0.9352 seconds with return value 0
//

void merge(int *data,int start,int end,int *result)
{
    int left_length = (end - start + 1) / 2 + 1;//左部分区间的数据元素的个数
    int left_index = start;
    int right_index = start + left_length;
    int result_index = start;
    while(left_index < start + left_length && right_index < end+1)
    {
        //对分别已经排好序的左区间和右区间进行合并
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
    if(1 == end - start)//如果区间中只有两个元素，则对这两个元素进行排序
    {
        if(data[start] > data[end])
        {
            int temp  = data[start];
            data[start] = data[end];
            data[end] = temp;
        }
        return;
    }
    else if(0 == end - start)//如果只有一个元素，则不用排序
        return;
    else
    {
        //继续划分子区间，分别对左右子区间进行排序
        merge_sort(data,start,(end-start+1)/2+start,result);
        merge_sort(data,(end-start+1)/2+start+1,end,result);
        //开始归并已经排好序的start到end之间的数据
        merge(data,start,end,result);
        //把排序后的区间数据复制到原始数据中去
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























