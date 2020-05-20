#include <iostream>

using namespace std;

int Find(int* arr, int n)
{
	if(n == arr[n])
	{
		return n;
	}

	arr[n] = Find(arr, arr[n]);
	return arr[n];
}

void Union(int* arr, int n1, int n2)
{
	int x = Find(arr, n1);
	int y = Find(arr, n2);

	if(x != y)
	{
		arr[y] = x;
	}
}

int main()
{
	int arr[8] {0, 1, 2, 3, 4, 5, 6, 7};

	Union(arr, 1, 2);
	Union(arr, 2, 3);
	Union(arr, 3, 4);
	Union(arr, 5, 6);

	return 0;
}