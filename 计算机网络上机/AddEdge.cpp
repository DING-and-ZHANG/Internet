#include "Graph.h"
#include<iostream>
#include<fstream>
using namespace std;
#define maxNumber 30
#define maxDistence  0x0FFFFFFF
void Graph::AddEdge()
{
	while (1)
	{
		int ahead = 0;
		int atail = 0;
		int head = 0;
		int tail = 0;
		int heavy = 0;
		cout << "请输入需要增加的边其中一头的路由器编号" << endl;
		cin >> ahead;
		cout << "请输入需要增加的边另一头的路由器编号" << endl;
		cin >> atail;
		cout << "请输入需要增加的边的权重" << endl;
		cin >> heavy;
		head = idToMatrix[ahead - 1];
		tail = idToMatrix[atail - 1];
		if (head < 0 || tail < 0)
			cout << "不存在输入的路由器" << endl;
		else if (head == tail)
			cout << "不能自己将自己连起来" << endl;
		else if (matrix[head][tail] != maxDistence)
			cout << "该边已经存在" << endl;
		else
		{
			matrix[head][tail] = heavy;
			matrix[tail][head] = heavy;
			cout << "添加完成" << endl;
		}
		char judge;
		cout << "是否需要继续加边,（输入n结束）" << endl;
		cin >> judge;
		if (judge == 'n' || judge == 'N')
			break;
	}
	SetNode();
	WriteFile();
}