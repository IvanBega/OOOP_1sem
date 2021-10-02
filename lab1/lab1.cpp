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
    Date d1(2022, 3, 3, 14, 50, 52);
    Date d2(2022, 3, 3, 14, 50, 51);
    bool b = d1 > d2;
    std::cout << b;
}
