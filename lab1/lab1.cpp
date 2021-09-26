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
    Date d1(2005, 9, 6,0,0,0);
    Date d2(2015, 9, 6,0,0,0);
    Date temp = Date::dateDiff(d2, d1);
    temp.print();
}
