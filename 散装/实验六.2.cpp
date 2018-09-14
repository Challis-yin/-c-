#include<iostream>
using namespace std;
class Rec
{
	public:
		int tiji(int x,int y,int z){
			ti = x*y*z;
			return ti;
		}
	private:
			int ti;
};Rec T;
int main(){
	int x,y,z;
	cin>>x>>y>>z;
	cout<<"Με»ύ£Ί "<<T.tiji(x,y,z)<<endl;
}
