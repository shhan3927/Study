#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    Graph<int> g;
    auto node1 = g.AddVertex(1);
    auto node2 = g.AddVertex(2);
    auto node3 = g.AddVertex(3);
    auto node4 = g.AddVertex(4);
    auto node5 = g.AddVertex(5);

    g.AddEdge(node1, node2);
    g.AddEdge(node1, node5);
    g.AddEdge(node2, node3);
    g.AddEdge(node3, node4);
    g.AddEdge(node4, node2);
    g.AddEdge(node5, node4);

    cout << g.HasPath(node1, node4) << endl;
    cout << g.HasPath(node2, node4) << endl;
    cout << g.HasPath(node2, node5) << endl;

    return 0;
}
