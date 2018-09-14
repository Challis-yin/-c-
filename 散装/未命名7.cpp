#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	double afterall;
	afterall = 3.5*3+2*7-'a';
	cout<<afterall<<endl;
	//aftrall = (double)(26/3+34%3+2.5);
	cout<<(double)(26/3+34%3+2.5)<<endl;
	afterall = 45/2+(int)3.14159/2;
	cout<<afterall<<endl;
	double a,b,c;a = 3;
	a=b=(c=a+=6);
	cout<<a<<"\t"<<b<<"\t"<<c<<endl;
	a = 3;
	afterall = (int)(a+6.5)%2+(a=b=5);
	cout<<afterall<<endl;
	double x,y;
	x = 2.5;a = 7;y = 4.7;
	double afteral = x+a%3*(int)(x+y)%2/4;
	cout<afteral<<endl;
	a = 2;b = 3;x = 3.5;y = 2.5;
	afterall = (float)(a+b)/2+(int)x%(int)y;
	
	
	return 0;
	
	
	
	
	
	
}
