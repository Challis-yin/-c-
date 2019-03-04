#include<iostream>
using namespace std;

//�������ڵ㣨����洢�Ķ������� 
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

//����ڵ� 
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//�������� 
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
    
//�ݹ�ʵ�ֵĲ�α���
ListNode* getTreeLevel(TreeNode* root, int dep) {
        // write code here
        ListNode* list=new ListNode(-1);
        ListNode* listHead=list;
        get1(root,list,dep);
        return listHead->next;
    }
    
    

