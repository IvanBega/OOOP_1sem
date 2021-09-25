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
    Date d1(2018, 3, 3, 0, 0, 0);
    //Date d2(2019, 3, 3, 0, 0, 0);
    Date temp = Date::dateFromDays(d1.dateToDays());
    temp.print();
}
