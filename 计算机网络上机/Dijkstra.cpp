#include<iostream>
#include "Graph.h"
#define maxDistence 0xFFFFFFF
using namespace std;

//Ѱ�Ҹ����
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

//Dijkstra�㷨
void Graph::Dijkstra(Graph G)
{
	int Node = 0;        //Դ������ĵ�
	int NextJump = 0;    //��¼��һ��
	int* Father = new int[G.number];   //���������
	int NowMinDis = maxDistence;       //Դ���������
	int* Dis = new int[G.number];      //A������������̾���
	int* Visited = new int[G.number];  //�ѷ��ʵĽ��

	int RouterID = 0;    //·����ID
	int TransFormID = 0; //ת��ID
	cout << "������������ĸ�·����(ID)��ʼ��" << endl;
L1:
	cout << flush;
	cin >> RouterID;
	//��·����IDת��Ϊ��ȷ��ID
	//TransFormID = G.idToMatrix[RouterID - 1];

	//��·����IDת��Ϊ��ȷ��ID
	TransFormID = RouterID;

	//�����ID����������
	if (TransFormID <= 0)
	{
		cout << "��·���������ڣ����������룡" << endl;
		goto L1;
	}

	//��ʼ��
	for (int i = 0; i < G.number; i++)
	{
		//A��Դ�㣩���������ľ���
		Dis[i] = G.hold[TransFormID - 1].edge[i];
		//���н���δ���ʣ�-1��
		Visited[i] = -1;
		//������ʼ��ΪԴ��
		Father[i] = TransFormID - 1;
	}

	Visited[TransFormID - 1] = 1;          //����A�ѷ���
	int Circulation = G.number - 1;        //ѭ������
	while (Circulation)
	{
		NowMinDis = maxDistence;           //Դ���������
		//Ѱ�Ҿ����A����Ľ��
		for (int i = 0; i < G.number; i++)
		{
			//��A���������ľ���С��MAX �� С�ڵ�ǰ��̾��루NowMinDis���� δ������ �� ������
			if (G.hold[TransFormID - 1].edge[i] < maxDistence && G.hold[TransFormID - 1].edge[i] < NowMinDis && Visited[i] == -1 && G.hold[TransFormID - 1].edge[i] != 0)
			{
				//�������·���ľ���
				NowMinDis = G.hold[TransFormID - 1].edge[i];
				//������̵Ľ��
				Node = i;
			}
		}
		Visited[Node] = 1;           //����Node�ѷ���

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
			if (G.hold[Node].edge[i] < maxDistence)
			{
				//A->i ����  A->Node->i
				if (Dis[i] > Dis[Node] + G.hold[Node].edge[i] && Visited[i] == -1 && G.hold[Node].edge[i] != 0)
				{
					Father[i] = Node;
					Dis[i] = Dis[Node] + G.hold[Node].edge[i];
				}
			}
		}
		Circulation--;
	}
	//��Next�����ڴ�
	G.hold[TransFormID - 1].nextJump = new int[G.number];

	//         ·��������     Ŀ������         ��һ��
	cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "|  RouterID  |  ObjectiveNet  |   NextJump  |" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
	//����һ���洢�����·�ɱ�
	for (int i = 0; i < G.number; i++)
	{
		//���Ŀ��������·��������
		if (i == TransFormID - 1)
		{
			//�õ�·��������һ�����洢
			NextJump = Find(i, TransFormID - 1, Father) + 1;
			G.hold[TransFormID - 1].nextJump[i] = NextJump;
			cout << "|  ·����" << G.hold[TransFormID - 1].ID << "   |    " << i + 1 << ".x.x.x" << "     |    " << NextJump << ".x.x.x  |" << endl;
			cout << "---------------------------------------------" << endl;
		}
		//���Ŀ��������·����������
		if (i != TransFormID - 1)
		{
			//�õ�·��������һ�����洢
			NextJump = Find(i, TransFormID - 1, Father) + 1;
			G.hold[TransFormID - 1].nextJump[i] = NextJump;
			cout << "|  ·����" << G.hold[TransFormID - 1].ID << "   |    " << i + 1 << ".x.x.x" << "     |    ·����" << NextJump << "  |" << endl;
			cout << "---------------------------------------------" << endl;
		}
	}
}
