#include <iostream>
#include<vector>
using namespace std; 
class MinimalBST {

public:
	int buildMinimalBST(vector<int> vals)
	{
		// write code here
		//ȡ���������м���ֵ��Ϊ�����������ĸ��������߶���С��
		return build(vals.size());
	}
	int build(int size)
	{
		if (size == 0)
		{
			return 0;
		}
		if (size == 1)
		{
			return 1;
		}
		return build(size / 2) + 1;
	}
};

int main()
{
	MinimalBST mbst;
	vector<int> bst;
	cout<<"������������Ľڵ����" <<endl;
	int length;
	cin>>length; 
	for (int i = 0; i < length; i++)
	{
		bst.push_back(2 * i);
	}
	int height = mbst.buildMinimalBST(bst);
	
	cout<<"��С�������Ĳ���Ϊ��" << height << "\n";

    cout << "Hello World!\n"; 
}

