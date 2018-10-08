#include<iostream>
using namespace std;

void f(int a)
{
	if(a==1) throw 0;
	if(a==0) throw 1.0;
}

int main()
{
	cout<<"hahahha"<<endl;
	int a;
	
	cin>>a;
	try{
		f(a);
	}
	catch(int){
		cout<<"YOU JUST IN 1";
	}
	catch(double){
		cout<<"sha bi huangzengrui";
	}
}
