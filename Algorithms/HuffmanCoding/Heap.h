#pragma once

#include <iostream>
#include <numeric>
#include <functional>

using namespace std;

const int HEAP_MAX = 100;

enum class EHeapType
{
	MIN,
	MAX,
};

template<typename T>
class Heap
{
public:
	Heap() = delete;
	Heap(EHeapType inType)
	: type(inType) {}

public:
	void Append(T value);
	void Build();
	void Heapify(int index);
	T ExtractTop();
	void Foreach(function<void (T& value)> func);
	int GetSize() const { return size; }

private:
	void Swap(int i, int j)
	{
		T temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
public:
	function<bool (T, T)> Compare = nullptr;
private:
	EHeapType type;
	T arr[HEAP_MAX];
	int size = 0;
};

template<typename T>
void Heap<T>::Append(T value)
{
	arr[size+1] = value;
	size++;
}

template<typename T>
void Heap<T>::Build()
{
    for(int i = size / 2; i > 0; i--)
    {
        Heapify(i);
    }
}

template<typename T>
void Heap<T>::Heapify(int index)
{
    int l = index * 2;
    int r = index * 2 + 1;
    int selected = index;

    if(l <= size)
    {
		if(Compare(arr[l],  arr[index]))
		{
        	selected = l;
		}
    }

    if(r <= size)
    {
		if(Compare(arr[r],  arr[selected]))
		{
        	selected = r;
		}
    }

    if(selected != index)
    {
		Swap(index, selected);
        Heapify(selected);
    }
}

template<typename T>
T Heap<T>::ExtractTop()
{
	if(size < 1)
	{
		return T();
	}

	T ret = arr[1];
	arr[1] = arr[size];
	size--;
	Heapify(1);

	return ret;
}

template<typename T>
void Heap<T>::Foreach(function<void (T& value)> func)
{
	for(int i=1; i<=size; i++)
	{
		func(arr[i]);
	}
}