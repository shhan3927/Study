#include <iostream>
#include "PriorityQueue.h"

using namespace std;

int main()
{
    PriorityQueue queue;
    queue.Insert(16);
    queue.Insert(14);
    queue.Insert(10);
    queue.Insert(8);
    queue.Insert(7);
    queue.Insert(9);
    queue.Insert(3);
    queue.Insert(2);
    queue.Insert(4);
    queue.Insert(1);

    queue.IncreseKey(9, 15);
    cout << queue.Maximum() << endl;
    queue.ExtractMax();
    cout << queue.Maximum() << endl;

    return 0;
}


