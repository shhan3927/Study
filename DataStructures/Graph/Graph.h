#pragma once

#include <map>
#include <list>
#include <memory>
#include <limits>
#include <functional>
#include <queue>

using namespace std;

enum class EColor
{
	White,
	Gray,
	Black
};

template<typename T>
struct Node
{
	void Reset()
	{
		distance = numeric_limits<int>::max();
		color = EColor::White;
		parent = nullptr;
	}

	int distance = 0;
	T value;
	EColor color = EColor::White;
	shared_ptr<Node> parent = nullptr;
};

//////////////////////////////////////

template<typename T>
using NodePtr = shared_ptr<Node<T>>;

template <typename T>
class Graph
{
public:
	NodePtr<T> AddVertex(T value);
	void AddEdge(NodePtr<T> src, NodePtr<T> dest);
	void BFS(NodePtr<T> root, function<void(NodePtr<T>)> callback);
	void DFS(NodePtr<T> root, function<void(NodePtr<T>)> callback);

private:
	map<NodePtr<T>, list<NodePtr<T>>> container;
};

template<typename T>
NodePtr<T> Graph<T>::AddVertex(T value)
{
	auto node = make_shared<Node<T>>();
	node->value = value;
	container[node] = list<NodePtr<T>>();

	return node;
}

template<typename T>
void Graph<T>::AddEdge(NodePtr<T> src, NodePtr<T> dest)
{
	auto& nodeList = container[src];
	nodeList.push_back(dest);
}

template<typename T>
void Graph<T>::BFS(NodePtr<T> root, function<void(NodePtr<T>)> callback)
{
	for (auto& pair : container)
	{
		pair.first->Reset();

		for (auto childNode : pair.second)
		{
			childNode->Reset();
		}
	}

	root->color = EColor::Gray;
	root->distance = 0;

	queue<NodePtr<T>> nodeQueue;
	nodeQueue.push(root);

	while (!nodeQueue.empty())
	{
		auto node = nodeQueue.front();
		nodeQueue.pop();
		callback(node);

		auto nodeList = container[node];
		for (auto childNode : nodeList)
		{
			if (childNode->color == EColor::White)
			{
				childNode->color = EColor::Gray;
				childNode->distance = node->distance + 1;
				childNode->parent = node;
				nodeQueue.push(childNode);
			}
		}

		node->color = EColor::Black;
	}
}

template<typename T>
void Graph<T>::DFS(NodePtr<T> root, function<void(NodePtr<T>)> callback)
{

}
