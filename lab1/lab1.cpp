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
    Date d1(2021, 2, 28, 14, 0, 0);
    d1.subtractDate(0, 0, 0, 15, 0, 0);
    d1.print();
}
