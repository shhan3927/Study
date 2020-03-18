#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    Node(T inData, Node* node)
    {
        data = inData;
        next = node;
    }

public:
    void SetData(T v) { data = v; }
    T GetData() const { return data; }
    void SetNext(Node* node) { next = node; }
    Node* GetNext() const { return next; }

private:
    T data;
    Node* next = nullptr;
};

Node<int>* InsertHeadInLinkedList(Node<int>** head, int data)
{
    Node<int>* node = new Node<int>(data, *head);
    *head = node;
    return node;
}

Node<int>* InsertTailInLinkedList(Node<int>** head, int data)
{
    Node<int>* node = new Node<int>(data, nullptr);
    if(*head == nullptr)
    {
        *head = node;
        return node;
    }

    auto current = *head;
    while(current->GetNext() != nullptr)
    {
        current = current->GetNext();
    }

    current->SetNext(node);
    return node;
}

void PrintLinkedList(Node<int>* head)
{
    auto current = head;
    while(current != nullptr){
        cout << current->GetData() << ", ";
        current = current->GetNext();
    }

    cout << endl;
}

void RemoveLinkedList(Node<int>* head)
{
    auto current = head;
    while(current != nullptr){
        auto buff = current;
        current = current->GetNext();
        delete current;
    }
}

int GetLinkedListSize(Node<int>* head)
{
    auto current = head;
    int size = 0;
    while(current != nullptr)
    {
        size ++;
        current = current->GetNext();
    }

    return size;
}