#include <iostream>
#include "SegmentTree.h"

using namespace std;

int main()
{
	SegmentTree sTree;

	int arr[4] = {3, 5, 7, 9};
	sTree.Init(arr, 4);
	sTree.Foreach([](int v)
	{
		cout << v << " ";
	});
	cout << endl;

	sTree.Update(1, 6);
	sTree.Foreach([](int v)
	{
		cout << v << " ";
	});
	cout << endl;

	cout << sTree.GetSum(0, 2) << endl;

	return 0;
}