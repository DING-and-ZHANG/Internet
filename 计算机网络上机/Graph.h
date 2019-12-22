#pragma once
#include"Node.h"
class Graph
{
public:
	Graph();
	void AddPoint();
	void AddEdge();
	void DeletePoint();
	void DeleteEdge();
	void WriteFile();//���ڴ��е���Ϣд���ļ����ļ���һ������ʾ���������е�·����������
	void ReadFile();//���ļ��е���Ϣ�����ڴ���
	void SetNode();//�����ڽӾ���д����·������ֵ
	void Dijkstra(Graph G);//Dijkstra����

private:
	int number;//������·�����ĸ���
	int** matrix;//������ڽӾ���,�����ڵĽ����Ӧ������ֵΪ-1
	Node* hold;//��Ϊһ������������Ÿ����ڵ����Ϣ
	int* idToMatrix;//�ڽӾ������ź�·������ŵĶ�Ӧ����(ÿ���±��Ӧ��ֵ��ʾ���Ǹ��±��ʾ�ı�ŵ�·�������ڽӾ����е����)
	//�ñ����±�ֵ+1��ʾ���������
};

