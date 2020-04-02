#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree<int> tree;

	tree.Insert(10);
	tree.Insert(5);
	tree.Insert(15);
	tree.Insert(2);
	tree.Insert(7);
	tree.Insert(12);
	tree.Insert(17);
	tree.Insert(1);
	tree.Insert(4);
	tree.Insert(6);
	tree.Insert(8);
	tree.Insert(11);
	tree.Insert(14);
	tree.Insert(16);
	tree.Insert(18);
	tree.Insert(3);
	
	tree.InorderTravel(tree.GetRoot(), [](const Node<int>* node) {
		cout << node->GetValue() << ", ";
	});
	cout << endl;

	for(int i=1; i<=18; i++)
	{
		tree.Delete(i);
	}
	
	tree.InorderTravel(tree.GetRoot(), [](const Node<int>* node) {
		cout << node->GetValue() << ", ";
	});
	cout << endl;

	return 0;
}