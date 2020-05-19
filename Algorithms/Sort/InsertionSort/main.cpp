#include <iostream>
#include <random>

using namespace std;

const int ARRAY_MAX = 100;

void InsertionSort(int* arr, int length)
{
    for(int i=1; i<length; i++)
    {
        int key = arr[i];
        int j = i-1;

        while(j > -1 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = key;
    }
}

void MakeRandomArray(int* arr)
{
    bool check[ARRAY_MAX+1] = {false, };

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, ARRAY_MAX);

    for (int i = 0; i < ARRAY_MAX; i++)
    {
        auto rand = dis(gen);
        while(check[rand])
        {
            rand = dis(gen);
        }

        arr[i] = rand;
        check[rand] = true;
    }
}

int main()
{
    int arr[ARRAY_MAX];

    MakeRandomArray(arr);
    InsertionSort(arr, ARRAY_MAX);

    for(auto i=0; i<ARRAY_MAX; i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;

    return 0;
}


