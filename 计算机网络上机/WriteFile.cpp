#include "Graph.h"
#include<iostream>
#include<fstream>
using namespace std;
#define maxNumber 30
#define maxDistence  0x0FFFFFFF
//将内存中的邻接矩阵信息写入文件中
void Graph::WriteFile()
{
	int head = 0;
	int tail = 0;
	//将内存中的邻接矩阵信息写入文件中
	fstream file("网络拓扑.txt", ios::out);
	//先将总的结点数写入文件
	file << number << endl;
	for (int i = 0; i < number; i++)
		for (int j = 0; j < i; j++)
		{
			if (matrix[i][j] != 0 && matrix[i][j] != maxDistence)
			{
				//利用矩阵的标号找到对应的路由器编号
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
