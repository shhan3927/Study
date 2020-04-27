#include <iostream>
#include <bitset>

using namespace std;

bitset<32> CCI_5_1(bitset<32> n, bitset<32> m, int i, int j)
{
    for(int index=2; index<=6; index++)
    {
        n &= ~(1<<i);
    }

    m = m << i | n;

    return m;
}

// CCI 정답
bitset<32> CCI_5_1_Answer(bitset<32> n, bitset<32> m, int i, int j)
{
    bitset<32> allOne;
    allOne.set();

    auto left = allOne << j+1;
    auto right = (1 << i) - 1;
    left |= right;

    n &= left;
    return m << i | n;
}

int main()
{
    bitset<32> n;
    n.set(10, true);

    bitset<32> m;
    m.set(0);
    m.set(1);
    m.set(4);

    cout << CCI_5_1(n, m, 2, 6).to_ulong() << endl;
    cout << CCI_5_1_Answer(n, m, 2, 6).to_ulong() << endl;

    return 0;
}
