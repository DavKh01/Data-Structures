#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack {
public:
    Stack();               // Constructor
    ~Stack();              // Destructor
    void push(const T&);   // Push element onto stack
    void pop();            // Pop element from stack
    T top() const;         // Get the top element
    bool isEmpty() const;  // Check if stack is empty
    int size() const;      // Get the number of elements in the stack

private:
    // Stack node definition
    struct Node {
        T data;
        Node* next;
        Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head;  // Pointer to the top of the stack
    int count;   // Number of elements in the stack
};
#include "stack.cpp"
#endif // STACK_H
