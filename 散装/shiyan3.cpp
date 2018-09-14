#include<iostream>
using namespace std;
int main(){
cout<<"开始！";
while(true){
	double a,b,c;int count = 1;
	cout<<"请输入："; 
	cin>>a;
	if(a==-1){
		break;
	}c = a;
	while(true){
	b = a;
	a = (a+c/a)/2;
	cout<<"x"<<count<<" = "<<a<<endl;
	count++;
	if(b-a<0.00001)
	break;
}
}
cout<<"结束"; 

return 0;
} 
