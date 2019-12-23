#include "Graph.h"
#include<iostream>
#include<fstream>
using namespace std;
#define maxNumber 30
#define maxDistence  0x0FFFFFFF
void Graph::AddPoint()
{
	cout << "开始添加路由器" << endl;
	while (1)
	{
		Node aNew;//一个新路由器
		cout << "请输入该路由器编号" << endl;
		cin >> aNew.ID;
		if (idToMatrix[aNew.ID - 1] >= 0)
		{
			cout << "已经存在该路由器" << endl;
		}
		else
		{
			number++;
			//更新邻接矩阵
			for (int i = 0; i < number - 1; i++)
			{
				matrix[i][number - 1] = maxDistence;
				matrix[number - 1][i] = maxDistence;
			}
			idToMatrix[aNew.ID - 1] = number - 1;
			while (1)
			{
				//循环加边
				int heavy = 0;
				int a = 1;//临时的变量,保存被连接的路由器编号
				int n = 0;
				cout << "请输入这个编号为" << aNew.ID << "的路由器和哪个路由器相连,输入0结束" << endl;
				cin >> n;
				if (n == 0)
				{
					break;
				}
				a = idToMatrix[n - 1];
				if (a < 0)
				{
					cout << "不存在这个结点" << endl;
				}
				else if (matrix[a][0] == -1)
				{
					cout << "不存在对应的结点" << endl;
				}
				else if (aNew.ID == n)
				{
					cout << "不能自己连接自己" << endl;
				}
				else
				{
					cout << "请输入这个新路由器到该相邻节点的权重" << endl;
					cin >> heavy;
					//同时也要给相应的被连接的路由器加边
					//更新邻接矩阵
					matrix[number - 1][number - 1] = 0;
					matrix[number - 1][a] = heavy;
					matrix[a][number - 1] = heavy;
					cout << "添加完成" << endl;
				}
			}
			//更新存放所有路由器的数组		
			char judge;
			cout << "是否需要继续添加新的路由器(输入y继续)" << endl;
			cin >> judge;
			if (judge != 'y' && judge != 'Y')
			{
				break;
			}
		}
	}
	//再将各个路由器中的信息通过邻接矩阵存入内存
	SetNode();
	WriteFile();
}