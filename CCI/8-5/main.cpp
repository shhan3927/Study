#include <iostream>
#include <vector>

using namespace std;

void GetPermsR(string s, vector<string>& buff, vector<string>& result, int i)
{
    if(i == s.length())
    {
        return;
    }

    vector<string> v;
    if( i == 0)
    {
        string c;
        c += s[i];
        v.push_back(c);
    }
    else
    {
        for(auto& b : buff)
        {
            for(int index = 0; index < b.length(); index++)
            {
                int j = 0;
                string bb;
                for(auto& c : b)
                {
                    if(j == index)
                    {
                        bb.push_back(s[i]);
                    }

                    bb.push_back(c);
                    j++;   
                }

                v.push_back(bb);
            }
            v.push_back(b + s[i]);
        }
    }

    result.insert(result.end(), v.begin(), v.end());

    GetPermsR(s, v, result, i+1);
}

void GetPerms(string s, vector<string>& result)
{
    vector<string> buffer;
    GetPermsR(s, buffer, result, 0);
}

int main()
{
    string s;
    cin >> s;
    vector<string> result;
    GetPerms(s, result);

    for(auto& r : result)
    {
        cout << r << endl;
    }

    return 0;
}
