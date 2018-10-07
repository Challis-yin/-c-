#include <iostream>
using namespace std;

class linearlist
{
	public:
		int ele[];
		int current;
		int max;
		linearlist(int length = 1)
		{
			ele = new int[length];
			current = 0;
			max = length;
		}
		void add(int a)
		{
			ele[current] = a;
			current++;
		}
		void deletes(int i)
		{
			if(i>current){
				cout<<"³¬³ö·¶Î§"<<endl;
			}
			for(int k = i;k<current;k++)
			{
				ele[k] = ele[k+1];
			}
			ele[current].~T();
		}
		void copys()
		{
			if(current <= max/4)
			{
				int kkk[] = new int[max/2];
				for(int i = 0;i<=max/4;i++){
					kkk[i] = ele[i];
				}
				delete ele;
				ele = kkk;
			}
			cout<<"bumanzutiaojian"<<endl;
		}
 } ;
 
 int main()
 {
 	linearlist aaa;
 	aaa = new linearlist(4);
 	aaa.add(2);
 	aaa.add(3);
 	aaa.deletes(1);
 	aaa.copys();
 }
