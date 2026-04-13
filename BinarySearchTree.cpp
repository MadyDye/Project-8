#include "BinarySearchTree.h"

// Constructor
template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    root = nullptr;
}

// Destructor
template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    destroyTree(root);
}

// Destroy tree
template <typename T>
void BinarySearchTree<T>::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

// Public insert
template <typename T>
void BinarySearchTree<T>::insert(const T& item) {
    insert(root, item);
}

// Private insert
template <typename T>
void BinarySearchTree<T>::insert(Node*& node, const T& item) {
    if (node == nullptr) {
        node = new Node(item);
    }
    else if (item < node->data) {
        insert(node->left, item);
    }
    else if (node->data < item) {
        insert(node->right, item);
    }
    // If equal, do nothing (no duplicates)
}

// Public contains
template <typename T>
bool BinarySearchTree<T>::contains(const T& item) const {
    return contains(root, item);
}

// Private contains
template <typename T>
bool BinarySearchTree<T>::contains(Node* node, const T& item) const {
    if (node == nullptr) return false;

    if (item == node->data) return true;
    else if (item < node->data)
        return contains(node->left, item);
    else
        return contains(node->right, item);
}

// Public remove
template <typename T>
void BinarySearchTree<T>::remove(const T& item) {
    root = remove(root, item);
}

// Private remove
template <typename T>
typename BinarySearchTree<T>::Node*
BinarySearchTree<T>::remove(Node* node, const T& item) {
    if (node == nullptr) return nullptr;

    if (item < node->data) {
        node->left = remove(node->left, item);
    }
    else if (node->data < item) {
        node->right = remove(node->right, item);
    }
    else {
        // Found node

        // Case 1: No children
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }

        // Case 2: One child
        else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Case 3: Two children
        else {
            Node* minNode = findMin(node->right);
            node->data = minNode->data;
            node->right = remove(node->right, minNode->data);
        }
    }

    return node;
}

// Find minimum
template <typename T>
typename BinarySearchTree<T>::Node*
BinarySearchTree<T>::findMin(Node* node) const {
    while (node && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Public preorder traversal
template <typename T>
void BinarySearchTree<T>::preorderTraverse(void visit(T&)) {
    preorder(root, visit);
}

// Private preorder
template <typename T>
void BinarySearchTree<T>::preorder(Node* node, void visit(T&)) {
    if (node) {
        visit(node->data);
        preorder(node->left, visit);
        preorder(node->right, visit);
    }
}

// Public inorder traversal
template <typename T>
void BinarySearchTree<T>::inorderTraverse(void visit(T&)) {
    inorder(root, visit);
}

// Private inorder
template <typename T>
void BinarySearchTree<T>::inorder(Node* node, void visit(T&)) {
    if (node) {
        inorder(node->left, visit);
        visit(node->data);
        inorder(node->right, visit);
    }
}
