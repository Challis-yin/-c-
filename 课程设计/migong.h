#include <iostream>
 

using namespace std;

class map{
	private:
		bool ok;
	public:
		void changes(bool b){ok = b;}
		int a[53][53];
		void con(){
			for(int i = 0;i<15;i++)
				for(int ii = 0;ii<15;ii++)
					a[i][ii] = 0;
		}
		void info(){
			for(int i=0;i<=52;i++){
		        for(int j=0;j<=52;j++){
		            if(a[i][j]==2){
		                printf("  ");
		            }
		            else if(a[i][j]==7){
		            	printf("g ");
					}
		            else{
		                printf("# ");
		            }
		        }
		        printf("\n");
    		}
				
		}
};












