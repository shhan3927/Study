#include <iostream>
#include <vector>
#include "Stack.h"

using namespace std;

class SetOfStack
{
public:
    virtual ~SetOfStack()
    {
        for(auto& s : stackList)
        {
            delete s;
        }
    }

public:
    void Push(int data)
    {
        if((currentIndex == -1) || (stackList[currentIndex]->Size() >= STACK_MAX))
        {
            stackList.push_back(new Stack<int>());
            currentIndex++;
        }

        stackList[currentIndex]->Push(data);
    }

    int Pop()
    {
        if(currentIndex == -1)
        {
            throw out_of_range("Stack is empty!");
        }

        int data = stackList[currentIndex]->Pop();
        if(stackList[currentIndex]->Size() == 0)
        {
            stackList.erase(stackList.begin() + currentIndex);
            currentIndex--;
        }

        return data;
    }

    int PopAt(int index)
    {
        if(index > currentIndex)
        {
            throw out_of_range("Stack is empty!");
        }

        int count = 0;
        Stack<int> stack;
        for(int i=stackList.size()-1; i>index; i--)
        {
            count += stackList[i]->Size();
        }

        for(int i=0; i<count; i++)
        {
            stack.Push(Pop());
        }

        int data = stackList[index]->Pop();
        while(!stack.Empty())
        {
            Push(stack.Pop());
        }

        return data;
    }

    void Dump()
    {
        int i=0;
        for(auto& stack : stackList)
        {
            cout << "stack " << i+1 << " : ";
            stack->Display();
            cout << endl;
            i++;
        }
    }

public:
    int GetStackListSize() const { return stackList.size(); }
    int GetCurrentIndex() const { return currentIndex; }

private:
    vector<Stack<int>*> stackList;
    int currentIndex = -1;
    const int STACK_MAX = 3;
};

int main()
{
    SetOfStack stack;
    for(int i=0; i<10; i++)
    {   
        stack.Push(i);
        cout << "Stack count : " << stack.GetStackListSize() << endl;
        cout << "Index : " << stack.GetCurrentIndex() << endl;
    }

    cout << "==========================" << endl;

    for(int i=0; i<10; i++)
    {   
        cout << "Stack count : " << stack.GetStackListSize() << endl;
        cout << "Index : " << stack.GetCurrentIndex() << endl;
        cout << stack.Pop() << endl;
    }

    cout << "==========================" << endl;
    for(int i=0; i<11; i++)
    {   
        stack.Push(i+1);
    }

    stack.Dump();
    stack.PopAt(1);
    cout << "++++++++++++++++" << endl;
    stack.Dump();

    return 0;
}