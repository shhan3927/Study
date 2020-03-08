#pragma once

#include <iostream>

using namespace std;

const int HEAP_MAX = 100;

template<typename T>
class Heap
{
public:
	void Add(T value);
	T GetRoot();
	void Print();
	void Swap(int i, int j)
	{
		T temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

private:
	T arr[HEAP_MAX];
	int size = 0;
};

template<typename T>
void Heap<T>::Add(T value)
{
	if (size >= HEAP_MAX) { return; }
	size++;
	arr[size] = value;
	int i = size / 2;
	int beforeIndex = size;

	while (i >= 1 && arr[beforeIndex] > arr[i])
	{
		Swap(beforeIndex, i);
		i = i / 2;
	}
}

template<typename T>
T Heap<T>::GetRoot()
{
	if (size == 0) { return T(); }

	T ret = arr[1];
	arr[1] = arr[size];
	size--;
	int i = 1;

	int leftIndex = 1 * 2;
	int rightIndex = 1 * 2 + 1;
	bool stateOfSwap = true;
	while ((leftIndex <= size || rightIndex <= size) && stateOfSwap)
	{
		int maxIndex = arr[leftIndex] >= arr[rightIndex] ? leftIndex : rightIndex;
		if (arr[i] < arr[maxIndex])
		{
			Swap(i, maxIndex);
			i = maxIndex;
			leftIndex = i * 2;
			rightIndex = i * 2 + 1;
		}
		else {
			stateOfSwap = false;
		}
	}

	return ret;
}

template<typename T>
void Heap<T>::Print()
{
	for (int i = 1; i <= size; i++)
	{
		cout << arr[i] << ", ";
	}

	cout << endl;
}