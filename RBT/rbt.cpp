#include "rbt.h"
#include <iostream>
template <typename T>
RBT<T>::RBT()
{
	NIL = new Node<T>(0);
	NIL->color = BLACK;
	NIL->left = nullptr;
	NIL->right = nullptr;
	root = NIL;
}

template <typename T>
void RBT<T>::initializeNULLNode(Node<T>* node, Node<T>* parent)
{
	node->data = 0;
	node->parent = parent;
	node->left = nullptr;
	node->right = nullptr;
	node->color = BLACK;
}

template <typename T>
void RBT<T>::preOrderHelper(Node<T>* node)
{
	if (node) {
		std::cout << node->data << " ";
		preOrderHelper(node->left);
		preOrderHelper(node->right);
	}
}

template <typename T>
void RBT<T>::inOrderHelper(Node<T>* node)
{
	if (node) {
		inOrderHelper(node->left);
		std::cout << node->data << " ";
		inOrderHelper(node->right);
	}
}

template <typename T>
void RBT<T>::postOrderHelper(Node<T>* node)
{
	if (node) {
		postOrderHelper(node->left);
		postOrderHelper(node->right);
		std::cout << node->data << " ";
	}
}

template <typename T>
Node<T>* RBT<T>::searchTreeHelper(Node<T>* node, T key)
{
	if (!node || key == node->data) {
		return node;
	}
	if (key < node->data) {
		return searchTreeHelper(node->left, key);
	}
	return searchTreeHelper(node->right, key);
}

template <typename T>
void RBT<T>::balanceInsert(Node<T>* k)
{
	Node<T>* u;
	while (k->parent->color == RED) {
		if (k->parent == k->parent->parent->right) {
			u = k->parent->parent->left;
			if (u->color == RED) {
				u->color = BLACK;
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				k = k->parent->parent;
			}
			else {
				if (k == k->parent->left) {
					k = k->parent;
					rightRotate(k);
				}
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				leftRotate(k->parent->parent);
			}
		}
		else {
			u = k->parent->parent->right;
			if (u->color == RED) {
				u->color = BLACK;
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				k = k->parent->parent;
			}
			else
			{
				if (k == k->parent->right) {
					k = k->parent;
					leftRotate(k);
				}
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				rightRotate(k->parent->parent);
			}
		}
		if (k == root) {
			break;
		}
	}
	root->color = BLACK;
}

template <typename T>
void RBT<T>::transplant(Node<T>* u, Node<T>* v)
{
	if (u->parent == nullptr) {
		root = v;
	}
	else if (u == u->parent->left) {
		u->parent->left = v;
	}
	else {
		u->parent->right = v;
	}
	v->parent = u->parent;
}

template <typename T>
void RBT<T>::balanceDelete(Node<T>* x)
{
	Node<T>* s;
	while (x != root && x->color == BLACK) {
		if (x == x->parent->left) {
			s = x->parent->right;
			if (s->color == RED) {
				s->color = BLACK;
				x->parent->color = RED;
				leftRotate(x->parent);
				s = x->parent->right;
			}
			if (s->left->color == BLACK && s->right->color == BLACK) {
				s->color = RED;
				x = x->parent;
			}
			else {
				if (s->right->color == BLACK) {
					s->left->color == BLACK;
					s->color = RED;
					rightRotate(s);
					s = x->parent->right;
				}
				s->color = x->parent->color;
				x->parent->color = BLACK;
				s->right->color = BLACK;
				leftRotate(x->parent);
				x = root;
			}
		}
		else {
			s = x->parent->left;
			if (s->color == RED) {
				s->color = BLACK;
				x->parent->color = RED;
				rightRotate(x->parent);
				s = x->parent->left;
			}
			if (s->left->color == BLACK && s->right->color == BLACK) {
				s->color = RED;
				x = x->parent;
			}
			else {
				if (s->left->color == BLACK) {
					s->right->color = BLACK;
					s->color = RED;
					leftRotate(s);
					s = x->parent->left;
				}
				s->color = x->parent->color;
				x->parent->color = BLACK;
				s->left->color = BLACK;
				rightRotate(x->parent);
				x = root;
			}
		}
	}
	x->color = BLACK;
}

template <typename T>
void RBT<T>::deleteNodeHelper(Node<T>* node, T key)
{
	Node<T>* z = NIL;
	Node<T>* x, * y;
	while (node != NIL) {
		if (node->data == key) {
			z = node;
		}
		if (node->data <= key) {
			node = node->right;
		}
		else {
			node = node->left;
		}
	}
	if (z == NIL) {
		std::cout << "The key does not exist in the tree:\n";
		return;
	}
	y = z;
	Color yColor = y->color;
	if (z->left == NIL) {
		x = z->right;
		transplant(z, z->right);
	}
	else if (z->right == NIL) {
		x = z->left;
		transplant(z, z->left);
	}
	else {
		y = minimum(z->right);
		yColor = y->color;
		x = y->right;
		if (y->parent == z) {
			x->parent = y;
		}
		else {
			transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	delete z;
	if (yColor == BLACK) {
		balanceDelete(x);
	}
}

template <typename T>
void RBT<T>::leftRotate(Node<T>* x)
{
	Node<T>* y = x->right;
	x->right = y->left;
	if (y->left != NIL) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nullptr) {
		this->root = y;
	}
	else if (x == x->parent->left) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

template <typename T>
void RBT<T>::rightRotate(Node<T>* x)
{
	Node<T>* y = x->right;
	x->left = y->right;
	if (y->right != NIL) {
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nullptr) {
		this->root = y;
	}
	else if (x = x->parent->right) {
		x->parent->right = y;
	}
	else {
		x->parent->left = y;
	}
	y->right = x;
	x->parent = y;
}

template <typename T>
void RBT<T>::insert(T key)
{
	Node<T>* node = new Node<T>(key);
	node->parent = nullptr;
	node->data = key;
	node->left = node->right = NIL;
	node->color = RED;
	Node<T>* y = nullptr;
	Node<T>* x = this->root;
	while (x != NIL) {
		y = x;
		if (node->data < x->data) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	node->parent = y;
	if (!y) {
		root = node;
	}
	else if (node->data < y->data) {
		y->left = node;
	}
	else {
		y->right = node;
	}
	if (node->parent == nullptr) {
		node->color = BLACK;
		return;
	}
	if (node->parent->parent == nullptr) {
		return;
	}
	balanceInsert(node);
}

template <typename T>
Node<T>* RBT<T>::minimum(Node<T>* node)
{
	while (node->left != NIL) {
		node = node->left;
	}
	return node;
}

template <typename T>
Node<T>* RBT<T>::maximum(Node<T>* node)
{
	while (node->right != NIL) {
		node = node->right;
	}
	return node;
}

template <typename T>
Node<T>* RBT<T>::successor(Node<T>* x)
{
	if (x->right != NIL) {
		return minimum(x->right);
	}
	Node<T>* y = x->parent;
	while (y != NIL && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;
}

template <typename T>
Node<T>* RBT<T>::predecessor(Node<T>* x) {
	if (x->left != NIL) {
		return maximum(x->left);
	}

	Node<T>* y = x->parent;
	while (y != NIL && x == y->left) {
		x = y;
		y = y->parent;
	}

	return y;
}

template <typename T>
Node<T>* RBT<T>::searchTree(T k) {
	return searchTreeHelper(this->root, k);
}

template <typename T>
void RBT<T>::deleteNode(T data) {
	deleteNodeHelper(this->root, data);
}

template <typename T>
void RBT<T>::preorder() {
	preOrderHelper(this->root);
}

template <typename T>
void RBT<T>::inorder() {
	inOrderHelper(this->root);
}

template <typename T>
void RBT<T>::postorder() {
	postOrderHelper(this->root);
}

template <typename T>
void RBT<T>::printTree() {
	if (root) {
		printHelper(this->root, "", true);
	}
}

template <typename T>
void RBT<T>::printHelper(Node<T>* root, std::string indent, bool last) {
	if (root != NIL) {
		std::cout << indent;
		if (last) {
			std::cout << "R----";
			indent += "   ";
		}
		else {
			std::cout << "L----";
			indent += "|  ";
		}

		std::string sColor = root->color ? "BLACK" : "RED";
		std::cout << root->data << "(" << sColor << ")" << std::endl;
		printHelper(root->left, indent, false);
		printHelper(root->right, indent, true);
	}
}

template class RBT<int>;
template class Node<int>;