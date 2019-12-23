#include "Graph.h"
#include<iostream>
#include<fstream>
using namespace std;
#define maxNumber 30
#define maxDistence  0x0FFFFFFF

Graph::Graph()
{
	number = 0;
	matrix = new int* [maxNumber];
	for (int i = 0; i < maxNumber; i++)
	{
		matrix[i] = new int[maxNumber];
		for (int j = 0; j < maxNumber; j++)
		{
			matrix[i][j] = -1;
		}
	}
	//matrix;
	hold = new Node[maxNumber];
	idToMatrix = new int [maxNumber];
	for (int i = 0; i < maxNumber; i++)
	{
		idToMatrix[i] = -1;
	}
}

/*//���ڴ��е��ڽӾ�����Ϣд���ļ���
void Graph::WriteFile()
{
	int head = 0;
	int tail = 0;
	//���ڴ��е��ڽӾ�����Ϣд���ļ���
	fstream file("��������.txt", ios::out);
	//�Ƚ��ܵĽ����д���ļ�
	file << number << endl;
	for (int i = 0; i < number; i++)
		for (int j = 0; j < i; j++)
		{
			if (matrix[i][j] != 0 && matrix[i][j] != maxDistence)
			{
				//���þ���ı���ҵ���Ӧ��·�������
				for (int ax = 0; ax < 30; ax++)
				{
					if (idToMatrix[ax] == i)
						tail = ax;
					if (idToMatrix[ax] == j)
						head = ax;
				}
				file << head+1 << " ";
				file << tail+1 << " ";
				file << matrix[i][j] << endl;
			}
		}
	file.close();
}

void Graph::ReadFile()
{
	int head = 0;//һ�ߵ�ͷ��㣨һ����С���Ǹ�Ϊͷ)
	int tail = 0;//һ���ߵ�β�ͽ�㣨һ���Ŵ���Ǹ�Ϊβ�ͣ�
	int heavy = 0;//����ߵ�Ȩ��
	cout << "�������ļ�����һ����������" << endl;
	fstream file("��������.txt", ios::in);
	file >> number;
	//��ʼ����ѭ��д�ڽӾ���
	while (!file.eof())
	{
		file >> head;
		file >> tail;
		file >> heavy;
		matrix[head - 1][tail - 1] = heavy;
		matrix[tail - 1][head - 1] = heavy;
		//���޷��ﵽ����Ϊ������
		idToMatrix[head - 1] = head - 1;
		idToMatrix[tail - 1] = tail - 1;
		for (int i = 0; i < number; i++)
		{
			if (matrix[head - 1][i] == -1)
			{
				matrix[head - 1][i] = maxDistence;
				matrix[i][head - 1] = maxDistence;
			}
			if (matrix[tail - 1][i] == -1)
			{
				matrix[tail - 1][i] = maxDistence;
				matrix[i][tail - 1] = maxDistence;
			}
		}
		matrix[head - 1][head - 1] = 0;
		matrix[tail - 1][tail - 1] = 0;
	}
	file.close();
	//�ٽ��ڽӾ����е�����д����������
	SetNode();
}

void Graph::AddPoint()
{
	cout << "��ʼ���·����" << endl;
	while (1)
	{
		Node aNew;//һ����·����
		cout << "�������·�������" << endl;
		cin >> aNew.ID;
		if (idToMatrix[aNew.ID - 1] >= 0)
		{
			cout << "�Ѿ����ڸ�·����" << endl;
		}
		else
		{
			number++;
			//�����ڽӾ���
			for (int i = 0; i < number - 1; i++)
			{
				matrix[i][number - 1] = maxDistence;
				matrix[number - 1][i] = maxDistence;
			}
			idToMatrix[aNew.ID - 1] = number - 1;
			while (1)
			{
				//ѭ���ӱ�
				int heavy = 0;
				int a = 1;//��ʱ�ı���,���汻���ӵ�·�������
				int n = 0;
				cout << "������������Ϊ" << aNew.ID << "��·�������ĸ�·��������,����0����" << endl;
				cin >> n;
				if (n == 0)
				{
					break;
				}
				a = idToMatrix[n - 1];
				if (a < 0)
				{
					cout << "������������" << endl;
				}
				else if (matrix[a][0] == -1)
				{
					cout << "�����ڶ�Ӧ�Ľ��" << endl;
				}
				else if (aNew.ID == n)
				{
					cout << "�����Լ������Լ�" << endl;
				}
				else
				{
					cout << "�����������·�����������ڽڵ��Ȩ��" << endl;
					cin >> heavy;
					//ͬʱҲҪ����Ӧ�ı����ӵ�·�����ӱ�
					//�����ڽӾ���
					matrix[number - 1][number - 1] = 0;
					matrix[number - 1][a] = heavy;
					matrix[a][number - 1] = heavy;
					cout << "������" << endl;
				}
			}
			//���´������·����������		
			char judge;
			cout << "�Ƿ���Ҫ��������µ�·����(����y����)" << endl;
			cin >> judge;
			if (judge != 'y' && judge != 'Y')
			{
				break;
			}
		}
	}
	//�ٽ�����·�����е���Ϣͨ���ڽӾ�������ڴ�
	SetNode();
	WriteFile();
}

void Graph::AddEdge()
{
	while (1)
	{
		int ahead = 0;
		int atail = 0;
		int head = 0;
		int tail = 0;
		int heavy = 0;
		cout << "��������Ҫ���ӵı�����һͷ��·�������" << endl;
		cin >> ahead;
		cout << "��������Ҫ���ӵı���һͷ��·�������" << endl;
		cin >> atail;
		cout << "��������Ҫ���ӵıߵ�Ȩ��" << endl;
		cin >> heavy;
		head=idToMatrix[ahead - 1];
		tail = idToMatrix[atail - 1];
		if (head < 0 || tail < 0)
				cout << "�����������·����" << endl;
		else if (head == tail)
			cout << "�����Լ����Լ�������" << endl;
		else if (matrix[head][tail] != maxDistence)
			cout << "�ñ��Ѿ�����" << endl;
		else
		{
			matrix[head][tail] = heavy;
			matrix[tail][head] = heavy;
			cout << "������" << endl;
		}
		char judge;
		cout << "�Ƿ���Ҫ�����ӱ�,������n������" << endl;
		cin >> judge;
		if (judge == 'n' || judge == 'N')
			break;
	}
	SetNode();
	WriteFile();
}

void Graph::SetNode()
{
	int head = 0;
	int tail = 0;
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			head = idToMatrix[i];
			tail = idToMatrix[j];
			if (head >= 0 && tail >= 0)
			{
				hold[i].ID = i + 1;
				hold[i].edge[j] = matrix[head][tail];
			}
		}
	}
}

void Graph::DeleteEdge()
{
	while (1)
	{
		int ahead = 0;
		int atail = 0;
		int head = 0;
		int tail = 0;
		int heavy = 0;
		cout << "��������Ҫɾ���ı�����һͷ��·�������" << endl;
		cin >> ahead;
		cout << "��������Ҫɾ���ı���һͷ��·�������" << endl;
		cin >> atail;
		head = idToMatrix[ahead - 1];
		tail = idToMatrix[atail - 1];
		if (head < 0 || tail < 0)
			cout << "�����������·����" << endl;
		else if (head == tail)
			cout << "�Լ����Լ�֮�䲻��Ҫ·��" << endl;
		else if (matrix[head][tail] == maxDistence)
			cout << "�ñ߲�����" << endl;
		else
		{
			matrix[head][tail] = maxDistence;
			matrix[tail][head] = maxDistence;
			cout << "ɾ�����" << endl;
		}
		char judge;
		cout << "�Ƿ���Ҫ����ɾ����,������n������" << endl;
		cin >> judge;
		if (judge == 'n' || judge == 'N')
			break;
	}
	SetNode();
	WriteFile();
}

void Graph::DeletePoint()
{
	while (1)
	{
		int deleteNumber = 0;
		int num = 0;
		cout << "��������Ҫɾ����·�������,ɾ�����·�������֮���·������Ž�������ǰһλ" << endl;
		cin >> num;
		//��ʼ��������(��ֱ�ӵ������ڽӾ���)
		//�Ƚ�ÿһ�д���num�������ϵ�һλ
		deleteNumber= idToMatrix[num - 1];
		if (matrix[num - 1][0] == -1)
		{
			cout << "�޸�·��������������ȷ�ı��" << endl;
		}
		else
		{
			for (int i = deleteNumber; i < number; i++)
				for (int j = deleteNumber; j < i; j++)
				{
					matrix[i][j] = matrix[i][j + 1];
				}
			//�ٽ�ÿһ�д���num����������Ųһλ
			for (int j = 0; j < number; j++)
				for (int i = deleteNumber; i < number; i++)
				{
					matrix[i][j] = matrix[i + 1][j];
				}
			//������䵽��������
			for (int i = 0; i < number; i++)
				for (int j = 0; j < i; j++)
				{
					matrix[j][i] = matrix[i][j];
				}
			//�޸Ķ�Ӧ��
			for (int i = 0; i < 30; i++)
			{
				if(idToMatrix[i]> idToMatrix[num - 1])
				idToMatrix[i]--;
			}
			idToMatrix[num - 1] = -1;
			number--;
			cout << "ɾ�����" << endl;
		}
		cout << "�Ƿ���Ҫ����ɾ�����,����n����" << endl;
		char judge;
		cin >> judge;
		if (judge == 'N' || judge == 'n')
		{
			break;
		}

	}
	SetNode();
	WriteFile();
}

Node Graph::PutNode(int id)
{
	return hold[id - 1];
}*/