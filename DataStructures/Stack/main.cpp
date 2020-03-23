/* hello.cpp */
#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack<int> stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);

    for(int i=0; i<5; i++)
    {
        try
        {
            cout << stack.Pop() << endl;
        }
        catch (out_of_range& e)
        {
            cout << e.what() << endl;
        }

        cout << "Stack Length : " << stack.Size() << endl;
    }

    try
    {
        cout << stack.Top() << endl;
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}


