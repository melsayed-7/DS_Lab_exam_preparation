#include "GraphAdjMatrix.h"

int main(){
        GraphAdjMatrix g(6);

		Edge EdgeList[] = 
		{ 
			{0,1, 2} , {0, 2, 1}, {1, 2, 5}, 
			{2, 3, 4} , {4, 5, 7}
		};

	    int n = sizeof(EdgeList)/sizeof(Edge);

		for(int i=0; i<n; i++)
			g.addEdge(EdgeList[i]);

		g.print(); 
		cout<<endl;
}