#include "GraphAdjList.h"
#include <iostream>
using namespace std;

    // Function to allocate new node of Adjacency List
    bool GraphAdjList::AddNewNode(int srcNode, int destNode)
    {
		if(srcNode>=vertCount || destNode>=vertCount )
			return false;
		
		Node* newNodePtr = new Node;
        newNodePtr->val = destNode;

        // point new node to current head
        newNodePtr->next = head[srcNode];
		head[srcNode] = newNodePtr; 
		return true;
    }

	//default ctor
	GraphAdjList::GraphAdjList(int nVert)
	{
        // allocate memory
        head = new Node*[nVert]();
        vertCount = nVert;

        // initialize head pointer for all vertices
        for (int i = 0; i < vertCount; i++)
            head[i] = nullptr;

	}


    // Constructor
    GraphAdjList::GraphAdjList(Edge edges[], int edgesCount, int nVert)
    {
        // allocate memory
        head = new Node*[nVert]();
        vertCount = nVert;

        // initialize head pointer for all vertices
        for (int i = 0; i < vertCount; i++)
            head[i] = nullptr;

        // add edges to the directed graph
        for (unsigned i = 0; i < edgesCount; i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;

			AddNewNode(src, dest);

            // Uncomment below lines for undirected graph

			//AddNewNode(dest, src);
        }
    }

    // Destructor
    GraphAdjList::~GraphAdjList() {
        for (int i = 0; i < vertCount; i++)
            delete[] head[i];

        delete[] head;
    }

	// print all neighboring vertices of given vertex
	void GraphAdjList::printList()
	{
		cout<<"\nAdjacency List:\n";
		// print adjacency list representation of graph
		for (int i = 0; i < vertCount; i++)
		{
			// print given vertex
			cout << i << " --";

			// print all its neighboring vertices
			Node* ptr = head[i];

			while (ptr != nullptr)
			{
				cout << " -> " << ptr->val << " ";
				ptr = ptr->next;
			}
			cout <<"->*"<< endl;
		}
	}