#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

void quickSort(int num[], int l, int r) {
    if (l >= r) 
        return;
    int i = l, j = r, x = num[l];
    while (i < j) {
        while (i < j && num[j] >= x)
            j--;
        if (i < j)
            num[i++] = num[j];
        while (i < j && num[i] <= x)
            i++;
        if (i < j)
            num[j--] = num[i];
    }
    num[i] = x;     
    quickSort(num, l, i - 1);
    quickSort(num, i + 1, r);
}

void change(int a,int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int intoBST(int a[],int num){
	
	if(num == 0)
		return;
	int temp = num/2;
	TreeNode* n1=new TreeNode(a[temp]);
	n1->right = getr(a,num,temp);
	intoBstr(a)
	return 0;
	
}

void intoBstr(int a[],int num){
	
} 

TreeNode getr(int a[],int num1,int num2){
	
	TreeNode t = new TreeNode(a[num1+(num2-num1)/2]);
	return t;
	
}

TreeNode getl(int a[],int num){
	TreeNode t = new TreeNode(a[num1/2]);
	return t;
}













 
