#include<iostream>
using namespace std;
int count(int x,int mi){
	if(mi==0) return 1;
	if(mi==1) return x;
	int y = 0;
	y = ((2*mi-1)*x*count(x,mi-1)-(mi-1)*count(x,mi-2));
	return y;
} 
int main(){
	int x,n;
	cin>>x>>n;
	cout<<count(x,n);
	return 0;
}
