#include "Graph.h"
#include<iostream>
#include<fstream>
using namespace std;
#define maxNumber 30
#define maxDistence  0x0FFFFFFF
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
