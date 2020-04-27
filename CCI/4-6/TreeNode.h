// CCI 정답
#pragma once

#include <memory>
#include <functional>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct TreeNode
{
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;
    int value;
};

using TreeNodePtr = shared_ptr<TreeNode>;

TreeNodePtr Insert(TreeNodePtr root, int value)
{
    TreeNodePtr node = root;
    TreeNodePtr parent = nullptr;
    while(node != nullptr)
    {
        parent = node;
        if(node->value > value)
        {
            node = node->left;
        }
        else if(node->value < value)
        {
            node = node->right;
        }
    }

    node = make_shared<TreeNode>();
    node->value = value;

    if(parent->value > node->value)
    {
        parent->left = node;
    }
    else if(parent->value < node->value)
    {
        parent->right = node;
    }

    return node;
}

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

// CCI Answer
void CreateLevelLinkedList(TreeNodePtr root, vector<list<TreeNodePtr>>& lists, int level)
{
    if(root == nullptr)
    { 
        return; 
    }

    if(lists.size() == level)
    {
        lists.push_back(list<TreeNodePtr>());
    }

    lists[level].push_back(root);
    CreateLevelLinkedList(root->left, lists, level+1);
    CreateLevelLinkedList(root->right, lists, level+1);
}

vector<list<TreeNodePtr>> CreatelevelLinkedList(TreeNodePtr root)
{
    vector<list<TreeNodePtr>> l;
    CreateLevelLinkedList(root, l, 0);
    return l;
}
