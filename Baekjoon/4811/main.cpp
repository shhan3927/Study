#include <iostream>
#include <vector>

using namespace std;

unsigned long GetCount(int one, int half, unsigned long (*cache)[31])
{
    if(cache[one][half] > 0)
    {
        return cache[one][half];
    }

    if((one == 1 && half == 0)
    || (one == 0 && half >= 0))
    {   
        return 1;
    }

    if(one < 0 || half < 0)
    {
        return 0;
    }

    unsigned long add1 = GetCount(one-1, half+1, cache);
    cache[one-1][half+1] = add1;
    unsigned long add2 = GetCount(one, half-1, cache);
    cache[one][half-1] = add2;

    return add1 + add2;
}

unsigned long GetCount(int n, unsigned long (*cache)[31])
{
    return GetCount(n, 0, cache);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    unsigned long cache[31][31] = {0, };
    vector<int> v;
    bool end = false;
    while(!end)
    {
        int n;
        cin >> n;
        if(n == 0)
        {
            end = true;
        }
        else
        {
            v.push_back(n);
        }   
    }

    for(int d : v)
    {
        cout << GetCount(d, cache) << "\n";
    }
    
    return 0;
}
