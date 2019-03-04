#include <iostream>

using namespace std;
struct chainNode{
int first;
int second;
chainNode *link;
chainNode(chainNode *p = NULL){first = 0;second = 0;link = p;}
chainNode(int f,int s,chainNode *t = NULL){
    first = f;
    second = s;
    link = t;
}
};
class list{
public :
    chainNode *first;
    int num = 0;
    list(){first = new chainNode();}
    void insert(int a,int b){
        chainNode kkk = new chainNode(a,b);
        chainNode *temp = first;
        cout<<"ok1";
        while(temp->link!=NULL&&temp->second<b)
        {
            cout<<"ok2";
            temp = temp->link;
        }
        *temp->link = kkk;
        num++;
        }
    void print()
    {
        chainNode *temp = first->link;
        while (temp->link)
        {
            cout<<temp->first<<"X"<<"^"<<temp->second<<" + ";
            temp = temp->link;
        }
        cout<<temp->first<<"X"<<"^"<<temp->second;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    list lists;
    lists.insert(2,5);
    lists.insert(3,4);
    lists.insert(5,2);
    lists.print();
    cout<<"sadf";
    return 0;
}

