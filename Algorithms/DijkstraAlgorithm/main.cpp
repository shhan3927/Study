#include <iostream>
#include <map>
#include <limits>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Edge
{
	Edge(int s, int d, int w)
	:start(s), dest(d), weight(w) {}

	int start;
	int dest;
	int weight;
};

struct Node
{
	Node(int v, int w, int p)
	:vertex(v), weight(w), parent(p) {}

	int vertex;
	int weight;
	int parent;
};

struct Graph
{
	Graph(int n)
	:vectexCount(n)
	{
		dests.resize(n+1);
		for(int i=1; i<=n; i++)
		{
			dests[i] = i;
		}
	}

	void AddEdge(int s, int d, int w)
	{
		edges[s].emplace_back(s, d, w);
	}

	int vectexCount;
	map<int, vector<Edge>> edges;
	vector<int> dests;
};

void Dijkstra(Graph g)
{
	auto Compare = [](const Node& one, const Node& other)
	{
		return one.weight > other.weight;
	};
	priority_queue<Node, vector<Node>, decltype(Compare)> q(Compare);

	for(int i=1; i<=g.vectexCount; i++)
	{
		g.dests[i] = i == g.vectexCount ? 0 : numeric_limits<int>::max();
		Node n(i, g.dests[i], 0);
		q.push(n);
	}

	while(!q.empty())
	{
		Node n = q.top();
		q.pop();

		if(n.weight <= g.dests[n.vertex])
		{
			for(auto& e : g.edges[n.vertex])
			{
				g.dests[e.dest] = min(g.dests[e.dest], g.dests[n.vertex] + e.weight);
				Node newNode(e.dest, g.dests[e.dest], n.vertex);
				q.push(newNode);
			}
		}
	}
}

int main()
{
	int n = 5;
	Graph g(n);
	g.AddEdge(1, 3, 3);
	g.AddEdge(1, 4, 3);
	g.AddEdge(2, 1, 3);
	g.AddEdge(3, 4, 2);
	g.AddEdge(4, 2, 1);
	g.AddEdge(4, 3, 1);
	g.AddEdge(5, 2, 4);
	g.AddEdge(5, 4, 2);

	Dijkstra(g);

	return 0;
}