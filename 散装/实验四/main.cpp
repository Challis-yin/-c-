#include <iostream>
#include "4.2.h"
using namespace std;

int main() 
{
	cout<<"***********�����ʼ��һ�������������ʾ*************"<<endl;
	cout<<"����Ԫ�ظ�����";
	int num = 0;
	cin>>num;
	int exam[num];
	//int Tnum = 1;
	for(int i = 0;i<num;i++){
		cin>>exam[i];
	}
	quickSort(exam,0,num);
	//int Tree[Tnum];
	cout<<intoBST(exam,num);
	
	
	
	
	
	
	
	return 0;
}
