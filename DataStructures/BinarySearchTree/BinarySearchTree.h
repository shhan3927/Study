#pragma once

#include <functional>

template <typename T>
class BinarySearchTree;

template<typename T>
class Node
{	
	friend class BinarySearchTree<T>;
public:
	Node(Node* inParent, Node* inLeft, Node* inRight, T inValue)
	:parent(inParent), left(inLeft), right(inRight), value(inValue) {}

public:
	Node* GetLeft() const { return left; }
	void SetLeft(Node* node) { left = node; }
	Node* GetRight() const { return right; }
	void SetRight(Node* node) { right = node; }
	T GetValue() const { return value; }

private:
	Node* left;
	Node* right;
	Node* parent;
	T value;
};

template<typename T>
class BinarySearchTree
{
public:
	~BinarySearchTree()
	{
		InorderTravel(root, [](const Node<T>* node){
			delete node;
		});
	}

public:
	Node<T>* Insert(T value);
	void Delete(T value);
	Node<T>* Minimum();
	Node<T>* Maximum();
	Node<T>* Minimum(Node<T>* node);
	Node<T>* Maximum(Node<T>* node);
	Node<T>* Successor(T value);  	// 직후 원소
	Node<T>* Predecessor(T value);	// 직전 원소
	Node<T>* Search(T value);
	Node<T>* Search(Node<T>* node, T value);
	void Transplant(Node<T>* one, Node<T>* other);
	int GetDepth(Node<T*> node) const;
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
Node<T>* BinarySearchTree<T>::Insert(T value)
{
	current = root;
	Node<T>* parent = nullptr;

	while (current != nullptr)
	{
		parent = current;
		if (current->value > value)
		{
			current = current->left;
		}
		else{
			current = current->right;
		}
	}

	current = new Node<T>(parent, nullptr, nullptr, value);

	if (parent == nullptr) 
	{ 
		root = current;
	}
 	else if (parent->value > value)
	{
		parent->left = current;
	}
	else
	{
		parent->right = current;
	}

	return current;
}

template<typename T>
void BinarySearchTree<T>::Delete(T value)
{
	auto node = Search(value);
	if(node == nullptr) { return; }

	if(node->left == nullptr)
	{
		Transplant(node, node->right);
	}
	else if(node->right == nullptr)
	{
		Transplant(node, node->left);
	}
	else
	{
		auto minNode = Minimum(node->right);
		if(minNode->parent != node)
		{
			Transplant(minNode, minNode->right);
			minNode->right = node->right;
			minNode->right->parent = minNode;
		}

		Transplant(node, minNode);
		minNode->left = node->left;
		minNode->left->parent = minNode;
	}
	
	delete node;
}

template<typename T>
Node<T>* BinarySearchTree<T>::Minimum()
{
	return Minimum(root);
}

template<typename T>
Node<T>* BinarySearchTree<T>::Maximum()
{
	return Maximum(root);
}

template<typename T>
Node<T>* BinarySearchTree<T>::Minimum(Node<T>* node)
{
	current = node;
	while(current->left != nullptr)
	{
		current = current->left;
	}

	return current;
}

template<typename T>
Node<T>* BinarySearchTree<T>::Maximum(Node<T>* node)
{
	current = node;
	while(current->right != nullptr)
	{
		current = current->right;
	}

	return current;
}

template<typename T>
Node<T>* BinarySearchTree<T>::Successor(T value)
{
	auto node = Search(value);
	if(node == nullptr)
	{
		return nullptr;
	}

	if(node->right != nullptr)
	{
		return Minimum(node->right);
	}

	current = node->parent;
	while(current != nullptr && node == current->right)
	{
		node = current;
		current = current->parent;
	}

	return current;
}

template<typename T>
Node<T>* BinarySearchTree<T>::Predecessor(T value)
{
	auto node = Search(value);
	if(node == nullptr)
	{
		return nullptr;
	}

	if(node->left != nullptr)
	{
		return node->left;
	}

	current = node->parent;

	while(current != nullptr && current->left == node)
	{
		node = current;
		current = current->parent;
	}

	return current;
}

template<typename T>
Node<T>* BinarySearchTree<T>::Search(T value)
{
	return Search(root, value);
}

template<typename T>
Node<T>* BinarySearchTree<T>::Search(Node<T>* node, T value)
{
	if(node == nullptr || node->value == value)
	{
		return node;
	}

	if(node->value > value)
	{
		return Search(node->left, value);
	}
	else
	{
		return Search(node->right, value);
	}
}

template<typename T>
void BinarySearchTree<T>::Transplant(Node<T>* one, Node<T>* other)
{
	if(one->parent == nullptr)
	{
		root = other;
	}
	else if(one == one->parent->left)
	{
		one->parent->left = other;
	}
	else
	{
		one->parent->right = other;
	}

	if(other != nullptr)
	{
		other->parent = one->parent;
	}
}

template<typename T>
void BinarySearchTree<T>::PreorderTravel(const Node<T>* node, std::function<void(const Node<T>*)>callback) const
{
	if (node == nullptr) { return; }
	callback(node);
	PreorderTravel(node->left, callback);
	PreorderTravel(node->right, callback);
}

template<typename T>
void BinarySearchTree<T>::InorderTravel(const Node<T>* node, std::function<void(const Node<T>*)>callback) const
{
	if (node == nullptr) { return; }
	InorderTravel(node->left, callback);
	callback(node);
	InorderTravel(node->right, callback);
}

template<typename T>
void BinarySearchTree<T>::PostorderTravel(const Node<T>* node, std::function<void(const Node<T>*)>callback) const
{
	if (node == nullptr) { return; }
	PostorderTravel(node->left, callback);
	PostorderTravel(node->right, callback);
	callback(node);
}

template<typename T>
int BinarySearchTree<T>::GetDepth(Node<T*> node) const
{
	if (node == nullptr) { return 0; }
	return 1 + std::max(GetDepth(node->left), GetDepth(node->right));
}
