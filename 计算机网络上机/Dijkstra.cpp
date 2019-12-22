#include<iostream>
#include "Graph.h"
#define maxDistence 0xFFFFFFF
using namespace std;

//Dijkstra算法
void Graph::Dijkstra(Graph G)
{
	cout << G.matrix[6][7] << endl;
	int Node = 0;        //源点最近的点
	int PreNode = -1;    //上一个结点
	int NowMinDis = maxDistence;      //源点最近距离
	int* Dis = new int[G.number];     //A到其它结点的最短距离
	int* Visited = new int[G.number]; //已访问的结点
	int** Road = new int* [G.number]; //路径

	int RouterID = 0;    //路由器ID
	int TransFormID = 0; //转换ID
	cout << "请输入你想从哪个路由器(ID)开始：" << endl;
L1:
	cout << flush;
	cin >> RouterID;
	//将路由器ID转换为正确的ID
	TransFormID = G.idToMatrix[RouterID];
	//假入该ID不存在内容
	if (TransFormID < 0)
	{
		cout << "该路由器不存在！请重新输入！" << endl;
		goto L1;
	}

	//初始化
	for (int i = 0; i < G.number; i++)
	{
		//A（源点）到其它结点的距离
		Dis[i] = G.hold[TransFormID].edge[i];
		//所有结点均未访问（-1）
		Visited[i] = -1;
		//每个点的路径为-1
		Road[i] = new int[G.number];
		for (int j = 0; j < 1; j++)
		{
			Road[i][j] = -1;
		}
	}

	Visited[TransFormID] = 1;          //表明A已访问
	int Circulation = G.number - 1;    //循环次数
	while (Circulation)
	{
		NowMinDis = maxDistence;       //源点最近距离
		//寻找距离点A最近的结点
		for (int i = 0; i < G.number; i++)
		{
			//点A到其它结点的距离小于MAX 且 小于当前最短距离（NowMinDis）且 未被访问
			if (G.hold[TransFormID].edge[i] < maxDistence && G.hold[TransFormID].edge[i] < NowMinDis && Visited[i] == -1)
			{
				//更改最短路径的距离
				NowMinDis = G.hold[TransFormID].edge[i];
				//距离最短的结点
				Node = i;
			}
		}
		Visited[Node] = 1;           //表明Node已访问
		Road[Node][0] = Node;

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
			if (G.matrix[Node][i] < maxDistence)
			{
				//A->i 大于  A->Node->i
				if (Dis[i] > Dis[Node] + G.matrix[Node][i] && Visited[i] == -1)
				{
					Road[i][0] = Node;
					Dis[i] = Dis[Node] + G.matrix[Node][i];
				}
			}
		}
		Circulation--;
	}
	//给Nxet分配内存
	G.hold[TransFormID].nextJump = new int[G.number];

	//         路由器名称     目的网络         下一跳
	cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "|  RouterID  |  ObjectiveNet  |   NextJump  |" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
	//把下一跳存储并输出
	for (int i = 0; i < G.number; i++)
	{
		G.hold[TransFormID].nextJump[i] = Road[i][0] + 1;
		cout << "|  路由器" << G.hold[TransFormID].ID << "   |    " << i + 1 << ".x.x.x" << "     |    路由器" << Road[i][0] + 1 << "  |" << endl;
		cout << "---------------------------------------------" << endl;
	}
}
