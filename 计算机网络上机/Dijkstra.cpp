#include<iostream>
#include "Graph.h"
#define maxDistence 0xFFFFFFF
using namespace std;

//Dijkstra算法
void Graph::Dijkstra(Graph G, Node& N)
{
	int Node = 0;                   //源点最近的点
	int PreNode = -1;               //上一个结点
	int Count = 0;                  //用于计数++
	int NowMinDis = maxDistence;    //源点最近距离

	int* Dis = new int[G.number];       //A到其它结点的最短距离
	int* Visited = new int[G.number];   //已访问的结点
	int** Road = new int* [G.number];   //路径

	//初始化
	for (int i = 0; i < G.number; i++)
	{
		//A（源点）到其它结点的距离
		Dis[i] = N.edge[i];
		//所有结点均未访问（-1）
		Visited[i] = -1;
		//每个点的路径为-1
		Road[i] = new int[G.number];
		for (int j = 0; j < 1; j++)
		{
			Road[i][j] = -1;
		}
	}

	Visited[N.ID] = 1;                 //表明A已访问
	int Circulation = G.number - 1;    //循环次数
	while (Circulation)
	{
		NowMinDis = maxDistence;        //源点最近距离
		//寻找距离点A最近的结点
		for (int i = 0; i < G.number; i++)
		{
			//点A到其它结点的距离小于MAX 且 小于当前最短距离（NowMinDis）且 未被访问
			if (N.edge[i] < maxDistence && N.edge[i] < NowMinDis && Visited[i] == -1)
			{
				//更改最短路径的距离
				NowMinDis = N.edge[i];
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
	N.nextJump = new int[G.number];

	//         路由器名称     目的网络         下一跳
	cout << "--------------------------------------------" << endl;
	cout << "|  RouterID  |  ObjectiveNet  |  NextJump  |" << endl;
	cout << "--------------------------------------------" << endl;
	//把下一跳存储并输出
	for (int i = 0; i < G.number; i++)
	{
		N.nextJump[i] = Road[i][0];
		cout << "|   路由器" << N.ID << "  |    " << i << ".x.x.x" << "     |   路由器" << Road[i][0] << "  |" << endl;
		cout << "--------------------------------------------" << endl;
	}

}
