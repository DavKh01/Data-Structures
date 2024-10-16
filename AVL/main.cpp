#include <iostream>
#include "avl.h"

int main() {
    AVL<int> tree;
    std::cout << "hello";
    // Inserting values
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    tree.insert(64);
    tree.insert(56);
    tree.insert(2);
    tree.insert(33);

    // Displaying the AVL tree using different traversal orders
    std::cout << "Inorder traversal: ";
    tree.inorder();

    std::cout << "Preorder traversal: ";
    tree.preorder();

    std::cout << "Postorder traversal: ";
    tree.postorder();

    // Searching for values
    int searchValue = 25;
    if (tree.search(searchValue)) {
        std::cout << "Value " << searchValue << " found in the tree." << std::endl;
    }
    else {
        std::cout << "Value " << searchValue << " not found in the tree." << std::endl;
    }

    // Getting the predecessor and successor
    try {
        int pred = tree.getPredecessor(30);
        std::cout << "Predecessor of 30: " << pred << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        int succ = tree.getSuccessor(30);
        std::cout << "Successor of 30: " << succ << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    // Deleting a value
    tree.deleteValue(20);
    std::cout << "Inorder traversal after deleting 20: ";
    tree.inorder();

    //Size of Nodes
    std::cout << "Size of Nodes: " << tree.getSize() << std::endl;

    //Height of tree
    std::cout << "Height of Tree: " << tree.getHeight() << std::endl;
    return 0;
}