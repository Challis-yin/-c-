#include<iostream>
using namespace std;

template<class T>

void swaps(T&a,T&b){
	T temp = a;
	a = b;
	b = temp;
}

template<class T>

void perm(T list[] , int k , int m)
{
	int i;
	if(k==m)
		{
			for(i = 0;i<=m;i++)
				cout<<list[i];
			cout <<endl;
		}
	else 
		for(i = k;i<=m;i++)
		{
			swaps(list[k],list[i]);
			perm(list,k+1,m);
			swaps(list[k],list[i]);
		}
}

int main()
{
	int a[5];
	for(int i = 0;i<5;i++){
		cin>>a[i];
	}
	perm(a,0,4);
}






 
