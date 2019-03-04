
#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include <conio.h>
using namespace std;

#define Size 15
#define maxsmall 7
#define smallroad 6
#define mouse 4
#define start 2
#define end 3
#define wall 1
#define road 0
#define up 0
#define down 1
#define left 2
#define right 3
#define Esc 5
bool iftime=false;
const int Max=1000;
class Cirqueue
{
public :
	Cirqueue(){front=rear=Max-1;}
	void Enqueue(int x)
	{
        if((rear+1)%Max==front)
			cout<<"Queue Full"<<endl;
		else
		{
			rear=(rear+1)%Max;
			data[rear]=x;
		}
	}
	int Dequeue()
	{  
		if(rear==front)
			return 0;
		else
		{  
			
			front=(front+1)%Max;
			return data[front];
		}
	}
	int empty()
	{
		if(rear==front)
			return 0;
		return 1;
	}
	void deleteall()
	{
		while(empty()!=0)
		{
			Dequeue();
		}
	}
private:
	int front,rear;
	int data[Max];
};Cirqueue q;
class Map
{
private:
	char maparr[Size + 1][Size + 1];
	int direction;
	int changing;
public:
	Map();
	int count;
	void creatmap(int x, int y);
	void meungame(int number);
	void startpaint();
	void creatall();
	int startgame();
	void roaddisplay();
	void smallroaddisplay(int x, int y);
	void display(int i, int j);
	int walk();
	void Changes();
};
void meun();
void gameexplain();
void storemap(Map aa)
{
	ofstream outfile;
	outfile.open("migong.txt", ios::app | ios::binary);
	if (!outfile)
	{
		cerr << "open file error!";
	}
	outfile.write((char*)&aa, sizeof(aa));
}
void remove(int x,int y) 
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
void hidden()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//�������Ϊ��׼���
	CONSOLE_CURSOR_INFO cci;//��ȡһ�����XXX
	GetConsoleCursorInfo(hOut,&cci);//�����й�ָ���Ŀ���̨��Ļ�������Ĺ��Ŀɼ��Ժʹ�С��Ϣ
	cci.bVisible=0;//���������Ϊ���ɼ�
	SetConsoleCursorInfo(hOut,&cci);//ʹ������Ч
}
HANDLE hThread1;
DWORD WINAPI Thread1(LPVOID lpParameter)
{                                
	int i=15;
	iftime=false;
	while(1)
	{   	
		remove(2,17);
		printf("\r\t%02d",i);
		if(i==0)
		{  
			iftime=true;
			TerminateThread(hThread1, 0);
			CloseHandle(hThread1);
			break; 
		}
		Sleep(1000);
		i--;	
	} 	
	return 0;
}

int main()
{   
	char choich;
	while(true)
	{  	
		int number=1;
		hidden();
		meun();
		cin>>choich;
		int select,flag=0;
		string go;
		switch(choich)
		{
		case '1':
		    system("cls");
			while(true)
			{
				Map map;
				map.creatall();
				flag=0;
				while(true)
				{ 
					map.meungame(number);
					system("cls");
					map.startpaint();
					cout<<"====================="<<endl;
					cout<<"........����ʱ......."<<endl;
					hThread1 = CreateThread(NULL, 0, Thread1, NULL, 0, NULL);	
					Sleep(1000);
					select=map.startgame(); 
					if(select==1 && iftime==false)
					{	 
						map.roaddisplay();
						TerminateThread(hThread1, 0);
						CloseHandle(hThread1);
						remove(2,18);
						cout<<"......��ϲ��ɹ��߳��Թ�......"<<endl;
						cout<<"  .............................."<<endl;
						while(true)
						{   
							cout<<"�����鿴���·��  ok"<<endl;
							cout << "����뱣�浱ǰ�Թ�  store"<<endl;
							cout<<"�Ƿ��������yes/no"<<endl;
							cin>>go;
							if(go=="yes")
							{
								flag=0;
								number++;
							}
							else if (go == "store") {
								storemap(map);
								number++;
							}
								
							else if(go=="no")
								flag=1;
							else if(go=="ok") 
							{
								flag=-1;
								system("cls");
								map.smallroaddisplay((Size+1)/2,(Size+1)/2);
								cout<<endl;
								system("pause");
							}
							else
							{   
								flag=-1;
								cout<<"�Բ���������ķ�ʽ��Ч������������yes/no"<<endl;
							}
							if(flag==1||flag==0)
								break;
						}
						if(flag==1||flag==0)
							break;
					}
					if(select==-1 && iftime==true)
					{  
						TerminateThread(hThread1, 0);
						CloseHandle(hThread1);
						remove(2,18);
						cout<<"δ�ڹ涨ʱ�����߳��Թ�������ʧ��"<<endl;
						cout<<"�Ƿ���һ�δ����أ�yes�� �� �˳���no��"<<endl;
						while(cin>>go)
						{
							if(go=="yes")
							{
							    flag=0;
								q.deleteall();
								break;
							}
							else if(go=="no")
							{
								flag=1;
								break;
							}
							else
								cout<<"���벻�淶����������yes/no"<<endl;
						} 
					}
					if(select==0||flag==1)
					{   
						TerminateThread(hThread1, 0);
						CloseHandle(hThread1);
						break;
					}
				}
				if(flag==1||select==0)
				{  
				system("cls");
					break;
				}
			}
			break;
		case '2':
			gameexplain();
			system("cls");
			break;
		case '3':
			exit(0);
			break;
		default:
			cout<<"����Ĳ��淶,����������"<<endl;
		    system("pause");
			system("cls");
			break;
		}
	}
    return 0;
}
void meun()
{   

	cout<<"��.....��.....��.....��.....��.....��.....��.....��.....��"<<endl;
    cout<<"                                                          "<<endl;
	cout<<"                                                          "<<endl;
	cout<<"                  �� ӭ �� �� �� �� �� Ϸ                 "<<endl;
	cout<<"                                                          "<<endl;
	cout<<"                                                          "<<endl;
	cout<<"                      1 . �� ʼ �� Ϸ                     "<<endl;
	cout<<"                                                          "<<endl;
	cout<<"                      2 . �� Ϸ ˵ ��                     "<<endl;
	cout<<"                                                          "<<endl;
	cout<<"                      3 . �� �� �� Ϸ                     "<<endl;
	cout<<"                                                          "<<endl;
    cout<<"                                                          "<<endl;
	cout<<"                                                          "<<endl;
	cout<<"��.....��.....��.....��.....��.....��.....��.....��.....��"<<endl;
}
void gameexplain()
{
	system("cls");
	cout<<"........................................................."<<endl;
    cout<<"                                                         "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"         1.���̷�������ƣ�������������                  "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"            up����                                       "<<endl;
	cout<<"            down����                                     "<<endl;
	cout<<"            left����                                     "<<endl;
	cout<<"            right����                                    "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"         2.�ڹ涨��15�����߳��Թ���Ϊ�ɹ���              "<<endl;
	cout<<"                                                         "<<endl;
    cout<<"           ������ʱ���ڲ����߳��Թ���ʧ��                "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"         3.��Ϸ��;�����˳����밴ESC��                   "<<endl;
	cout<<"           �����Ҫ�޸��Թ����밴 C ��                   "<<endl;
	cout<<"........................................................."<<endl;
	system("pause");
}
void Map::meungame(int number)
{  
	system("cls");
	count=number;
	cout<<"                                         "<<endl;
	cout<<"           �� ��"<<count<<"�� ��         "<<endl;
	cout<<"                                         "<<endl;
	cout<<"                                         "<<endl;
	system("pause");
}
Map::Map()
{
	int i,j;
	count=0;
	changing = 0;
	for(i=1;i<=Size;i++)
		for(j=1;j<=Size;j++)
			maparr[i][j]=wall;
}
void Map::startpaint()
{  
	maparr[(Size+1)/2][(Size+1)/2]=mouse; 
	maparr[Size-1][Size]=end; 
	for(int i=1;i<=Size;i++)
	{
		for(int j=1;j<=Size;j++)
		{  
			if(maparr[i][j]==mouse && (i!=(Size+1)/2 || j!=(Size+1)/2))
				maparr[i][j]=road;
			display(i,j);
		}
		cout<<endl;
	}
}
void Map::display(int i,int j)
{    
	remove(2*j-2,i-1);
	switch(maparr[i][j])
	{
	case start:
		cout<<"��";
		break; 
	case end:
		cout<<"��";
		break; 
	case wall:
		cout<<"��";
		break; 
	case road:
		cout<<"  ";
		break; 
	case mouse :
		cout<<"��";
		break;
	case smallroad:
		cout<<"*";
		break;
	case maxsmall:
		cout<<"@";
		break;
	}
}
void Map::creatmap(int x,int y)
{
	int c[4][2]={0, 1, 1,0,
				 0,-1,-1,0}; 
	int i,j,t;
	for(i=0;i<4;i++)
	{
		j=rand()%4;
		t=c[i][0];c[i][0]=c[j][0];c[j][0]=t;
		t=c[i][1];c[i][1]=c[j][1];c[j][1]=t;
	}
	maparr[x][y]=road;
	for(i=0;i<4;i++)
		if(maparr[x+2*c[i][0]][y+2*c[i][1]]==wall)
		{
			maparr[x+c[i][0]][y+c[i][1]]=road;
			creatmap(x+2*c[i][0],y+2*c[i][1]);
		}
}
void Map::creatall()
{       
	srand((unsigned)time(NULL));
	creatmap(2*(rand()%(Size/2)+1),2*(rand()%(Size/2)+1)); 
	
} 
int Map::walk()
{
	char c;
	while(c=getch())
	{   
		if(c == 99) return 6;
		if(c==27) return Esc; 
		if(c==72) return left; 
		if(c==80) return right; 
		if(c==75) return up; 
		if(c==77) return down; 
	}
	return -1;
}
int Map::startgame()
{    
	int x=(Size+1)/2;
	int y=(Size+1)/2;
	int flag=0,select;
	while(iftime!=true)
	{
		select=walk(); 
		q.Enqueue(x);
		q.Enqueue(y);
		switch(select)
		{
		case up:
			if(maparr[x][y-1]!=wall)
			{   
				maparr[x][y]=road;
				maparr[x][y-1]=mouse;
				display(x,y);
				display(x,y-1);
				y--;
			}
			break;
		case down:
			if(maparr[x][y+1]!=wall)
			{   
				maparr[x][y]=road;
				maparr[x][y+1]=mouse;
				display(x,y);
				display(x,y+1);
				y++;
			}
			break;
		case left:
			if(maparr[x-1][y]!=wall)
			{   
				maparr[x][y]=road;
				maparr[x-1][y]=mouse;
				display(x,y);
				display(x-1,y);
				x--;
			}
			break;
		case right:
			if(maparr[x+1][y]!=wall)
			{   
				maparr[x][y]=road;
				maparr[x+1][y]=mouse;
				display(x,y);
				display(x+1,y);
				x++;
			}
			break;
		case Esc:
			flag=1;
			break;
		default:
			break;
		}
		if(maparr[Size-1][Size]==mouse||flag==1)
			break;
		if(iftime==true)
			return -1;
	}
	if(flag==1)
		return 0;
	return 1;
}
void Map::Changes() {
	changing = 1;
	int x = (Size + 1) / 2;
	int y = (Size + 1) / 2;
	int flag = 0, select;
	int before = road;
	while (flag != 1)
	{

		select = walk();
		switch (select)
		{
		case up:


			maparr[x][y] = before;
			before = maparr[x][y - 1];
			maparr[x][y - 1] = mouse;
			display(x, y);
			display(x, y - 1);
			y--;

			break;
		case down:
		{
			maparr[x][y] = before;
			before = maparr[x][y + 1];
			maparr[x][y + 1] = mouse;
			display(x, y);
			display(x, y + 1);
			y++;
		}
		break;
		case left:
			if (maparr[x - 1][y] != wall)
			{
				maparr[x][y] = before;
				before = maparr[x - 1][y];
				maparr[x - 1][y] = mouse;
				display(x, y);
				display(x - 1, y);
				x--;
			}
			break;
		case right:
			if (maparr[x + 1][y] != wall)
			{
				maparr[x][y] = before;
				before = maparr[x + 1][y];
				display(x, y);
				display(x + 1, y);
				x++;
			}
			break;
		case Esc:
			flag = 1;
			break;
		case 6:
			switch (before)
			{
			case wall:
				before = road;
				break;
			case road:
				before = wall;
				break;
			}
		default:
			break;
		}

	}
	changing = 0;
	if (flag == 1)
		return;
	return;
	}

void Map::roaddisplay()
{  
	int x,y;
	while(true)
	{   
		x=q.Dequeue();
		y=q.Dequeue();
		maparr[x][y]=6;
		if(x==0)
			break;
		else
		{
			display(x,y);
			maparr[x][y]=road;
		}
	}
}
void Map::smallroaddisplay(int x,int y)
{    
	int direction[][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int p=0,i=0,j=0;
	int arr[100]={0};
	int brr[100]={0};
	int record[100]={0};
	int visited[Size+1][Size+1]={0};
	arr[p]=x;
	brr[p]=y;
	maparr[x][y]=road;
	while(true)
	{
		i=i+1;
		if(i<=4)
		{
			x=arr[p]+direction[i-1][0];
			y=brr[p]+direction[i-1][1];
			if(y<=Size && x<=Size)
			{
				if(maparr[x][y]==road && visited[x][y]==0)
				{
					p++;
					record[p]=i;
					arr[p]=x;
					brr[p]=y;
					visited[x][y]=1;
					i=0;
				}
			}
		}
		else
		{
			i=record[p];
			p--;
		}
		if(x==Size-1 && y==Size-1)
			break;
	}
	for(j=1;j<=p;j++)
			maparr[arr[j]][brr[j]]=7;
	for(int k=1;k<=Size;k++)
		for( j=1;j<=Size;j++) 
			display(k,j);
}
	
	

