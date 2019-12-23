#include "Graph.h"
#include<iostream>
#include<fstream>
using namespace std;
#define maxNumber 30
#define maxDistence  0x0FFFFFFF
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