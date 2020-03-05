#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree<int> tree;

	tree.Add(5);
	tree.Add(3);
	tree.Add(8);
	tree.Add(1);
	tree.Add(4);
	tree.Add(6);
	tree.Add(9);

	tree.PreorderTravel(tree.GetRoot(), [](const Node<int>* node) {
		cout << node->GetValue() << ", ";
	});
	cout << endl;

	tree.InorderTravel(tree.GetRoot(), [](const Node<int>* node) {
		cout << node->GetValue() << ", ";
	});
	cout << endl;

	tree.PostorderTravel(tree.GetRoot(), [](const Node<int>* node) {
		cout << node->GetValue() << ", ";
	});
	cout << endl;

	auto node = tree.Find(tree.GetRoot(), 3);
	cout << tree.Find(tree.GetRoot(), 3)->GetValue() << endl;
	//cout << tree.GetDepth(node) << endl;

	return 0;
}