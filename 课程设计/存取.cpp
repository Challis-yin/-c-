
#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include <conio.h>
#include<stack>
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
class Cirqueue {
	public :
		Cirqueue() {
			front=rear=Max-1;
		}
		void Enqueue(int x) {
			if((rear+1)%Max==front)
				cout<<"Queue Full"<<endl;
			else {
				rear=(rear+1)%Max;
				data[rear]=x;
			}
		}
		int Dequeue() {
			if(rear==front)
				return 0;
			else {

				front=(front+1)%Max;
				return data[front];
			}
		}
		int empty() {
			if(rear==front)
				return 0;
			return 1;
		}
		void deleteall() {
			while(empty()!=0) {
				Dequeue();
			}
		}
	private:
		int front,rear;
		int data[Max];
};
Cirqueue q;

struct point { //位置
	int x,y;
} p;
stack<point> path,temp;
class Map {
	private:
		char maparr[Size+1][Size+1];
		int direction;

	public:
		Map();
		int count;
		void creatmap(int x,int y);
		void meungame(int number);
		void startpaint();
		void creatall();
		int startgame();
		void roaddisplay();
		void smallroaddisplay(int x,int y);
		void display(int i,int j);
		void changing();
		int walk();

//寻找所有路径


		void dfs(int x,int y) {
			int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

			if(x==Size-1 && y==Size-1) { //成功---下面处理路径问题
				cout << "******************路径"<< ++count <<  "******************" << endl;
				while(!path.empty()) { //将path里面的点取出来，放在temp里面
					//path从栈顶-栈底的方向，路径是从终点-起点的顺序
					point p1 = path.top();
					path.pop();
					temp.push(p1);
				}
				while(!temp.empty()) {
					//输出temp里面的路径，这样刚好是从起点到终点的顺序
					point p1 = temp.top();
					temp.pop();
					path.push(p1);//将路径放回path里面，因为后面还要回溯!!!
					cout << "(" << p1.x << "," << p1.y << ")" << endl;
				}
				return;
			}
			if(x<0 || x>=Size || y<0 || y>=Size)//越界
				return;
			//如果到了这一步，说明还没有成功，没有出界
			for(int i=0; i<4; i++) { //从4个方向探测
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];//nx,ny：选择一个方向，前进一步之后，新的坐标
				if(0<=nx && nx<Size && 0<=ny && ny<Size && maparr[nx][ny]==0 && maparr[nx][ny]==0) {
					//条件：nx,ny没有出界，maze[nx][ny]=0这个点不是障碍可以走，vis[nx][ny]=0说明(nx,ny)没有访问过，可以访问
					maparr[nx][ny]=1;//设为访问过
					p.x = nx;
					p.y = ny;
					path.push(p);//让当前点进栈
					dfs(nx,ny);//进一步探测
					maparr[nx][ny]=0;//回溯
					path.pop();//由于是回溯，所以当前点属于退回去的点，需要出栈
				}
			}
		}
};
void meun();
void gameexplain();

void storemap(Map aa) {
	ofstream outfile;
	outfile.open("migong.txt", ios::app | ios::binary);
	if (!outfile) {
		cerr << "open file error!";
	}
	outfile.write((char*)&aa, sizeof(aa));
}
void remove(int x,int y) {
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
void hidden() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义输出为标准输出
	CONSOLE_CURSOR_INFO cci;//获取一个光标XXX
	GetConsoleCursorInfo(hOut,&cci);//检索有关指定的控制台屏幕缓冲区的光标的可见性和大小信息
	cci.bVisible=0;//将光标设置为不可见
	SetConsoleCursorInfo(hOut,&cci);//使设置生效
}



HANDLE hThread1;
DWORD WINAPI Thread1(LPVOID lpParameter)//多线程实现时间的控制
{
	int i=15;//设置时间为15秒
	iftime=false;//判断是否还有时间
	while(1)
	{
		remove(2,17);//将光标移动到迷宫的下方
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

void mmp4() {
	//zidingyi ditu moshi
	int flag,select;
	string go;
	int number = 1;
	system("cls");
	while(true) {
		Map map4;
		map4.creatall();
		flag=0;

		system("cls");
		map4.startpaint();
		map4.changing();

		system("cls");
		flag=0;
		while(true) {
			map4.creatall();
			map4.meungame(number);
			system("cls");
			map4.startpaint();
			cout<<"====================="<<endl;
			cout<<"........倒计时......."<<endl;
			hThread1 = CreateThread(NULL, 0, Thread1, NULL, 0, NULL);
			Sleep(1000);
			select=map4.startgame();
			if(select==1 && iftime==false) {
				map4.roaddisplay();
				TerminateThread(hThread1, 0);
				CloseHandle(hThread1);
				remove(2,18);
				cout<<"......恭喜你成功走出迷宫......"<<endl;
				cout<<"  .............................."<<endl;
				while(true) {
					cout<<"如果想查看最短路径  ok\n如果像输出所有路径 oks"<<endl;
					cout << "如果想保存当前迷宫  store"<<endl;
					cout<<"是否继续闯关yes/no"<<endl;
					cin>>go;
					if(go=="yes") {
						flag=0;
						number++;
					} else if(go=="oks") {
						flag=-1;
						int count = 0;
						p.x = (Size+1)/2;
						p.y = (Size+1)/2;
						path.push(p);
						map4.dfs(p.x,p.y);
					} else if (go == "store") {
						storemap(map4);
						number++;
					}

					else if(go=="no")
						flag=1;
					else if(go=="ok") {
						flag=-1;
						system("cls");
						map4.smallroaddisplay((Size+1)/2,(Size+1)/2);
						cout<<endl;
						system("pause");
					} else {
						flag=-1;
						cout<<"对不起，您输入的方式无效，请重新输入yes/no"<<endl;
					}
					if(flag==1||flag==0)
						break;
				}
				if(flag==1||flag==0)
					break;
			}
			if(select==-1 && iftime==true) {
				TerminateThread(hThread1, 0);
				CloseHandle(hThread1);
				remove(2,18);
				cout<<"未在规定时间内走出迷宫，闯关失败"<<endl;
				cout<<"是否再一次闯本关（yes） 或 退出（no）"<<endl;
				while(cin>>go) {
					if(go=="yes") {
						flag=0;
						q.deleteall();
						break;
					} else if(go=="no") {
						flag=1;
						break;
					} else
						cout<<"输入不规范请重新输入yes/no"<<endl;
				}
			}
			if(select==0||flag==1) {
				TerminateThread(hThread1, 0);
				CloseHandle(hThread1);
				break;
			}
		}
		if(flag==1||select==0) {
			system("cls");
			break;
		}
	}
}

int main() {
	char choich;
	while(true) {
		int number=1;
		hidden();
		meun();
		cin>>choich;
		int select,flag=0;
		string go;

		switch(choich) {
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
					cout<<"........倒计时......."<<endl;
					hThread1 = CreateThread(NULL, 0, Thread1, NULL, 0, NULL);
					Sleep(1000);
					select=map.startgame();
					if(select==1 && iftime==false)
					{
						map.roaddisplay();
						TerminateThread(hThread1, 0);
						CloseHandle(hThread1);
						remove(2,18);
						cout<<"......恭喜你成功走出迷宫......"<<endl;
						cout<<"  .............................."<<endl;
						while(true)
						{
							cout<<"如果想查看最短路径  ok"<<endl;
							cout << "如果想保存当前迷宫  store"<<endl;
							cout<<"是否继续闯关yes/no"<<endl;
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
							else if(go=="oks")
							{
								flag=-1;
                                int count = 0;
                                p.x = (Size+1)/2;
                                p.y = (Size+1)/2;
                                path.push(p);
                                map.dfs(p.x,p.y);
							}
							else
							{
								flag=-1;
								cout<<"对不起，您输入的方式无效，请重新输入yes/no"<<endl;
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
						cout<<"未在规定时间内走出迷宫，闯关失败"<<endl;
						cout<<"是否再一次闯本关（yes） 或 退出（no）"<<endl;
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
								cout<<"输入不规范请重新输入yes/no"<<endl;
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
			case '4':
				mmp4();


				break;

			case '5':
				Map a;

				fstream infile("migong.txt",ios::in | ios::binary);
				if (!infile) {
					cout<<"open file error!"<<endl;
					getchar();
					//exit(0);
				}
				infile.read((char*)&a, sizeof(a));


				flag=0;

				while(true) {
					a.meungame(number);
					system("cls");
					a.startpaint();
					cout<<"====================="<<endl;
					cout<<"........倒计时......."<<endl;
					hThread1 = CreateThread(NULL, 0, Thread1, NULL, 0, NULL);
					Sleep(1000);
					select=a.startgame();
					if(select==1 && iftime==false) {
						a.roaddisplay();
						TerminateThread(hThread1, 0);
						CloseHandle(hThread1);
						remove(2,18);
						cout<<"......恭喜你成功走出迷宫......"<<endl;
						cout<<"  .............................."<<endl;
						while(true) {
							cout<<"如果想查看最短路径 请输入 ok\n如果想要打印所有路径 请输入 oks"<<endl;
							cout<<"如果想存储该迷宫 请输入 store"<<endl;
							cin>>go;
							if(go=="yes") {
								flag=0;
								number++;
							} else if (go == "store") {
								storemap(a);
								number++;
							}

							else if(go=="no")
								flag=1;
							else if(go=="ok") {
								flag=-1;
								system("cls");
								a.smallroaddisplay((Size+1)/2,(Size+1)/2);
								cout<<endl;
								system("pause");
							} else {
								flag=-1;
								cout<<"对不起，您输入的方式无效，请重新输入yes/no"<<endl;
							}
							if(flag==1||flag==0)
								break;
						}
						if(flag==1||flag==0)
							break;
					}
					if(select==-1 && iftime==true) {
						TerminateThread(hThread1, 0);
						CloseHandle(hThread1);
						remove(2,18);
						cout<<"未在规定时间内走出迷宫，闯关失败"<<endl;
						cout<<"是否再一次闯本关（yes） 或 退出（no）"<<endl;
						while(cin>>go) {
							if(go=="yes") {
								flag=0;
								q.deleteall();
								break;
							} else if(go=="no") {
								flag=1;
								break;
							} else
								cout<<"输入不规范请重新输入yes/no"<<endl;
						}
					}
					if(select==0||flag==1) {
						TerminateThread(hThread1, 0);
						CloseHandle(hThread1);
						break;
					}
				}
				if(flag==1||select==0) {
					system("cls");
					break;
				}


				break;

//		default:
//			cout<<"输入的不规范,请重新输入"<<endl;
//		    system("pause");
//			system("cls");
		}
	}
	return 0;
}
void meun() {

	cout<<"★.....★.....★.....★.....★.....★.....★.....★.....★"<<endl;
	cout<<"                                                         "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"               课 程 设 计     迷宫问题-2                "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"                      1 . 开 始 游 戏                    "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"                      2 . 游 戏 说 明                     "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"                      3 . 退 出 游 戏                     "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"                      4 . 自 定 义 模 式                  "<<endl;
	cout<<"                                                          "<<endl;
	cout<<"                      5 . 读 取 存 档                    "<<endl;
	cout<<"                                                          "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"★.....★.....★.....★.....★.....★.....★.....★.....★"<<endl;
}
void gameexplain() {
	system("cls");
	cout<<"........................................................."<<endl;
	cout<<"                                                         "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"         1.键盘方向键控制，上下左右行走                  "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"         2.在规定的15秒内走出迷宫则为成功                "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"         3.游戏如想退出，请按ESC键                       "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"         4.输入 ok 显示最短路径                          "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"         5.输入 oks 显示所有路径                         "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"         6.自定义模式为更改迷宫模式                      "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"         7.读取存档可以显示你存储起来的迷宫              "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"                                                         "<<endl;
	cout<<"........................................................."<<endl;
	system("pause");
}
void Map::meungame(int number) {
	system("cls");
	count=number;
	cout<<"                                         "<<endl;
	cout<<"           ◤ 现在是第"<<count<<"关 ◢         "<<endl;
	cout<<"                                         "<<endl;
	cout<<"                                         "<<endl;
	system("pause");
}
Map::Map() {
	int i,j;
	count=0;
	for(i=1; i<=Size; i++)
		for(j=1; j<=Size; j++)
			maparr[i][j]=wall;
}
void Map::startpaint() {
	maparr[(Size+1)/2][(Size+1)/2]=mouse;
	maparr[Size-1][Size]=end;
	for(int i=1; i<=Size; i++) {
		for(int j=1; j<=Size; j++) {
			if(maparr[i][j]==mouse && (i!=(Size+1)/2 || j!=(Size+1)/2))
				maparr[i][j]=road;
			display(i,j);
		}
		cout<<endl;
	}
}
void Map::display(int i,int j) {
	remove(2*j-2,i-1);
	switch(maparr[i][j]) {
		case start:
			cout<<"入";
			break;
		case end:
			cout<<"粮";
			break;
		case wall:
			cout<<"■";
			break;
		case road:
			cout<<"  ";
			break;
		case mouse :
			cout<<"♀";
			break;
		case smallroad:
			cout<<"*";
			break;
		case maxsmall:
			cout<<"@";
			break;
	}
}
void Map::creatmap(int x,int y) {
	int c[4][2]= {0, 1, 1,0,
	              0,-1,-1,0
	             };
	int i,j,t;
	for(i=0; i<4; i++) {
		j=rand()%4;
		t=c[i][0];
		c[i][0]=c[j][0];
		c[j][0]=t;
		t=c[i][1];
		c[i][1]=c[j][1];
		c[j][1]=t;
	}
	maparr[x][y]=road;
	for(i=0; i<4; i++)
		if(maparr[x+2*c[i][0]][y+2*c[i][1]]==wall) {
			maparr[x+c[i][0]][y+c[i][1]]=road;
			creatmap(x+2*c[i][0],y+2*c[i][1]);
		}
}
void Map::creatall() {
	srand((unsigned)time(NULL));
	creatmap(2*(rand()%(Size/2)+1),2*(rand()%(Size/2)+1));

}
int Map::walk() {
	char c;
	while(c=getch()) {

		if(c==100)
			return 7;
		if(c==99) {
			//change();
			return 6;
		}
		if(c==27) return Esc;
		if(c==72) return left;
		if(c==80) return right;
		if(c==75) return up;
		if(c==77) return down;
	}
	return -1;
}
int Map::startgame() {
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
void Map::changing() {
	int changing = 1;
	int x = (Size + 1) / 2;
	int y = (Size + 1) / 2;
	int flag = 0, select;
	int before = road;
	while (flag != 1) {

		select = walk();
		switch (select) {
			case up:
				if(maparr[x][y-1]!=wall) {
					maparr[x][y]=before;
					before = road;
					maparr[x][y-1]=mouse;
					display(x,y);
					display(x,y-1);
					y--;
				} else {
					maparr[x][y]=before;
					before = wall;
					maparr[x][y-1]=mouse;
					display(x,y);
					display(x,y-1);
					y--;
				}
				break;
			case down:
				if(maparr[x][y+1]!=wall) {
					maparr[x][y]=before;
					before = road;
					maparr[x][y+1]=mouse;
					display(x,y);
					display(x,y+1);
					y++;
				} else {
					maparr[x][y]=before;
					before = wall;
					maparr[x][y+1]=mouse;
					display(x,y);
					display(x,y+1);
					y++;
				}
				break;
			case left:
				if(maparr[x-1][y]!=wall) {
					maparr[x][y]=before;
					before = road;
					maparr[x-1][y]=mouse;
					display(x,y);
					display(x-1,y);
					x--;
				} else {
					maparr[x][y]=before;
					before = wall;
					maparr[x-1][y]=mouse;
					display(x,y);
					display(x-1,y);
					x--;
				}
				break;
			case right:
				if(maparr[x+1][y]!=wall) {
					maparr[x][y]=before;
					before = road;
					maparr[x+1][y]=mouse;
					display(x,y);
					display(x+1,y);
					x++;
				} else {
					maparr[x][y]=before;
					before = wall;
					maparr[x+1][y]=mouse;
					display(x,y);
					display(x+1,y);
					x++;
				}
				break;
			case Esc:
				flag = 1;
				break;
			case 6:
				switch (before) {
					case wall:
						before = road;
						break;
					case road:
						before = wall;
						break;
				}
				break;
			case 7:
				flag = 1;
				break;
			default:
				break;
		}

	}
	changing = 0;
	if (flag == 1)
		return;
	return;
}
void Map::roaddisplay() {
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
void Map::smallroaddisplay(int x,int y) {
	int direction[][2]= {{0,1},{1,0},{0,-1},{-1,0}};
	int p=0,i=0,j=0;
	int arr[100]= {0};
	int brr[100]= {0};
	int record[100]= {0};
	int visited[Size+1][Size+1]= {0};
	arr[p]=x;
	brr[p]=y;
	maparr[x][y]=road;
	while(true) {
		i=i+1;
		if(i<=4) {
			x=arr[p]+direction[i-1][0];
			y=brr[p]+direction[i-1][1];
			if(y<=Size && x<=Size) {
				if(maparr[x][y]==road && visited[x][y]==0) {
					p++;
					record[p]=i;
					arr[p]=x;
					brr[p]=y;
					visited[x][y]=1;
					i=0;
				}
			}
		} else {
			i=record[p];
			p--;
		}
		if(x==Size-1 && y==Size-1)
			break;
	}
	for(j=1; j<=p; j++)
		maparr[arr[j]][brr[j]]=7;
	for(int k=1; k<=Size; k++)
		for( j=1; j<=Size; j++)
			display(k,j);
}



