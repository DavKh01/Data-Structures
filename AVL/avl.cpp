#include <iostream>
#include "avl.h"

template<typename T>
AVL<T>::AVL() : root{ nullptr } {}

template<typename T>
AVL<T>::~AVL()
{
    clear(root);
}

template<typename T>
typename AVL<T>::Node* AVL<T>::insertHelper(Node*& node, T value)
{
    if (!node) {
        return new Node(value);
    }
    if (value < node->data) {
        node->left = insertHelper(node->left, value);
    }
    else {
        node->right = insertHelper(node->right, value);
    }
    return Balance(node);
}

template<typename T>
void AVL<T>::insert(T value)
{
    root = insertHelper(root, value);
}

template<typename T>
typename AVL<T>::Node* AVL<T>::searchHelper(Node* node, T value) const
{
    if (!node) {
        return node;
    }
    if (value == node->data) {
        return node;
    }
    if (value < node->data) {
        return searchHelper(node->left, value);
    }
    else {
        return searchHelper(node->right, value);
    }
}

template<typename T>
bool AVL<T>::search(T value) const
{
    return searchHelper(root, value) != nullptr;
}

template<typename T>
void AVL<T>::inorderHelper(Node* node) const
{
    if (!node) {
        return;
    }
    inorderHelper(node->left);
    std::cout << node->data << ' ';
    inorderHelper(node->right);
}

template<typename T>
void AVL<T>::inorder() const
{
    inorderHelper(root);
    std::cout << std::endl;
}

template<typename T>
void AVL<T>::preorderHelper(Node* node) const
{
    if (!node) {
        return;
    }
    std::cout << node->data << ' ';
    preorderHelper(node->left);
    preorderHelper(node->right);
}

template<typename T>
void AVL<T>::preorder() const
{
    preorderHelper(root);
    std::cout << std::endl;
}

template<typename T>
void AVL<T>::postorderHelper(Node* node) const
{
    if (!node) {
        return;
    }
    postorderHelper(node->left);
    postorderHelper(node->right);
    std::cout << node->data << ' ';
}

template<typename T>
void AVL<T>::postorder() const
{
    postorderHelper(root);
    std::cout << std::endl;
}

template<typename T>
void AVL<T>::clear(Node* node)
{
    if (!node) {
        return;
    }
    clear(node->left);
    clear(node->right);
    delete node;
}

template<typename T>
typename AVL<T>::Node* AVL<T>::getMin(Node* node) const
{
    if (!node || !node->left) {
        return node;
    }
    return getMin(node->left);
}

template<typename T>
typename AVL<T>::Node* AVL<T>::getMax(Node* node) const
{
    if (!node || !node->right) {
        return node;
    }
    return getMax(node->right);
}

template<typename T>
int AVL<T>::getHeightHelper(Node* node) const
{
    if (!node) {
        return 0;
    }
    return std::max(getHeightHelper(node->left), getHeightHelper(node->right)) + 1;
}

template<typename T>
int AVL<T>::getHeight() const
{
    return getHeightHelper(root);
}

template<typename T>
int AVL<T>::getSizeHelper(Node* node) const
{
    if (!node) {
        return 0;
    }
    return getSizeHelper(node->left) + getSizeHelper(node->right) + 1;
}

template<typename T>
int AVL<T>::getSize() const
{
    return getSizeHelper(root);
}

template<typename T>
typename AVL<T>::Node* AVL<T>::getPredecessorHelper(Node* node) const
{
    if (!node) {
        return node;
    }
    if (node->left) {
        return getMax(node->left);
    }
    Node* ancestor = root;
    Node* predecessor = nullptr;
    while (ancestor != node) {
        if (node->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        }
        else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
}

template<typename T>
T AVL<T>::getPredecessor(T value) const
{
    Node* tmp = searchHelper(root, value);
    Node* node = getPredecessorHelper(tmp);
    if (!node) {
        throw std::runtime_error("The element is the first:\n");
    }
    return node->data;
}

template<typename T>
typename AVL<T>::Node* AVL<T>::getSuccessorHelper(Node* node) const
{
    if (!node) {
        return node;
    }
    if (node->right) {
        return getMin(node->right);
    }
    Node* ancestor = root;
    Node* successor = nullptr;
    while (ancestor != node) {
        if (node->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else {
            ancestor = ancestor->right;
        }
    }
    return successor;
}

template<typename T>
T AVL<T>::getSuccessor(T value) const
{
    Node* tmp = searchHelper(root, value);
    Node* node = getSuccessorHelper(tmp);
    if (!node) {
        throw std::runtime_error("The element is the first:\n");
    }
    return node->data;
}

template<typename T>
typename AVL<T>::Node* AVL<T>::leftRotate(Node* node)
{
    Node* y = node->right;
    Node* T1 = y->left;
    y->left = node;
    node->right = T1;
    return y;
}

template<typename T>
typename AVL<T>::Node* AVL<T>::rightRotate(Node* node)
{
    Node* y = node->left;
    Node* T1 = y->right;
    y->right = node;
    node->left = T1;
    return y;
}

template<typename T>
typename AVL<T>::Node* AVL<T>::deleteValueHelper(Node* node, T value)
{
    if (!node) {
        return node;
    }
    if (value < node->data) {
        node->left = deleteValueHelper(node->left, value);
    }
    else if (value > node->data) {
        node->right = deleteValueHelper(node->right, value);
    }
    else {
        if (!node->left) {
            Node* tmp = node->right;
            delete node;
            return tmp;
        }
        if (!node->right) {
            Node* tmp = node->left;
            delete node;
            return tmp;
        }
        else {
            Node* tmp = getMin(node->right);
            node->data = tmp->data;
            node->right = deleteValueHelper(node->right, node->data);
        }
    }
    return Balance(node);
}

template<typename T>
void AVL<T>::deleteValue(T value)
{
    root = deleteValueHelper(root, value);
}

template<typename T>
int AVL<T>::getBF(Node* node)
{
    return node ? getHeightHelper(node->left) - getHeightHelper(node->right) : 0;
}

template<typename T>
typename AVL<T>::Node* AVL<T>::Balance(Node* node)
{
    int bf = getBF(node);
    // left left
    if (bf > 1 && getBF(node->left) >= 0) {
        return rightRotate(node);
    }
    // left right
    if (bf > 1 && getBF(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // right right
    if (bf < -1 && getBF(node->right) <= 0) {
        return leftRotate(node);
    }
    // right left
    if (bf < -1 && getBF(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
