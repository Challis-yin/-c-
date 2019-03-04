#include<iostream>
#include<stack>
#include<assert.h>
#include<vector>
using namespace std;
class TwoStacks {

public:

    vector<int> twoStacksSort(vector<int> numbers) {

        // write code here

        vector<int> forSort;

            if(numbers.size() <= 1) return numbers;

            forSort.push_back(numbers.back()); //vector中的函数 除了pop_back之外有front吗

            numbers.pop_back();

            while(numbers.size() > 0)

            {
               int temp = numbers.back();
               numbers.pop_back();
               int popnum = 0;
               while((!forSort.empty())&&temp>forSort.back())
               {
               	numbers.push_back(forSort.back());
               	forSort.pop_back();
               	popnum++;
			   }
			   forSort.push_back(temp);
			   while(popnum>0)
			   {
			   	forSort.push_back(numbers.back());
			   	numbers.pop_back();
			   	popnum--;
			   }
            }

            //reverse(forSort.begin(),forSort.end());

            return forSort;

    }

};

int main()
{
	TwoStacks ts;
	
	vector <int> a;
	cout<<"输入排序数字的数目："<<endl;
	int num;
	cin>>num;
	for(int i = 0;i<num;i++){
		int c = 0;
		cin>>c;
		a.push_back(c);
	}
		
	cout<<endl;
	vector <int> result =ts.twoStacksSort(a);
	for(int i = 0;i<num;i++)
	{
		cout<<result[i]<<"	";
	}
	
}
