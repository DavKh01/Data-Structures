#include <iostream>
#include "array.h"

int main() {
    Array<int, 5> arr;
    arr.fill(10);

    std::cout << "Array elements: ";
    for (std::size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "First element: " << arr.front() << std::endl;
    std::cout << "Last element: " << arr.back() << std::endl;

    return 0;
}
