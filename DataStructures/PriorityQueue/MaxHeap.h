#pragma once

const int HEAP_MAX = 10;

class MaxHeap
{
public:
    void Insert(int key);
    void Heapify(int index);
    void IncreaseKey(int index, int key);
    int ExtractMax();
    int Maximun();

private:
    int heapSize = 0;
    int arr[HEAP_MAX+1];
};
