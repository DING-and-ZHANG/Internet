#include "Graph.h"
#include<iostream>
#include<fstream>
using namespace std;
#define maxNumber 30
#define maxDistence  0x0FFFFFFF
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
		head = idToMatrix[ahead - 1];
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