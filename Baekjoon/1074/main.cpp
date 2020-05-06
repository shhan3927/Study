#include <iostream>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;

void Travel(int r, int c, int n, queue<pair<int, int>>& q)
{
    if(n == 1)
    {
        q.push(make_pair(r, c));
        q.push(make_pair(r, c+1));
        q.push(make_pair(r+1, c));
        q.push(make_pair(r+1, c+1));
        return;
    }

    Travel(r, c, n/2, q);
    Travel(r, c+n, n/2, q);
    Travel(r+n, c, n/2, q);
    Travel(r+n, c+n, n/2, q);
}

void Travel(int n, queue<pair<int, int>>& q)
{
    Travel(0, 0, n/2, q);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, r, c;

    cin >> n >> r >> c;

    queue<pair<int, int>> q;
    Travel(pow(2, n), q);

    int count = 0;
    while(!q.empty())
    {
        if(q.front().first == r && q.front().second == c)
        {
            break;
        }

        count++;
        q.pop();
    }

    cout << count << "\n";
    
    return 0;
}
