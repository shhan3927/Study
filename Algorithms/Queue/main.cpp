/* hello.cpp */
#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue<int> queue;
    queue.Add(1);
    queue.Add(2);
    queue.Add(3);
    queue.Add(4);

    for(int i=0; i<5; i++)
    {
        try
        {
            cout << queue.Peek() << endl;
            queue.Remove();
        }
        catch (out_of_range& e)
        {
            cout << e.what() << endl;
        }

        cout << "Stack Length : " << queue.Size() << endl;
    }
    
    return 0;
}


