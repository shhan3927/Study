#include <iostream>
#include <queue>
#include <cmath>
#include "BinarySearchTree.h"

using namespace std;

void PrintTree(BinarySearchTree<int>& tree)
{
	queue<int> values;
	int depth = tree.GetDepth(tree.GetRoot());
	tree.PreorderTravel(tree.GetRoot(), [&values](const Node<int>* node) {
		values.push(node->GetValue());
	});

	int i = 0;
	while(!values.empty())
	{
		int count = pow(2, i);
		int tabCount = depth - 1 - i;

		for(int j=0; j<tabCount; j++)
		{
			cout << "\t";
		}

		for(int j=0; j<count; j++)
		{
			cout << values.front() << "\t";
			values.pop();
		}

		cout << endl;
		i++;
	}
}

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

	PrintTree(tree);
	tree.LeftRotate(tree.Search(15));
	PrintTree(tree);
	
	// tree.InorderTravel(tree.GetRoot(), [](const Node<int>* node) {
	// 	cout << node->GetValue() << ", ";
	// });
	// cout << endl;

	// for(int i=1; i<=18; i++)
	// {
	// 	tree.Delete(i);
	// }
	
	// tree.InorderTravel(tree.GetRoot(), [](const Node<int>* node) {
	// 	cout << node->GetValue() << ", ";
	// });
	// cout << endl;

	

	return 0;
}