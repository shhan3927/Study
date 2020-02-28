/* hello.cpp */
#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

Node<int>* LinkedListInsertTest(LinkedList<int>& list, int value)
{
    return list.InsertInHead(value);
}

void ShowLinkedList(LinkedList<int>& list)
{
    list.Foreach([](int value){
        cout << value << ", ";
    });

    cout << endl;
}

int main()
{
    LinkedList<int> list;
    auto node1 = LinkedListInsertTest(list, 1);
    ShowLinkedList(list);
    auto node2 = LinkedListInsertTest(list, 2);
    ShowLinkedList(list);
    auto node3 = LinkedListInsertTest(list, 3);
    ShowLinkedList(list);
    auto node4 = LinkedListInsertTest(list, 4);
    ShowLinkedList(list);
    auto node5 = LinkedListInsertTest(list, 5);
    ShowLinkedList(list);

    list.Delete(node5);
    ShowLinkedList(list);
    list.Delete(node2);
    ShowLinkedList(list);
    list.Delete(node3);
    ShowLinkedList(list);
    list.Delete(node4);
    ShowLinkedList(list);
    list.Delete(node1);
    ShowLinkedList(list);

    return 0;
}


