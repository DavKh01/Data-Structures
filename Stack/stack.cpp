#include "stack.h"
#include <iostream>
template <typename T>
Stack<T>::Stack() :head{ nullptr }, count{ 0 } {}

template <typename T>
Stack<T>::~Stack() {
	while (head) {
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
}

template <typename T>
void Stack<T>::push(const T& value) {
	head = new Node(value,head);
	++count;
}

template <typename T>
void Stack<T>::pop() {
	if (head) {
		Node* tmp = head;
		head = head->next;
		delete tmp;
		--count;
	}
}

template <typename T>
T Stack<T>::top()const {
	if (head) {
		return head->data;
	}
	throw std::runtime_error("Stack is empty\n");
}

template <typename T>
bool Stack<T>::isEmpty() const {
	return head == nullptr;
}

template <typename T>
int Stack<T>::size() const{
	return count;
}