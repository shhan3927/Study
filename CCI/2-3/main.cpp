#include <iostream>
#include "LinkedList.h"

using namespace std;

void DeleteNode1(Node<int>* node)
{
    auto current = node;
    auto next = node->GetNext();

    while(next != nullptr)
    {
        current->SetData(next->GetData());
        current->SetNext(next);

        if(next->GetNext() == nullptr)
        {
            current->SetNext(nullptr);
        }

        current = next;
        next = next->GetNext();
    }
    
    current->SetNext(nullptr);
    delete current;
}

void DeleteNode2(Node<int>* node)
{
    if(node->GetNext() == nullptr) 
    {
        return;
    }

    auto next = node->GetNext();
    node->SetData(next->GetData());
    node->SetNext(next->GetNext());
    delete next;
}

int main()
{
    Node<int>* head = nullptr;
    InsertHeadInLinkedList(&head, 3);
    InsertHeadInLinkedList(&head, 4);
    auto node1 = InsertHeadInLinkedList(&head, 5);
    auto node2 = InsertHeadInLinkedList(&head, 9);
    InsertHeadInLinkedList(&head, 6);
    PrintLinkedList(head);

    DeleteNode1(node1);
    PrintLinkedList(head);

    DeleteNode2(node2);
    PrintLinkedList(head);

    RemoveLinkedList(head);
    return 0;
}