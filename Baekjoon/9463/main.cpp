#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GetCrossCount(vector<int>& one, vector<int>& other)
{
    auto FindIndex = [](vector<int>& v, int key)
    {
        auto it = find(v.begin(), v.end(), key);
        if(it == v.end())
        {
            return -1;
        }

        int index = distance(v.begin(), it);
        return index;
    };

    int count = 0;

    for(int i=0; i<one.size(); i++)
    {
        int j = FindIndex(other, one[i]);

        for(int k=i+1; k<one.size(); k++)
        {
            if(FindIndex(other, one[k]) < j)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int count;

    cin >> count;

    vector<int> v1;
    vector<int> v2;

    for(int i=0; i<count; i++)
    {
        int n;
        cin >> n;

        for(int j=0; j<n; j++)
        {
            int digit;
            cin >> digit;
            v1.push_back(digit);
        }

        for(int j=0; j<n; j++)
        {
            int digit;
            cin >> digit;
            v2.push_back(digit);
        }

        cout << GetCrossCount(v1, v2) << "\n";
    }

    return 0;
}
