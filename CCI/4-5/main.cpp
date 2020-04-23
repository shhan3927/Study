#include <iostream>
#include "TreeNode.h"

using namespace std;

// 이진 트리가 이진 탐색 트리인지 검증
bool CheckBST(TreeNodePtr tree)
{
    if(tree == nullptr)
    {
        return true;
    }

    if(tree->left != nullptr && tree->value < tree->left->value)
    {
        return false;
    }

    if(tree->right != nullptr && tree->value > tree->right->value)
    {
        return false;
    }

    bool isCheck = CheckBST(tree->left);
    if(!isCheck)
    {
        return false;
    }

    return CheckBST(tree->right);
}

int main()
{
    TreeNodePtr tree = make_shared<TreeNode>();
    tree->value = 8;

    Insert(tree, 4);
    Insert(tree, 12);
    Insert(tree, 2);
    Insert(tree, 6);
    Insert(tree, 10);
    Insert(tree, 14);
    Insert(tree, 1);
    Insert(tree, 16);
    auto node = Insert(tree, 15);

    cout << CheckBST(tree) << endl;

    node->value = 9;

    cout << CheckBST(tree) << endl;

    return 0;
}
