#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int GetPartialValue(stack<int>& s, int c)
{
    if(s.empty()) 
    {
        return -1;
    }

    int find = c == -2 ? -1 : -3;
    int multi = c == -2 ? 2 : 3;
    int sum = 0;
    bool isFound = false;
    while(!s.empty() && !isFound)
    {
        if(s.top() == find)
        {
            isFound = true;
        }
        else if(s.top() < 0)
        {
            return -1;
        }

        if(s.top() > 0)
        {
            sum += s.top();
        }
        s.pop();
    }
    
    if(isFound)
    {
        if(sum == 0)
        { 
            return multi; 
        }
        else
        {
            return sum * multi;
        }
    }

    return -1;
}

int GetBracketValue(vector<int>& str)
{
    stack<int> s;
    for(auto& c : str)
    {
        if(c == -2 || c == -4)
        {
            int partial = GetPartialValue(s, c);
            if(partial == -1)
            {
                return 0;
            }
            else
            {
                s.push(partial);
            }
        }
        else
        {
            s.push(c);
        }
    }

    if(s.empty())
    {
        return 0;
    }

    int sum = 0;
    while(!s.empty())
    {
        if(s.top() < 0 )
        {
            return 0;
        }

        sum += s.top();
        s.pop();
    }
    
    return sum;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;

    // Convert char to int
    vector<int> strInt;
    for(auto& c : str)
    {
        switch(c)
        {
        case '(':
            strInt.push_back(-1);
            break;   
        case ')':
            strInt.push_back(-2);
            break; 
        case '[':
            strInt.push_back(-3);
            break; 
        case ']':
            strInt.push_back(-4);
            break;          
        }
    }

    cout << GetBracketValue(strInt) << "\n";
    
    return 0;
}
