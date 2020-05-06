#include <iostream>

using namespace std;

int MakeChange(int amount, int* denoms, int index)
{
    if(index >= 3)
    {
        return 1;
    }

    int denomAmount = denoms[index];
    int ways = 0;
    for(int i=0; i*denomAmount <= amount; i++)
    {
        int amountRemaining = amount - i * denomAmount;
        ways += MakeChange(amountRemaining, denoms, index+1);
    }

    return ways;
}

int MakeChange(int n)
{
    int denoms[] = {25, 10, 5, 1};
    return MakeChange(n, denoms, 0);
}

int main()
{
    int n;
    cin >> n;

    cout << MakeChange(n) << endl;

    return 0;
}
