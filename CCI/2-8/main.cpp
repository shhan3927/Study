#include <iostream>
#include <set>
#include "LinkedList.h"

using namespace std;
using NodePtr = Node<int>*;

NodePtr GetCircularNode(NodePtr head)
{
    set<NodePtr> s;
    auto node = head;
    while(node != nullptr)
    {
        if(s.find(node) != s.end())
        {
            return node;
        }

        s.insert(node);
        node = node->GetNext();
    }

    return nullptr;
}

int main()
{
    Node<int>* head = nullptr;
    InsertHeadInLinkedList(&head, 6);
    InsertHeadInLinkedList(&head, 1);
    auto node1 = InsertHeadInLinkedList(&head, 7);
    InsertHeadInLinkedList(&head, 3);
    InsertHeadInLinkedList(&head, 7);
    InsertHeadInLinkedList(&head, 1);
    InsertHeadInLinkedList(&head, 1);
    InsertTailInLinkedList(&head, node1);

    auto node = GetCircularNode(head);
    cout << node->GetData() << endl;

    RemoveLinkedList(head);

    return 0;
}