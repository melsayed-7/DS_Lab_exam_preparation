
#include "BSTree.h"

#include <iostream>
using namespace std;

int main()
{
	BSTree<int> bst;

	//build tree       8 
	//               /   \ 
	//              3     13
	//             / \   / 
	//            1   4 9

	//==============================================================
	//							InsertBST function
	//==============================================================
	cout << "building the tree with sequence 8 13 3 9 1 4" << endl << endl;
	bst.insertBST(8);
	bst.insertBST(13);
	bst.insertBST(3);
	bst.insertBST(9);
	bst.insertBST(1);
	bst.insertBST(4);

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
	bst.lessthan(bst.root,10);
	//==============================================================
	//							Destroy
	//==============================================================
	cout << "Destroying tree " << endl;
	bst.destroy_tree();



	return 0;
}
