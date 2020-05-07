#include "SegmentTree.h"
#include <cmath>

void SegmentTree::Init(int* arr, int size)
{
    if(container != nullptr)
    {
        delete[] container;
    }

    v.clear();

    for(int i=0; i<size; i++)
    {
        v.push_back(arr[i]);
    }

    capacity = (int)ceil(log2(size)) * 4 + 1;
    container = new int[capacity];
    Init(1, 0, size-1);
}

int SegmentTree::Init(int index, int start, int end)
{
    if(start == end)
    {
        container[index] = v[start];
        return container[index];
    }

    int mid = (start + end) / 2;
    container[index] = Init(index*2, start, mid) + Init(index*2+1, mid+1, end);
    return container[index];
}

void SegmentTree::Update(int index, int value)
{
    int diff = value - v[index];
    Update(1, 0, v.size()-1, index, diff);
    v[index] = value;
}

void SegmentTree::Update(int node, int start, int end, int index, int diff)
{
    if(index < start || index > end)
    {
        return;
    }

    container[node] += diff;

    if(start == end)
    {
        return;
    }

    int mid = (start + end) / 2;
    Update(node*2, start, mid, index, diff);
    Update(node*2+1, mid+1, end, index, diff);
}

int SegmentTree::GetSum(int left, int right)
{
    return GetSum(1, left, right, 0, v.size()-1);
}

int SegmentTree::GetSum(int node, int left, int right, int start, int end)
{
    if(left > end || right < start)
    {
        return 0;
    }

    if(left <= start && right >= end)
    {
        return container[node];
    }

    int mid = (start + end) / 2;
    return GetSum(node*2, left, right, start, mid) + GetSum(node*2+1, left, right, mid+1, end);
}

void SegmentTree::Foreach(std::function<void (int)> func)
{
    int i=1;
    while(i<=capacity && container[i] != 0)
    {
        func(container[i]);
        i++;
    }
}
