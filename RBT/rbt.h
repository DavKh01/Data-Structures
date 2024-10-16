#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include <string>
enum Color { RED, BLACK };

template <typename T>
struct Node {
    T data;
    Color color;
    Node* left, * right, * parent;

    Node(T data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

template <typename T>
class RBT {
private:
    Node<T>* root;
    Node<T>* NIL;

    void initializeNULLNode(Node<T>* node, Node<T>* parent);
    void preOrderHelper(Node<T>* node);
    void inOrderHelper(Node<T>* node);
    void postOrderHelper(Node<T>* node);
    Node<T>* searchTreeHelper(Node<T>* node, T key);
    void balanceInsert(Node<T>* k);
    void balanceDelete(Node<T>* x);
    void transplant(Node<T>* u, Node<T>* v);
    void deleteNodeHelper(Node<T>* node, T key);
    void printHelper(Node<T>* root, std::string indent, bool last);

public:
    RBT();
    void preorder();
    void inorder();
    void postorder();
    Node<T>* searchTree(T k);
    Node<T>* minimum(Node<T>* node);
    Node<T>* maximum(Node<T>* node);
    Node<T>* successor(Node<T>* x);
    Node<T>* predecessor(Node<T>* x);
    void leftRotate(Node<T>* x);
    void rightRotate(Node<T>* x);
    void insert(T key);
    void deleteNode(T data);
    void printTree();
};
#include "rbt.cpp"
#endif
