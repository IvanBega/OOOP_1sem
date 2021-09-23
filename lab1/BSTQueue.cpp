#pragma once
#include "Queue.cpp"
#include <iostream>
template<class T>
class BSTQueue : Queue<T>
{
public:
	void push(T data, int priority)
	{
		if (head == NULL)
		{
			head = new Tree(data, priority);
		}
		else
			insert(head, data, priority);
	}
	T lookup_elem()
	{
		Tree* current = head;
		while (current->lt)
		{
			current = current->lt;
		}
		return current->data;
	}
	T pop()
	{
		return NULL;
	}
private:
	struct Tree
	{
		T data;
		int priority;
		Tree* lt;
		Tree* rt;
		Tree(T Data, int Priority, Tree* left = NULL, Tree* right = NULL)
		{
			data = Data; priority = Priority; lt = left; rt = right;
		}
	};
	Tree* head = NULL;
	Tree* insert(Tree* current, T data, int priority)
	{
		if (current == NULL)
		{
			return new Tree(data, priority);
		}
		if (priority < current->priority)
		{
			current->lt = insert(current->lt, data, priority);
		}
		else
		{
			current->rt = insert(current->rt, data, priority);
		}
	}
};