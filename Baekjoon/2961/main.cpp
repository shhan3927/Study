#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Material
{
    Material(int ss, int bb)
    :s(ss), b(bb) {}
    int s;
    int b;
};

void GetFlavor(int n, int max, int s, int b, int& min, vector<Material>& v)
{
    if(n >= 0)
    {
        if(s == 0 && b == 0)
        {
            s = v[n].s;
            b = v[n].b;
        }
        else
        {
            s *= v[n].s;
            b += v[n].b;
        }

        min = std::min(min, abs(s-b));
    }

    for(int i=n+1; i<max; i++)
    {
        GetFlavor(i, max, s, b, min, v);
    }
}

int GetMinFlavor(int max, vector<Material>& v)
{
    int s = 0;
    int b = 0;
    int min = 100000000;
    GetFlavor(-1, max, s, b, min, v);

    return min;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<Material> v;

    int count;
    cin >> count;

    for(int i=0; i<count; i++)
    {
        int s, b;
        cin >> s >> b;
        v.emplace_back(s, b);
    }
    
    cout << GetMinFlavor(count, v) << "\n";

    return 0;
}
