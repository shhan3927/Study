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

int main()
{
    set<int> s;
    
    Node<int>* head = nullptr;
    InsertHeadInLinkedList(&head, 3);
    InsertHeadInLinkedList(&head, 4);
    InsertHeadInLinkedList(&head, 5);
    InsertHeadInLinkedList(&head, 3);
    InsertHeadInLinkedList(&head, 6);
    PrintLinkedList(head);

    auto current = head;
    Node<int>* prev = nullptr;
    while(current != nullptr)
    {
        if(s.find(current->GetData()) != s.end())
        {
            Node<int>* buf = current;
            current = current->GetNext();
            if(buf == head)
            {
                head = current;
            }
            if(prev != nullptr)
            {
                prev->SetNext(current);
            }
            delete buf;
        }
        else
        {
            s.insert(current->GetData());
            prev = current;
            current = current->GetNext();
        }
    }
    PrintLinkedList(head);

    RemoveLinkedList(head);
    return 0;
}