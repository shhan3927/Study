#include <iostream>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

int Init(int* arr, int* sTree, int n, int start, int end)
{
    if(start == end)
    {
        sTree[n] = arr[start];
        return sTree[n];
    }

    int mid = (start + end) / 2;
    sTree[n] = Init(arr, sTree, n*2, start, mid) + Init(arr, sTree, n*2+1, mid+1, end);
    return sTree[n];
}

void Update(int* arr, int* sTree, int n, int start, int end, int index, int diff)
{
    if(index < start || index > end)
    {
        return;
    }

    sTree[n] += diff;
    if(start == end)
    {
        arr[index] += diff;
        return;
    }

    int mid = (start + end) / 2;
    Update(arr, sTree, n*2, start, mid, index, diff);
    Update(arr, sTree, n*2+1, mid+1, end, index, diff);
}

int GetSum(int* arr, int* sTree, int n, int left, int right, int start, int end)
{
    if(left > end || right < start)
    {
        return 0;
    }

    if(left <= start && right >= end)
    {
        return sTree[n];
    }

    int mid = (start + end) / 2;
    
    return GetSum(arr, sTree, n*2, left, right, start, mid) + GetSum(arr, sTree, n*2+1, left, right, mid+1, end);
}

void Display(int* arr, int* sTree, int s1, int s2)
{
    cout << "arr : ";
    for(int i=0; i<s1; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "\n";

    cout << "sTree : ";
    for(int i=1; i<=s2; i++)
    {
        cout << sTree[i] << ", ";
    }
    cout << "\n";
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int size, n;
    cin >> size >> n;

    string s;
    cin >> s;

    int* arr = new int[size];
    int sTreeSize = static_cast<int>(ceil(log2(size)))*4+1;
    int* sTree = new int[sTreeSize];
    int i=0;
    for(auto c : s)
    {
        arr[i] = c - '0';
        i++;
    }

    vector<pair<int, int>> v;
    for(int i=0; i<n; i++)
    {
        int start, end;
        cin >> start >> end;
        v.push_back(make_pair(start-1, end-1));
    }

    ////////////////////////////
    vector<int> result;
    Init(arr, sTree, 1, 0, size-1);
    Display(arr, sTree, size, sTreeSize);
    for(int i=0; i<n; i++)
    {
        result.push_back(GetSum(arr, sTree, 1, v[i].first, v[i].second, 0, size-1));

        for(int j=v[i].first; j<=v[i].second; j++)
        {
            Update(arr, sTree, 1, 0, size-1, j, 1);
        }
        Display(arr, sTree, size, sTreeSize);
    }
    
    for(auto v : result)
    {
        cout << v << "\n";
    }

    delete[] arr;
    delete[] sTree;

    return 0;
}
