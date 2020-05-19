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
		finish = numeric_limits<int>::max();
	}

	int distance = 0;
	int finish = 0; // 깊이 우선 탐색 중 노드 탐색 종료 시 기록되는 시간.
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
	void ResetAllVertex();
	void AddEdge(NodePtr<T> src, NodePtr<T> dest);
	void BFS(NodePtr<T> root, function<void(NodePtr<T>)> callback);
	void DFS(function<void(NodePtr<T>)> callback);
	void DFSVisit(NodePtr<T> node, function<void(NodePtr<T>)> callback);

private:
	int time = 0;
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
void Graph<T>::ResetAllVertex()
{
	time = 0;
	for (auto& pair : container)
	{
		pair.first->Reset();
	}
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
	ResetAllVertex();	
	root->color = EColor::Gray;
	root->distance = 0;

	queue<NodePtr<T>> nodeQueue;
	nodeQueue.push(root);

	while (!nodeQueue.empty())
	{
		auto node = nodeQueue.front();
		nodeQueue.pop();

		if(callback != nullptr)
		{
			callback(node);
		}

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
void Graph<T>::DFS(function<void(NodePtr<T>)> callback)
{
	ResetAllVertex();
	time = 0;

	for(auto& it : container)
	{
		auto node = it.first;
		if(node->color == EColor::White)
		{
			DFSVisit(node, callback);
		}
	}
}

template<typename T>
void Graph<T>::DFSVisit(NodePtr<T> node, function<void(NodePtr<T>)> callback)
{
	time += 1;
	node->distance = time;
	node->color = EColor::Gray;

	for(auto& childNode : container[node])
	{
		if(childNode->color == EColor::White)
		{
			childNode->parent = node;
			DFSVisit(childNode, nullptr);
		}
	}

	time += 1;
	node->finish = time;
	node->color = EColor::Black;
}