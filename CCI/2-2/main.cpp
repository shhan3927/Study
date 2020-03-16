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

Node<int>* FindNodeFromBackward(Node<int>* head, int backwardIndex)
{
    auto size = GetLinkedListSize(head);

    auto forwardIndex = size - backwardIndex;
    if(forwardIndex > size || forwardIndex < 0)
    {
        return nullptr;
    }

    auto current = head;
    for(int i=0; i<forwardIndex; i++)
    {
        current = current->GetNext();
    }

    return current;
}

// Recursively
void GetNode(Node<int>** node, int k, int i)
{
    if(i == k)
    {
        return;
    }

    *node = (*node)->GetNext();
    GetNode(node, k, ++i);
}

void GetReverseNode(Node<int>* head, Node<int>** node, int i)
{
    int k = GetLinkedListSize(head) - i;
    GetNode(node, k, 0);
}

// Craking Coding Interview 
Node<int>* nthToLast(Node<int>* head, int k, int& i)
{
    if(head == nullptr)
    {
        return nullptr;
    }

    Node<int>* nd = nthToLast(head->GetNext(), k, i);
    i = i + 1;
    if(i == k)
    {
        return head;
    }

    return nd;
}

Node<int>* nthToLast(Node<int>* head, int k)
{
    int i=0;
    return nthToLast(head, k, i);
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

    Node<int>* node = head;
    GetReverseNode(head, &node, 5);
    cout << node->GetData() << endl;

    node = nthToLast(head, 3);
    cout << node->GetData() << endl;

    RemoveLinkedList(head);
    return 0;
}