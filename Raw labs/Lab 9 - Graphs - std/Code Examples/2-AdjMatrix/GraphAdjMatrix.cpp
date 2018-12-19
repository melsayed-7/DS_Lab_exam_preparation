#include "GraphAdjMatrix.h"

#include <iostream>
using namespace std;

//check this
//https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/



GraphAdjMatrix::GraphAdjMatrix(int n)
{
	numVertices = n;
	adjMatrix = new double*[n];
	for(int i=0; i<n; i++)
	{
		adjMatrix[i] = new double[n];
		for(int j = 0; j<n; j++)
			adjMatrix[i][j] = 0;
	}
}
void GraphAdjMatrix::addEdge(Edge e)
{
	adjMatrix[e.src][e.dest] = e.weight;
	adjMatrix[e.dest][e.src] = e.weight;
}
 
void GraphAdjMatrix::removeEdge(int i, int j) 
{
    adjMatrix[i][j] = 0;
    adjMatrix[j][i] = 0;
}
 
bool GraphAdjMatrix::isEdge(int i, int j) 
{
    return adjMatrix[i][j];
}

void GraphAdjMatrix::print() {
	cout<<"\n    ";
	for(int j=0; j<numVertices; j++)
		cout<<j<<" ";
	cout<<"\n   ";
	for(int j=0; j<numVertices; j++)
		cout<<"--";
	for (int i = 0; i < numVertices; i++) {
                cout <<endl<< i << " | ";
                for (int j = 0; j < numVertices; j++)
                    cout << adjMatrix[i][j] << " ";
                  
    }

}
 
GraphAdjMatrix::~GraphAdjMatrix() {
    for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];
    delete[] adjMatrix;
}

