#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<pair<int, int>> v;
    int num;
    cin >> num;

    for(int i=0; i<num; i++)
    {
        int value;
        cin >> value;
        v.emplace_back(i+1, value);
    }

    stack<pair<int, int>> s;
    for(auto& p : v)
    {
        if(!s.empty())
        {
            bool found = s.top().second > p.second;
            while(!s.empty() && !found)
            {
                s.pop();
                if(!s.empty() && s.top().second > p.second)
                {
                    found = true;
                }
            }

            if(found)
            {
                cout << s.top().first << " ";
                s.push(p);
            }
            else
            {
                cout << "0 ";
                s.push(p);
            }
        }
        else
        {
            cout << "0 ";
            s.push(p);
        }
    }
    
    cout << "\n";

    return 0;
}
