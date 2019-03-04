#include<iostream>
#include"exp4.3.0.h"
using namespace std;
int main(){
	
	TreeNode* n1=new TreeNode(4);
	TreeNode* n2=new TreeNode(5);
	TreeNode* n3=new TreeNode(7);
	TreeNode* n4=new TreeNode(63);
	TreeNode* n5=new TreeNode(18);
	TreeNode* n6=new TreeNode(6);
	TreeNode* n7=new TreeNode(10);
	TreeNode* n8=new TreeNode(12);
	
	n1->left=n2;
	n1->right=n3;
	n2->left=n4;
	n2->right=n5;
	n3->left=n6;
	n5->left=n7;
	n6->right=n8;
	
	ListNode* res=getTreeLevel(n1,3);
	while(res){
		cout<<res->val<<"  ";
		res=res->next;
	}
	return 0;
}
