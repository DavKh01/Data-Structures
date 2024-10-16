#ifndef Array_H
#define Array_H

#include <cstddef> // For std::size_t
#include <stdexcept> // For std::out_of_range

template <typename T, std::size_t N>
class Array {
private:
    T data[N];

public:
    // Element access
    T& at(std::size_t index) {
        if (index >= N) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& at(std::size_t index) const {
        if (index >= N) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    T& operator[](std::size_t index) {
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        return data[index];
    }

    T& front() {
        return data[0];
    }

    const T& front() const {
        return data[0];
    }

    T& back() {
        return data[N - 1];
    }

    const T& back() const {
        return data[N - 1];
    }

    T* dataPtr() {
        return data;
    }

    const T* dataPtr() const {
        return data;
    }

    // Capacity
    constexpr std::size_t size() const noexcept { return N; }
    constexpr bool empty() const noexcept { return N == 0; }

    // Modifiers
    void fill(const T& value) {
        for (std::size_t i = 0; i < N; ++i) {
            data[i] = value;
        }
    }

    void swap(Array<T, N>& other) {
        for (std::size_t i = 0; i < N; ++i) {
            T temp = data[i];
            data[i] = other.data[i];
            other.data[i] = temp;
        }
    }
};

#endif
