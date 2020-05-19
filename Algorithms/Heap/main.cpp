#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
	Heap<int> heap(EHeapType::MIN);
	heap.Append(1);
	heap.Append(10);
	heap.Append(4);
	heap.Append(9);
	heap.Append(3);
	heap.Append(8);

	heap.Build();
	cout << heap.ExtractTop() << endl;

	return 0;
}