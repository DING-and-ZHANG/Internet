#include "Graph.h"
#include<iostream>
#include<fstream>
using namespace std;
#define maxNumber 30
#define maxDistence  0x0FFFFFFF
void Graph::ReadFile()
{
	int head = 0;//一边的头结点（一般编号小的那个为头)
	int tail = 0;//一个边的尾巴结点（一般编号大的那个为尾巴）
	int heavy = 0;//这个边的权重
	cout << "先利用文件创建一个网络拓扑" << endl;
	fstream file("网络拓扑.txt", ios::in);
	file >> number;
	//开始利用循环写邻接矩阵
	while (!file.eof())
	{
		file >> head;
		file >> tail;
		file >> heavy;
		matrix[head - 1][tail - 1] = heavy;
		matrix[tail - 1][head - 1] = heavy;
		//将无法达到的置为最大距离
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
	//再将邻接矩阵中的内容写入各个结点中
	SetNode();
}