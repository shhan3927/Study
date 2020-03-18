#include <iostream>
#include <stack>
#include <queue>
#include "LinkedList.h"

using namespace std;

bool IsPalindrome(Node<int>* head)
{
    auto current = head;
    stack<int> s;
    queue<int> q;

    while(current != nullptr)
    {
        s.push(current->GetData());
        q.push(current->GetData());
        current = current->GetNext();
    }

    int i=1;
    while(i <= s.size() / 2)
    {
        if(s.top() != q.front())
        {
            return false;
        }

        s.pop();
        q.pop();

        i++;
    }

    return true;
}

int main()
{
    Node<int>* head = nullptr;
    InsertHeadInLinkedList(&head, 6);
    InsertHeadInLinkedList(&head, 1);
    InsertHeadInLinkedList(&head, 7);
    InsertHeadInLinkedList(&head, 3);
    InsertHeadInLinkedList(&head, 7);
    InsertHeadInLinkedList(&head, 1);
    InsertHeadInLinkedList(&head, 1);

    cout << IsPalindrome(head) << endl;

    RemoveLinkedList(head);

    return 0;
}