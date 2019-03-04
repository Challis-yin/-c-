#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;
template<class T>
class Queue
{
public:
    //�����
    void push(const T&data){
        stack1.push(data);
    }
    //������
    void Pop()
    {
        //�������ջ���ǿ�ջ����ʱ˵�������ǿյ�
        if (stack1.empty() && stack2.empty())
            cout << "this queue is empty" << endl;
        //���ջ2����Ԫ�أ��ǳ����оͳ�ջ2�е�
        if (!stack2.empty()){
            stack2.pop();
        }
        //��ʱ����ջ2���ǿ�ջ����Ҫ�����еĻ����Ǿ���Ҫ��ջ1�е�����Ԫ
        //����ջ��ջ2��,ע��һ��Ҫ��ջ1�е�����Ԫ�ض���ջ��ջ2��
        else{
            while (stack1.size() > 0){
                stack2.push(stack1.top());
                stack1.pop();
            }
            stack2.pop();
        }
    }
    T&Front()//��ȡ��ͷԪ�أ���ʱ��ͷλ��ջ2��ջ��
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
    cout << "��ͷΪ:>   "<<q.Front() << endl;
    cout<<"����pop����";
    int o;
    cin>>o;
    for(int pp = 0;pp<o;pp++)
    	q.Pop();
    cout << "��ͷΪ:>   " << q.Front() << endl;
}
int main()
{
    TestQueue();
    return 0;
}

