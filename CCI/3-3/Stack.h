#pragma once

#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T>
class Stack
{
public:
    Stack() {}
    virtual ~Stack()
    {
        for(int i=0; i<length; i++)
        {
            Pop();
        }
    }

public:
    void Push(T data);
    T Pop();
    T Top();
    bool Empty() { return length == 0; }
    int Size() { return length; }
    void Display();

private:
    struct Node
    {
        Node(T inData, Node* inNext)
        :data(inData), next(inNext) {}

        T data;
        Node* next = nullptr;
    };

    Node* top = nullptr;
    int length = 0;
};

template<typename T>
void Stack<T>::Push(T data)
{
    auto node = new Node(data, top);
    top = node;
    length++;
}

template<typename T>
T Stack<T>::Pop()
{
    if(Empty()) 
    { 
        throw std::out_of_range("Stack is empty!");
    }

    auto buffer = top;
    T data = buffer->data;
    top = top->next;
    length--;
    delete buffer;
    return data;
}

template<typename T>
T Stack<T>::Top()
{
    if(Empty()) 
    { 
        throw std::out_of_range("Stack is empty!");
    }

    return top->data;
}

template<typename T>
void Stack<T>::Display()
{
    auto current = top;
    while(current != nullptr)
    {
        cout << current->data << ", ";
        current = current->next;
    }
}
