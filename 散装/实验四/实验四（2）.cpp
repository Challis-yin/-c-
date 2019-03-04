#include <iostream>
#include<vector>
using namespace std; 
class MinimalBST {

public:
	int buildMinimalBST(vector<int> vals)
	{
		// write code here
		//取有序数组中间数值作为二叉搜索树的根，这样高度最小。
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
	cout<<"请输入二叉树的节点个数" <<endl;
	int length;
	cin>>length; 
	for (int i = 0; i < length; i++)
	{
		bst.push_back(2 * i);
	}
	int height = mbst.buildMinimalBST(bst);
	
	cout<<"最小生成树的层数为：" << height << "\n";

    cout << "Hello World!\n"; 
}

