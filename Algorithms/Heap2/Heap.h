#pragma once

#include <iostream>
#include <numeric>

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

private:
	void Swap(int i, int j)
	{
		T temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
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
	auto Compare = [this](int i, int j){
		return type == EHeapType::MAX ? arr[i] > arr[j] : arr[i] < arr[j];
	};

    int l = index * 2;
    int r = index * 2 + 1;
    int selected = index;

    if(l <= size)
    {
		if(Compare(l, index))
		{
        	selected = l;
		}
    }

    if(r <= size)
    {
		if(Compare(r, selected))
		{
        	selected = r;
		}
    }

    if(selected != index)
    {
        int temp = arr[index];
        arr[index] = arr[selected];
        arr[selected] = temp;

        Heapify(selected);
    }
}

template<typename T>
T Heap<T>::ExtractTop()
{
	if(size < 1)
	{
		return type == EHeapType::MIN ? numeric_limits<int>::min()
									: numeric_limits<int>::max();
	}

	int ret = arr[1];
	arr[1] = arr[size];
	size--;
	Heapify(1);

	return ret;
}