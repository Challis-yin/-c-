#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;
template<class T>
class Queue
{
public:
    //入队列
    void push(const T&data){
        stack1.push(data);
    }
    //出队列
    void Pop()
    {
        //如果两个栈都是空栈，此时说明队列是空的
        if (stack1.empty() && stack2.empty())
            cout << "this queue is empty" << endl;
        //如果栈2中有元素，那出队列就出栈2中的
        if (!stack2.empty()){
            stack2.pop();
        }
        //此时表明栈2已是空栈，再要出队列的话，那就需要把栈1中的所有元
        //素入栈到栈2中,注意一定要是栈1中的所有元素都入栈到栈2中
        else{
            while (stack1.size() > 0){
                stack2.push(stack1.top());
                stack1.pop();
            }
            stack2.pop();
        }
    }
    T&Front()//获取队头元素，此时队头位于栈2的栈顶
    {
        assert(!stack1.empty() || !stack2.empty());
        if (stack2.empty()){
            while (!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }
private:
    stack<T> stack1;
    stack<T> stack2;
};
void TestQueue()
{
    Queue<int> q;
    int i;
    int num = 0;
    cin>>i;
    while(i!=-1) {
    	num++;
	    q.push(i);
	    cin>>i;
	}
    cout << "队头为:>   "<<q.Front() << endl;
    cout<<"输入pop次数";
    int o;
    cin>>o;
    for(int pp = 0;pp<o;pp++)
    	q.Pop();
    cout << "队头为:>   " << q.Front() << endl;
}
int main()
{
    TestQueue();
    return 0;
}

