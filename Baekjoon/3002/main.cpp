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

void Update(int* arr, int* sTree, int n, int left, int right, int start, int end, int diff, int size)
{
    if(left > end || right < start)
    {
        return;
    }

    int count = 0;
    if(left <= start && right >= end)
    {   
        count = end - start + 1;
    }
    else if(right >= end)
    {
        count = end - left + 1;
    }
    else if(left <= start)
    {
        count = right - start + 1;
    }

    sTree[n] = (count + sTree[n]);

    if(start == end)
    {
        sTree[n] %= 10;
        return;
    }
    else
    {
        int gap = size * 9 - sTree[n];
        if(gap < 0)
        {
            sTree[n] -= abs(gap) * 10;
        }
    }
    
    int mid = (start + end) / 2;
    Update(arr, sTree, n*2, left, right, start, mid, diff, size/2);
    Update(arr, sTree, n*2+1, left , right, mid+1, end, diff, size/2);
}

int GetSum(int* arr, int* sTree, int n, int left, int right, int start, int end)
{
    if(left > end || right < start)
    {
        return 0;
    }

    if(left <= start && right >= end)
    {
        if(start == end)
        {
            return sTree[n];
        }
        return sTree[n];
    }

    int mid = (start + end) / 2;
    return GetSum(arr, sTree, n*2, left, right, start, mid) + GetSum(arr, sTree, n*2+1, left, right, mid+1, end);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int size, n;
    cin >> size >> n;

    int* arr = new int[size];
    int sTreeSize = 1 << (static_cast<int>(ceil(log2(size)))+1);
    int* sTree = new int[sTreeSize];

    for(int i=0; i<size; i++)
    {
        scanf("%1d", arr+i);
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
    for(int i=0; i<n; i++)
    {
        cout << GetSum(arr, sTree, 1, v[i].first, v[i].second, 0, size-1) << "\n";
        Update(arr, sTree, 1, v[i].first, v[i].second, 0, size-1, 1, static_cast<int>(ceil(log2(size))));
    }
    
    delete[] arr;
    delete[] sTree;

    return 0;
}
