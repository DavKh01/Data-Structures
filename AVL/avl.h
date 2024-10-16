#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template<typename T>
class AVL {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        int height;
        Node(T val)
            : data(val)
            , left(nullptr)
            , right(nullptr)
            , height(0)
        {}
    };

    Node* root;

    Node* insertHelper(Node*& node, T value);
    Node* searchHelper(Node* node, T value) const;
    void inorderHelper(Node* node) const;
    void preorderHelper(Node* node) const;
    void postorderHelper(Node* node) const;
    void clear(Node* node);
    Node* getMin(Node* node) const;
    Node* getMax(Node* node) const;
    int getHeightHelper(Node* node) const;
    int getSizeHelper(Node* node) const;
    Node* getPredecessorHelper(Node* node) const;
    Node* getSuccessorHelper(Node* node) const;
    Node* leftRotate(Node* node);
    Node* rightRotate(Node* node);
    Node* deleteValueHelper(Node* node, T value);
    int getBF(Node* node);
    Node* Balance(Node* node);
public:
    AVL();
    ~AVL();

    void insert(T value);
    bool search(T value) const;
    void inorder() const;
    void preorder() const;
    void postorder() const;
    void deleteValue(T value);
    int getHeight() const;
    int getSize() const;
    T getPredecessor(T value) const;
    T getSuccessor(T value) const;
};

#include "avl.cpp"
#endif // AVL_H