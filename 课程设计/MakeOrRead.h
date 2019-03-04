#include<iostream>
#include<fstream>
#include<stdio.h>
#include"migong.h"
#include<stdlib.h>
#include<queue> 
using namespace std; 

struct pairs{
	int x;
	int y;
};

void make(map aa){
	ofstream outfile;
	outfile.open("migong.txt",ios::app | ios::binary);
	if (!outfile)
   {
        cerr << "open file error!";
    }
	outfile.write((char*)&aa,sizeof(aa));
}




void read(){
	map a;
	
	fstream infile("migong.txt",ios::in | ios::binary);
	if (!infile)
            {
                cout<<"open file error!"<<endl;
                getchar();
                //exit(0);
            }
	infile.read((char*)&a, sizeof(a));
	a.info(); 
}

//bool ToF(int aa[][53],int x,int y){
//	queue<pairs> que;
//	pairs first;
//	first.x = x;
//	first.y = y;
//	que.push(first);
//	aa.a[7][7] = 2;
//	while(!que.empty()){
//		pairs point = que.front();
//		que.pop();
//		up(aa,que,point);
//		down(aa,que,point);
//		left(aa,que,point);
//		right(aa,que,point);
//	}
//	if(aa.a[13][13]==2)
//		return true;
//	return false;
//}






