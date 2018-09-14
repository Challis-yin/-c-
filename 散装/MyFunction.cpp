#include<iostream>
using namespace std;
int findMaxElement1D(int x[]){
	int max = x[0];
	for(int i = 0;i<sizeof(x)/8;i++){
		if(max<=x[i])
		max = x[i];
	}
	return max;
}
int findMaxElement2D(int x[][ 4]){
	int max = x[0][0];
	for(int i = 0;i<sizeof(x);i++){
		for(int i1 = 0;i1<sizeof(x[i]);i1++){
			if(max<=x[i][i1])
			max = x[i][i1];
		}
	}
	return max;
}
void sort(int x[],int n){
	int i,j,k,t;
	for(i=0;i<n;i++){
		k = i;
		for(j = i+1;j<n;j++){
			if(x[j]<x[k]) k = j;
			t = x[k];
			x[k] = x[i];
			x[i] = t;
		}
	}
}
int main(){
	int a = 5;int a1;
	cout<<"输入一维数组大小："<<endl;
	cin>>a1;
	a = a1;
	int D1[a];
	for(int i = 0;i<a;i++){
		int xxx;
		cin>>xxx;
		D1[i] = xxx;
	}
	int final = findMaxElement1D(D1);
	cout<<"MAX: "<<final<<endl;
	cout<<"排序";
	sort(D1,a );
	for(int i = 0;i<a;i++){
		cout<<D1[i]<<"   ";
	} 
	cout<<"请输入二维数组大小： "<<endl;
	 
	return 0;
}





