#include "Graph.h"
#include<iostream>
#include<fstream>
using namespace std;
#define maxNumber 30
#define maxDistence  0x0FFFFFFF
//���ڴ��е��ڽӾ�����Ϣд���ļ���
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
				file << head + 1 << " ";
				file << tail + 1 << " ";
				file << matrix[i][j] << endl;
			}
		}
	file.close();
}
