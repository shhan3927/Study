/* hello.cpp */
#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
	Heap<int> heap;
	heap.Add(1);
	heap.Add(10);
	heap.Add(4);
	heap.Add(9);
	heap.Add(3);
	heap.Add(8);

	heap.Print();
	cout << "root : " << heap.GetRoot() << endl;
	heap.Print();

	heap.Add(7);
	heap.Print();

	return 0;
}