#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
using namespace std;

template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& d) : data(d), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper functions
    void insert(Node*& node, const T& item);
    bool contains(Node* node, const T& item) const;
    Node* remove(Node* node, const T& item);
    Node* findMin(Node* node) const;

    void preorder(Node* node, void visit(T&));
    void inorder(Node* node, void visit(T&));

    void destroyTree(Node* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(const T& item);
    bool contains(const T& item) const;
    void remove(const T& item);

    void preorderTraverse(void visit(T&));
    void inorderTraverse(void visit(T&));
};

#include "BinarySearchTree.cpp"

#endif
