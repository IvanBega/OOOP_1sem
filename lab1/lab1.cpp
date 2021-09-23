#pragma once
#include <vector>
#include "LinkedListQueue.cpp"
#include "BinaryHeapQueue.cpp"
#include "Date.cpp"
#include "VectorQueue.cpp"
#include "BSTQueue.cpp"
#include <iostream>

int main()
{
    BSTQueue<int> q;
    q.push(1, 1);
    q.push(2, 2);
    q.push(3, 3);
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    q.push(1, 1);
    q.push(2, 2);
    q.push(3, 3);
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
}
