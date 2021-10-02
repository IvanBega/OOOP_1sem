#pragma once
#include <vector>
#include <iostream>
#include "Queue.cpp"
#include "LinkedListQueue.cpp"
#include "BinaryHeapQueue.cpp"
#include "Date.cpp"
#include "VectorQueue.cpp"
#include "BSTQueue.cpp"
#include "UserInterface.cpp"


int main()
{
	using namespace std;
	cout << "Demonstrating LinkedListQueue: \n";
	UserInterface::Test<LinkedListQueue<Date>>(10);
	cout << "\n";
	cout << "Demonstrating VectorQueue: \n";
	UserInterface::Test<VectorQueue<Date>>(10);
	cout << "\n";
	cout << "Demonstrating BinaryHeapQueue: \n";
	UserInterface::Test<BinaryHeapQueue<Date>>(10);
	cout << "\n";
	cout << "Demonstrating BSTQueue: \n";
	UserInterface::Test<BSTQueue<Date>>(10);
	cout << "\n";
	cout << "Demonstrating Date addition: \n";
	UserInterface::AddDateDemonstration(10);
	cout << "\n";
	cout << "Demonstrating Date subtraction: \n";
	UserInterface::SubtractDateDemonstration(10);
	cout << "\n";
	
}
