#include "Graph.h"
#include<iostream>
#include<fstream>
using namespace std;
#define maxNumber 30
#define maxDistence  0x0FFFFFFF
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