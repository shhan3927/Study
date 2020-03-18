#include <iostream>
#include <cmath>
#include "LinkedList.h"

using namespace std;

Node<int>* GetDuplicatedNode(Node<int>* one, Node<int>* other)
{
    int sizeOne = GetLinkedListSize(one);
    int sizeOther = GetLinkedListSize(other);
    int diff = abs(sizeOne - sizeOther);
    auto minNode = sizeOne > sizeOther ? other : one;
    auto maxNode = sizeOne > sizeOther ? one : other;

    while(diff > 0)
    {
        maxNode = maxNode->GetNext();
        diff--;
    }

    int minSize = sizeOne > sizeOther ? sizeOther : sizeOne;
    while(minSize > 0)
    {
        if(minNode == maxNode)
        {
            return minNode;
        }

        minNode = minNode->GetNext();
        maxNode = maxNode->GetNext();
        minSize--;
    }

    return nullptr;
}

int main()
{
    Node<int>* head1 = nullptr;
    InsertHeadInLinkedList(&head1, 6);
    InsertHeadInLinkedList(&head1, 1);
    auto node1 = InsertHeadInLinkedList(&head1, 7);
    InsertHeadInLinkedList(&head1, 3);
    InsertHeadInLinkedList(&head1, 7);
    InsertHeadInLinkedList(&head1, 1);
    InsertHeadInLinkedList(&head1, 1);

    Node<int>* head2 = nullptr;
    InsertHeadInLinkedList(&head2, node1);
    InsertHeadInLinkedList(&head2, 5);
    InsertHeadInLinkedList(&head2, 7);
    InsertHeadInLinkedList(&head2, 3);
    InsertHeadInLinkedList(&head2, 7);
    InsertHeadInLinkedList(&head2, 1);
    InsertHeadInLinkedList(&head2, 1);

    auto node = GetDuplicatedNode(head1, head2);
    PrintLinkedList(node);

    RemoveLinkedList(head1);
    //RemoveLinkedList(head2);

    return 0;
}