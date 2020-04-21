#include "MaxHeap.h"
#include <limits>

using namespace std;

void MaxHeap::Insert(int key)
{
    heapSize++;
    arr[heapSize] = numeric_limits<int>::min();
    IncreaseKey(heapSize, key);
}

void MaxHeap::IncreaseKey(int index, int key)
{
    if(key < arr[index])
    {
        return;
    }

    arr[index] = key;
    while(index > 1 && arr[index] > arr[index/2])
    {
        int temp = arr[index];
        arr[index] = arr[index / 2];
        arr[index / 2] = temp;
        index = index / 2;
    }
}

int MaxHeap::ExtractMax()
{
    if(heapSize < 1)
    {
        return numeric_limits<int>::min();
    }

    int max = arr[1];
    arr[1] = arr[heapSize];
    heapSize--;
    Heapify(1);

    return max;
}

int MaxHeap::Maximun()
{
    if(heapSize < 1)
    {
        return numeric_limits<int>::min();
    }

    return arr[1];
}

void MaxHeap::Heapify(int index)
{
    int l = index * 2;
    int r = index * 2 + 1;
    int largest = index;

    if(l <= heapSize && arr[l] > arr[index])
    {
        largest = l;
    }

    if(r <= heapSize && arr[r] > arr[largest])
    {
        largest = r;
    }

    if(largest != index)
    {
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;

        Heapify(largest);
    }
}
