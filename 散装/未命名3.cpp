#include <iostream>
using namespace std;

class polynomials
{
	private:
		int degree;
		int *box;
		int num; 
	public:
		polynomials(){
			degree = 0;
			num = 0;
			box = new int[200];
		}
		int Degree(){
			return degree;
		}
		void input(int cishu,int xishu){
			int ci;
			cout<<"请输入一个项的次数"<<endl;
			cin>>ci;
			cout<<"请输入一个项的系数"<<endl;
			cin>>box[ci];
		}
		void output(){
			for(int i = 0;i<100;i++){
				if(box[i]!=0){
					if(i==0)
						cout<<box[i];
					cout<<"+"<<box[i].xi<<"X"<<box[i].ci;
				}
				
			}
		}
		void add(polynomias b) {
			for (int i = 0;i<100;i++){
				box[i] = box[i] + b.box[i];
			}
		}
		void substruct(polynomias b){
			for (int i = 0;i<100;i++){
				box[i] = box[i] - b.box[i];
			}
		}
		void multiply(polynomias b,polynomias& c){
			for(int i = 0;i<100;i++){
				for(int o = 0;o<100;o++){
					c.box[i*o] = box[i]*b.box[o];
				}
			}
		}
		void devide(){
			
		}
		int value(int x){
			return box[x];
		}
};












