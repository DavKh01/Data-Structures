#include <iostream>
#include "rbt.h"

int main() {
    RBT<int> tree;

    // Inserting nodes
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);
    tree.insert(5);

    // Printing the tree structure
    std::cout << "Tree after insertion:" << std::endl;
    tree.printTree();

    // Searching for a node
    int key = 15;
    Node<int>* node = tree.searchTree(key);
    if (node != nullptr && node != nullptr) {
        std::cout << "Node with key " << key << " found." << std::endl;
    }
    else {
        std::cout << "Node with key " << key << " not found." << std::endl;
    }

    // Deleting a node
    tree.deleteNode(20);
    std::cout << "Tree after deleting node 20:" << std::endl;
    tree.printTree();

    // Traversing the tree
    std::cout << "Preorder traversal:" << std::endl;
    tree.preorder();
    std::cout << std::endl;

    std::cout << "Inorder traversal:" << std::endl;
    tree.inorder();
    std::cout << std::endl;

    std::cout << "Postorder traversal:" << std::endl;
    tree.postorder();
    std::cout << std::endl;

    return 0;
}
