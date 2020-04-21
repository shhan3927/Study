#include <iostream>

using namespace std;

void Swap(int& one, int& other)
{
	auto temp = one;
	one = other;
	other = temp;
}

int Division(int* arr, int p, int r)
{
	int key = arr[r];
	int i = p - 1;

	for (int j = p; j < r; j++)
	{
		if (arr[j] < key)
		{
			i++;
			Swap(arr[i], arr[j]);
		}
	}

	Swap(arr[i + 1], arr[r]);
	return i + 1;
}

void QuickSort(int* arr, int p, int r)
{
	if (p >= r)
	{
		return;
	}
	
	int m = Division(arr, p, r);
	QuickSort(arr, p, m - 1);
	QuickSort(arr, m + 1, r);
}

int main()
{
	int arr[] = { 3, 4, 5, 1, 8, 2, 10, 6 };

	QuickSort(arr, 0, 7);

	return 0;
}