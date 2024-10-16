#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Front element: " << queue.front() << std::endl;
    std::cout << "Queue size: " << queue.size() << std::endl;

    queue.dequeue();
    std::cout << "Front element after dequeue: " << queue.front() << std::endl;
    std::cout << "Queue size after dequeue: " << queue.size() << std::endl;

    return 0;
}
