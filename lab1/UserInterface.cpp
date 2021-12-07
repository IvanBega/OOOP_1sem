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
#include <chrono>
class UserInterface
{
public:
	template<typename T>
	static void Test(int count)
	{
		T q;
		auto start = std::chrono::high_resolution_clock::now();
		UserInterface::QueueDemonstration(q, count);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		std::cout << "\nTook " << duration.count() << " microseconds";
	}
	template<typename T>
	static void QueueDemonstration(T q, int count)
	{
		std::cout << "Pushing " << count << " elements:\n";
		for (int i = 0; i < count; i++)
		{
			// pushing
			Date temp;
			temp.fillWithRandom();
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
			date.fillWithRandom();
			dateToAdd.fillWithRandom();
			dateToAdd.subtractYear(2000);
			cout << "Adding ";
			dateToAdd.print3();
			cout << " to the "; date.print3(); cout << endl;
			date.addDate(dateToAdd);
			cout << "Result: "; date.print(); cout << endl;
			
		}
	}
	static void SubtractDateDemonstration(int count)
	{
		using namespace std;
		Date date, dateToSubtract;
		for (int i = 0; i < count; i++)
		{
			date.fillWithRandom();
			dateToSubtract.fillWithRandom();
			dateToSubtract.subtractYear(2000);

			cout << "Subtracting ";
			dateToSubtract.print3();
			cout << " from "; date.print3(); cout << endl;
			date.subtractDate(dateToSubtract);
			cout << "Result: "; date.print(); cout << endl;
			
		}
	}
	static void DateDiffDemonstration(int count)
	{
		using namespace std;
		Date date1, date2;
		int days;
		for (int i = 0; i < count; i++)
		{
			date1.fillWithRandom();
			date2.fillWithRandom();
			date1.print();
			cout << "\n";
			date2.print();
			cout << "\n";
			int days = Date::dateDiff(date1, date2);
			cout << "Distance between two dates is " << days << " days\n"
				<< "------------------------------------------------\n";
		}
	}
	static void ConsoleQueueInterface()
	{
		using namespace std;
		int option;
		Queue<int>* q = NULL;
		cout << "Choose data structure:\n1 - LinkedListQueue\n2 - VectorQueue\n3 - BSTQueue\n4 - BinaryHeapQueue\n5 - Exit\n";
		cin >> option;

		// choosing data structure
		switch (option)
		{
		case 1:
			cout << "Using LinkedListQueue\n";
			q = new LinkedListQueue<int>;
			break;
		case 2:
			cout << "Using VectorQueue\n";
			q = new VectorQueue<int>;
			break;
		case 3:
			cout << "Using BSTQueue\n";
			q = new BSTQueue<int>;
			break;
		case 4:
			q = new BinaryHeapQueue<int>;
			cout << "Using BinaryHeapQueue\n";
			break;
		}

		// choosing operations  on data structure
		cout << "\nChoose operation:\n1 - Lookup top element\n2 - Insert\n3 - Pop\n4 - Exit\n";
		cin >> option;
		int priority, data;
		while (option != 4)
		{
			switch (option)
			{
			case 1:
				cout << "Top element is " << q->lookup_elem() << "\n";
				break;
			case 2:
				cout << "Enter data: ";
				cin >> data;
				cout << "Enter priority: ";
				cin >> priority;
				q->push(data, priority);
				break;
			case 3:
				cout << "Popped element " << q->pop() << "\n";
				break;
			}
			cout << "Choose next operation: ";
			cin >> option;
		}
	}
	static void ConsoleDateInterface()
	{
		using namespace std;
		Date d1, d2;
		int option = 0, days = 0;
		while (option < 5)
		{
			cout << "\nChoose date operation:\n0 - Fill randomy\n1 - Fill from Console\n2 - Add date\n3 - Subtract date\n4 - Date distance\n5 - Main menu\n";
			cin >> option;
			switch (option)
			{
			case 0:
				d1.fillWithRandom();
				cout << "Your date is "; d1.print(); cout << "\n";
				break;
			case 1:
				d1.fillFromConsole();
				cout << "\n";
				break;
			case 2:
				cout << "Enter date you want to add:\n";
				d2.fillFromConsole();
				cout << "\n";
				d1.addDate(d2);
				cout << "\n";
				cout << "Result of addition is "; d1.print(); cout << "\n";
				break;

			case 3:
				cout << "Enter date to subtract:\n";
				d2.fillFromConsole();
				cout << "\n";
				d1.subtractDate(d2);
				cout << "Result of subtraction is "; d1.print(); cout << "\n";

				break;
			case 4:
				cout << "Enter date you want to compare to:\n";
				d2.fillFromConsole();
				cout << "\n";
				d1.print();
				cout << "\n";
				d2.print();
				cout << "\n";
				days = Date::dateDiff(d1, d2);
				cout << "Distance between two dates is " << days << " days\n"
					<< "------------------------------------------------\n";
				break;
			case 5:
				option = 5;
				break;
			}
		}
	}
};