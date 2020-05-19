#include <iostream>
#include <random>
#include "Heap.h"

using namespace std;

int main()
{
    Heap heap;
    heap.Append(4);
    heap.Append(1);
    heap.Append(3);
    heap.Append(2);
    heap.Append(16);
    heap.Append(9);
    heap.Append(10);
    heap.Append(14);
    heap.Append(8);
    heap.Append(7);  

    heap.Sort();

    return 0;
}


