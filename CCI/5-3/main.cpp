#include <iostream>
#include <bitset>
#include <stack>

using namespace std;

int CCI_5_3(int n)
{
    stack<int> s;
    int count = 0;
    while(n > 0)
    {
        if((n & 1) == 1)
        {
            count++;
        }
        else
        {
            s.push(count);
            count = 0;
        }

        n = n >> 1;
    }

    int before = 0;
    int max = 0;
    while(!s.empty())
    {
        int v = s.top();
        s.pop();

        if(before + v > max)
        {
            max = before + v;
        }

        before = v;
    }

    return max+1;
}

int main()
{
    bitset<32> m = 0x6ef;
    int n = 1775;

    cout << m.to_ulong() << endl;
    cout << CCI_5_3(1775) << endl;

    return 0;
}
