#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int Init(int* arr, int* tree, int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = arr[start];
        return tree[node];
    }

    int mid = (start + end) / 2;
    tree[node] = Init(arr, tree, node*2, start, mid) + Init(arr, tree, node*2+1, mid+1, end);
    return tree[node];
}

void Update(int* arr, int* tree, int node, int start, int end, int index, int diff)
{
    if(index < start || index > end)
    {
        return;
    }

    tree[node] += diff;

    if(start == end)
    {
        return;
    }

    int mid = (start + end) / 2;
    Update(arr, tree, node*2, start, mid, index, diff);
    Update(arr, tree, node*2+1, mid+1, end, index, diff);
}


int GetSum(int* arr, int* tree, int node, int left, int right, int start, int end)
{
    if(left > end || right < start)
    {
        return 0;
    }

    if(left <= start && right >= end)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return GetSum(arr, tree, node*2, left, right, start, mid) + 
            GetSum(arr, tree,node*2+1, left, right, mid+1, end);
}

struct Command
{
    int type;
    int start;
    int end;
    int diff;
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    int* arr = new int[n];
    for(int i=0; i<n; i++)
    {
        int value;
        cin >> value;
        arr[i] = value;
    }

    vector<Command> v;
    for(int i=0; i<m+k; i++)
    {
        Command c;
        cin >> c.type;
        cin >> c.start >> c.end;
        if(c.type == 1)
        {
            cin >> c.diff;
        }
        v.push_back(c);
    }

    int* tree = new int[1 << ((int)(ceil(log2(n)))+1)];
    Init(arr, tree, 1, 0, n-1);

    for(auto& c : v)
    {
        if(c.type == 1)
        {
            for(int i=c.start-1; i<=c.end-1; i++)
            {
                Update(arr, tree, 1, 0, n-1, i, c.diff);
            }
        }
        else if(c.type == 2)
        {
            cout << GetSum(arr, tree, 1, c.start-1, c.end-1, 0, n-1) << "\n";
        }
    }

    delete[] arr;
    delete[] tree;

    return 0;
}
