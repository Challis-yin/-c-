#include<iostream>
using namespace std;
void sort(int a,int b,int c){
	int temp;
	if(a<b){
		temp = a;
		a = b;
		b = temp;
	}
	if(a<c){
		temp = a;
		a = c;
		c = temp;
	}
	if(b<c){
		temp = b;
		b = c;
		c = temp;
	}
	cout<<a<<"  "<<b<<"  "<<c<<endl;
}

void sort(int *p1,int *p2,int *p3){
	int temp;
	if(*p1<*p2){
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
	if(*p1<*p3){
		temp = *p1;
		*p1 = *p3;
		*p3 = temp;
	}
	if(*p2<*p3){
		temp = *p2;
		*p2 = *p3;
		*p3 = temp;
	}
}
void sort1(int &a,int &b,int &c){
		int temp;
	if(a<b){
		temp = a;
		a = b;
		b = temp;
	}
	if(a<c){
		temp = a;
		a = c;
		c = temp;
	}
	if(b<c){
		temp = b;
		b = c;
		c = temp;
	}
}

int main(){
	int w;	 
	int a = 0,b = 0,c = 0;
		cout<<"请输入3个尽量不同的数字"<<endl;
		 cin>>a>>b>>c;
	cout<<"请输入您想要的方法 1.数字 2.指针 3.引用"<<endl;
	cin>>w;
	switch(w){
		case 1:	
		 sort(a,b,c);
		 cout<<a<<"  "<<b<<"  "<<c<<endl;
		 break;
		 case 3 :
		 sort1(a,b,c);
		 cout<<a<<"  "<<b<<"  "<<c<<endl;
		 break;
		case 2: 
		 sort(&a,&b,&c);
		 cout<<a<<"  "<<b<<"  "<<c<<endl;
		 break;
		}
	return 0;
} 






