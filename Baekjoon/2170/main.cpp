#include <iostream>
#include <utility>
#include <queue>
#include <cmath>

#define INF 1e9+1;

using namespace std;
using Point = pair<int, int>;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    auto Comp = [](Point& one, Point& other)
    {
        return one.first > other.first;
    };
    priority_queue<Point, vector<Point>, decltype(Comp)> q(Comp);

    while(n--)
    {
        int l, r;
        cin >> l >> r;
        q.push(make_pair(l, r));
    }

    int length = 0;
    int inf = -INF;
    Point current = make_pair(inf, inf);

    while(!q.empty())
    {
        Point p = q.top();
        q.pop();

        if(current.first > inf && current.second > inf)
        {
            if(p.first <= current.second)
            {
                current.second = max(current.second, p.second);
            }
            else
            {
                length += current.second - current.first;
                current = p;
            }
        }
        else
        {
            current = p;
        }
        
    }

    length += current.second - current.first;
    cout << length << "\n";

    return 0;
}
