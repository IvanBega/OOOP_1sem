#pragma once
#include <vector>
#include "LinkedListQueue.cpp"
#include "BinaryHeapQueue.cpp"
#include "Date.cpp"
#include "VectorQueue.cpp"
#include <iostream>

int main()
{
    LinkedListQueue<int> q;
    q.push(1, 1);
    q.push(2, 1);
    q.push(3, 1);
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
}
