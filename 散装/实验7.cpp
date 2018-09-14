#include<iostream>
using namespace std;
class student
{
	private:
		int num;
		int mark;
	public:
		student(int a,int b){
			num = a;
			mark = b;
		}
		student(){
			num = 0;mark = 0;
		}
		student getbest(student kkk[]){
			 student a = kkk [0];
			for(int i = 1;i<5;i++){
				if(kkk[i].getmark()>a.getmark())
					a = kkk[i];
			}
			return a;
		}
		int getnum(){
			return num;
		}
		int getmark(){
			return mark;
		}
}; 
int main()
{
	int num = 0,mark = 0;
	student stu[5]={
		student(1,100),
		student(2,97),
		student(3,98),
		student(4,90),
		student(5,94)
	};
	
	for(int i = 0;i<5;i = i+2){
		cout<<stu[i].getnum()<<"	"<<stu[i].getmark()<<endl;
	}
	cout<<endl;
	student *p;
	p = stu;
	cout<<stu[1].getbest(p).getnum()<<"	"<<stu[1].getbest(p).getmark()<<endl;
	
}






















