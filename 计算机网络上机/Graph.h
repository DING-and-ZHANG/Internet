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
	void WriteFile();//将内存中的信息写入文件（文件第一个数显示的是网络中的路由器个数）
	void ReadFile();//将文件中的信息存入内存中
	void SetNode();//利用邻接矩阵写各个路由器的值
	void Dijkstra(Graph G);//Dijkstra函数

private:
	int number;//网络中路由器的个数
	int** matrix;//网络的邻接矩阵,不存在的结点相应的行列值为-1
	Node* hold;//作为一个数组用来存放各个节点的信息
	int* idToMatrix;//邻接矩阵的序号和路由器序号的对应变量(每个下标对应的值表示的是该下标表示的编号的路由器在邻接矩阵中的序号)
	//该变量下标值+1表示的是其序号
};

