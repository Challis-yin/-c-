#include<iostream>
using namespace std;
//
//P456ҳ20�� 
//
struct pairs{
	public:
		char a;
		int* b;
		S(void){}
		void show(void) {cout<<a<<"\t"<<b<<endl;}
		pairs(char aq,int* bq){
			a = aq;
			b = bq;
		}
};
pairs* pp  =  pairs[100]; 
void getTable(linkedBinaryTree t,int * a){//a��һ�����飬ʢ�ű����á� 
	int *b;
	b = int[100];
	for(int i = 0;i<a.length();i++){
		b[i] = a[i];
	}
	treeNode x = t;
	if  (x.leftchild!=NULL){ 
		b.append(0);
		getTable(x.leftchild,b);
		} 
	if (x.rightchild!=NULL){
		b.append(1)
		getTable(x.rightchild,b);
	}
	pairs a = pairs(x.data,b);
	pp.append(a);
}
linkedBinaryTree<int>* huffmanTree(T weight[], int n){
	huffmanNode<T> *hNode = new huffmanNode<T> [n+1];
	linkedBinaryTree <int> emptyTree;
	for(int i = 1;i<=n;i++){
		hNode[i].weight = weight[i];
		hNode[i].tree = new linkBinaryTree<int>;
		hNode[i].tree->makeTree(i,emptyTree,emptyTree);
	}
	minHeap<huffmanNode<T>> heap(1);
	heap.initialize(hNode,n);
	
	huffmanNode<T> w,x,y;
	linkedBinaryTree<int> *z;
	for(i = 1;i<n;i++){
		x = heap.top();heap.pop();
		y = heap.top();heap.pop();
		
		z = new linkBinaryTree<int>;
		z->makeTree(0,*x.tree,*y.tree);
		w.weight = x.weight + y.weight;
		w.tree = z;
		heap.push(w);
		delete x.tree;
		delete y.tree;
		
	}
	
	return heap.top().tree;
	
}

//
//��ν��� 
//

char* jieMa(int* miWen,linkedBinaryTree<int>* t){
	int n = sizeof(miWen)/sizeof(miWen[0]);
	huffmanNode<T> h = t;
	char * kkk = char[100];
	for(int i = 0;i<n;i++){
		try{
			if(i = 1)
			h = h->rightchild;
		if(i = 0)
			h = h->leftchile;
		}
		catch(NoMem){
			cout<<"ERROR"<<endl;
			exit(0);
		}
		if(h.leftchild == NULL&&h.rightchild == NULL)
		{
			cout<<h.data<<"	";
			kkk.append(h.data);
			huffmanNode<T> h = t;
		}
			
	}
	return kkk;
}

//
//499ҳ10�� 
//

template <class K,class E>
void  <const K,E>* binarySearchTree<K,E>::insert(const pair<const K,E>& thePair)
{
	binaryTreeNode<pair<const K,E> > *p = root,*pp = NULL;
	
	while (p!=NULL)
	{
		pp = p;
		if(thePair.first<p->element.first)
			p = p->p.leftchild;
		else
			if(thePair.first>p->element.first)
				p = p->rightchild;
			else
			{
				p->element.second = thePair.second;
				return;
			}
	 }
	binaryTreeNode<pair<K,E> > *newNode = 
	 	new binaryTreeNode<pair<const K,E>> (thePair);
	if(root != NULL)
		if(thePair.first<p->element.first)
			pp->leftchild = newNode;
		else
			pp->rightchild = newNode;
	else
		root = newNode;
	treeSize++;
}
void zhongxu(binaryTree& t)
{
	if(t!=NULL){
		zhongxu(t.leftchild);
		visit(t);
		zhongxu(t.rightchild);
	}
}
void paixu(int * a)
{
	pair * kkk;
	int n = sizeof(a)/sizeof(a[0]);
	kkk = pair[n];
	for(int i = 0;i<n;i++){
		kkk[i].first = a[i];
	}
	insert(kkk);
	zhongxu(t);
}

//
//499ҳ12�� 
//

void split(const K& theKey,binarySearchTree<K,E> *lessThan,binarySearchTree<K,E> *greatThan)
{
	binaryTreeNode<pair<const K,E> > *p = root;
	while (p!=NULL){
		if(theKey<p->element.first)
			p->leftchild;
		else
			if(thekey>p->element.first)
				p = p->rightchild;
			else 
				break;
	}
	if(p==null){
		cout<<"û�иýڵ�"<<endl; 
		return;
	}
	
}

//
//p509 19
//

template <class T>
class AVLTreeNode{
    public:
        T key;              
        int height;         
        AVLTreeNode *left;    
        AVLTreeNode *right;   

        AVLTreeNode(T value, AVLTreeNode *l, AVLTreeNode *r):
            key(value), height(0),left(l),right(r) {}
};
int AVLTree<T>::height(AVLTreeNode<T>* tree) 
{
    if (tree != NULL)
        return tree->height;

    return 0;
}
AVLTreeNode<T>* AVLTree<T>::leftLeftRotation(AVLTreeNode<T>* k2)
{
    AVLTreeNode<T>* k1;

    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max( height(k2->left), height(k2->right)) + 1;
    k1->height = max( height(k1->left), k2->height) + 1;

    return k1;
}AVLTreeNode<T>* AVLTree<T>::rightRightRotation(AVLTreeNode<T>* k1)
{
    AVLTreeNode<T>* k2;

    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max( height(k1->left), height(k1->right)) + 1;
    k2->height = max( height(k2->right), k1->height) + 1;

    return k2;
}
AVLTreeNode<T>* AVLTree<T>::rightLeftRotation(AVLTreeNode<T>* k1)
{
    k1->right = leftLeftRotation(k1->right);

    return rightRightRotation(k1);
}
AVLTreeNode<T>* AVLTree<T>::insert(AVLTreeNode<T>* &tree, T key)
{
    if (tree == NULL) 
    {
        // �½��ڵ�
        tree = new AVLTreeNode<T>(key, NULL, NULL);
        if (tree==NULL)
        {
            cout << "ERROR: create avltree node failed!" << endl;
            return NULL;
        }
    }
    else if (key < tree->key) // Ӧ�ý�key���뵽"tree��������"�����
    {
        tree->left = insert(tree->left, key);
        // ����ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
        if (height(tree->left) - height(tree->right) == 2)
        {
            if (key < tree->left->key)
                tree = leftLeftRotation(tree);
            else
                tree = leftRightRotation(tree);
        }
    }
    else if (key > tree->key) // Ӧ�ý�key���뵽"tree��������"�����
    {
        tree->right = insert(tree->right, key);
        // ����ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ�
        if (height(tree->right) - height(tree->left) == 2)
        {
            if (key > tree->right->key)
                tree = rightRightRotation(tree);
            else
                tree = rightLeftRotation(tree);
        }
    }
    else //key == tree->key)
    {
        cout << "���ʧ�ܣ������������ͬ�Ľڵ㣡" << endl;
    }

    tree->height = max( height(tree->left), height(tree->right)) + 1;

    return tree;
}



//
//�ݹ��ʵ��indexed BST��insert delete ascend����
//
























