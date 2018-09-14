#include<iostream>
using namespace std;
template <typename T>
T max(T a,T b,T c){
	if(b>a) a = b;
	if(c>a) a = c;
	return a;
}
int main() 
{
	int a,b,c;
	double a1,b1,c1;
	long a2,b2,c2;
	cout<<"请输入三个int类型：";
	cin>>a>>b>>c;
	cout<<"请输入三个double类型：";
	cin>>a1>>b1>>c1;
	cout<<"请输入三个long类型："; 
	cin>>a2>>b2>>c2;
	cout<<max(a,b,c)<<endl;
	cout<<max(a1,b1,c1)<<endl;
	cout<<max(a2,b2,c2)<<endl; 
}
