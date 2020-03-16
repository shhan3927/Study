#include <iostream>
#include <set>
#include "LinkedList.h"

using namespace std;

void RemoveDuplicatedNode(Node<int>* head)
{
    set<int> s;
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
}

int main()
{
    Node<int>* head = nullptr;
    InsertHeadInLinkedList(&head, 3);
    InsertHeadInLinkedList(&head, 4);
    InsertHeadInLinkedList(&head, 5);
    InsertHeadInLinkedList(&head, 3);
    InsertHeadInLinkedList(&head, 6);
    PrintLinkedList(head);

    RemoveDuplicatedNode(head);
    PrintLinkedList(head);

    RemoveLinkedList(head);
    return 0;
}