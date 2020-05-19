#pragma once

#include "MaxHeap.h"

class PriorityQueue
{
public:
    void Insert(int key) { heap.Insert(key); }
    int Maximum() { return heap.Maximun(); }
    void ExtractMax() { heap.ExtractMax(); }
    void IncreseKey(int index, int key) { heap.IncreaseKey(index, key); }

private:
    MaxHeap heap;
};
