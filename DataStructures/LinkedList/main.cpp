/* hello.cpp */
#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

class Stack
{
public:
    void Push(int data)
    {
        list.InsertInHead(data);
    }

    int Pop()
    {
        int ret = list.GetHeadData();
        list.DeleteHead();
        return ret;
    }

    void Print()
    {
        list.Foreach([](int data){
            cout << data << ", ";
        });

        cout << endl;
    }

private:
    LinkedList<int> list;
};

int main()
{
    Stack stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);

    cout << stack.Pop() << endl;
    stack.Print();
    cout << stack.Pop() << endl;
    stack.Print();
    cout << stack.Pop() << endl;
    stack.Print();
    cout << stack.Pop() << endl;
    stack.Print();

    return 0;
}


