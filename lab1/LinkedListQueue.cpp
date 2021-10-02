#pragma once
#include <iostream>
#include "Queue.cpp"
template<class T>
class LinkedListQueue : public Queue<T>
{
public:
	void push(T data, int priority)
	{
		Node* current = head;
		Node* temp = new Node();
		temp->data = data;
		temp->priority = priority;
		if (head == NULL)
		{
			temp->next = NULL;
			head = temp;
			return;
		}
		if (priority < head->priority)
		{
			//std::cout << "head priority is " << head->priority << ", inserting priority is " << priority << std::endl;
			temp->next = head;
			head = temp;
		}
		else
		{

			while (current->next != NULL && current->next->priority <= priority)
			{
				current = current->next;
			}

			temp->next = current->next;
			current->next = temp;
		}
	}
	T pop()
	{
		Node* temp = head;
		T data = head->data;
		head = head->next;
		delete temp;
		return data;
	}
	T lookup_elem()
	{
		return head->data;
	}
private:
	struct Node
	{
		T data;
		Node* next;
		int priority;
	};
	Node* head = NULL;
};