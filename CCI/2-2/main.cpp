#include <iostream>
#include "LinkedList.h"

using namespace std;

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