#pragma once

// Data structure to store Adjacency list nodes
struct Node {
    int val;
    Node* next;
};

// Data structure to store graph edges
struct Edge {
    int src, dest;
};

class GraphAdjList
{
    int vertCount;  // Number of vertices in the graph

    // An array of pointers to Node to represent adjacency list
    Node **head;

public:

    // Function to allocate new node of Adjacency List
    bool AddNewNode(int srcNode, int destNode);

	//default ctor
	GraphAdjList(int nVert = 2);

    // Constructor
    GraphAdjList(Edge edges[], int edgesCount, int nVert);

    // Destructor
    ~GraphAdjList();

	// print all neighboring vertices of given vertex
	void printList();
};