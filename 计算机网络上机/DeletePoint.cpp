#include "Graph.h"
#include<iostream>
#include<fstream>
using namespace std;
#define maxNumber 30
#define maxDistence  0x0FFFFFFF
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
		deleteNumber = idToMatrix[num - 1];
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
				if (idToMatrix[i] > idToMatrix[num - 1])
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