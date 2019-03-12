#include <iostream>
#include "Binary_tree.h"

using namespace std;

int main()
{
	Tree<int> Int_Tree(10);
	Int_Tree.add_node(5);
	Int_Tree.add_node(15);
	Int_Tree.add_node(7);
	Int_Tree.add_node(4);
	Int_Tree.add_node(7);
	Int_Tree.add_node(12);
	Int_Tree.add_node(18);

	cout << "Prefix print:\n";
	Int_Tree.treeprint_prefix();

	cout << "Infix print:\n";
	Int_Tree.treeprint_infix();

	cout << "Postfix print:\n";
	Int_Tree.treeprint_postfix();
};

