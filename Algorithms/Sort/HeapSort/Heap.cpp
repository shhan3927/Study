#include "Heap.h"

void Heap::Append(int value)
{
    arr[heapSize+1] = value;
    heapSize++;
}

void Heap::Build()
{
    for(int i = heapSize / 2; i > 0; i--)
    {
        Heapify(i);
    }
}

void Heap::Heapify(int index)
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

void Heap::Sort()
{
    Build();

    for(int i = heapSize; i>1; i--)
    {
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        heapSize--;
        Heapify(1);
    }
}