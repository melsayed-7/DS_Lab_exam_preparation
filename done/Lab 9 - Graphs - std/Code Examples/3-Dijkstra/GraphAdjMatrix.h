#pragma once

#include <iostream>
using namespace std;

struct Edge
{
	int src,dest;
	int weight;
	Edge(int s, int d, int w)
	{
		src =s;
		dest =d;
		weight = w;
	}

};


class GraphAdjMatrix
{
	int **adjMatrix;	//pointer to 2D matrix of weights of edges
	int numVertices;
public:
	GraphAdjMatrix(int n);
	void addEdge(Edge e);
	void removeEdge(int i, int j);
	bool isEdge(int i, int j);	
    void print();
	int ** getAdjMatrix();
	~GraphAdjMatrix();
};
