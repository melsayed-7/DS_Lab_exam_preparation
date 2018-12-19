#pragma once

#include <iostream>
using namespace std;

struct Edge
{
	int src,dest;
	double weight;
};


class GraphAdjMatrix
{
	double **adjMatrix;	//pointer to 2D matrix of weights of edges
	int numVertices;
public:
	GraphAdjMatrix(int n);
	void addEdge(Edge e);
	void removeEdge(int i, int j);
	bool isEdge(int i, int j);	
    void print();
	~GraphAdjMatrix();
};
