#pragma once
#include <vector>
#include <iostream>
#include "Queue.cpp"
#include "LinkedListQueue.cpp"
#include "BinaryHeapQueue.cpp"
#include "Date.cpp"
#include "VectorQueue.cpp"
#include "BSTQueue.cpp"
#include <cstdlib>
#include <ctime>
class UserInterface
{
public:
	static void LinkedListQueueDemonstration(int count)
	{
		LinkedListQueue<Date> q;
		// pushing
		std::cout << "Pusing " << count << " elements to LinkedListQueue:\n";
		for (int i = 0; i < count; i++)
		{
			Date temp;
			std::srand(std::rand());
			int priority = rand() % 1000;
			q.push(temp, priority);
			temp.print();
			std::cout << ", priority " << priority << std::endl;
		}
		std::cout << "\n";
		// popping
		Date temp;
		std::cout << "Popping " << count << " elements from LinkedListQueue:\n";
		for (int i = 0; i < count; i++)
		{
			temp = q.pop();
			temp.print();
			std::cout << "\n";
		}
	}
	static void BSTQueueDemonstration(int count)
	{
		BSTQueue<Date> q;
		// pushing
		std::cout << "Pusing " << count << " elements to BSTQueue:\n";
		for (int i = 0; i < count; i++)
		{
			Date temp;
			std::srand(std::rand());
			int priority = rand() % 1000;
			q.push(temp, priority);
			temp.print();
			std::cout << ", priority " << priority << std::endl;
		}
		std::cout << "\n";
		// popping
		Date temp;
		std::cout << "Popping " << count << " elements from BSTQueue:\n";
		for (int i = 0; i < count; i++)
		{
			temp = q.pop();
			temp.print();
			std::cout << "\n";
		}
	}
	static void VectorQueueDemonstration(int count)
	{
		VectorQueue<Date> q;
		// pushing
		std::cout << "Pusing " << count << " elements to VectorQueue:\n";
		for (int i = 0; i < count; i++)
		{
			Date temp;
			std::srand(std::rand());
			int priority = rand() % 1000;
			q.push(temp, priority);
			temp.print();
			std::cout << ", priority " << priority << std::endl;
		}
		std::cout << "\n";
		// popping
		Date temp;
		std::cout << "Popping " << count << " elements from VectorQueue:\n";
		for (int i = 0; i < count; i++)
		{
			temp = q.pop();
			temp.print();
			std::cout << "\n";
		}
	}
	static void BinaryHeapQueueDemonstration(int count)
	{
		BinaryHeapQueue<Date> q;
		// pushing
		std::cout << "Pusing " << count << " elements to VectorQueue:\n";
		for (int i = 0; i < count; i++)
		{
			Date temp;
			std::srand(std::rand());
			int priority = rand() % 1000;
			q.push(temp, priority);
			temp.print();
			std::cout << ", priority " << priority << std::endl;
		}
		std::cout << "\n";
		// popping
		Date temp;
		std::cout << "Popping " << count << " elements from VectorQueue:\n";
		for (int i = 0; i < count; i++)
		{
			temp = q.pop();
			temp.print();
			std::cout << "\n";
		}
	}
	//static void QueueDemonstration(Queue<T> q, int count)
	//{
	//	std::cout << "Pusing " << count << " elements:\n";
	//	for (int i = 0; i < count; i++)
	//	{
	//		Date temp;
	//		std::srand(std::rand());
	//		int priority = rand() % 1000;
	//		q.push(temp, priority);
	//		temp.print();
	//		std::cout << ", priority " << priority << std::endl;
	//	}
	//	std::cout << "\n";
	//	// popping
	//	Date temp;
	//	std::cout << "Popping " << count << " elements:\n";
	//	for (int i = 0; i < count; i++)
	//	{
	//		temp = q.pop();
	//		temp.print();
	//		std::cout << "\n";
	//	}
	//}
};