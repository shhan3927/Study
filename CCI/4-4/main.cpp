#include <iostream>
#include "TreeNode.h"
#include <vector>
#include <list>
#include <queue>

using namespace std;

int GetDepth(TreeNodePtr tree, int depth)
{
    if(tree == nullptr) { return depth; }
    depth++;
    auto lDepth = GetDepth(tree->left, depth);
    auto rDepth = GetDepth(tree->right, depth);

    return max(lDepth, rDepth);
}

// BST의 균형이 맞는지 체크, 균형이 맞다는 것은 왼쪽 부분 트리와
// 오른쪽 부분 트리의 높이 차가 최대 하나인 것을 의미한다.
bool IsBalanced(TreeNodePtr tree)
{
    auto lDepth = GetDepth(tree->left, 1);
    auto rDepth = GetDepth(tree->right, 1);
    return abs(lDepth - rDepth) <= 1;
}

int GetDepth2(TreeNodePtr tree)
{
    if(tree == nullptr)
    {
        return -1;
    }

    auto l = GetDepth2(tree->left);
    if(l == -100) { return -100; }

    auto r = GetDepth2(tree->right);
    if(r == -100) { return -100; }

    if(abs(l-r) > 1)
    {
        return -100;
    }

    return max(l, r) + 1;
}

bool IsBalanced2(TreeNodePtr tree)
{
    return GetDepth2(tree) != -100;
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
    Insert(tree, 17);

    cout << IsBalanced2(tree) << endl;

    Insert(tree, 18);
    Insert(tree, 19);

    cout << IsBalanced2(tree) << endl;

    return 0;
}
