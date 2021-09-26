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
    Date d1(2020, 2, 1,0,0,0);
    d1.addDate(8, 5, 30);
    d1.print();
}
