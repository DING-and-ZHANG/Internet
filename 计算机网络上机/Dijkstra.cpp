#include<iostream>
#include "Graph.h"
#define maxDistence 0xFFFFFFF
using namespace std;

//寻找父结点
int Find(int Node, int TransForm, int* Father)
{
	while (Father[Node] != TransForm)
	{
		Node = Father[Node];
	}
	if (Father[Node] == TransForm)
	{
		return Node;
	}
}

//Dijkstra算法
void Graph::Dijkstra(Graph G)
{
	int Node = 0;        //源点最近的点
	int NextJump = 0;    //记录下一跳
	int* Father = new int[G.number];   //父结点数组
	int NowMinDis = maxDistence;       //源点最近距离
	int* Dis = new int[G.number];      //A到其它结点的最短距离
	int* Visited = new int[G.number];  //已访问的结点

	int RouterID = 0;    //路由器ID
	int TransFormID = 0; //转换ID
	cout << "请输入你想从哪个路由器(ID)开始：" << endl;
L1:
	cout << flush;
	cin >> RouterID;
	//将路由器ID转换为正确的ID
	//TransFormID = G.idToMatrix[RouterID - 1];

	//将路由器ID转换为正确的ID
	TransFormID = RouterID;

	//假入该ID不存在内容
	if (TransFormID <= 0)
	{
		cout << "该路由器不存在！请重新输入！" << endl;
		goto L1;
	}

	//初始化
	for (int i = 0; i < G.number; i++)
	{
		//A（源点）到其它结点的距离
		Dis[i] = G.hold[TransFormID - 1].edge[i];
		//所有结点均未访问（-1）
		Visited[i] = -1;
		//父结点初始化为源点
		Father[i] = TransFormID - 1;
	}

	Visited[TransFormID - 1] = 1;          //表明A已访问
	int Circulation = G.number - 1;        //循环次数
	while (Circulation)
	{
		NowMinDis = maxDistence;           //源点最近距离
		//寻找距离点A最近的结点
		for (int i = 0; i < G.number; i++)
		{
			//点A到其它结点的距离小于MAX 且 小于当前最短距离（NowMinDis）且 未被访问 且 非自身
			if (G.hold[TransFormID - 1].edge[i] < maxDistence && G.hold[TransFormID - 1].edge[i] < NowMinDis && Visited[i] == -1 && G.hold[TransFormID - 1].edge[i] != 0)
			{
				//更改最短路径的距离
				NowMinDis = G.hold[TransFormID - 1].edge[i];
				//距离最短的结点
				Node = i;
			}
		}
		Visited[Node] = 1;           //表明Node已访问

		/*
		if (PreNode == -1)
		{
			goto L1;
		}
		else
		{
			//A->Node 大于 A->Pre->Node
			if (Dis[Node] > Dis[PreNode] + G.matrix[PreNode][Node])
			{
				Dis[Node] = Dis[PreNode] + G.matrix[PreNode][Node];
			}
		}
	L1:
		PreNode = Node;
		*/

		for (int i = 0; i < G.number; i++)
		{
			//源点所得最近点可达的结点
			if (G.hold[Node].edge[i] < maxDistence)
			{
				//A->i 大于  A->Node->i
				if (Dis[i] > Dis[Node] + G.hold[Node].edge[i] && Visited[i] == -1 && G.hold[Node].edge[i] != 0)
				{
					Father[i] = Node;
					Dis[i] = Dis[Node] + G.hold[Node].edge[i];
				}
			}
		}
		Circulation--;
	}
	//给Next分配内存
	G.hold[TransFormID - 1].nextJump = new int[G.number];

	//         路由器名称     目的网络         下一跳
	cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "|  RouterID  |  ObjectiveNet  |   NextJump  |" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
	//把下一跳存储并输出路由表
	for (int i = 0; i < G.number; i++)
	{
		//如果目的网络与路由器相连
		if (i == TransFormID - 1)
		{
			//得到路由器的下一跳并存储
			NextJump = Find(i, TransFormID - 1, Father) + 1;
			G.hold[TransFormID - 1].nextJump[i] = NextJump;
			cout << "|  路由器" << G.hold[TransFormID - 1].ID << "   |    " << i + 1 << ".x.x.x" << "     |    " << NextJump << ".x.x.x  |" << endl;
			cout << "---------------------------------------------" << endl;
		}
		//如果目的网络与路由器不相连
		if (i != TransFormID - 1)
		{
			//得到路由器的下一跳并存储
			NextJump = Find(i, TransFormID - 1, Father) + 1;
			G.hold[TransFormID - 1].nextJump[i] = NextJump;
			cout << "|  路由器" << G.hold[TransFormID - 1].ID << "   |    " << i + 1 << ".x.x.x" << "     |    路由器" << NextJump << "  |" << endl;
			cout << "---------------------------------------------" << endl;
		}
	}
}
