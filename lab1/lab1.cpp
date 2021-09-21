#include "LinkedListQueue.cpp"
#include "BinaryHeapQueue.cpp"
#include <iostream>

int main()
{
    BinaryHeapQueue<int> bq;
    bq.push(100, 1);
    bq.push(200, 1);
    bq.push(300, 1);
    std::cout << bq.pop() << std::endl;
    std::cout << bq.pop() << std::endl;
    std::cout << bq.pop() << std::endl;
}
