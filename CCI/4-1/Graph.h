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
	bool HasPath(NodePtr<T> start, NodePtr<T> end);

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
void Graph<T>::ResetAllVertex()
{
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
bool Graph<T>::HasPath(NodePtr<T> start, NodePtr<T> end)
{
	ResetAllVertex();
	queue<NodePtr<T>> q;
	start->color = EColor::Gray;

	q.push(start);
	while(!q.empty())
	{
		auto node = q.front();
		q.pop();

		for(auto child : container[node])
		{
			if(child == end)
			{
				return true;
			}
			else if(child->color != EColor::Black)
			{
				child->color = EColor::Gray;
				q.push(child);
			}
		}

		node->color = EColor::Black;
	}

	return false;
}