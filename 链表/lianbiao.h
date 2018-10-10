#ifndef LIANBIAO_H_INCLUDED
#define LIANBIAO_H_INCLUDED



#endif
#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

template <class T>
class chainNode {
//	friend chain<T>;
	private:
		T data;
		chainNode<T> *link;
};

template<class T>
class chain
{
	public:
		Chain(){ first  = 0;		}
		~chain();
		bool isEmpty() const {return first == 0;}
		int length() const;
		void erase();
		bool find(int k,T& x) const;
		int search(const T& x) const;
		chain<T>& Delete (int k,T& x);
		chain<T>& insert (int k ,const T& x);
		void output(ostream& out) const;
		chain<T>& append(const T& x);
	private:
		chainNode<T> *first;
};

/*
删去链表的所有元素
*/

template <class T>
chain<T>:: ~chain()
{
	chainNode<T> *next;
	while (first){
		next = first->link;
		delete first;
		first = next;
	}
}
/*
返回链表的长度
*/
template <class T>
int chain<T>::length() const
{
	chainNode<T> *current = first;
	int len = 0;
	while (current){
		len++;
		current = current->link;
	}
	return len;
}

/*
查找 第N个链表个体是否存在 通过引用返回它的值 返回true or false
*/

template <class T>
bool chain<T>::find(int k,T& x) const
{
	if (k<1) return false;
	chainNode <T> *current = first;
	int i = 1;
	while(i<k&&current){
		current = current.link;
		i++;
	}
	if(current) {
		x = current.data;
		return true;
	}
	return false;
 }

/*
寻找值为 x 的链表项存不存在，返回其序号
*/

template <class T>
int chain<T>::search(const T& x) const
{
	chainNode <T>*current = first;
	int i = 1;
	while (current && current.data!=x){
		current = current->link;
		i++;
	}
	if(current) return i;
	return 0;
}

/*
输出一个链表的方法
*/

template <class T>
void chain<T>::output(ostream& out) const
{
	chainNode<T> *current;
	for (current = first;current;current = current.link){
		out << current.data<<"  ";
	}
}

/*
删除掉链表中第K位置的元素
*/

template <class T>
chain<T>& chain<T>::Delete(int k,T& x)
{
	if(k<1||!first) throw 1;
	chainNode<T> *p = first;

	if(k==1) first = first.link;
	else{
		chainNode<T> *q = first;
		for(int i = 1;i<k-1&&q;i++) q = q.link;
		if(!q||!q.link)
			throw 1;
		p = q.link;
		q.link = p.link;
	}
	x = p.data;
	delete p;
	return *this;
}

/*
在指定位置插入一个链表元素
*/

template <class T>
chain<T>& chain<T>::insert(int k,const T& x)
{
	if(k<0) throw 1;
	chainNode<T> *p = first;
	for (int i = 1;i< k&&p;i++)
	{
		p = p->link;
	}
	if(k>0&&!p) throw 1;
	chainNode<T> *y = new chainNode<T>;
	y->data = x;
	if(k){
		y->link = p->link;
		p->link = y;
	}
	else{
		y->link = first;
		first = y;
	}
	return *this;
}

/*
清空链表
*/

template <class T>
void chain<T>::erase()
{
	chainNode<T> *next;
	while(first){
		next = first->link;
		delete first;
		first = next;
	}
}

/*

*/

template <class T>
chain<T>& chain<T>::append(const T& x)
{
	chainNode<T> *y;
	y = new chainNode<T>;
	y->data = x;
	y->link = 0;
	chainNode<T> *next = first;
	while(next){
		next = next->link;
	}
	next->link = y;
	return *this;
}
