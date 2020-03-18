#include <iostream>
#include <cmath>
#include <stack>
#include "LinkedList.h"

using namespace std;

Node<int>* GetSum(Node<int>* one, Node<int>* other)
{
    auto GetDigit = [](Node<int>* head)
    {
        int digit = 0;
        auto current = head;
        int i = 0;

        while(current != nullptr)
        {
            digit += current->GetData() * pow(10, i);
            current = current->GetNext();
            i++;
        }

        return digit;
    };

    int sum = GetDigit(one) + GetDigit(other);

    stack<int> stack;
    while(sum > 0)
    {
        stack.push(sum % 10);
        sum /= 10;
    }

    Node<int>* head = nullptr;
    while(!stack.empty())
    {
        auto node = new Node<int>(stack.top(), head);
        stack.pop();
        head = node;
    }

    return head;
}

void Add(Node<int>* n1, Node<int>* n2, Node<int>** result, int value)
{
    if(n1 == nullptr && n2 == nullptr) { return; }

    auto value1 = n1 != nullptr ? n1->GetData() : 0;
    auto value2 = n2 != nullptr ? n2->GetData() : 0;
    int sum = value1 + value2 + value;

    InsertTailInLinkedList(result, sum % 10);
    auto next1 = n1 != nullptr ? n1->GetNext() : nullptr;
    auto next2 = n2 != nullptr ? n2->GetNext() : nullptr;
    Add(next1, next2, result, sum / 10);
}

Node<int>* GetSumRecursively(Node<int>* head1, Node<int>* head2)
{
    Node<int>* result = nullptr;
    Add(head1, head2, &result, 0);
    return result;
}

int main()
{
    Node<int>* head1 = nullptr;
    InsertHeadInLinkedList(&head1, 6);
    InsertHeadInLinkedList(&head1, 1);
    InsertHeadInLinkedList(&head1, 7);

    Node<int>* head2 = nullptr;
    InsertHeadInLinkedList(&head2, 2);
    InsertHeadInLinkedList(&head2, 9);
    InsertHeadInLinkedList(&head2, 5);
    InsertHeadInLinkedList(&head2, 5);

    auto sumHead1 = GetSum(head1, head2);
    PrintLinkedList(sumHead1);

    auto sumHead2 = GetSumRecursively(head1, head2);
    PrintLinkedList(sumHead2);

    RemoveLinkedList(head1);
    RemoveLinkedList(head2);
    RemoveLinkedList(sumHead1);
    RemoveLinkedList(sumHead2);

    return 0;
}