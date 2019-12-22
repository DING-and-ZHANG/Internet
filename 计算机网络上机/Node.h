#pragma once
class Node
{
public:
	Node();
	friend class Graph;


private:
	int ID;//路由器编号
	int* edge;//记录与该路由器相邻的路由器的边的权重，作为数组，下标表示路由器，值表示权重不相邻的置为最大值
	int* nextJump;//记录到各个路由器在最短路径下的下一跳
};

