#pragma once

const int HEAP_MAX = 10;

class Heap
{
public:
    void Append(int value);
    void Build();
    void Heapify(int index);
    void Sort();

private:
    int heapSize = 0;
    int arr[HEAP_MAX+1];
};
