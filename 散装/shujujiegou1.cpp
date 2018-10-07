#include <iostream>
using namespace std;

/*
构建一个抽象父类
*/

template <class T>
class linearList
{
	public:
		virtual ~linearList () {};
		virtual bool empty() const = 0;
		virtual int size() const = 0;
		virtual T& get(int theIndex) const = 0;
		virtual int indexOf(const T& theElement) const = 0;
		virtual void erase(int theIndex) = 0;
		virtual void insert(int theIndex,const T& theElement) = 0;
		virtual void output(ostream& out) const = 0;
};
template <class T>
void changeLength1D(T&a,int oldLength,int newLength)
{
//	if(newLength < 0)
//		throw illegalParameterValue("new length must be >= 0");
	T* temp = new T[newLength];
	int number = min(oldLength,newLength);
	copy(a,a+number,temp);
	delete [] a;
	a = temp;
}
/*
新的类 ARRAYLIST
*/
template <class T>
class arrayList : public linearList<T>
{
	public:
		arrayList(int init = 10);
		arrayList(const arrayList<T>&);
		~arrayList() {delete [] element;}
		
		bool empty() const {return listSize == 0;}
//		int size() const (return listSize;)
		T& get(int theIndex) const;
		int indexOf(const T& theElement) const;
		void erase(int theIndex);
		void insert(int theIndex,const T& theElement);
		void outPut (ostream& out) const;
		
		int capacity() const {return arrayLength;}
	protected:
		void checkIndex(int theIndex) const;
		
		T* element;
		int arrayLength;
		int listSize;
 } ;
 
 
 /*  
 			构造函数 
 */
 template <class T>
 arrayList<T>::arrayList(int init)
 {
 	if(init<1){
 	ostringstream s;
// 	s<<"MUST >= 0"<<init<<"kkk";
// 	throw illegalparameterValue(s.str());}
 	arrayLength = init;
 	element = new T[arrayLength];
 	listSize = 0;
 }
 
template <class T>
 arrayList<T>::arrayList(const arrayList<T>& theList)
 {
 	arrayLength = theList.arrayLength;
 	listSize = theList.listSize;
 	element = new T[arrayLength];
 	copy(theList.element,theList.element+listsize,element);
 }
 
 /*
 		CHECK 	GET		INSEXOF
*/
template<class T>
 void arrayList<T>:: checkIndex(int theIndex) const
 {
 	
 }
template<class T>
T& arrayList<T>:: indexOf(const T& theElement) const
{
	int i = (int) (find(element,element + listSize,theElement)-element);
	if(i==listSize)
		return -1;
	return i;
}
template<class T>
T& arrayList<T>:: get(int theIndex) const
{
	checkIndex(theIndex);
	return element[theIndex];
}
/*
删除一个元素
*/
template<class T>
 void arrayList<T>:: erase(int theIndex) const 
 {
 	checkIndex(theIndex);
 	copy(element + theIndex + 1,element + listsize,element + theIndex);
 	element[--listsize].~T();
 }
 /* 
 		插入操作
*/ 
template <class T>
void arrayList<T>::insert(int theIndex,const T& theElement)
{
	if(theIndex < 0||theIndex>listSize)
	{
		ostringstream s;
		s<<"bu xing";
		throw illegalIndex(s.str());
		
	}
	
	if(listSize == arrayLength)
	{
		changeLength1D(element,arrayLength,2*arrayLength);
		arrayLength = arrayLength*2;
	}
	
	copy_backward(element+theIndex,element+listSize,element+1+listSize);
	element[theIndex] = theElement;
	listSize++;	
}

/*
把一个线性表插入到输出流
*/


 

template <class T>
void arrayList<T>::output(cout->out) const
{
	copy(element,element+listSize,ostream_iterator<T>(cout," "));
}
template <class T>
ostream& operator<<(ostream& out,const arrayList<T>& x)
{
	x.output(out);
	return out;
}











