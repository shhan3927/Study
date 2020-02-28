#pragma once

#include <functional>
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
    T GetData() const { return data; }
    void SetNext(Node* node) { next = node; }
    Node* GetNext() const { return next; }

private:
    T data;
    Node* next = nullptr;
};

template <typename T>
class LinkedList
{
public:
    LinkedList():head(nullptr){}
    ~LinkedList(){ DeleteAll(); }

public:
    Node<T>* InsertInHead(int data);
    T GetHeadData() const { return head->GetData(); }
    bool Delete(Node<T>* node);
    bool DeleteHead();
    void DeleteAll();
    void Foreach(std::function<void (T)>);

private:
    Node<T>* head = nullptr;
};

template <typename T>
Node<T>* LinkedList<T>::InsertInHead(int data)
{
    Node<T>* node = new Node<T>(data, head);
    head = node;
    return node;
}

template <typename T>
bool LinkedList<T>::Delete(Node<T>* node)
{
    if(node == head)
    {
        Node<T>* next = head->GetNext();
        delete head;
        head = next;
        return true;
    }

    Node<T>* current = head->GetNext();
    Node<T>* before = head;

    while(current != nullptr)
    {
        if(current== node)
        {
            before->SetNext(current->GetNext());
            delete current;
            return true;
        }

        before = current;
        current = current->GetNext();
    }

    return false;
}

template <typename T>
bool LinkedList<T>::DeleteHead()
{
    return Delete(head);
}

template <typename T>
void LinkedList<T>::DeleteAll()
{
    Node<T>* current = head;

    while(current != nullptr)
    {
        auto next = current->GetNext();
        delete current;
        current = next;
    }

    head = nullptr;
}

template <typename T>
void LinkedList<T>::Foreach(std::function<void (T)> callback)
{
    Node<T>* current = head;

    while(current != nullptr)
    {
        callback(current->GetData());
        current = current->GetNext();
    }
}
