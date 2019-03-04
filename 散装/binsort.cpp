#include <iostream>
using namespace std;
const int mum = 10;

class stu
{
	public:
		int shu;
		stu *next = NULL;
		
		stu(int a)
		{
			shu = a;
		}
};

int main()
{
	stu a((int)98);
	stu b(67);
	stu c(89);
	stu d(87);
	stu e(73);
	stu f(75);
	
	stu *first = &a;
	
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	
	
	
	stu **bottom,**top;
	bottom = new stu*[10];
	top = new stu*[10];
	
	while(first){
		
		int i = first->shu/10;
		cout<<i<<endl;
		if (bottom[i]==NULL){
			bottom[i] = top[i] = first;
		}
		else{
			top[i]->next = first;
			top[i] = first;
		}
		first = first->next; 
		
		} 
	
	stu * p = NULL;
	for(int i = 0;i<10;i++){
		if(bottom[i]!=NULL){
			if(p==NULL)
				first = bottom[i];
			else
				p->next = bottom[i];
			p = top[i]; 
		}
		if(p!=NULL)
			p->next = NULL;
		delete [] top;
		delete [] bottom;
	}
	
	stu *current = first;
	while(current){
//		cout<<current->shu<<endl;
//		current = current->next; 
		cout<<"000";
	}
	 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
