#include <iostream>
#include <memory>
#include <map>
#include <fstream>
#include "Heap.h"

using namespace std;

struct Node
{
	char c;
	int freq;
	shared_ptr<Node> left;
	shared_ptr<Node> right;
};

shared_ptr<Node> CreateNode(char c, int freq, shared_ptr<Node> left, shared_ptr<Node> right)
{
	auto node = make_shared<Node>();
	node->c = c;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

void Preorder(shared_ptr<Node> node, string code, map<char, string>& codeMap)
{
	if(node == nullptr)
	{
		return;
	}
	
	if(node->left == nullptr && node->right == nullptr)
	{
		codeMap[node->c] = code;
	}

	Preorder(node->left, code + "0", codeMap);
	Preorder(node->right, code + "1", codeMap);
}

int main()
{	
	Heap<shared_ptr<Node>> heap(EHeapType::MIN);
	heap.Compare = [](shared_ptr<Node> one, shared_ptr<Node> other)
	{
		return one->freq < other->freq;
	};

	string s = "abcefaabeefffffffaabceddddddd";
	map<char, int> charMap;
	for(auto c : s)
	{
		if(charMap.find(c) == charMap.end())
		{
			charMap[c] = 0;
		}

		charMap[c]++;
	}

	for(auto it : charMap)
	{
		heap.Append(CreateNode(it.first, it.second, nullptr, nullptr));
	}
	heap.Build();

	int n = heap.GetSize();
	for(int i=1; i<n; i++)
	{
		auto node = CreateNode(' ', 0, nullptr, nullptr);
		node->left = heap.ExtractTop();
		node->right = heap.ExtractTop();
		node->freq = node->left->freq + node->right->freq;

		heap.Append(node);
		heap.Build();
	}

	auto root = heap.ExtractTop();

	map<char, string> codeMap;
	string buffer;
	Preorder(root, buffer, codeMap);

	ofstream file1;
	file1.open("text.txt");

	if(file1.is_open())
	{
		file1.write(s.c_str(), s.size());
		file1.close();
	}

	for(auto c : s)
	{
		buffer += codeMap[c];
	}

	ofstream file2;
	file2.open("decode_test.txt");
	if(file2.is_open())
	{
		file2.write(buffer.c_str(), buffer.size());
		file2.close();
	}

	return 0;
}