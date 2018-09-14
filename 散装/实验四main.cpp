#include <iostream>
#include <math.h>
#include <string>
using namespace std;
void first(){
	char a[100] ;
	int num; 
	char *p = a;
	cout<<"请输入字符串"<<endl;
	cin>>a;
	cout<<"请输入要求的数字"<<endl;
	cin>>num;
	for(int i = 0;i<sizeof(a)/8;i++,p++){
		if(i>=num)
		cout<<*p;
	}
	cout<<endl;
}

void second(){
	int a[3][3],kkk; 
	int *p1 = a[1];
	int *p2 = a[2];
	int *p3 = a[3];
	cout<<"请输入3*3矩阵"<<endl;
	for(int i = 0;i<3;i++){
	cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
//	cout<<"是否转制 输入  0 / 1"<<endl;
//	cin>>kkk;
//	if(kkk==1){
		int temp;
		for(int i = 0;i<3;i++){
			for(int o = 0;o<3;o++){
				if(i>o){
				temp = a[i][o];
				a[i][o] = a[o][i];
				a[o][i] = temp;
			}
			}
		}
//	}
	cout<<"Accomplish!!"<<endl; 
	for(int i = 0;i<3;i++){
		for(int o = 0;o<3;o++){
			cout<<a[i][o]<<" ";
		}
		cout<<endl;
	}
	
}	
char a[100],*p = a;
void fuzhu(char *p){
		if(*p>='0'&&*p<='9')
		{
			cout<<*p;			fuzhu(p+1);
		}
		else {
		p = p+1;
		return;	
		}
		
	}
	
void third(){

	cin>>a;
	for(;*p!='\0';p++){
		if((*p>='0'&&*p<='9')&&!((*(p-1)>='0'&&*(p-1)<='9')))
		fuzhu(p);
		cout<<endl;
	}
	 
	}
	
int main() {
	int number;
	cout<<"输入试验编号  1/ 2/ 3"<<endl;
	cin>> number;
	if(number==1)
	first();
	if(number == 2)
	second();
	if(number == 3)
	third();
//	char a = '1';
//	cout<<a;
	return 0;
}



