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
    Date d1(2021, 2, 28,15,47,0);
    d1.addDate(0, 0, 1, 15, 13, 0);
    d1.print();
}
