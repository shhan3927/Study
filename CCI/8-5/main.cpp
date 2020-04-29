#include <iostream>

using namespace std;

int MultiplyR(int a, int b, int i)
{
    if((b >> i) <= 0) { return 0; }

    auto c = b >> i;
    auto r = c & (1);

    if(r == 1)
    {
        return (a << i) + MultiplyR(a, b, i+1);
    }
    else if(r == 0)
    {
        return MultiplyR(a, b, i+1);
    }

    return 0;
}

int Multiply(int a, int b)
{
    return MultiplyR(a, b, 0);
}

int main()
{
    int a = 40;
    int b = 500;

    cout << Multiply(a, b) << endl;

    return 0;
}
