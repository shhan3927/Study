#include <iostream>
#include "Stack.h"

using namespace std;

void SortStack(Stack<int>& stack)
{
	Stack<int> buffer;

	while (!stack.Empty())
	{
		buffer.Push(stack.Pop());
	}

	while (!buffer.Empty())
	{
		auto data = buffer.Pop();
		int count = 0;
		while (!stack.Empty() && data > stack.Top())
		{
			buffer.Push(stack.Pop());
			count++;
		}

		stack.Push(data);

		for (int i = 0; i < count; i++)
		{
			stack.Push(stack.Pop());
		}
	}
}

int main()
{
	Stack<int> stack;
	stack.Push(4);
	stack.Push(8);
	stack.Push(2);
	stack.Push(1);
	stack.Push(3);
	stack.Push(6);
	stack.Push(5);
	stack.Push(10);

	SortStack(stack);

	while (!stack.Empty())
	{
		cout << stack.Pop() << ", ";
	}

	cout << endl;

    return 0;
}
