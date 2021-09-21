#include <vector>
#include "LinkedListQueue.cpp"
#include "BinaryHeapQueue.cpp"
#include "Date.cpp"
#include "VectorQueue.cpp"
#include <iostream>

int main()
{
    VectorQueue<int> v;
    v.push(10, 5);
    v.push(7, 5);
    v.push(12, 5);
    v.push(9, 5);
    std::cout << v.pop() << endl;
    std::cout << v.pop() << endl;
    std::cout << v.pop() << endl;
    std::cout << v.pop() << endl;
}
