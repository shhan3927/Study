#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
	Graph<int> graph;
	auto node0 = graph.AddVertex(0);
	auto node1 = graph.AddVertex(1);
	auto node2 = graph.AddVertex(2);
	auto node3 = graph.AddVertex(3);
	auto node4 = graph.AddVertex(4);
	auto node5 = graph.AddVertex(5);

	graph.AddEdge(node0, node1);
	graph.AddEdge(node0, node3);

	graph.AddEdge(node1, node4);

	graph.AddEdge(node2, node4);
	graph.AddEdge(node2, node5);

	graph.AddEdge(node3, node1);

	graph.AddEdge(node4, node3);
	graph.AddEdge(node5, node5);

	graph.BFS(node0, [](NodePtr<int> node)
	{
		cout << node->value << ", ";
	});

	cout << endl;

	graph.DFS(nullptr);

	return 0;
}