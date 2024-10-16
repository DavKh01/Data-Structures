#include <iostream>
#include "deque.h"

int main() {
    Deque<int> deque;

    deque.pushFront(10);
    deque.pushBack(20);
    deque.pushFront(5);
    deque.pushBack(25);

    std::cout << "Front element: " << deque.front() << std::endl;
    std::cout << "Back element: " << deque.back() << std::endl;
    std::cout << "Deque size: " << deque.size() << std::endl;

    deque.popFront();
    std::cout << "Front element after popFront: " << deque.front() << std::endl;
    std::cout << "Deque size after popFront: " << deque.size() << std::endl;

    deque.popBack();
    std::cout << "Back element after popBack: " << deque.back() << std::endl;
    std::cout << "Deque size after popBack: " << deque.size() << std::endl;

    return 0;
}
