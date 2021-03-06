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
	int TrueNextJump = 0;//记录实际下一跳
	int* Father = new int[30];   //父结点数组
	int NowMinDis = maxDistence;       //源点最近距离
	int* Dis = new int[30];      //A到其它结点的最短距离
	int* Visited = new int[30];  //已访问的结点

	int RouterID = 0;    //路由器ID
	int TransFormID = 0; //转换ID
	int NewTransID = 0;
	cout << "请输入你想从哪个路由器(ID)开始：" << endl;
	cout << flush;
	cin >> RouterID;

	//将路由器ID转换为正确的ID
	NewTransID = G.idToMatrix[RouterID - 1];
	TransFormID = RouterID;

	//假入该ID不存在内容
	if (NewTransID <= -1)
	{
		cout << "该路由器不存在！" << endl;
	}
	else
	{
		//初始化
		for (int i = 0; i < 30; i++)
		{
			//A（源点）到其它结点的距离
			Dis[i] = G.hold[TransFormID - 1].edge[i];
			//所有结点均未访问（-1）
			Visited[i] = -1;
			//父结点初始化为源点
			Father[i] = TransFormID - 1;
		}

		Visited[TransFormID - 1] = 1;          //表明A已访问
		int Circulation = 30 - 1;        //循环次数
		while (Circulation)
		{
			NowMinDis = maxDistence;           //源点最近距离
			//寻找距离点A最近的结点
			for (int i = 0; i < G.number; i++)
			{
				//点A到其它结点的距离小于MAX 且 小于当前最短距离（NowMinDis）且 未被访问 且 非自身
				if (Dis[i] < maxDistence && Dis[i] < NowMinDis && Visited[i] == -1 && Dis[i] != 0)
				{
					//更改最短路径的距离
					NowMinDis = Dis[i];
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
		G.hold[TransFormID - 1].nextJump = new int[30];
		for (int i = 0; i < 30; i++)
		{
			G.hold[TransFormID - 1].nextJump[i] = -1;
		}

		
		for (int i = 0; i < 30; i++)
		{
			cout << "I:" << i+1 << "  To:" << G.idToMatrix[i]+1 << endl;
		}
		cout << endl << endl;
		for (int i = 0; i < G.number; i++)
		{
			cout << "I:" << i+1 << "  Father:" << Father[i]+1 << endl;
		}
		cout << endl << endl;
		

		//         路由器名称     目的网络         下一跳
		cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << "|  RouterID  |  ObjectiveNet  |   NextJump  |" << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
		//把下一跳存储并输出路由表
		for (int i = 0; i < 30; i++)
		{
			if (G.hold[i].ID >= 0)
			{
				//如果目的网络与路由器相连
				if (i == TransFormID - 1)
				{
					//得到路由器的下一跳并存储
					NextJump = Find(i, TransFormID - 1, Father) + 1;
					for (int j = 0; j < 30; j++)
					{
						if (NextJump == G.idToMatrix[j])
						{
							TrueNextJump = j + 1;
							break;
						}
					}
					//TrueNextJump = G.idToMatrix[NextJump];

					G.hold[TransFormID - 1].nextJump[i] = TrueNextJump;
					cout << "|  路由器" << G.hold[TransFormID - 1].ID << "   |    " << i + 1 << ".x.x.x" << "     |    " << NextJump << ".x.x.x  |" << endl;
					cout << "---------------------------------------------" << endl;
				}
				//如果目的网络与路由器不相连
				if (i != TransFormID - 1)
				{
					//得到路由器的下一跳并存储
					NextJump = Find(i, TransFormID - 1, Father) + 1;
					for (int j = 0; j < 30; j++)
					{
						if (NextJump == G.idToMatrix[j])
						{
							TrueNextJump = j;
							break;
						}
					}
					G.hold[TransFormID - 1].nextJump[i] = TrueNextJump;
					cout << "|  路由器" << G.hold[TransFormID - 1].ID << "   |    " << i + 1 << ".x.x.x" << "     |    路由器" << TrueNextJump << "  |" << endl;
					cout << "---------------------------------------------" << endl;
				}
			}
		}
	}
}
