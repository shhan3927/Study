#include <iostream>
#include "Stack.h"

using namespace std;

class MyQueue
{
public:
    void Add(int data)
    {
        Stack<int> buffer;
        while(!stack.Empty())
        {
            buffer.Push(stack.Pop());
        }

        stack.Push(data);
        while(!buffer.Empty())
        {
            stack.Push(buffer.Pop());
        }
    }

    int Peek() { return stack.Top(); }
    void Remove()
    {
        stack.Pop();
    }

    bool Empty()
    {
        return stack.Empty();
    }

private:
    Stack<int> stack;
};

int main()
{
    MyQueue queue;
    queue.Add(1);
    queue.Add(2);
    queue.Add(3);
    queue.Add(4);
    queue.Add(5);

    while(!queue.Empty())
    {
        cout << queue.Peek() << endl;
        queue.Remove();
    }

    return 0;
}
