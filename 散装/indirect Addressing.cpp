#include<iostream>
using namespace std;
/*
间接表 
*/
template <class T>
class IndirectList
{
	public:
		IndirectList(int Max = 10);
		~IndirectList();
		bool IsEmpty() const {return length == 0;}
		int Length() const {return length;}
		bool Find(int k,T& x) const;
		IndirectList<T>& Delete(int k , T& x);
		IndirectList<T>& Insert(int k , const T& x);
		void output(ostream& out) const;
	private:
		T **table;
		int length;
		int max; 
}
template <class T>
IndirectList<T>::IndirectList(int Max)
{
	max = Max;
	table = new T *[max];
	length = 0;
}
template <class T>
IndirectList<T>::~IndirectList()
{
	for(int i = 0;i<length;i++){
		delete table[i];
	}
	delete [] table;
}

/*
 查  找 
*/

template <class T>
bool IndirectList<T>::Find(int k,T& x) const
{
	if (k<1 || k>length) return false;
	x = *table[k-1];
	return ture;
}

/*
删去指定元素 
*/

template <class T> 
IndirectList<T>& IndirectList<T>::Delete(int k,T& x)
{
	if (Find(k,x)){
		for (int i = k;i<length;i++){
			table[i-1] = table[i];
		}
		length--;
		return *this;
	}
	else throw OutOfBounds();
}

/*

*/

template <class T>
IndirectList<T>& IndirectList<T>::Insert(int k,const T& x)
{
	if(k<0||k>length){
		throw OutOfBounds();
	}
	if(length == max){
		throw NoMam();
	}
	for(int i = length - 1;i>=k;i--){
		table[i+1] = table[i];
	}
	table[k] = new T;
	*table[k] = x;
	length++;
	return *this;
 } 


















