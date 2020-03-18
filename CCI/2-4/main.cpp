#include <iostream>
#include "LinkedList.h"

using namespace std;

void SortingWithPivot(Node<int>** head, int value)
{
    auto pivot = *head;
    while(pivot->GetData() < value && pivot != nullptr)
    {
        pivot = pivot->GetNext();
    }

    if(pivot == nullptr) { return; }

    auto before = pivot;
    auto current = pivot->GetNext();

    while(current != nullptr)
    {
        if(current->GetData() < value)
        {
            before->SetNext(current->GetNext());
            current->SetNext(*head);
            *head = current;
            current = before->GetNext();
        }
        else
        {
            before = current;
            current = current->GetNext();
        }
    }
}

int main()
{
    Node<int>* head = nullptr;
    InsertHeadInLinkedList(&head, 2);
    InsertHeadInLinkedList(&head, 10);
    InsertHeadInLinkedList(&head, 1);
    InsertHeadInLinkedList(&head, 8);
    InsertHeadInLinkedList(&head, 5);
    InsertHeadInLinkedList(&head, 3);
    PrintLinkedList(head);

    SortingWithPivot(&head, 5);
    PrintLinkedList(head);

    RemoveLinkedList(head);
    return 0;
}