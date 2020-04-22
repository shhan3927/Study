#include <iostream>
#include "TreeNode.h"
#include <vector>
#include <list>
#include <queue>

using namespace std;

vector<list<TreeNodePtr>> MakeLinkedListWithSameDepthNode(TreeNodePtr t)
{
    vector<list<TreeNodePtr>> ret;
    queue<TreeNodePtr> q;

    q.push(t);
    while(!q.empty())
    {
        list<TreeNodePtr> list;
        while(!q.empty())
        {
            list.push_back(q.front());
            q.pop();
        }

        auto it = list.begin();
        while(it != list.end())
        {
            if((*it)->left != nullptr)
            {
                q.push((*it)->left);
            }
            if((*it)->right != nullptr)
            {
                q.push((*it)->right);
            }

            it++;
        }

        ret.push_back(list);
    }

    return ret;
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

    InorderTravel(tree);
    cout << endl;

    // auto depthNode = MakeLinkedListWithSameDepthNode(tree);

    // for(auto l : depthNode)
    // {
    //     for(auto node : l)
    //     {
    //         cout << node->value << ", ";
    //     }
    //     cout << endl;
    // }

    auto v = CreatelevelLinkedList(tree);
    for(auto l : v)
    {
        for(auto node : l)
        {
            cout << node->value << ", ";
        }
        cout << endl;
    }

    return 0;
}
