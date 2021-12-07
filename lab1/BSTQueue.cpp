#pragma once
#include "Queue.cpp"
#include <iostream>
template<class T>
class BSTQueue : public Queue<T>
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
		return minTree()->data;
	}
	T pop()
	{
		if (head->lt == NULL)
		{
			Tree* temp = head;
			T data = temp->data;
			head = head->rt;
			delete temp;
			return data;
		}
		return delete_tree(head);
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
			return new Tree(data, priority, NULL, NULL);
		}
		if (priority <= current->priority)
		{
			current->lt = insert(current->lt, data, priority);
		}
		else
		{
			current->rt = insert(current->rt, data, priority);
		}
		return current;
	}
	Tree* minTree()
	{
		Tree* current = head;
		while (current->lt)
		{
			current = current->lt;
		}
		return current;
	}
	T delete_tree(Tree* current)
	{
		Tree* prev = NULL;
		while (current->lt)
		{
			prev = current;
			current = current->lt;
		}
		if (prev && current->rt)
		{
			prev->lt = current->rt;
		}
		else
		{
			prev->lt = NULL;
		}
		T data = current->data;
		delete current;
		return data;

	}
};