#pragma once

#include <stdexcept>

template<typename T>
class Queue
{
public:
    Queue() {}
    virtual ~Queue()
    {
        for(int i=0; i<size; i++)
        {
            Remove();
        }
    }

public:
    void Add(T data);
    void Remove();
    T Peek();
    bool Empty() { return size == 0; }
    int Size() { return size; }

private:
    struct Node
    {
        Node(T inData, Node* inNext)
        :data(inData), next(inNext) {}

        T data;
        Node* next = nullptr;
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
};

template<typename T>
void Queue<T>::Add(T data)
{
    auto node = new Node(data, nullptr);
    if(head == nullptr)
    {
        head = node;
    }
    else
    {
        tail->next = node;    
    }
    tail = node;
    size++;
}

template<typename T>
void Queue<T>::Remove()
{
    if(Empty()) 
    { 
        throw std::out_of_range("Stack is empty!");
    }

    auto buffer = head;
    head = buffer->next;
    if(buffer == tail)
    {
        tail = nullptr;
    }
    size--;
    delete buffer;
}

template<typename T>
T Queue<T>::Peek()
{
    if(Empty()) 
    { 
        throw std::out_of_range("Stack is empty!");
    }

    return head->data;
}
