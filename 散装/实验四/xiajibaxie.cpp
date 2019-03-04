#include<iostream>
using namespace std;

void kkk(int a[])
{
	int length = sizeof(a)/sizeof(a[0]);
	cout<<length<<endl;
	for(int i = 0;i<length;i++){
		cout<<a[i]<<endl;
	}
}

int main()
{
	int a[] = {0,1,2,3,4};
	int length = sizeof(a)/sizeof(a[0]);
	cout<<length<<endl;
	kkk(a);
	return 0;
}

