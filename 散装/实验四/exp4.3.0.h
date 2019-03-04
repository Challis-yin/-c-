#include<iostream>
using namespace std;

//二叉树节点（链表存储的二叉树） 
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

//链表节点 
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//辅助方法 
void get1(TreeNode* root,ListNode* &list,int dep)
    {
        if(dep<=0||root==NULL)
            return;
        if(dep==1)
        {
            ListNode* listnext=new ListNode(root->val);
            list->next=listnext;
            list=list->next;
            return ;
        }
        get1(root->left,list,dep-1);
        get1(root->right,list,dep-1);
    }
    
//递归实现的层次遍历
ListNode* getTreeLevel(TreeNode* root, int dep) {
        // write code here
        ListNode* list=new ListNode(-1);
        ListNode* listHead=list;
        get1(root,list,dep);
        return listHead->next;
    }
    
    

