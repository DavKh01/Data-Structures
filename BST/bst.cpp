#include<iostream>
#include "bst.hpp"
BST::BST() : node{nullptr} {}

BST::~BST(){
    clear(node);
}

BST::Node* BST::insert(Node* node, int val){
    if(!node) {
        return new Node(val);
    }
    if(val < node->data){
        node->left = insert(node->left,val);
    }
    else {
        node->right = insert(node->right,val);
    }
    return node;
}

BST::Node* BST::findMax(Node* node){
    if(!node || !node->right) {
        return node;
    }
    return findMax(node->right);
}

BST::Node* BST::findMin(Node* node) {
    if(!node || !node->left){
        return node;
    }
    return findMin(node->left);
}

BST::Node* BST::find(Node* node, int val) {
    if(!node) {
        return nullptr;
    }
    if(val < node->data) {
        return find(node->left,val);
    }
    if(val > node->data) {
        return find(node->right, val);
    }
    return node;
}

BST::Node* BST::remove(Node* node, int val) {
    if(!node){
        return nullptr;
    }
    Node* tmp;
    if(val < node->data){
        node->left = remove(node->left, val);
    }
    else if (val > node->data) {
        node->right = remove(node->right, val);
    }
    else if(node->left && node->right) {
        tmp = findMin(node->right);
        node->data = tmp->data;
        node->right = remove(node->right, node->data);
    }
    else {
        tmp = node;
        if(!node->left) {
            node = node->right;
        }
        else if(!node->right){
            node = node->left;
        }
        delete tmp;
    }
    return node;
}

void BST::inorder(Node* node){
    if(!node) {
        return;
    }
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

BST::Node* BST::clear(Node* node) {
    if(!node) {
        return node;
    }
    clear(node->left);
    clear(node->right);
    delete node;
    return nullptr;
}

void BST::insert(int val) {
    node = insert(node,val);
}

void BST::remove(int val) {
    node = remove(node, val);
}

void BST::display(){
    inorder(node);
    std::cout << std::endl;
}

void BST::search(int val) {
    node = find(node, val);
}