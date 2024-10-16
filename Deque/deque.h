#ifndef DEQUE_HPP
#define DEQUE_HPP

template <typename T>
class Deque {
public:
    Deque();               // Constructor
    ~Deque();              // Destructor
    void pushFront(const T&); // Add element to the front of the deque
    void pushBack(const T&);  // Add element to the back of the deque
    void popFront();       // Remove element from the front of the deque
    void popBack();        // Remove element from the back of the deque
    T front() const;       // Get the front element
    T back() const;        // Get the back element
    bool isEmpty() const;  // Check if the deque is empty
    int size() const;      // Get the number of elements in the deque

private:
    // Deque node definition
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& data, Node* next = nullptr, Node* prev = nullptr)
            : data(data), next(next), prev(prev) {}
    };

    Node* head;  // Pointer to the front of the deque
    Node* tail;  // Pointer to the back of the deque
    int count;   // Number of elements in the deque
};
#include "deque.cpp"
#endif // DEQUE_HPP
