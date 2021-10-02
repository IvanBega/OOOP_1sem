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
    /*Date d1(2021, 3, 1, 14, 0, 0);
    Date d2(2021, 2, 28, 14, 0, 0);
    Date temp = Date::dateDiff(d1, d2);
    temp.print();*/
    BSTQueue<int> q;
    q.push(7, 7);
    q.push(9, 9);
    q.push(8, 8);
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
}
