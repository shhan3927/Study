#pragma once

#include <functional>

template<typename T>
class Node
{
public:
	Node(Node* inLeft, Node* inRight, T inValue)
	:left(inLeft), right(inRight), value(inValue) {}

public:
	Node* GetLeft() const { return left; }
	void SetLeft(Node* node) { left = node; }
	Node* GetRight() const { return right; }
	void SetRight(Node* node) { right = node; }
	T GetValue() const { return value; }

private:
	Node* left;
	Node* right;
	T value;
};

template<typename T>
class BinarySearchTree
{
public:
	Node<T>* Add(T value);
	const Node<T>* Find(const Node<T>* node, T value) const;
	int GetDepth(const Node<T*> node) const;
	void PreorderTravel(const Node<T>* node, std::function<void (const Node<T>*)>callback) const;
	void InorderTravel(const Node<T>* node, std::function<void(const Node<T>*)>callback) const;
	void PostorderTravel(const Node<T>* node, std::function<void(const Node<T>*)>callback) const;

public:
	const Node<T>* GetRoot() const { return root; }

private:
	Node<T>* root = nullptr;
	Node<T>* current;
};

template<typename T>
Node<T>* BinarySearchTree<T>::Add(T value)
{
	current = root;
	Node<T>* parent = nullptr;

	while (current != nullptr)
	{
		if (current->GetValue() == value) { return nullptr; }

		parent = current;
		if (current->GetValue() < value)
		{
			current = current->GetRight();
		}
		else {
			current = current->GetLeft();
		}
	}

	current = new Node<T>(nullptr, nullptr, value);
	if (root == nullptr) 
	{ 
		root = current; 
	}
	else if(parent != nullptr)
	{
		if (parent->GetValue() > value)
		{
			parent->SetLeft(current);
		}
		else
		{
			parent->SetRight(current);
		}
	}

	return current;
};

template<typename T>
void BinarySearchTree<T>::PreorderTravel(const Node<T>* node, std::function<void(const Node<T>*)>callback) const
{
	if (node == nullptr) { return; }
	callback(node);
	PreorderTravel(node->GetLeft(), callback);
	PreorderTravel(node->GetRight(), callback);
}

template<typename T>
void BinarySearchTree<T>::InorderTravel(const Node<T>* node, std::function<void(const Node<T>*)>callback) const
{
	if (node == nullptr) { return; }
	InorderTravel(node->GetLeft(), callback);
	callback(node);
	InorderTravel(node->GetRight(), callback);
}

template<typename T>
void BinarySearchTree<T>::PostorderTravel(const Node<T>* node, std::function<void(const Node<T>*)>callback) const
{
	if (node == nullptr) { return; }
	PostorderTravel(node->GetLeft(), callback);
	PostorderTravel(node->GetRight(), callback);
	callback(node);
}

template<typename T>
const Node<T>* BinarySearchTree<T>::Find(const Node<T>* node, T value) const
{
	if (node == nullptr) { return nullptr; }
	if (node->GetValue() == value) { return node; }
	if (node->GetValue() > value) { return Find(node->GetLeft(), value); }
	if (node->GetValue() < value) { return Find(node->GetRight(), value); }
}

template<typename T>
int BinarySearchTree<T>::GetDepth(const Node<T*> node) const
{
	if (node == nulllptr) { return 0; }
	return 1 + std::max_align_t(GetDepth(node->GetLeft()), GetDepth(node->GetRight));
}
