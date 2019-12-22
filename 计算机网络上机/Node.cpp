#include "Node.h"



Node::Node()
{
	ID = 0;
	edge = new int[30];
	nextJump = new int[30];
	for (int i = 0; i < 30; i++)
	{
		edge[i] = 0;
		nextJump[i] = 0;
	}
}


