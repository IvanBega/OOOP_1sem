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
    Date d1(2021, 1, 31, 0, 0, 0);
    Date d2(2026, 1, 31, 0, 0, 0);
    Date temp = Date::secondsToDate(d2.toSeconds() - d1.toSeconds());
    temp.print();
}
