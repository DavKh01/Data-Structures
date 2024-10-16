#include <iostream>
#include "Queue.h"

template <typename T>
Queue<T>::Queue() : head{nullptr}, tail{nullptr}, count{0} {}

template <typename T>
Queue<T>::~Queue() {
	while (head) {
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
}

template <typename T>
void Queue<T>::enqueue(const T& val) {
	Node* newNode = new Node(val);
	if (!head) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	++count;
}

template <typename T>
void Queue<T>::dequeue() {
	if (head) {
		Node* tmp = head;
		head = head->next;
		delete tmp;
		--count;
		if (!head) {
			tail = nullptr;
		}
	}
	else {
		throw std::runtime_error("Queue is empty");
	}
}

template <typename T>
T Queue<T>::front() const {
	if (head) {
		return head->data;
	}
	throw std::runtime_error("Queue is empty");
}

template <typename T>
bool Queue<T>::isEmpty() const {
	return head == nullptr;
}

template <typename T>
int Queue<T>::size() const {
	return count;
}