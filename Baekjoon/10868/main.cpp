#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>
#include <utility>

using namespace std;

int Init(int* arr, int* tree, int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = arr[start];
        return tree[node];
    }

    int mid = (start + end) / 2;
    tree[node] = min(Init(arr, tree, node*2, start, mid), Init(arr, tree, node*2+1, mid+1, end));
    return tree[node];
}

int GetMinValue(int* arr, int* tree, int node, int left, int right, int start, int end)
{
    if(left > end || right < start)
    {
        return 1e9 + 1;
    }

    if(left <= start && right >= end)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return min(GetMinValue(arr, tree, node*2, left, right, start, mid), 
            GetMinValue(arr, tree, node*2+1, left, right, mid+1, end));
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, count;
    cin >> n >> count;

    int* arr = new int[n];
    int size = 1 << (static_cast<int>(ceil(log2(n))) + 1);
    int* tree = new int[size];
    vector<int> left;
    vector<int> right;

    for(int i=0; i<n; i++)
    {
        int value;
        cin >> value;
        arr[i] = value;
    }

    for(int i=0; i<count; i++)
    {
        int value1, value2;
        cin >> value1 >> value2;
        left.push_back(value1);
        right.push_back(value2);
    }

    Init(arr, tree, 1, 0, n-1);

    int i= 0;
    for(auto& value : left)
    {
        cout << GetMinValue(arr, tree, 1, left[i]-1, right[i]-1, 0, n-1) << "\n";
        i++;
    }

    delete[] arr;
    delete[] tree;

    return 0;
}
