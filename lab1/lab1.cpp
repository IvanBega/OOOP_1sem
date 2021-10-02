#pragma once
#include <vector>
#include <iostream>
#include "Queue.cpp"
#include "LinkedListQueue.cpp"
#include "BinaryHeapQueue.cpp"
#include "Date.cpp"
#include "VectorQueue.cpp"
#include "BSTQueue.cpp"


int main()
{
	Date d1;
	for (int i = 0; i < 100; i++)
	{
		d1.fillWithRandom();
		d1.print();
		std::cout << std::endl;
	}
}
