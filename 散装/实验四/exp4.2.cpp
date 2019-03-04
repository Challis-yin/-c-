#include <iostream>
//#include "../BSTt.h"
#include<cmath>
using namespace std;
template <class T>
class BinaryTreeNode {
public:
    BinaryTreeNode() {LeftChild = RightChild = 0;LeftSize=1;}
    BinaryTreeNode(const T& e)
    { data = e; LeftChild = RightChild = 0;LeftSize=1;}
    BinaryTreeNode(const T& e, BinaryTreeNode *l,
                   BinaryTreeNode *r)
    { data = e; LeftChild = l; RightChild = r;if(l)LeftSize=l->LeftSize+1;}
//private:
    T data;
    BinaryTreeNode<T> *LeftChild,  // left subtree
            *RightChild; // right subtree
    int LeftSize;
};

BinaryTreeNode<int>* buildMinBST(int vals[], int start, int end) {
    //假设该数组0索引不存数据
    if (start == end) {
        BinaryTreeNode<int>* b = new BinaryTreeNode<int>;
        b->data = vals[start];
        return b;
    }
    int index = (end - start + 1) / 2 +start;
    BinaryTreeNode<int>* a = new BinaryTreeNode<int>;
    BinaryTreeNode<int>* a_lc = buildMinBST(vals, start, index - 1);
    if (index < end) {
        BinaryTreeNode<int>* a_rc = buildMinBST(vals, index + 1, end);
        a->RightChild = a_rc;
    }
    else {
        a->RightChild = 0;
    }
    a->data = vals[index];
    a->LeftChild = a_lc;

    return a;
}

int buildMinBST(int vals[], BinaryTreeNode<int>* a,int length) {
    int n = length-1; //假设该数组0索引不存数据
    a = buildMinBST(vals, 1, n);
    int height = ceil(log(n + 1) / log(2));
    return height;
}

int main()
{
	BinaryTreeNode<int>* b;
	int a[36];
	for(int i = 0;i<36;i++)
	{
		a[i] = i;
	}
	int height = buildMinBST(a,b,36);
	cout<<height<<endl;
}
