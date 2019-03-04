#include<iostream>
#include"exp5.1.0.h"
using namespace std;
int main()
{
    Graph_List g;
    createGraph(g);
    print(g);
    Prim(g, 1);
    system("pause");
    return 0;
}
