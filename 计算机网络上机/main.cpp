#include<iostream>
#include"Graph.h"
#include"Node.h"
using namespace std;

int main()
{
	Graph net;
	net.ReadFile();
	while (1)
	{
		cout << "1.增加路由器" << endl;
		cout << "2.增加边" << endl;
		cout << "3.删除路由器" << endl;
		cout << "4.删除边" << endl;
		cout << "5.输出路由表" << endl;
		cout << "6.结束" << endl;
		cout << "已生成网络拓扑，请输入相应编号选择需要的操作" << endl;
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			net.AddPoint();
			break;
		}
		case 2:
		{
			net.AddEdge();
			break;
		}
		case 3:
		{
			net.DeletePoint();
			break;
		}
		case 4:
		{
			net.DeleteEdge();
			break;
		}
		case 5:
		{
			net.Dijkstra(net);
			break;
		}
		case 6:
		{
			return 0;
		}
		default:
		{
			cout << "请输入1-5之间的数" << endl;
			break;
		}
		}
	}


}