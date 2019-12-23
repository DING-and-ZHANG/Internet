#include "Graph.h"
#include<iostream>
#include<fstream>
using namespace std;
#define maxNumber 30
#define maxDistence  0x0FFFFFFF
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
