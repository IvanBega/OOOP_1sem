#include <vector>
#include <iostream>
#include "Queue.cpp"
template<class T>
class Node
{
public:
	T data;
	Node* next;
};

template<class T, int N>
class LinkedListQueue : Queue<T>
{
public:
	LinkedListQueue()
	{
		initialize_queue();
	}
	void add(T data, int priority)
	{
		Node<T>* temp = new Node<T>();
		temp->data = data;
		temp->next = arr[priority];
		arr[priority] = temp;
	}
	T lookup_elem()
	{
		Node<T>* prev;
		int j;
		Node<T>* current = lookup_elem(&prev, j);
		return current->data;
	}
	T pop()
	{
		Node<T>* prev;
		int j;
		Node<T>* ondelete = lookup_elem(&prev, j);
		T temp = ondelete->data;
		if (prev)
		{
			prev->next = ondelete->next;
		}
		else
		{
			arr[j] = NULL;
		}
		delete ondelete;
		return temp;

	}
private:
	Node<T>* arr[N];
	Node<T>* lookup_elem(Node<T>** prev, int& j)
	{
		Node<T>* temp = NULL;
		for (int i = 0; i < N; i++)
		{
			*prev = NULL;
			temp = arr[i];
			if (temp)
			{
				j = i;
				while (temp->next)
				{
					*prev = temp;
					temp = temp->next;
				}
				return temp;
			}
		}
		return NULL;
	}
	void initialize_queue()
	{
		for (int i = 0; i < N; i++)
		{
			arr[i] = NULL;
		}
	}
};