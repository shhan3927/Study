#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct SegmentTree
{
    SegmentTree(int size)
    {
        arr.resize(size+1);
        int h = (int)ceil(log2(size)) + 1;
        int n = (1 << h) - 1;
        tree.resize(n);
        lazy.resize(n);
    }

    ~SegmentTree()
    {
        int a= 3;
    }

    vector<long long> arr;
    vector<long long> tree;
    vector<long long> lazy;
};

long long Init(SegmentTree& sTree, int node, int start, int end)
{
    if(start == end)
    {
        sTree.tree[node] = sTree.arr[start];
        return sTree.tree[node];
    }

    int mid = (start + end) / 2;
    sTree.tree[node] = Init(sTree, node*2, start, mid) + Init(sTree, node*2+1, mid+1, end);
    return sTree.tree[node];
}

void UpdateLazy(SegmentTree& sTree, int node, int start, int end)
{
    if(sTree.lazy[node] == 0)
    {
        return;
    }

    sTree.tree[node] += (end - start + 1) * sTree.lazy[node];
    if(start != end)
    {
        sTree.lazy[node*2] += sTree.lazy[node];
        sTree.lazy[node*2+1] += sTree.lazy[node];
    }

    sTree.lazy[node] = 0;
}

void UpdateRange(SegmentTree& sTree, int node, int left, int right, int start, int end, int diff)
{
    UpdateLazy(sTree, node, start, end);

    if(right < start || left > end)
    {
        return;
    }

    if(start >= left && right >= end)
    {
        sTree.tree[node] += (end - start + 1)*diff;
        if(start != end)
        {
            sTree.lazy[node*2] += diff;
            sTree.lazy[node*2+1] += diff;
        }

        return;
    }

    int mid = (start + end) / 2;
    UpdateRange(sTree, node*2, left, right, start, mid, diff);
    UpdateRange(sTree, node*2+1, left, right, mid+1, end, diff);

    sTree.tree[node] = sTree.tree[node*2] + sTree.tree[node*2+1];
}

long long GetSum(SegmentTree& sTree, int node, int left, int right, int start, int end)
{
    UpdateLazy(sTree, node, start, end);

    if(left > end || right < start)
    {
        return 0;
    }

    if(left <= start && right >= end)
    {    
        return sTree.tree[node];
    }

    int mid = (start + end) / 2;
    return GetSum(sTree, node*2, left, right, start, mid) + 
            GetSum(sTree,node*2+1, left, right, mid+1, end);
}

struct Command
{
    int type;
    int start;
    int end;
    long long diff;
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, k;
    //cin >> n >> m >> k;
    scanf("%d %d %d",&n,&m,&k);

    SegmentTree tree(n);
    for(int i=0; i<n; i++)
    {
        scanf("%lld", &tree.arr[i+1]);
        // long long value;
        // cin >> value;
        // tree.arr[i+1] = value;
    }

    vector<Command> v;
    for(int i=0; i<m+k; i++)
    {
        Command c;
        cin >> c.type;
        cin >> c.start >> c.end;
        if(c.type == 1)
        {
            scanf("%lld", &c.diff);
            //cin >> c.diff;
        }
        v.push_back(c);
    }

    ////////////////////////////////
    Init(tree, 1, 1, n);

    for(auto& c : v)
    {
        if(c.type == 1)
        {
            UpdateRange(tree, 1, c.start, c.end, 1, n, c.diff);
        }
        else if(c.type == 2)
        {
            cout << GetSum(tree, 1, c.start, c.end, 1, n) << "\n";
        }
    }

    return 0;
}
