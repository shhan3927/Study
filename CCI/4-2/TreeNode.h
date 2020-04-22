// CCI 정답
#pragma once

#include <memory>
#include <functional>
#include <iostream>

using namespace std;

struct TreeNode
{
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;
    int value;
};

using TreeNodePtr = shared_ptr<TreeNode>;

void InorderTravel(TreeNodePtr node)
{
    if(node == nullptr) { return; }
    InorderTravel(node->left);
    cout << node->value << ", ";
    InorderTravel(node->right);
}

TreeNodePtr CreateMinimalBst(int* arr, int start, int end)
{
    if(start > end)
    {
        return nullptr;
    }

    int m = (start + end + 1) / 2;
    TreeNodePtr node = make_shared<TreeNode>();
    node->value = arr[m];
    node->left = CreateMinimalBst(arr, start, m-1);
    node->right = CreateMinimalBst(arr, m+1, end);

    return node;
}