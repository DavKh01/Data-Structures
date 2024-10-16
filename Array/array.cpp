#include "array.h"

template <typename T, std::size_t N>
T& Array<T, N>::at(std::size_t index) {
    if (index >= N) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T, std::size_t N>
const T& Array<T, N>::at(std::size_t index) const {
    if (index >= N) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T, std::size_t N>
T& Array<T, N>::operator[](std::size_t index) {
    return data[index];
}

template <typename T, std::size_t N>
const T& Array<T, N>::operator[](std::size_t index) const {
    return data[index];
}

template <typename T, std::size_t N>
T& Array<T, N>::front() {
    return data[0];
}

template <typename T, std::size_t N>
const T& Array<T, N>::front() const {
    return data[0];
}

template <typename T, std::size_t N>
T& Array<T, N>::back() {
    return data[N - 1];
}

template <typename T, std::size_t N>
const T& Array<T, N>::back() const {
    return data[N - 1];
}

template <typename T, std::size_t N>
T* Array<T, N>::dataPtr() {
    return data;
}

template <typename T, std::size_t N>
const T* Array<T, N>::dataPtr() const {
    return data;
}

// Capacity
template <typename T, std::size_t N>
 std::size_t Array<T, N>::size() const noexcept {
    return N;
}

template <typename T, std::size_t N>
 bool Array<T, N>::empty() const noexcept {
    return N == 0;
}

template <typename T, std::size_t N>
void Array<T, N>::fill(const T& value) {
    for (std::size_t i = 0; i < N; ++i) {
        data[i] = value;
    }
}

template <typename T, std::size_t N>
void Array<T, N>::swap(Array<T, N>& other) {
    for (std::size_t i = 0; i < N; ++i) {
        T temp = data[i];
        data[i] = other.data[i];
        other.data[i] = temp;
    }
}

