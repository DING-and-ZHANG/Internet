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
		cout << "请输入需要删除的路由器编号,删除后该路由器编号之后的路由器编号将依次提前一位" << endl;
		cin >> num;
		//开始调整矩阵(先直接调整下邻接矩阵)
		//先将每一列大于num的依次上调一位
		deleteNumber = idToMatrix[num - 1];
		if (matrix[num - 1][0] == -1)
		{
			cout << "无该路由器，请输入正确的编号" << endl;
		}
		else
		{
			for (int i = deleteNumber; i < number; i++)
				for (int j = deleteNumber; j < i; j++)
				{
					matrix[i][j] = matrix[i][j + 1];
				}
			//再将每一行大于num的依次向左挪一位
			for (int j = 0; j < number; j++)
				for (int i = deleteNumber; i < number; i++)
				{
					matrix[i][j] = matrix[i + 1][j];
				}
			//最后扩充到整个矩阵
			for (int i = 0; i < number; i++)
				for (int j = 0; j < i; j++)
				{
					matrix[j][i] = matrix[i][j];
				}
			//修改对应表
			for (int i = 0; i < 30; i++)
			{
				if (idToMatrix[i] > idToMatrix[num - 1])
					idToMatrix[i]--;
			}
			idToMatrix[num - 1] = -1;
			number--;
			cout << "删除完成" << endl;
		}
		cout << "是否需要继续删除结点,输入n结束" << endl;
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