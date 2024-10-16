#include "stack.h"
#include <iostream>
int main() {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << std::endl;
    std::cout << "Stack size: " << stack.size() << std::endl;

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl;
    std::cout << "Stack size after pop: " << stack.size() << std::endl;
    int x;
    std::cin >> x;
    return 0;
}