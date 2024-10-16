#include<iostream>
#include "deque.h"
template<typename T>
Deque<T>::Deque() :head{nullptr}, tail{nullptr}, count{0} {}

template<typename T>
Deque<T>::~Deque() {
	while (head) {
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
}

template<typename T>
void Deque<T>::pushFront(const T& val) {
	Node* newNode = new Node(val, head, nullptr);
	if (!head) {
		head = tail = newNode;
	}
	else {
		head->prev = newNode;
		head = newNode;
	}
	++count;
}

template<typename T>
void Deque<T>::pushBack(const T& val) {
	Node* newNode = new Node(val, nullptr, tail);
	if (!head) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	++count;
}

template<typename T>
void Deque<T>::popFront() {
	if (!head) {
		throw std::runtime_error("Deque is empty");
	}
	Node* tmp = head;
	if (head == tail) {
		head = tail = nullptr;
	}
	else {
		head = head->next;
		head->prev = nullptr;
	}
	delete tmp;
	--count;
}

template<typename T>
void Deque<T>::popBack() {
	if (!head) {
		throw std::runtime_error("Deque is empty");
	}
	Node* tmp = tail;
	if (head == tail) {
		head = tail = nullptr;
	}
	else {
		tail = tail->prev;
		tail->next = nullptr;
	}
	delete tmp;
	--count;
}

template<typename T>
T Deque<T>::front() const {
	if (!head) {
		throw std::runtime_error("Deque is empty");
	}
	return head->data;
}

template<typename T>
T Deque<T>::back() const {
	if (!head) {
		throw std::runtime_error("Deque is empty");
	}
	return tail->data;
}

template<typename T>
bool Deque<T>::isEmpty() const{
	return head == nullptr;
}

template<typename T>
int Deque<T>::size() const {
	return count;
}