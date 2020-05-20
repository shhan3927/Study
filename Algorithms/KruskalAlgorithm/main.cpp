#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    Edge(int n1, int n2, int d)
    :node1(n1), node2(n2), distance(d) {}

    int node1;
    int node2;
    int distance;
};

int Find(vector<int>& p, int n)
{
    if(p[n] == n)
    {
        return n;
    }

    return p[n] = Find(p, p[n]);
}

void Union(vector<int>& p, int n1, int n2)
{
    n1 = Find(p, n1);
    n2 = Find(p, n2);

    if(n1 < n2)
    {
        p[n2] = n1;
    }
    else
    {
        p[n1] = n2;
    }
}

int main()
{
    int n = 7;
    vector<Edge> v;
    v.emplace_back(1, 7, 12);
    v.emplace_back(1, 4, 28);
    v.emplace_back(1, 2, 67);
    v.emplace_back(1, 5, 17);
    v.emplace_back(2, 4, 24);
    v.emplace_back(2, 5, 62);
    v.emplace_back(3, 5, 20);
    v.emplace_back(3, 6, 37);
    v.emplace_back(4, 7, 13);
    v.emplace_back(5, 6, 45);
    v.emplace_back(5, 7, 73);

    sort(v.begin(), v.end(), [](const Edge& one, const Edge& other)
    {
        return one.distance < other.distance;
    });

    vector<int> p(n+1);
    for(int i=1; i<=n; i++)
    {
        p[i] = i;
    }

    int distance = 0;
    for(auto e : v)
    {
        if(Find(p, e.node1) != Find(p, e.node2))
        {
            Union(p, e.node1, e.node2);
            distance += e.distance;
        }
    }

    cout << distance << endl;

    return 0;
}

