#include <iostream>
#include "Queue.cpp"
using namespace std;
template<class T>
class LinkedListQueue : Queue<T>
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
		if (head->priority > priority)
		{
			temp->next = head;
			head = temp;
		}
		else
		{

			while (current->next != NULL && current->next->priority < priority)
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