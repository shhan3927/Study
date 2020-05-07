#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

struct TreeNode
{
    TreeNode(char v, TreeNode* p, TreeNode* l, TreeNode* r)
    : value(v), parent(p), left(l), right(r) {}

    TreeNode* Add(char c)
    {
        TreeNode* node = new TreeNode(c, this, nullptr, nullptr);
        if(left == nullptr)
        {
            left = node;
        }
        else if(right == nullptr)
        {
            right = node;
        }

        return node;
    }

    char value;
    TreeNode* parent = nullptr;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
};

void PostOrderForFree(TreeNode* node)
{
    if(node == nullptr)
    {
        return;
    }

    PostOrderForFree(node->left);
    PostOrderForFree(node->right);
    if(node != nullptr)
    {
        delete node;
    }
}

TreeNode* GetCommonAncestor(TreeNode* one, TreeNode* other)
{
    auto GetDepth = [](TreeNode* c)
    {
        int depth = 1;
        while(c->parent != nullptr)
        {
            c = c->parent;
            depth++;
        }

        return depth;
    };

    int depth1 = GetDepth(one);
    int depth2 = GetDepth(other);

    TreeNode* deeper = depth1 > depth2 ? one: other;
    TreeNode* weaker = depth1 > depth2 ? other: one;
    int diff = abs(depth1 - depth2);

    for(int i=0; i<diff; i++)
    {
        deeper = deeper->parent;
    }

    while((deeper!= nullptr && weaker != nullptr) 
        && (deeper != weaker))
    {
        deeper = deeper->parent;
        weaker = weaker->parent;
    }

    if(deeper != nullptr && weaker != nullptr)
    {
        return deeper;
    }

    return nullptr;
}

struct TreeData
{
    int direction;
    TreeNode* in = nullptr;
    TreeNode* out = nullptr;
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int vertexN;
    cin >> vertexN;

    string buffer;
    cin >> buffer;

    vector<int> direction;
    for(auto c : buffer)
    {
        direction.push_back(c - '0');
    }

    int r1, r2;
    cin >> r1 >> r2;
    {
        TreeNode* tree = nullptr;
        TreeNode* root = nullptr;
        vector<TreeData> treeDatas;

        int index = 0;
        int minus = 0;
        for(auto i : direction)
        {
            TreeData treeData;
            treeData.direction = i;

            if(i == 0)
            {
                if(tree == nullptr)
                {
                    tree = new TreeNode('a' + index - minus, nullptr, nullptr, nullptr);
                    root = tree;
                }
                else
                {
                    tree = tree->Add('a' + index - minus);
                }

                treeData.in = tree;
            }
            else
            {
                treeData.out = tree;
                tree = tree->parent;
                minus++;
            }
            
            treeDatas.push_back(treeData);
            index++;
        }

        TreeNode* removeTree1 = treeDatas[r1-1].in != nullptr ? treeDatas[r1-1].in : treeDatas[r1-1].out;
        TreeNode* removeTree2 = treeDatas[r2-1].in != nullptr ? treeDatas[r2-1].in : treeDatas[r2-1].out;

        auto commonAncester = GetCommonAncestor(removeTree1, removeTree2);
        int foundCount = 0;
        int found[2];
        int i = 0;
        while(foundCount < 2)
        {
            if(treeDatas[i].in == commonAncester)
            {
                found[foundCount] = i+1;
                foundCount++;
            }
            else if(treeDatas[i].out == commonAncester)
            {
                found[foundCount] = i+1;
                foundCount++;
            }
            i++;
        }

        cout << found[0] << " " << found[1] << "\n";

        PostOrderForFree(root);
    }

    //////////////////////////////////
    // 다른 풀이
    {
        struct Node
        {
            Node(char v, Node* p)
            : value(v), parent(p) {}
            char value;
            Node* parent = nullptr;
        };

        struct NodeData
        {
            int direction;
            Node* in = nullptr;
            Node* out = nullptr;

            Node* GetNode()
            {
                return in != nullptr ? in : out;
            }
        };

        vector<Node*> nodes;
        vector<NodeData> datas;
        Node* current = nullptr;

        for(auto i : direction)
        {
            NodeData data;
            data.direction = i;
            if(i == 0)
            {
                current = new Node('a' + datas.size(), current);
                nodes.push_back(current);
                data.in = current;
            }
            else
            {
                data.out = current;
                current = current->parent;
            }
            datas.push_back(data);
        }

        auto node1 = datas[r1-1].GetNode();
        auto node2 = datas[r2-1].GetNode();

        auto GetDepth = [](Node* n)
        {
            int depth = 1;
            auto current = n;
            while(current != nullptr)
            {
                current = current->parent;
                depth++;
            }

            return depth;
        };

        auto depth1 = GetDepth(node1);
        auto depth2 = GetDepth(node2);

        auto minNode = depth1 > depth2 ? node2 : node1;
        auto maxNode = depth1 > depth2 ? node1 : node2;

        for(int i=0; i<abs(depth1-depth2); i++)
        {
            maxNode = maxNode->parent;
        }

        while(minNode != maxNode)
        {
            minNode = minNode->parent;
            maxNode = maxNode->parent;
        }

        int result[2];
        int found = 0;
        int i = 0;
        while((found < 2) && (i < datas.size()))
        {
            if(datas[i].GetNode() == maxNode)
            {
                result[found] = i+1;
                found++;
            }
            i++;
        }

        cout << result[0] << " " << result[1] << "\n";

        for(auto n : nodes)
        {
            delete n;
        }
    }
    return 0;
}
