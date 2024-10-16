#include "bst.hpp"
int main() {
    BST t;
    t.insert(45);
    t.insert(32);
    t.insert(123);
    t.insert(1);
    t.insert(-8);
    t.display();
    return 0; 
}