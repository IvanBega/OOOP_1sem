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
    Date d1(2023, 3, 3, 0, 0, 0);
    Date d2(2022, 3, 2, 0, 0, 0);
    bool b = d1 > d2;
    std::cout << b;
}
