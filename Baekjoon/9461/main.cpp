#include <iostream>
#include <map>
#include <vector>

using namespace std;

long GetSum(int n, map<int, long>& c)
{
    if(n >=1 && n <= 3)
    {
        return 1;
    }
    
    if(n >= 4 && n <= 5)
    {
        return 2;
    }

    if(c.find(n) == c.end())
    {
        c[n] = GetSum(n-1, c) + GetSum(n-5, c);
    }

    return c[n];
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    map<int, long> cache;

    int count, n;
    cin >> count;

    vector<int> input;
    for(int i=0; i<count; i++)
    {
        cin >> n;
        input.push_back(n);
    } 

    for(auto i : input)
    {
        cout << GetSum(i, cache) << "\n";
    }

    return 0;
}
