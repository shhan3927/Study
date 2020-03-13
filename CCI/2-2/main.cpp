#include <iostream>
#include <set>

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

void InsertHeadInLinkedList(Node<int>** head, int data)
{
    Node<int>* node = new Node<int>(data, *head);
    *head = node;
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

Node<int>* FindNodeFromBackward(Node<int>* head, int backwardIndex)
{
    auto current = head;
    int size = 0;
    while(current != nullptr)
    {
        size ++;
        current = current->GetNext();
    }

    auto forwardIndex = size - backwardIndex;
    if(forwardIndex > size || forwardIndex < 0)
    {
        return nullptr;
    }
    current = head;
    for(int i=0; i<forwardIndex; i++)
    {
        current = current->GetNext();
    }

    return current;
}

int main()
{
    set<int> s;
    
    Node<int>* head = nullptr;
    InsertHeadInLinkedList(&head, 3);
    InsertHeadInLinkedList(&head, 4);
    InsertHeadInLinkedList(&head, 5);
    InsertHeadInLinkedList(&head, 9);
    InsertHeadInLinkedList(&head, 6);
    PrintLinkedList(head);

    auto found = FindNodeFromBackward(head, 5);
    if(found != nullptr)
    {
        cout << found->GetData() << endl;
    }

    RemoveLinkedList(head);
    return 0;
}