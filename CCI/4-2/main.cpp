#include <iostream>
#include "BinarySearchTree.h"
#include "TreeNode.h"

using namespace std;

void MakeMinTree(BinarySearchTree<int>& t, int* arr, int start, int end)
{
    int m = (end + start + 1) / 2;
    if(m >= 0)
    {
        t.Insert(arr[m]);
    }

    if(m-1 >= start)
    {
        MakeMinTree(t, arr, start, m-1);
    }
    if(m+1 <= end)
    {
        MakeMinTree(t, arr, m+1, end);
    }
}

int main()
{
    BinarySearchTree<int> tree;
    int arr[] = {1,2,3,4,5,6,7,8};
    MakeMinTree(tree, arr, 0, 7);
    tree.InorderTravel(tree.GetRoot(), [](const Node<int>* node)
    {
        cout << node->GetValue() << ", ";
    });

    cout << endl;
    cout << "Tree Depth : " << tree.GetDepth(tree.GetRoot()) << endl;

    // CCI 정답
    cout << "==== CCI Answer ====" << endl;
    auto treeNode = CreateMinimalBst(arr, 0, 7);
    InorderTravel(treeNode);
    cout << endl;

    return 0;
}
