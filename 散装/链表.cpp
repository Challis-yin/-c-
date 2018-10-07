#include <iostream>
using namespace std;
template <class T>
class chain{
public:
	T ele;
	chain<T> *next;
	chain(const T& ele){
		this.ele = ele;
		this.next = null;
	}
	chain(const T& ele, chain<T> next){
		this.ele = ele;
		this.next = next;
	}
};
class chains{
	public:
		chain head;
		void add;
		
};
int main(){
	cout<<"sf"<<endl;
	
}
