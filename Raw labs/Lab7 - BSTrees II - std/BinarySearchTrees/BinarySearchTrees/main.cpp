
#include "BinarySearchTree.h"

#include <iostream>
using namespace std;

int main()
{
	BinarySearchTree<int> bst;


	//build tree       8 
	//               /   \ 
	//              3     13
	//             / \   / 
	//            1   4 9

	//==============================================================
	//							InsertBST function
	//==============================================================
	cout << "building the tree with sequence 8 13 3 9 1 4" << endl << endl;
	bst.insert(8);
	bst.insert(13);
	bst.insert(3);
	bst.insert(9);
	bst.insert(1);
	bst.insert(4);

	cout<<"           8"<<endl;
	cout<<"          /  \\"<<endl;
	cout<<"         3    13"<<endl;
	cout<<"        /\\   /"<<endl; 
	cout<<"       1   4 9"<<endl;



	//==============================================================
	//							Traversal
	//==============================================================
	// traverse the tree with different schemes
	cout << "The tree pre-order traversal" << endl;
	bst.preorder_traverse();
	cout << endl;

	cout << "The tree in-order traversal" << endl;
	bst.inorder_traverse();
	cout << endl;

	cout << "The tree post-order traversal" << endl;
	bst.postorder_traverse();
	cout << endl;
	
	//==============================================================
	//							Destroy
	//==============================================================
	
	cout<<"\nNode count = "<<bst.countNodes();

	cout << "\nDestroying tree " << endl;
	bst.destroyTree();
	return 0;
}
