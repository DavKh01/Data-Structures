#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue {
public:
    Queue();               // Constructor
    ~Queue();              // Destructor
    void enqueue(const T&); // Add element to the queue
    void dequeue();        // Remove element from the queue
    T front() const;       // Get the front element
    bool isEmpty() const;  // Check if the queue is empty
    int size() const;      // Get the number of elements in the queue

private:
    // Queue node definition
    struct Node {
        T data;
        Node* next;
        Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head;  // Pointer to the front of the queue
    Node* tail;  // Pointer to the back of the queue
    int count;   // Number of elements in the queue
};
#include "Queue.cpp"
#endif // QUEUE_H
