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
	template<typename T>
	static void Test(int count)
	{
		T q;
		UserInterface::QueueDemonstration(q, count);
	}
	template<typename T>
	static void QueueDemonstration(T q, int count)
	{
		std::cout << "Pushing " << count << " elements:\n";
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
		std::cout << "Popping " << count << " elements:\n";
		for (int i = 0; i < count; i++)
		{
			temp = q.pop();
			temp.print();
			std::cout << "\n";
		}
	}
	static void AddDateDemonstration(int count)
	{
		using namespace std;
		Date date, dateToAdd;
		for (int i = 0; i < count; i++)
		{
			dateToAdd.subtractYear(2000);

			cout << "Adding ";
			dateToAdd.print2();
			cout << " to the "; date.print(); cout << endl;
			date.addDate(dateToAdd);
			cout << "Result: "; date.print(); cout << endl;
			date.fillWithRandom();
			dateToAdd.fillWithRandom();
		}
	}
};