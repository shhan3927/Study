#include <iostream>
#include <vector>

using namespace std;

int Find(vector<int>& p, int n)
{
    if(p[n] == n)
    {
        return n;
    }

    p[n] = Find(p, p[n]);
    return p[n];
}

void Union(vector<int>&p, int n1, int n2)
{
    int x = Find(p, n1);
    int y = Find(p, n2);

    if(x < y)
    {
        p[y] = x;
    }
    else
    {
        p[x] = y;
    }   
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n;

    vector<int> p(n+1);

    for(int i=1; i<=n; i++)
    {
        p[i] = i;
    }

    cin >> m;
    while(m--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        Union(p, n1, n2);
    }

    int count = 0;
    for(int i=2; i<=n; i++)
    {
        if(Find(p, 1) == Find(p, i))
        {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}
