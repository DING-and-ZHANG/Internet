#include<iostream>
#include "Graph.h"
#define maxDistence 0xFFFFFFF
using namespace std;

//Dijkstra�㷨
void Graph::Dijkstra(Graph G, Node& N)
{
	int Node = 0;                   //Դ������ĵ�
	int PreNode = -1;               //��һ�����
	int Count = 0;                  //���ڼ���++
	int NowMinDis = maxDistence;    //Դ���������

	int* Dis = new int[G.number];       //A������������̾���
	int* Visited = new int[G.number];   //�ѷ��ʵĽ��
	int** Road = new int* [G.number];   //·��

	//��ʼ��
	for (int i = 0; i < G.number; i++)
	{
		//A��Դ�㣩���������ľ���
		Dis[i] = N.edge[i];
		//���н���δ���ʣ�-1��
		Visited[i] = -1;
		//ÿ�����·��Ϊ-1
		Road[i] = new int[G.number];
		for (int j = 0; j < 1; j++)
		{
			Road[i][j] = -1;
		}
	}

	Visited[N.ID] = 1;                 //����A�ѷ���
	int Circulation = G.number - 1;    //ѭ������
	while (Circulation)
	{
		NowMinDis = maxDistence;        //Դ���������
		//Ѱ�Ҿ����A����Ľ��
		for (int i = 0; i < G.number; i++)
		{
			//��A���������ľ���С��MAX �� С�ڵ�ǰ��̾��루NowMinDis���� δ������
			if (N.edge[i] < maxDistence && N.edge[i] < NowMinDis && Visited[i] == -1)
			{
				//�������·���ľ���
				NowMinDis = N.edge[i];
				//������̵Ľ��
				Node = i;
			}
		}
		Visited[Node] = 1;           //����Node�ѷ���
		Road[Node][0] = Node;

		/*
		if (PreNode == -1)
		{
			goto L1;
		}
		else
		{
			//A->Node ���� A->Pre->Node
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
			//Դ�����������ɴ�Ľ��
			if (G.matrix[Node][i] < maxDistence)
			{
				//A->i ����  A->Node->i
				if (Dis[i] > Dis[Node] + G.matrix[Node][i] && Visited[i] == -1)
				{
					Road[i][0] = Node;
					Dis[i] = Dis[Node] + G.matrix[Node][i];
				}
			}
		}
		Circulation--;
	}
	//��Nxet�����ڴ�
	N.nextJump = new int[G.number];

	//         ·��������     Ŀ������         ��һ��
	cout << "--------------------------------------------" << endl;
	cout << "|  RouterID  |  ObjectiveNet  |  NextJump  |" << endl;
	cout << "--------------------------------------------" << endl;
	//����һ���洢�����
	for (int i = 0; i < G.number; i++)
	{
		N.nextJump[i] = Road[i][0];
		cout << "|   ·����" << N.ID << "  |    " << i << ".x.x.x" << "     |   ·����" << Road[i][0] << "  |" << endl;
		cout << "--------------------------------------------" << endl;
	}

}
